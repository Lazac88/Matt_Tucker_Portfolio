using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    public delegate double LaplacianMethod(Cell currentCell, bool isAFeed);

    public class GridManager
    {
        private const int NUM_NEIGHBOURS = 8;
        private const int PERP_NEIGHBOURS = 4;  //Const to set the number of perpendicular neighbours

        public Cell[,] currentGrid { get; set; }
        public Cell[,] refreshGrid { get; set; }
        private CellFactory cellFactory;
        private int gridSize;
        private int seedSize;       //This is generated automatically depending on the grid size. Is 25% of total grid

        //Simulation parameters
        public double aFeed { get; set; }
        public double bKill { get; set; }
        private double diffA;
        private double diffB;

        public LaplacianMethod laplacianMethod { get; set; }

        //Array of the perpendicular neighbours in a cell
        int[] perpNeighbours;
        //Array of the perpendicular neighbours in a cell
        int[] angularNeighbours;

        public GridManager(int gridSize, SimulationParameters sp)
        {
            this.gridSize = gridSize;
            this.laplacianMethod = null;
            this.aFeed = sp.FeedA;
            this.bKill = sp.KillB;
            this.diffA = sp.DiffA;
            this.diffB = sp.DiffB;

            //Want seed size to be 25% of total grid
            //Below calculation is doubled as it is plus and minus from the centre point
            seedSize = gridSize / 8;

            cellFactory = new CellFactory();

            currentGrid = BuildNewGrid();
            SetMiddleSeed();            
            GiveGridCellNeighbours(); //Get cell neighbours

            refreshGrid = currentGrid;  //Create a copy of the original grid to reset it later

            perpNeighbours = new int[] { 1, 3, 4, 6 };      //These numbers need to be specified as it is the way I made my neighbours array
            angularNeighbours = new int[] { 0, 2, 5, 7 };
        }

        //Method to reset grid back to starting position
        public void RefreshGrid()
        {
            currentGrid = refreshGrid;
        }

        public Cell[,] BuildNewGrid()
        {
            //Create new Cell 2D Array
            Cell[,] newGrid = new Cell[gridSize, gridSize];

            //Double for loop to fill grid with cells
            for(int x = 0; x < gridSize; x++)
            {
                for(int y = 0; y < gridSize; y++)
                {
                    newGrid[x, y] = cellFactory.GetCell();                    
                }
            }            

            return newGrid;
        }

        public void SetMiddleSeed()
        {
            //Creates some seeds in the middle of the grid
            int start = (gridSize / 2) - seedSize;
            int end = (gridSize / 2) + seedSize;
            for (int x = start; x < end; x++)
            {
                for (int y = start; y < end; y++)
                {
                    currentGrid[x, y].A = 0.000;
                    currentGrid[x, y].B = 1.000;
                }
            }
        }

        public void GiveGridCellNeighbours()
        {
            for (int x = 0; x < gridSize; x++)
            {
                for (int y = 0; y < gridSize; y++)
                {
                    //Give cell its neighbours
                    currentGrid[x, y].myNeighbours = FindCellNeighbours(x, y);
                }
            }
        }

        private Cell[] FindCellNeighbours(int xGrid, int yGrid)
        {
            Cell[] neighbourArray = new Cell[NUM_NEIGHBOURS];
            int count = 0;

            //double for loop to get all neighbours
            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    if(x == 0 && y == 0)    //Check that not looking at itself
                    {
                        //Do Nothing
                        //I originally tried if(x != 0 && y != 0) but it would trigger if only one number was 0
                    }
                    else
                    {
                        int xPos = xGrid + x;
                        int yPos = yGrid + y;
                        //Find neighbour grid position. If it is off grid wrap around - using CheckForEdgesMethod
                        int neighbourX = CheckForEdges(xPos);
                        int neighbourY = CheckForEdges(yPos);
                        neighbourArray[count] = currentGrid[neighbourX, neighbourY];
                        count++;
                    }
                }
            }
            return neighbourArray;
        }

        //Checks to see if gridPosition is off the grid, and returns the wrapped around number if so
        private int CheckForEdges(int gridPosition)
        {
            int gridPos = gridPosition;
            int edgeIndex = gridSize - 1;
            if(gridPos < 0)
            {
                gridPos = edgeIndex;
            }
            if(gridPos > edgeIndex)
            {
                gridPos = 0;
            }
            return gridPos;
        }        

        public void ComputeNewConcentrations()
        {
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    //Grab cell and simulation parameters
                    Cell gridCell = currentGrid[i, j];
                    double concentrationA = gridCell.A;
                    double concentrationB = gridCell.B;

                    //Calculate the values needed for the equation
                    double LaplacianA = laplacianMethod(gridCell, true);
                    double LaplacianB = laplacianMethod(gridCell, false);

                    double diffATimesLaplacian = diffA * LaplacianA;
                    double diffBTimesLaplacian = diffB * LaplacianB;

                    //Test hard coded params
                    //double diffATimesLaplacian = 0.000000000000000222;
                    //double diffBTimesLaplacian = 0;

                    double equationABSquared = getABSquared(concentrationA, concentrationB);

                    double equationAFeed = getAFeed(concentrationA, aFeed);
                    double equationBKill = getBKill(aFeed, bKill, concentrationB);

                    //Finish the equation and get the new concentrations of A and B
                    double newA = concentrationA + diffATimesLaplacian - equationABSquared + equationAFeed;
                    double newB = concentrationB + diffBTimesLaplacian + equationABSquared - equationBKill;

                    //Change the holding value of the current cell
                    if (newA > 1)
                    {
                        gridCell.tempA = 1;
                    }
                    else if (newA < 0)
                    {
                        gridCell.tempA = 0;
                    }
                    else
                    {
                        gridCell.tempA = newA;
                    }

                    if (newB > 1)
                    {
                        gridCell.tempB = 1;
                    }
                    else if (newB < 0)
                    {
                        gridCell.tempB = 0;
                    }
                    else
                    {
                        gridCell.tempB = newB;
                    }
                }
            }
        }

        

        //Updates each cell to its new concentration
        public void UpdateCellsToNewConcentrations()
        {
            for (int i = 0; i < gridSize; i++)
            {
                for (int j = 0; j < gridSize; j++)
                {
                    //Get current cell
                    Cell gridCell = currentGrid[i, j];

                    //Update A and B values with the holding values
                    gridCell.A = gridCell.tempA;
                    gridCell.B = gridCell.tempB;
                }
            }
        }

        //Methods to calculate the various parts of the equation
        public double getABSquared(double concentrationA, double concentrationB)
        {
            double bSquared = concentrationB * concentrationB;
            double ABSquared = concentrationA * bSquared;
            return ABSquared;
        }

        public double getAFeed(double concentrationA, double feedA)
        {
            double oneMinusA = 1.000 - concentrationA;
            double newFeed = feedA * oneMinusA;
            return newFeed;
        }

        public double getBKill(double feedA, double killB, double concentrationB)
        {
            double feedPlusKill = killB + feedA;
            double newKill = feedPlusKill * concentrationB;
            return newKill;
        }


        //====================================================================LAPLACIAN METHODS==================================================================//
        public double PerpendicularLap(Cell currentCell, bool isAFeed)
        {
            Cell[] neighbours = currentCell.myNeighbours;
            //Mysterious nature constants
            double h = 2.5 / 127.0;
            double rh = 1.0 / h / h;

            //Calculate the sum of the neighbour cells
            double neighboursSum = 0.000;
            double currentCellConcentration = 0.000;
            if (isAFeed)
            {
                currentCellConcentration = currentCell.A;
                for (int i = 0; i < PERP_NEIGHBOURS; i++)
                {
                    int neighbourCellIndex = perpNeighbours[i];
                    Cell neighbourCell = neighbours[neighbourCellIndex];
                    neighboursSum += neighbourCell.A;
                }
            }
            else    //Is BKill
            {
                currentCellConcentration = currentCell.B;
                for (int i = 0; i < PERP_NEIGHBOURS; i++)
                {
                    int neighbourCellIndex = perpNeighbours[i];
                    Cell neighbourCell = neighbours[neighbourCellIndex];
                    neighboursSum += neighbourCell.B;
                }
            }

            double fourTimesConc = 4 * currentCellConcentration;

            double finalLaplacianValue = rh * (neighboursSum - fourTimesConc);
            return finalLaplacianValue;
        }

        public double ConvolutionLap(Cell currentCell, bool isAFeed)
        {
            Cell[] neighbours = currentCell.myNeighbours;

            //Calculate the sum of the neighbour cells
            double neighboursSum = 0.000;
            double concTimesConstant = 0.000;
            //Grab the sum of perpendicular neighbours
            foreach (int i in perpNeighbours)
            {
                if (isAFeed)
                {
                    concTimesConstant = neighbours[i].A * 0.200;
                }
                else
                {
                    concTimesConstant = neighbours[i].B * 0.200;
                }
                neighboursSum += concTimesConstant;
            }
            //Grab the sum of angular neighbours
            foreach (int i in angularNeighbours)
            {
                if (isAFeed)
                {
                    concTimesConstant = neighbours[i].A * 0.050;
                }
                else
                {
                    concTimesConstant = neighbours[i].B * 0.050;
                }
                neighboursSum += concTimesConstant;
            }
            //Calculate current cell
            if (isAFeed)
            {
                concTimesConstant = currentCell.A * -1.000;
            }
            else
            {
                concTimesConstant = currentCell.B * -1.000;
            }
            neighboursSum += concTimesConstant;

            return neighboursSum;
        }

        public double DeltaLap(Cell currentCell, bool isAFeed)
        {
            Cell[] neighbours = currentCell.myNeighbours;

            double currentCellConc = 0.000;

            //Calculate the sum of the neighbour cells
            double neighboursSum = 0.000;

            if (isAFeed)
            {
                currentCellConc = currentCell.A;
                foreach (Cell c in neighbours)
                {
                    neighboursSum += c.A;
                }
            }
            else        //Is BKill
            {
                currentCellConc = currentCell.B;
                foreach (Cell c in neighbours)
                {
                    neighboursSum += c.B;
                }
            }

            double avgNeighbourConc = neighboursSum / 8.000;
            double diffNeighboursToCurrent = avgNeighbourConc - currentCellConc;

            return diffNeighboursToCurrent;
        }
    }
}

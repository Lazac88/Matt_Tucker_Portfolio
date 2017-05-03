using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PatternSimulator
{    

    public class SimulationManager
    { 
        private GridManager gridManager;
        private OutputManager outputManager;
        private LaplacianMethodFactory laplacianMethodFactory;
        public Cell[,] currentGrid { get; set; }
        SimulationParameters simParams;

        public SimulationManager(OutputManager outputManager, int gridSize, SimulationParameters sp)
        {
            this.outputManager = outputManager;
            //Initialize the grid to null, will be used by methods later
            currentGrid = null;
            //Create the gridManager
            gridManager = new GridManager(gridSize, sp);
            //Create Laplacian Method Factory
            laplacianMethodFactory = new LaplacianMethodFactory(gridManager);
            
            simParams = sp;         
        }        

        //Method for running the simulation over a range of parameters
        public void RunSimulationRange(double aFeedMax, double bKillMax, int iterations, TextBox txtBoxIterations, TextBox txtBoxFeedA, TextBox txtBoxKillB, bool saveToDisk)
        {
            //Grab the data that doesn't change outside the for loop
            LaplacianMethod lm = GetLaplacianMethodFromEnum(simParams.LaplacianMethod);
            //Set the grids Laplacian Method
            gridManager.laplacianMethod = lm;
            double aFeedMin = simParams.FeedA;
            double bKillMin = simParams.KillB;
            
            //Double forloop to run through the whole specified range
            for (double aFeed = aFeedMin; aFeed < aFeedMax; aFeed += 0.001)
            {
                for (double bKill = bKillMin; bKill < bKillMax; bKill += 0.001)
                {
                    //Reset the grid with current params
                    gridManager.RefreshGrid();
                    gridManager.aFeed = aFeed;
                    gridManager.bKill = bKill;
                    
                    //Run the simulation for specified iterations
                    for (int i = 0; i < iterations; i++)
                    {
                        gridManager.ComputeNewConcentrations();
                        gridManager.UpdateCellsToNewConcentrations();

                        //User Feedback (Slows down simulation a little but gives the user decent feedback as to what is happening)
                        txtBoxFeedA.Text = aFeed.ToString();
                        txtBoxKillB.Text = bKill.ToString();
                        txtBoxIterations.Text = i.ToString();
                        Application.DoEvents();
                    }
                    //Grab the grid at the end of the simulation and draw it
                    currentGrid = gridManager.currentGrid;
                    outputManager.DrawCells(currentGrid);
                    if(saveToDisk)      //Check if user wants to save the simulation (Saves to default folder)
                    {
                        String info = GetParameterString(aFeed, bKill, iterations);
                        outputManager.SaveBitmapToDisk(info, simParams.LaplacianMethod);
                    }
                    //GC.Collect();     //Does not improve simulation speed                    
                }
            }
        }

        //This method is used with the user interface. Allows a single simulation to be run
        public void SingleParameterSimulation(SimulationParameters sp, int iterations, bool saveToDisk)
        {
            LaplacianMethod lm = GetLaplacianMethodFromEnum(sp.LaplacianMethod);
            gridManager.laplacianMethod = lm;

            //Run the simulation for specified iterations
            for (int i = 0; i < iterations; i++)
            {
                gridManager.ComputeNewConcentrations();
                gridManager.UpdateCellsToNewConcentrations();
                currentGrid = gridManager.currentGrid;                          //Draw the grid at each iteration - allows the user to see pattern development
                outputManager.DrawCells(currentGrid, sp.ColourAlgorithm);
            }
            if(saveToDisk)
            {
                String info = GetParameterString(sp.FeedA, sp.KillB, iterations);
                outputManager.SaveBitmapToDisk(info, sp.LaplacianMethod);
            }                        
        }        

        //Convert From Enum to LaplacianMethod
        public LaplacianMethod GetLaplacianMethodFromEnum(ELaplacain laplacian)
        {
            LaplacianMethod lm = null;
            if (laplacian == ELaplacain.Delta)
            {
                lm = laplacianMethodFactory.GetDeltaMeans();
            }
            else if (laplacian == ELaplacain.Convolution)
            {
                lm = laplacianMethodFactory.GetConvolution();
            }
            else if (laplacian == ELaplacain.Perpendicular)
            {
                lm = laplacianMethodFactory.GetPerpendicular();
            }
            return lm;
        }

        //Method to convert aFeed and bKill info to string
        private String GetParameterString(double a, double b, int iterations)
        {
            String AFeedString = a.ToString();
            String BKillString = b.ToString();
            String iterationString = iterations.ToString();
            String info = "FeedA" + AFeedString + "KillB" + BKillString + "Iterations" + iterationString;
            return info;
        }

        //Used for testing purposes. Could be modified to run with user input
        public void TimerTickSimulation(SimulationParameters sp, int gridSize, int iterations, bool saveToDisk)
        {
            
        }
    }
}

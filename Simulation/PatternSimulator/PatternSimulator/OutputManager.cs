using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PatternSimulator
{
    public delegate Color ColourAlgorithm(double concentrationB);
    public class OutputManager
    {
        //Needed to completely clear panel
        private const int TOTAL_PANEL_SIZE = 512;

        private Graphics mainGraphics;
        private Bitmap offScreenBitmap;
        private Graphics offScreenCanvas;
        private Panel displayPanel;

        //Used to calculate square size and loop over 2D array
        private int gridSize;
        //Size of rectangle
        private int cellSize;

        private Brush cellBrush;

        private String colourAlgoName;

        //Temp variable for testing
        private int count;

        //ColourAlgorithm Factory
        ColourAlgorithmFactory colourAlgorithmFactory;

        public OutputManager(int gridSize, Panel displayPanel)
        {
            this.displayPanel = displayPanel;
            this.gridSize = gridSize;
            cellSize = TOTAL_PANEL_SIZE / gridSize;

            colourAlgoName = "LongRainbow";

            //Double Buffering
            offScreenBitmap = new Bitmap(TOTAL_PANEL_SIZE, TOTAL_PANEL_SIZE);
            offScreenCanvas = Graphics.FromImage(offScreenBitmap);
            mainGraphics = displayPanel.CreateGraphics();

            count = 0;

            colourAlgorithmFactory = new ColourAlgorithmFactory(this);
        }

        //TODO
        //Draw Grid To Canvas
        //Hard Coded colour algorithm
        public void DrawCells(Cell[,] gridCells)
        {
            Color cellColour;
            for (int x = 0; x < gridSize; x++)
            {
                for(int y = 0; y < gridSize; y++)
                {
                    //Get info to colour cell
                    Cell currentCell = gridCells[x, y];
                    double bConc = currentCell.B;
                    cellColour = LongRainbow(bConc);
                    cellBrush = new SolidBrush(cellColour);

                    //Draw Rect
                    int panelX = x * cellSize;
                    int panelY = y * cellSize;

                    offScreenCanvas.FillRectangle(cellBrush, panelX, panelY, cellSize, cellSize);
                }
            }
            //Draw grid
            mainGraphics.DrawImage(offScreenBitmap, 0, 0);
        }

        //Overloaded method to specify type of colour algorithm
        public void DrawCells(Cell[,] gridCells, EColourAlgo colourAlgo)
        {
            Color cellColour;
            ColourAlgorithm colourAlgorithm = GetColourAlgorithm(colourAlgo);
            
            for (int x = 0; x < gridSize; x++)
            {
                for (int y = 0; y < gridSize; y++)
                {
                    //Get info to colour cell
                    Cell currentCell = gridCells[x, y];
                    double bConc = currentCell.B;
                    cellColour = colourAlgorithm(bConc);
                    cellBrush = new SolidBrush(cellColour);

                    //Draw Rect
                    int panelX = x * cellSize;
                    int panelY = y * cellSize;

                    offScreenCanvas.FillRectangle(cellBrush, panelX, panelY, cellSize, cellSize);
                }
            }
            //Draw grid
            mainGraphics.DrawImage(offScreenBitmap, 0, 0);
        }

        public ColourAlgorithm GetColourAlgorithm(EColourAlgo colourAlgo)
        {
            ColourAlgorithm ca = null;
            if(colourAlgo == EColourAlgo.GrayScale)
            {
                ca = colourAlgorithmFactory.GetGrayScale();
                colourAlgoName = "GrayScale";
            }
            else if(colourAlgo == EColourAlgo.ShortRainbow)
            {
                ca = colourAlgorithmFactory.GetShortRainbow();
                colourAlgoName = "ShortRainbow";
            }
            else
            {
                ca = colourAlgorithmFactory.GetLongRainbow();
                colourAlgoName = "LongRainbow";
            }
            return ca;
        }
        
        //Save Bitmap to Hard Drive
        public void SaveBitmapToDisk(String patternName, ELaplacain laplacian)
        {
            Bitmap endImage = offScreenBitmap;
            String patNameColour = patternName + colourAlgoName;
            String lapName = laplacian.ToString();
            // Save the image as a jpeg.
            //endImage.Save("M:\\PatternsFolder\\" + patNameColour + ".jpeg", System.Drawing.Imaging.ImageFormat.Jpeg);
            endImage.Save(patNameColour + lapName + ".jpeg", System.Drawing.Imaging.ImageFormat.Jpeg);
        }


        //=========================================================COLOUR ALGORITHMS======================================================================================//
        public Color GrayScale(double concentrationB)
        {
            double x = concentrationB * 255;
            double y = Math.Floor(x);
            int z = Convert.ToInt16(y);
            Color myColour = new Color();
            myColour = Color.FromArgb(z, z, z);
            return myColour;
        }

        public Color ShortRainbow(double concentrationB)
        {
            double a = (1.000 - concentrationB) / 0.25;
            double X = Math.Floor(a);
            int switchX = Convert.ToInt16(X);
            double Y = Math.Floor(255 * (a - X));
            int y = Convert.ToInt16(Y);
            Color myColour = new Color();
            switch(switchX)
            {
                case 0:
                    myColour = Color.FromArgb(255, y, 0);
                    break;
                case 1:
                    myColour = Color.FromArgb(255, 255, 0);
                    break;
                case 2:
                    myColour = Color.FromArgb(0, 255, y);
                    break;
                case 3:
                    myColour = Color.FromArgb(0, 255, 255);
                    break;
                case 4:
                    myColour = Color.FromArgb(0, 0, 255);
                    break;
            }

            return myColour;
        }

        public Color LongRainbow(double concentrationB)
        {
            double a = (1.000 - concentrationB) / 0.2;
            double X = Math.Floor(a);
            int switchX = Convert.ToInt16(X);
            double Y = Math.Floor(255 * (a - X));
            int y = Convert.ToInt16(Y);
            Color myColour = new Color();
            switch (switchX)
            {
                case 0:
                    myColour = Color.FromArgb(255, y, 0);
                    break;
                case 1:
                    myColour = Color.FromArgb(255, 255, 0);
                    break;
                case 2:
                    myColour = Color.FromArgb(0, 255, y);
                    break;
                case 3:
                    myColour = Color.FromArgb(0, 255, 255);
                    break;
                case 4:
                    myColour = Color.FromArgb(y, 0, 255);
                    break;
                case 5:
                    myColour = Color.FromArgb(255, 0, 255);
                    break;
            }

            return myColour;
        }
    }
}

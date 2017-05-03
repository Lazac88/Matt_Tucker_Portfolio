using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PatternSimulator
{
    public partial class Form1 : Form
    {
        private const int GRID_SIZE = 64;

        public Form1()
        {
            InitializeComponent();
        }

        SimulationManager simulationManager;

        OutputManager outputManager;

        //Simulation Parameters
        SimulationParameters sp;        

        private void Form1_Load(object sender, EventArgs e)
        {
            outputManager = null;            

            simulationManager = null;
                
            sp = null;

        }        

        //This method runs the single simulation button
        private void btnGo_Click(object sender, EventArgs e)
        {
            bool runSimulation = true;
            int iterations = 0;

            try
            {
                SimulationParameters sp = GetParameters();
            }
            catch (FormatException)
            {
                runSimulation = false;
                MessageBox.Show("Please enter simulation AFeed and BKill");
            }
            try
            {
                iterations = GetIterations();
            }
            catch(FormatException)
            {
                runSimulation = false;
                MessageBox.Show("Please enter number of iterations");
            }
            
            EColourAlgo colourAlgo = GetColourAlgorithm();
            bool save = GetSaveImage();            
            int gridSize = GetGridSize();

            if(runSimulation)       //Only run if user input is correct
            {
                outputManager = new OutputManager(gridSize, displayPanel);                      //I create the output manager on button click because it needs the grid size
                simulationManager = new SimulationManager(outputManager, gridSize, sp);       //I create the simulation manager on button click because it requires the output manager above
                simulationManager.SingleParameterSimulation(sp, iterations, save);
            }            
        }


        //This method runs the simulation range button
        private void btnRunRange_Click(object sender, EventArgs e)
        {
            int iterations = 0;
            double aFeedMax = -100;
            double bKillMax = -100;
            bool runSimulation = true;
            try
            {
                SimulationParameters sp = GetParameters();
            }
            catch (FormatException)
            {
                runSimulation = false;
                MessageBox.Show("Please enter simulation AFeed and BKill");
            }
            try
            {
                iterations = GetIterations();
            }
            catch (FormatException)
            {
                runSimulation = false;
                MessageBox.Show("Please enter number of iterations");
            }
            try
            {
                aFeedMax = GetAFeedMax();
                bKillMax = GetBKillMax();
            }
            catch(FormatException)
            {
                runSimulation = false;
                MessageBox.Show("Please enter AFeed and BKill end range");
            }            

            EColourAlgo colourAlgo = GetColourAlgorithm();
            bool save = GetSaveImage();                        
            int gridSize = GetGridSize();

            if(runSimulation)       //Only run if user input is correct
            {
                outputManager = new OutputManager(gridSize, displayPanel);
                simulationManager = new SimulationManager(outputManager, gridSize, sp);
                simulationManager.RunSimulationRange(aFeedMax, bKillMax, iterations, txtBoxIterations, txtBoxAFeed, txtBoxBKill, save);
            }            
        }

        //====================================================Methods for Form data=====================================================================================//

        private double GetAFeedMax()
        {
            double aFeedMax = -100;
            try
            {
                aFeedMax = Convert.ToDouble(txtBoxARange.Text);
            }
            catch (FormatException fe)
            {
                throw fe;
            }
            return aFeedMax;
        }
        private double GetBKillMax()
        {
            double bKillMax = -100;
            try
            {
                bKillMax = Convert.ToDouble(txtBoxBRange.Text);
            }
            catch (FormatException fe)
            {
                throw fe;
            }
            return bKillMax;
        }

        private bool GetSaveImage()
        {
            bool save = false;
            if(rBtnSave.Checked)
            {
                save = true;
            }
            return save;
        }

        private EColourAlgo GetColourAlgorithm()
        {
            EColourAlgo colour = EColourAlgo.LongRainbow;
            if(rBtnGreyScale.Checked)
            {
                colour = EColourAlgo.GrayScale;
            }
            else if(rBtnSRainbow.Checked)
            {
                colour = EColourAlgo.ShortRainbow;
            }
            else if(rBtnLRainbow.Checked)
            {
                colour = EColourAlgo.LongRainbow;
            }
            return colour;
        }
        
        private int GetIterations()
        {
            int Iterations = -1;
            try
            {
                Iterations = Convert.ToInt16(txtBoxIterations.Text);
            }
            catch(FormatException fe)
            {
                throw fe;
            }
            return Iterations;
        }

        private int GetGridSize()
        {
            int GridSize;
            if (rBtnSize16.Checked)
            {
                GridSize = 16;
            }
            else if (RBtnSize64.Checked)
            {
                GridSize = 64;
            }
            else
            {
                GridSize = 256;
            }
            return GridSize;
        }

        //Sets all entered parameter values. Adds the Diff's depending on the selected laplacian
        private SimulationParameters GetParameters()
        {
            double AFeed = -100;
            double BKill = -100;
            try
            {
                AFeed = Convert.ToDouble(txtBoxAFeed.Text);
                BKill = Convert.ToDouble(txtBoxBKill.Text);
            }catch(FormatException fe)
            {                
                throw fe;
            }
            
            ELaplacain selectedLaplacian;
            double DiffA;
            double DiffB;
            if(rBtnDelta.Checked)
            {
                selectedLaplacian = ELaplacain.Delta;
                DiffA = 1.000;
                DiffB = 0.500;
            }
            else if (rBtnConvolution.Checked)
            {
                selectedLaplacian = ELaplacain.Convolution;
                DiffA = 1.000;
                DiffB = 0.500;
            }
            else
            {
                selectedLaplacian = ELaplacain.Perpendicular;
                DiffA = 0.00002;
                DiffB = 0.00001;
            }
             
            //Create the SimulationParameters object
            sp = new SimulationParameters(DiffA, DiffB, AFeed, BKill);
            //Set the Laplacian and Colour Algorithm
            sp.LaplacianMethod = selectedLaplacian;
            sp.ColourAlgorithm = GetColourAlgorithm();
            return sp;
        }

        //Method used to run simulation on a timer. Too slow and not used in my final version.
        //Good for testing and slowing the simulation down
        private void timer1_Tick(object sender, EventArgs e)
        {
            //simulationManager.TimerTickSimulation();
            //outputManager.DrawCells(simulationManager.endGrid);
        }

    }
}

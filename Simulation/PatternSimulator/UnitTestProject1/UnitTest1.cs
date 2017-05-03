using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using PatternSimulator;

namespace UnitTestProject1
{
    [TestClass]
    public class UnitTest1
    {
        SimulationParameters sp = new SimulationParameters(1.000, 0.500, 0.032, 0.061);
        GridManager gridManager;
        

        [TestMethod]
        public void getAFeed_Correct_Return()
        {
            gridManager = new GridManager(4, sp);

            double concentrationA = 0.5;
            double feedA = 0.032;

            double expected = 0.016;
            double actual = gridManager.getAFeed(concentrationA, feedA);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getAFeed_WithZeroConc()
        {
            gridManager = new GridManager(4, sp);

            double concentrationA = 0;
            double feedA = 0.032;

            double expected = 0.032;
            double actual = gridManager.getAFeed(concentrationA, feedA);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getBKill_Correct_Return()
        {
            gridManager = new GridManager(4, sp);

            double concentrationB = 0.5;
            double killB = 0.061;
            double feedA = 0.032;

            double expected = 0.0465;
            double actual = gridManager.getBKill(feedA, killB, concentrationB);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getBKill_WithZeroConc()
        {
            gridManager = new GridManager(4, sp);

            double concentrationB = 0;
            double killB = 0.061;
            double feedA = 0.032;

            double expected = 0.000;
            double actual = gridManager.getBKill(feedA, killB, concentrationB);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getABSquared()
        {
            gridManager = new GridManager(4, sp);

            double concentrationA = 0.875;
            double concentrationB = 0.125;

            double expected = 0.013671875;
            double actual = gridManager.getABSquared(concentrationA, concentrationB);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getABSquared_WithZeroConcA()
        {
            gridManager = new GridManager(4, sp);

            double concentrationA = 0.000;
            double concentrationB = 1.000;

            double expected = 0.000;
            double actual = gridManager.getABSquared(concentrationA, concentrationB);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void getABSquared_WithZeroConcB()
        {
            gridManager = new GridManager(4, sp);

            double concentrationA = 1.000;
            double concentrationB = 0.000;

            double expected = 0.000;
            double actual = gridManager.getABSquared(concentrationA, concentrationB);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void DeltaMeans_AConc_A1_B0()
        {
            Cell myCell = new Cell();
            gridManager = new GridManager(4, sp);

            //Create 8 neighbours for the cell
            //Only 1 neighbour has 0 A and 1 B
            Cell[] myNeighbours = new Cell[8];
            for(int i = 0; i < 8; i++)
            {
                myNeighbours[i] = new Cell();
            }
            myNeighbours[7].A = 0.000;
            myNeighbours[7].B = 1.000;

            myCell.myNeighbours = myNeighbours;


            double expected = -0.125;
            double actual = gridManager.DeltaLap(myCell, true);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void DeltaMeans_AConc_A0_B1()
        {
            Cell myCell = new Cell();
            gridManager = new GridManager(4, sp);
            myCell.A = 0.000;
            myCell.B = 1.000;

            //Create 8 neighbours for the cell
            //Only 1 neighbour has 0 A and 1 B
            Cell[] myNeighbours = new Cell[8];
            for (int i = 0; i < 8; i++)
            {
                myNeighbours[i] = new Cell();
            }
            myNeighbours[7].A = 0.000;
            myNeighbours[7].B = 1.000;

            myCell.myNeighbours = myNeighbours;


            double expected = 0.875;
            double actual = gridManager.DeltaLap(myCell, true);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void DeltaMeans_BConc_A1_B0()
        {
            Cell myCell = new Cell();
            gridManager = new GridManager(4, sp);

            //Create 8 neighbours for the cell
            //Only 1 neighbour has 0 A and 1 B
            Cell[] myNeighbours = new Cell[8];
            for (int i = 0; i < 8; i++)
            {
                myNeighbours[i] = new Cell();
            }
            myNeighbours[7].A = 0.000;
            myNeighbours[7].B = 1.000;

            myCell.myNeighbours = myNeighbours;


            double expected = 0.125;
            double actual = gridManager.DeltaLap(myCell, false);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void DeltaMeans_BConc_A0_B1()
        {
            Cell myCell = new Cell();
            gridManager = new GridManager(4, sp);
            myCell.A = 0.000;
            myCell.B = 1.000;

            //Create 8 neighbours for the cell
            //Only 1 neighbour has 0 A and 1 B
            Cell[] myNeighbours = new Cell[8];
            for (int i = 0; i < 8; i++)
            {
                myNeighbours[i] = new Cell();
            }
            myNeighbours[7].A = 0.000;
            myNeighbours[7].B = 1.000;

            myCell.myNeighbours = myNeighbours;


            double expected = -0.875;
            double actual = gridManager.DeltaLap(myCell, false);

            Assert.AreEqual(expected, actual);
        }
    }
}

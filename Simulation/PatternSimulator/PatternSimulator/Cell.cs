using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    public class Cell
    {
        private const int NUM_NEIGHBOURS = 8;
        public double A { get; set; }
        public double B { get; set; }
        public double tempA { get; set; }
        public double tempB { get; set; }
        public Cell[] myNeighbours { get; set; }

        public Cell()
        {
            A = 1.000;
            B = 0.000;
            myNeighbours = new Cell[8];
        }

        //This method moves all temp vaules to current values once all calculations on the grid have been performed.
        public void UpdateMyself()
        {
            A = tempA;
            B = tempB;
        }
    }
}

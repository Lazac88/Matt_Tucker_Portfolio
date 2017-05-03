using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    //A factory used to produce new cells for the grid
    public class CellFactory
    {
        public CellFactory()
        {

        }

        public Cell GetCell()
        {
            Cell cell = new Cell();
            return cell;
        }
    }
}

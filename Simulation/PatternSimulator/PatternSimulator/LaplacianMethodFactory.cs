using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    public class LaplacianMethodFactory
    {
        //Factory Class to create my Laplacian Methods

        GridManager gridManager;
        public LaplacianMethodFactory(GridManager gridManager)
        {
            this.gridManager = gridManager;
        }

        public LaplacianMethod GetDeltaMeans()
        {
            LaplacianMethod lm = new LaplacianMethod(gridManager.DeltaLap);
            return lm;
        }

        public LaplacianMethod GetConvolution()
        {
            LaplacianMethod lm = new LaplacianMethod(gridManager.ConvolutionLap);
            return lm;
        }

        public LaplacianMethod GetPerpendicular()
        {
            LaplacianMethod lm = new LaplacianMethod(gridManager.PerpendicularLap);
            return lm;
        }
    }
}

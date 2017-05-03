using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    //Factory Class to make colour algorithms
    public class ColourAlgorithmFactory
    {
        OutputManager outputManager;

        public ColourAlgorithmFactory(OutputManager outputManager)
        {
            this.outputManager = outputManager;
        }

        public ColourAlgorithm GetGrayScale()
        {
            ColourAlgorithm ca = new ColourAlgorithm(outputManager.GrayScale);
            return ca;
        }

        public ColourAlgorithm GetShortRainbow()
        {
            ColourAlgorithm ca = new ColourAlgorithm(outputManager.ShortRainbow);
            return ca;
        }

        public ColourAlgorithm GetLongRainbow()
        {
            ColourAlgorithm ca = new ColourAlgorithm(outputManager.LongRainbow);
            return ca;
        }
    }
}

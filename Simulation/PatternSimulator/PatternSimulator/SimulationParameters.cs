using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    public class SimulationParameters
    {
        public double DiffA { get; set; }
        public double DiffB { get; set; }
        public double FeedA { get; set; }
        public double KillB { get; set; }
        public ELaplacain LaplacianMethod { get; set; }
        public EColourAlgo ColourAlgorithm { get; set; }

        public SimulationParameters(double DiffA, double DiffB, double FeedA, double KillB)
        {
            this.DiffA = DiffA;
            this.DiffB = DiffB;
            this.FeedA = FeedA;
            this.KillB = KillB;
            LaplacianMethod = ELaplacain.Convolution;
            ColourAlgorithm = EColourAlgo.LongRainbow;
        }

        public override String ToString()
        {
            String simParams = "DiffA" + DiffA.ToString() + "DiffB" + DiffB.ToString() + "FeedA" + FeedA.ToString() + "KillB" + KillB.ToString();
            return simParams;
        }
    }
}

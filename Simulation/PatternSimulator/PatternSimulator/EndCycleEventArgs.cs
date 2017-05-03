using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternSimulator
{
    public class EndCycleEventArgs
    {
        public Cell[,] EndGrid { get; set; }
        public SimulationParameters SimulationParameters { get; set; }
        public String Laplacian { get; set; }
        public String ShadingAlgorithms { get; set; }

        public EndCycleEventArgs(Cell[,] endGrid, SimulationParameters simulationParameters, String laplacian, String shadingAlgorithms)
        {
            this.EndGrid = endGrid;
            this.SimulationParameters = simulationParameters;
            this.Laplacian = laplacian;
            this.ShadingAlgorithms = shadingAlgorithms;
        }
    }
}

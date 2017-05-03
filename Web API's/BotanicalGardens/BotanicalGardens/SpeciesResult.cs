using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BotanicalGardens
{
    public class SpeciesResult : Result

    {
        private const int NUM_VALUES_TO_RETURN = 4;

        public int speciesID { get; set; }
        public int genImgResID { get; set; }
        public String genName { get; set; }
        public String sciName { get; set; }
        public String genDescription { get; set; }

        public SpeciesResult()
        {

        }
        public SpeciesResult(String genName, String sciName)
        {
            this.genName = genName;
            this.sciName = sciName;
            this.genDescription = genDescription;
            this.speciesID = speciesID;
            this.genImgResID = genImgResID;
        }
        public SpeciesResult(String genName, String sciName, String genDescription, int speciesID, int genImgResID)
        {
            this.speciesID = speciesID;
            this.genImgResID = genImgResID;
            this.genName = genName;
            this.sciName = sciName;
            this.genDescription = genDescription;
        }

        public string[] getInfo()
        {
            string[] myDetails = new string[NUM_VALUES_TO_RETURN];
            myDetails[0] = Convert.ToString(speciesID);
            myDetails[1] = genName;
            myDetails[2] = sciName;
            myDetails[3] = genDescription;
            return myDetails;
        }
        public int getImageID()
        {
            return genImgResID;
        }
    }

    public class RootObject
    {
        public Search search { get; set; }
    }

    public class Search
    {
        public List<SpeciesResult> results { get; set; }
    }
}

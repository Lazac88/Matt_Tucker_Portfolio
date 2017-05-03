using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BotanicalGardens
{
    public class CollectionResult : Result
    {
        private const int NUM_VALUES_TO_RETURN = 3;

        public int collectionID { get; set; } 
        public String collectionName { get; set; } 
        public String collectionDescription { get; set; }

        public CollectionResult()
        {

        }
        public CollectionResult(String collectionName, String collectionDescription)
        { 
            this.collectionName = collectionName;
            this.collectionDescription = collectionDescription;  
        }
        public CollectionResult(int collectionID, String collectionName, String collectionDescriptionID)
        {
            this.collectionID = collectionID;  
            this.collectionName = collectionName;
            this.collectionDescription = collectionDescription;
        }

        public string[] getInfo()
        {
            string[] myDetails = new string[NUM_VALUES_TO_RETURN];
            myDetails[0] = collectionID.ToString();
            myDetails[1] = collectionName;
            myDetails[2] = collectionDescription;
            return myDetails;
        }

        public int getImageID()
        {
            return collectionID;
        }
    }

    public class CollectionRootObject
    {
        public CollectionSearch search { get; set; }
    }

    public class CollectionSearch
    {
        public List<SpeciesResult> results { get; set; }
    }
}

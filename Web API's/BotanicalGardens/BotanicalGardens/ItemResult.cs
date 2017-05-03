using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BotanicalGardens
{
    public class ItemResult : Result
    {
        private const int NUM_VALUES_TO_RETURN = 9;

        //Properties of an Item Result
        public int itemID { get; set; }
        public double latitude { get; set; }
        public double longitude { get; set; }
        public String siteSpecificDescription { get; set; }  
        public int siteSpecificImgResID { get; set; }
        public DateTime dateCreated { get; set; }
        public DateTime dateModified { get; set; }
        public int speciesID { get; set; }
        public int collectionID { get; set; } 
        public String itemName { get; set; }

        // Empty default constructor
        public ItemResult() { }
        
        //======================================================================================================================
        // Constructor mainly used for error output
        //======================================================================================================================
        public ItemResult(String itemName, String siteSpecificDescription)
        {
            this.itemName = itemName;
            this.siteSpecificDescription = siteSpecificDescription;
        }

        //======================================================================================================================
        // Overloaded constructor for Item
        //======================================================================================================================
        public ItemResult(int itemID, double latitude, double longitude, String siteSpecificDescription, int siteSpecificImgResID,
            DateTime dateCreated, DateTime dateModified, int speciesID, int collectionID)
        {
            this.itemID = itemID;
            this.latitude = latitude;
            this.longitude = longitude;
            this.siteSpecificDescription = siteSpecificDescription;
            this.siteSpecificImgResID = siteSpecificImgResID;
            this.dateCreated = dateCreated;
            this.dateModified = dateModified;
            this.speciesID = speciesID;
            this.collectionID = collectionID;
        }

        //======================================================================================================================
        // This method creates a string array and populates each element in the array with data that has been parsed, then returns
        // the string array to be used in the output on the form
        //======================================================================================================================
        public string[] getInfo()
        {
            string[] myDetails = new string[NUM_VALUES_TO_RETURN];
            myDetails[0] = Convert.ToString(itemID);
            myDetails[1] = Convert.ToString(latitude);
            myDetails[2] = Convert.ToString(longitude);
            myDetails[3] = siteSpecificDescription;
            myDetails[4] = Convert.ToString(siteSpecificImgResID);
            myDetails[5] = Convert.ToString(dateCreated);
            myDetails[6] = Convert.ToString(dateModified);
            myDetails[7] = Convert.ToString(speciesID);
            myDetails[8] = Convert.ToString(collectionID);
            return myDetails;
        }

        //======================================================================================================================
        // This method returns the image on the kate server that corresponds with that integer eg kate.ict.op.ac.nz/images/3.jpg
        //======================================================================================================================
        public int getImageID()
        {
            return siteSpecificImgResID;
        }
    }

    public class ItemRootObject
    {
        public Search search { get; set; }
    }
    
    public class ItemSearch
    {
        public List<SpeciesResult> results { get; set; }
    }
}

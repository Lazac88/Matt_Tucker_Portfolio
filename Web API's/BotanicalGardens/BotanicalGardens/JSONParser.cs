using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BotanicalGardens
{
    public static class JSONParser
    {      
        public static List<Result> getParsedJSON(String json)
        {
            try
            {
                List<SpeciesResult> myDeserializedObjList = (List<SpeciesResult>)JsonConvert.DeserializeObject((json), typeof(List<SpeciesResult>)); 

                //create a list of results
                List<Result> resultList = new List<Result>();

                //loop over the deserialized object and add each element to resultList
                foreach(SpeciesResult s in myDeserializedObjList)
                {
                    resultList.Add(s);
                }

                return resultList;
            }
            catch (JsonException e)
            {
                //if an error occurs, return a result populated by error messages.
                Result result = new SpeciesResult("Error Error", e.Message);
                List<Result> error = new List<Result>();
                error.Add(result);
                return error;
            }
        }

        public static List<Result> getCollectionJSON(String json)
        {
            try
            {
                List<CollectionResult> deserializedObjList = (List<CollectionResult>)JsonConvert.DeserializeObject((json), typeof(List<CollectionResult>));
                List<Result> resultList = new List<Result>();
                foreach (CollectionResult c in deserializedObjList)
                {
                    resultList.Add(c);
                }

                return resultList;
            }
            catch (JsonException e)
            {
                Result result = new CollectionResult("Error Error", e.Message);
                List<Result> error = new List<Result>();
                error.Add(result);
                return error;
            }
        }

        public static List<Result> getItemJSON(String json)
        {
            try
            {
                // Nested JSON deserialized
                dynamic jsonData = JsonConvert.DeserializeObject<dynamic>(json); // May need a better function here

                List<Result> resultList = new List<Result>();
                 
                foreach (var result in jsonData)
                {  
                    //Extract all fields within SpeciesID
                    var theSpecies = result.speciesID; 

                    SpeciesResult res = new SpeciesResult();

                    res.speciesID = theSpecies.speciesID; 
                    res.genName = theSpecies.genName;
                    res.sciName = theSpecies.sciName;
                    res.genDescription = theSpecies.genDescription;
                    res.genImgResID = theSpecies.genImgResID;
                    resultList.Add(res);  
                }  

                return resultList;
            }
            catch (JsonException e)
            {
                Result result = new ItemResult("Error Error", e.Message);
                List<Result> error = new List<Result>();
                error.Add(result);
                return error;
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BotanicalGardens
{
    class AppManager
    {
        public AppManager()
        {

        }

        public String Search(String search)
        {
            return HTTPProcessor.getJSON(search);
        }

        private List<Result> getResult(String json)
        {
            return JSONParser.getParsedJSON(json);
        } 

        private List<Result> getCollectionResult(String json)
        {
            return JSONParser.getCollectionJSON(json);
        }

        private List<Result> getItemResult(String json)
        {
            return JSONParser.getItemJSON(json);
        } 

        public List<Result> collectionSearch(String userInput)
        {
            List<Result> results = new List<Result>();

            try
            {
                String json = Search(userInput);
                results = getCollectionResult(json);
            }
            catch (Exception e)
            {
                //builds a new result with the error message
                CollectionResult error = new CollectionResult("A Networking Error Has Occured", e.Message);
                results.Add(error);
            }
            //Returns as normal even with the error message 

            if (results.Count() == 0)
            {
                CollectionResult result = new CollectionResult("No Results", "No results found. Please try a different search value");
                results.Add(result);
            }
            return results;

        }

        public List<Result> collectionItemSearch(String userInput)
        {
            List<Result> results = new List<Result>();

            try
            {
                String json = Search(userInput);
                results = getItemResult(json);
            }
            catch (Exception e)
            {
                //builds a new result with the error message
                CollectionResult error = new CollectionResult("A Networking Error Has Occured", e.Message);
                results.Add(error);
            }
            //Returns as normal even with the error message 

            if (results.Count() == 0)
            {
                CollectionResult result = new CollectionResult("No Results", "No results found. Please try a different search value");
                results.Add(result);
            }
            return results;

        }
    }
}

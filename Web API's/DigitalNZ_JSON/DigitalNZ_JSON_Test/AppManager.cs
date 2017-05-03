using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DigitalNZ_JSON_Test
{
    class AppManager
    {

        public AppManager()
        {

        }

        public String Search(String search, int pages)
        {
            return  HTTPProcessor.getJSON(search,pages);
        }        

        private List<Result> getResult(String json)
        {
            return JSONParser.getParsedJSON(json);
        } 

        //Search starts here. This method accepts a search term and number of pages
        public List<Result> runSearch(String userInput, int pages)
        {
            List<Result> results = new List<Result>();  //List to hold results
            try
            {
                String json = Search(userInput,pages);      //Calls the search method above that returns a JSON string if successful
                results = getResult(json);                  //Calls the getResults method which sends the string to the JSON parser and returns a list of Result
            }
            catch (Exception e)
            {
                //builds a new result with the error message
                Result error = new Result("An Networking Error Has Occured", e.Message);
                results.Add(error);
            }
            //Returns as normal even with the error message 

            if (results.Count() == 0)
            {
                Result result = new Result("No Results", "No results found. Please try a different search value");
                results.Add(result);
            }
            return results;  
             
        }
    }
}

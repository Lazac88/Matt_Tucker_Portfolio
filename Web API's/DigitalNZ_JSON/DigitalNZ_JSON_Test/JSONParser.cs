using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace DigitalNZ_JSON_Test
{
    public static class JSONParser
    {
        public static List<Result> getParsedJSON(String jsonString)
        {
            try     //Creates a RootObject from the JSON string --RootObject is a class defined in the Result class
                    //RootObject holds an instance of the Search Class (called search) -- also defined in the Result class
                    //Search class holds a List of Results (called results)
            {
                RootObject result = JsonConvert.DeserializeObject<RootObject>(jsonString);
                return result.search.results;
            }
            catch (JsonException e)
            {
                Result result = new Result("Error Error", e.Message);
                List<Result> error = new List<Result>();
                error.Add(result);
                return error;
            }
        }
    }
}

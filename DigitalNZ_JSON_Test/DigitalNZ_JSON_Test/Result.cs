using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DigitalNZ_JSON_Test
{
    public class Result
    {
        public String title { get; set; }
        public String description { get; set; }
        public String landing_url { get; set; }

        public Result()
        {

        }

        public Result(String title, String description)
        {
            this.title = title;
            this.description = description;
            landing_url = "";
        }
    }

    public class RootObject
    {
        public Search search { get; set; }
    }

    public class Search
    {
        public List<Result> results { get; set; }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DigitalNZ_JSON_Test
{
    public static class HTTPProcessor
    { 
        public static String getJSON(String searchTerm, int pageResults)
        {
            String searchResult = "";

            //DigitalNZ uses the format http:/ /api.digitalnz.org/[version]/records.[response_format]?[request-parameters]
            //current version is v3
            //response formats can be: JSON, XML, rss
            //Main request-parameters: api_key (we have one), text
            //Example http:/ /api.digitalnz.org/v3/records.json?api_key=pzby93yyajfuPiWXMcJ_&text=kiwi
            //Create the request string
            String myURL = "http://api.digitalnz.org/v3/records.json?api_key=pzby93yyajfuPiWXMcJ_&text=";
            // Append the searchTerm to include 30 pages per result and of type image (Need to check the and/or for category)
            // Spec requires at least 30 pages per result
            myURL += searchTerm + "&per_page=" + pageResults.ToString() + "&and[category][]=Images";

            try
            {
                // Create request
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(myURL);
                request.ContentType = "text/json";
                request.Method = "GET";
                // Get response
                var response = (HttpWebResponse)request.GetResponse();

                // Error check prior to reading contents
                if (response.StatusCode == HttpStatusCode.OK)
                {
                    using (var sr = new StreamReader(response.GetResponseStream()))
                    {
                        searchResult = sr.ReadToEnd();
                        sr.Close();
                    }

                    response.Close();
                }
            }

            catch (WebException ex)
            {
                //Re throws the exception so the calling method 
                //can deal with it 
                throw;
            }

            return searchResult;
        }
    }
}
    
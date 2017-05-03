using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BotanicalGardens
{
    public static class HTTPProcessor
    {
        public static String getJSON(String searchTerm)
        {
            String searchResult = "";

            // Localhost testing
            //String myURL = "http://127.0.0.1:8000"; 

            // PythonAnywhere URL
            String myURL = "http://commsoft.pythonanywhere.com/";

            // Append search value
            myURL += searchTerm;
			
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

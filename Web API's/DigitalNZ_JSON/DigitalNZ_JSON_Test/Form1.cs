using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DigitalNZ_JSON_Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.AcceptButton = btnSearch;
            resultDataGrid.AutoSizeColumnsMode =
            DataGridViewAutoSizeColumnsMode.DisplayedCells;
            this.resultDataGrid.Columns[0].AutoSizeMode = DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.resultDataGrid.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.DisplayedCells;
            this.resultDataGrid.Columns[2].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;

            resultDataGrid.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
        }

        private void btnSearch_Click(object sender, EventArgs e)
        {
            resultDataGrid.Rows.Clear();

            // Get textField value
            String userInput = txtInput.Text;

            // Get page results value
            String pageResults = numPages.Value.ToString();
            int pages = int.Parse(pageResults);

            AppManager testClass = new AppManager();

            List<Result> myList = testClass.runSearch(userInput, pages);

            //loop over the results and add to the datagrid
            foreach(Result r in myList)
            {
                string[] rowData = { r.title, r.description, r.landing_url };
                resultDataGrid.Rows.Add(rowData);
            } 

        }

        private void resultDataGrid_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //if the user clicks in the link column
            if(e.ColumnIndex == 2)
            {
                //get the url from that particular row
                string sUrl = resultDataGrid.Rows[e.RowIndex].Cells[2].Value.ToString();

                //provides access to local and remote processes, eg urls, file paths etc.
                ProcessStartInfo sInfo = new ProcessStartInfo(sUrl);

                //open the url in internet explorer
                Process.Start(sInfo);
            }
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BotanicalGardens
{
    public partial class Commsoft : Form
    {
        private string[] collection_headers = new string[] { "Collection Id", "Collection Name", "Collection Description", "Collection Image" };
        private string[] species_headers = new string[] { "Species Id", "General Name", "Scientific Name", "Description", "Species Image" };

        private WebClient wc;
        private int rowHeight;
        private int collectionSelectedID;
        private AppManager testClass;
        private String searchQuery;
        private DataGridViewImageColumn imageColumn;
        private List<Result> collectionList;

        //Added values to specify what is being searched on
        private String imageType;
        private int imageCell;

        public Commsoft()
        {
            InitializeComponent();

            testClass = new AppManager();
            wc = new WebClient();
            searchQuery = "";
            imageType = "/plantimages/";
            rowHeight = 140;
            collectionSelectedID = 0;  
            imageCell = 4;

            // Image column settings
            imageColumn = new DataGridViewImageColumn(); 
            imageColumn.Name = "Image";
            imageColumn.HeaderText = "Image";

            // Get all collections and populate drop down
            populateCollections();

            this.AcceptButton = btnSearch;
        }
         
        private void btnSearch_Click_1(object sender, EventArgs e)
        {
            // Get user input
            String userInput = txtInput.Text.Trim();  

            if (userInput == "")
            {
                searchQuery = "/gardens/item/search/?search=";
            }
            else
            {
                // Convert first char to uppercase
                userInput = userInput.Substring(0, 1).ToUpper() + userInput.Substring(1);
                searchQuery = "/gardens/item/search/?search=" + userInput;
            } 
             
            imageType = "/plantimages/";

            List<Result> myList = testClass.collectionItemSearch(searchQuery);

            buildGrid(species_headers);
            displayResults(myList); 
    }

    // Search within a Collection
    private void btnCollectionSearch_Click(object sender, EventArgs e)
    {
        int index = collectionCombo.SelectedIndex + 1;

        String collectionSearchQuery = "/gardens/item.json/?collectionID=" + index;

        // Retrieve list of all Species Instances with the selection Collection ID
        List<Result> collectionSearchList = testClass.collectionItemSearch(collectionSearchQuery);

        buildGrid(species_headers);
        displayResults(collectionSearchList);
    }

    // On load, populate combo box with all Collections
    public void populateCollections()
    {
        searchQuery = "/gardens/collection.json/";
        collectionList = testClass.collectionSearch(searchQuery);

        String[] firstResult = collectionList[0].getInfo();
        String collectionInfo = firstResult[2];

        //loop over the results and add to the datagrid
        foreach (Result r in collectionList)
        {
            String[] data = r.getInfo();
            String item = data[1];

            collectionCombo.Items.Add(item);
        }

        collectionCombo.SelectedIndex = 0;
        labelCollection.Text = collectionInfo;
    }

    //Update current Combo Box index. Output Collection description to label
    private void collectionCombo_SelectedIndexChanged(object sender, EventArgs e)
    {
        collectionSelectedID = collectionCombo.SelectedIndex;

        String[] optionSelected = collectionList[collectionSelectedID].getInfo();

        String collectionInfo = optionSelected[2];
        labelCollection.Text = collectionInfo;
    }

    // Set up the datagrid based on search query
    public void buildGrid(string[] headers)
    {
        int size = headers.Length;
        int limit = size - 1;

        // Set datagrid properties
        resultDataGrid.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.None;
        resultDataGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.None;
        resultDataGrid.RowsDefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;
        resultDataGrid.ColumnHeadersDefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;

        // Clear all rows and columns 
        resultDataGrid.Rows.Clear();
        resultDataGrid.Columns.Clear();

        // Rebuild datagrid based on header array contents
        for (int i = 0; i < limit; i++)
        {
            resultDataGrid.Columns.Add(headers[i], headers[i]);
        }

        // Add image column of type DataGridViewImageColumn 
        resultDataGrid.Columns.Add(imageColumn);
        imageColumn.DisplayIndex = limit;

        // Set description column mode
        resultDataGrid.Columns[limit - 1].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
    }

    public void displayResults(List<Result> results)
    {
        int counter = 0;
        string urlImagePath = "";

        //loop over the results and add to the datagrid
        foreach (Result r in results)
        {
            //if theres no related images for a search term, then it doesn't exist (at this stage)
            if (r.getImageID() == 0)
            {
                urlImagePath = "http://www.ikea.com/PIAimages/0173210_PE327299_S5.JPG";
            }
            else
            {
                string imgID = Convert.ToString(r.getImageID());
                urlImagePath = "http://kate.ict.op.ac.nz/~aberhjk1" + imageType + imgID + ".jpg";
            }

            byte[] bytes = wc.DownloadData(urlImagePath);
            MemoryStream ms = new MemoryStream(bytes);
            Image img = Image.FromStream(ms);

            // Resize bitmap to fit cell
            Bitmap bitmap = new Bitmap(img, rowHeight, rowHeight);

            string[] rowData = r.getInfo();
            resultDataGrid.Rows.Add(rowData);

            // Set Image column to Bitmap
            resultDataGrid.Rows[counter].Cells[imageCell].Value = bitmap;

            // Set row height
            resultDataGrid.Rows[counter].Height = rowHeight;
            counter++;
        }
    }

    private void btnReset_Click(object sender, EventArgs e)
    {
        txtInput.Text = "";
    }
}
}

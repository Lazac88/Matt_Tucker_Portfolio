namespace DigitalNZ_JSON_Test
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.numPages = new System.Windows.Forms.NumericUpDown();
            this.resultDataGrid = new System.Windows.Forms.DataGridView();
            this.Title = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Description = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LandingUrl = new System.Windows.Forms.DataGridViewLinkColumn();
            ((System.ComponentModel.ISupportInitialize)(this.numPages)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.resultDataGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // txtInput
            // 
            this.txtInput.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtInput.Location = new System.Drawing.Point(25, 52);
            this.txtInput.Multiline = true;
            this.txtInput.Name = "txtInput";
            this.txtInput.Size = new System.Drawing.Size(1120, 32);
            this.txtInput.TabIndex = 0;
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(25, 90);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(1120, 48);
            this.btnSearch.TabIndex = 1;
            this.btnSearch.Text = "Search";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // numPages
            // 
            this.numPages.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numPages.Location = new System.Drawing.Point(1186, 52);
            this.numPages.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numPages.Name = "numPages";
            this.numPages.Size = new System.Drawing.Size(69, 32);
            this.numPages.TabIndex = 3;
            this.numPages.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
            // 
            // resultDataGrid
            // 
            this.resultDataGrid.AllowUserToAddRows = false;
            this.resultDataGrid.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.resultDataGrid.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.resultDataGrid.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.resultDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.resultDataGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Title,
            this.Description,
            this.LandingUrl});
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.resultDataGrid.DefaultCellStyle = dataGridViewCellStyle1;
            this.resultDataGrid.Location = new System.Drawing.Point(25, 160);
            this.resultDataGrid.Name = "resultDataGrid";
            this.resultDataGrid.RowHeadersVisible = false;
            this.resultDataGrid.RowHeadersWidth = 600;
            this.resultDataGrid.Size = new System.Drawing.Size(1195, 426);
            this.resultDataGrid.TabIndex = 4;
            this.resultDataGrid.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.resultDataGrid_CellContentClick);
            // 
            // Title
            // 
            this.Title.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.AllCells;
            this.Title.HeaderText = "Title";
            this.Title.Name = "Title";
            this.Title.Width = 52;
            // 
            // Description
            // 
            this.Description.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.AllCells;
            this.Description.HeaderText = "Description";
            this.Description.Name = "Description";
            this.Description.Width = 85;
            // 
            // LandingUrl
            // 
            this.LandingUrl.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.AllCells;
            this.LandingUrl.HeaderText = "Landing URL";
            this.LandingUrl.Name = "LandingUrl";
            this.LandingUrl.Width = 76;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1267, 661);
            this.Controls.Add(this.resultDataGrid);
            this.Controls.Add(this.numPages);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.txtInput);
            this.Name = "Form1";
            this.Text = "DigitalNZ";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numPages)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.resultDataGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.NumericUpDown numPages;
        private System.Windows.Forms.DataGridView resultDataGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn Title;
        private System.Windows.Forms.DataGridViewTextBoxColumn Description;
        private System.Windows.Forms.DataGridViewLinkColumn LandingUrl;
    }
}


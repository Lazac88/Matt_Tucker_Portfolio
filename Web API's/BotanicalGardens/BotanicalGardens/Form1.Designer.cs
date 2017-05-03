namespace BotanicalGardens
{
    partial class Commsoft
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            this.resultDataGrid = new System.Windows.Forms.DataGridView();
            this.btnSearch = new System.Windows.Forms.Button();
            this.collectionCombo = new System.Windows.Forms.ComboBox();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.labelCollection = new System.Windows.Forms.Label();
            this.btnCollectionSearch = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btnReset = new System.Windows.Forms.Button();
            this.lblEnter = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.resultDataGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // resultDataGrid
            // 
            this.resultDataGrid.AllowUserToAddRows = false;
            this.resultDataGrid.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.resultDataGrid.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.resultDataGrid.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.resultDataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.resultDataGrid.DefaultCellStyle = dataGridViewCellStyle2;
            this.resultDataGrid.Location = new System.Drawing.Point(12, 105);
            this.resultDataGrid.Name = "resultDataGrid";
            this.resultDataGrid.RowHeadersVisible = false;
            this.resultDataGrid.RowHeadersWidth = 600;
            this.resultDataGrid.Size = new System.Drawing.Size(1195, 461);
            this.resultDataGrid.TabIndex = 8;
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(194, 59);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(87, 30);
            this.btnSearch.TabIndex = 6;
            this.btnSearch.Text = "Search";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click_1);
            // 
            // collectionCombo
            // 
            this.collectionCombo.FormattingEnabled = true;
            this.collectionCombo.Location = new System.Drawing.Point(412, 12);
            this.collectionCombo.Name = "collectionCombo";
            this.collectionCombo.Size = new System.Drawing.Size(209, 21);
            this.collectionCombo.TabIndex = 14;
            this.collectionCombo.SelectedIndexChanged += new System.EventHandler(this.collectionCombo_SelectedIndexChanged);
            // 
            // txtInput
            // 
            this.txtInput.Location = new System.Drawing.Point(74, 16);
            this.txtInput.Name = "txtInput";
            this.txtInput.Size = new System.Drawing.Size(207, 20);
            this.txtInput.TabIndex = 15;
            // 
            // labelCollection
            // 
            this.labelCollection.AutoSize = true;
            this.labelCollection.Location = new System.Drawing.Point(409, 68);
            this.labelCollection.Name = "labelCollection";
            this.labelCollection.Size = new System.Drawing.Size(0, 13);
            this.labelCollection.TabIndex = 16;
            // 
            // btnCollectionSearch
            // 
            this.btnCollectionSearch.Location = new System.Drawing.Point(627, 10);
            this.btnCollectionSearch.Name = "btnCollectionSearch";
            this.btnCollectionSearch.Size = new System.Drawing.Size(124, 30);
            this.btnCollectionSearch.TabIndex = 17;
            this.btnCollectionSearch.Text = "Collection Search";
            this.btnCollectionSearch.UseVisualStyleBackColor = true;
            this.btnCollectionSearch.Click += new System.EventHandler(this.btnCollectionSearch_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(409, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 13);
            this.label1.TabIndex = 18;
            this.label1.Text = "Description:";
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(74, 59);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(87, 30);
            this.btnReset.TabIndex = 19;
            this.btnReset.Text = "Clear";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // lblEnter
            // 
            this.lblEnter.AutoSize = true;
            this.lblEnter.Location = new System.Drawing.Point(18, 19);
            this.lblEnter.Name = "lblEnter";
            this.lblEnter.Size = new System.Drawing.Size(50, 13);
            this.lblEnter.TabIndex = 20;
            this.lblEnter.Text = "Search:  ";
            // 
            // Commsoft
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1251, 607);
            this.Controls.Add(this.lblEnter);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnCollectionSearch);
            this.Controls.Add(this.labelCollection);
            this.Controls.Add(this.txtInput);
            this.Controls.Add(this.collectionCombo);
            this.Controls.Add(this.resultDataGrid);
            this.Controls.Add(this.btnSearch);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Commsoft";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Database Search";
            ((System.ComponentModel.ISupportInitialize)(this.resultDataGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView resultDataGrid;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.ComboBox collectionCombo;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.Label labelCollection;
        private System.Windows.Forms.Button btnCollectionSearch;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.Label lblEnter;
    }
}


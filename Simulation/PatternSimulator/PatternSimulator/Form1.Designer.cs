namespace PatternSimulator
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
            this.components = new System.ComponentModel.Container();
            this.displayPanel = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btnGo = new System.Windows.Forms.Button();
            this.txtBoxAFeed = new System.Windows.Forms.TextBox();
            this.lblAFeed = new System.Windows.Forms.Label();
            this.txtBoxBKill = new System.Windows.Forms.TextBox();
            this.lblBKill = new System.Windows.Forms.Label();
            this.grpBoxLaplacian = new System.Windows.Forms.GroupBox();
            this.rBtnPerpendicular = new System.Windows.Forms.RadioButton();
            this.rBtnConvolution = new System.Windows.Forms.RadioButton();
            this.rBtnDelta = new System.Windows.Forms.RadioButton();
            this.grpBoxColour = new System.Windows.Forms.GroupBox();
            this.rBtnLRainbow = new System.Windows.Forms.RadioButton();
            this.rBtnSRainbow = new System.Windows.Forms.RadioButton();
            this.rBtnGreyScale = new System.Windows.Forms.RadioButton();
            this.grpBoxGridSize = new System.Windows.Forms.GroupBox();
            this.rBtnSize256 = new System.Windows.Forms.RadioButton();
            this.RBtnSize64 = new System.Windows.Forms.RadioButton();
            this.rBtnSize16 = new System.Windows.Forms.RadioButton();
            this.txtBoxIterations = new System.Windows.Forms.TextBox();
            this.lblIterations = new System.Windows.Forms.Label();
            this.lblSetRange = new System.Windows.Forms.Label();
            this.txtBoxARange = new System.Windows.Forms.TextBox();
            this.txtBoxBRange = new System.Windows.Forms.TextBox();
            this.lblTo1 = new System.Windows.Forms.Label();
            this.lblTo2 = new System.Windows.Forms.Label();
            this.btnRunRange = new System.Windows.Forms.Button();
            this.grpBoxSave = new System.Windows.Forms.GroupBox();
            this.btnDontSave = new System.Windows.Forms.RadioButton();
            this.rBtnSave = new System.Windows.Forms.RadioButton();
            this.grpBoxLaplacian.SuspendLayout();
            this.grpBoxColour.SuspendLayout();
            this.grpBoxGridSize.SuspendLayout();
            this.grpBoxSave.SuspendLayout();
            this.SuspendLayout();
            // 
            // displayPanel
            // 
            this.displayPanel.Location = new System.Drawing.Point(13, 13);
            this.displayPanel.Name = "displayPanel";
            this.displayPanel.Size = new System.Drawing.Size(512, 512);
            this.displayPanel.TabIndex = 0;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 10;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // btnGo
            // 
            this.btnGo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGo.Location = new System.Drawing.Point(567, 443);
            this.btnGo.Name = "btnGo";
            this.btnGo.Size = new System.Drawing.Size(190, 82);
            this.btnGo.TabIndex = 1;
            this.btnGo.Text = "Run Single Simulation";
            this.btnGo.UseVisualStyleBackColor = true;
            this.btnGo.Click += new System.EventHandler(this.btnGo_Click);
            // 
            // txtBoxAFeed
            // 
            this.txtBoxAFeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtBoxAFeed.Location = new System.Drawing.Point(567, 40);
            this.txtBoxAFeed.Name = "txtBoxAFeed";
            this.txtBoxAFeed.Size = new System.Drawing.Size(190, 26);
            this.txtBoxAFeed.TabIndex = 2;
            // 
            // lblAFeed
            // 
            this.lblAFeed.AutoSize = true;
            this.lblAFeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAFeed.Location = new System.Drawing.Point(564, 17);
            this.lblAFeed.Name = "lblAFeed";
            this.lblAFeed.Size = new System.Drawing.Size(67, 20);
            this.lblAFeed.TabIndex = 3;
            this.lblAFeed.Text = "A Feed";
            // 
            // txtBoxBKill
            // 
            this.txtBoxBKill.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtBoxBKill.Location = new System.Drawing.Point(568, 92);
            this.txtBoxBKill.Name = "txtBoxBKill";
            this.txtBoxBKill.Size = new System.Drawing.Size(190, 26);
            this.txtBoxBKill.TabIndex = 4;
            // 
            // lblBKill
            // 
            this.lblBKill.AutoSize = true;
            this.lblBKill.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblBKill.Location = new System.Drawing.Point(564, 69);
            this.lblBKill.Name = "lblBKill";
            this.lblBKill.Size = new System.Drawing.Size(49, 20);
            this.lblBKill.TabIndex = 6;
            this.lblBKill.Text = "B Kill";
            // 
            // grpBoxLaplacian
            // 
            this.grpBoxLaplacian.Controls.Add(this.rBtnPerpendicular);
            this.grpBoxLaplacian.Controls.Add(this.rBtnConvolution);
            this.grpBoxLaplacian.Controls.Add(this.rBtnDelta);
            this.grpBoxLaplacian.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpBoxLaplacian.Location = new System.Drawing.Point(568, 186);
            this.grpBoxLaplacian.Name = "grpBoxLaplacian";
            this.grpBoxLaplacian.Size = new System.Drawing.Size(190, 117);
            this.grpBoxLaplacian.TabIndex = 7;
            this.grpBoxLaplacian.TabStop = false;
            this.grpBoxLaplacian.Text = "Laplacian Method";
            // 
            // rBtnPerpendicular
            // 
            this.rBtnPerpendicular.AutoSize = true;
            this.rBtnPerpendicular.Location = new System.Drawing.Point(7, 86);
            this.rBtnPerpendicular.Name = "rBtnPerpendicular";
            this.rBtnPerpendicular.Size = new System.Drawing.Size(137, 24);
            this.rBtnPerpendicular.TabIndex = 2;
            this.rBtnPerpendicular.Text = "Perpendicular";
            this.rBtnPerpendicular.UseVisualStyleBackColor = true;
            // 
            // rBtnConvolution
            // 
            this.rBtnConvolution.AutoSize = true;
            this.rBtnConvolution.Location = new System.Drawing.Point(7, 56);
            this.rBtnConvolution.Name = "rBtnConvolution";
            this.rBtnConvolution.Size = new System.Drawing.Size(121, 24);
            this.rBtnConvolution.TabIndex = 1;
            this.rBtnConvolution.Text = "Convolution";
            this.rBtnConvolution.UseVisualStyleBackColor = true;
            // 
            // rBtnDelta
            // 
            this.rBtnDelta.AutoSize = true;
            this.rBtnDelta.Checked = true;
            this.rBtnDelta.Location = new System.Drawing.Point(7, 26);
            this.rBtnDelta.Name = "rBtnDelta";
            this.rBtnDelta.Size = new System.Drawing.Size(128, 24);
            this.rBtnDelta.TabIndex = 0;
            this.rBtnDelta.TabStop = true;
            this.rBtnDelta.Text = "Delta Means";
            this.rBtnDelta.UseVisualStyleBackColor = true;
            // 
            // grpBoxColour
            // 
            this.grpBoxColour.Controls.Add(this.rBtnLRainbow);
            this.grpBoxColour.Controls.Add(this.rBtnSRainbow);
            this.grpBoxColour.Controls.Add(this.rBtnGreyScale);
            this.grpBoxColour.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpBoxColour.Location = new System.Drawing.Point(567, 319);
            this.grpBoxColour.Name = "grpBoxColour";
            this.grpBoxColour.Size = new System.Drawing.Size(190, 117);
            this.grpBoxColour.TabIndex = 8;
            this.grpBoxColour.TabStop = false;
            this.grpBoxColour.Text = "Colour Algorithm";
            // 
            // rBtnLRainbow
            // 
            this.rBtnLRainbow.AutoSize = true;
            this.rBtnLRainbow.Checked = true;
            this.rBtnLRainbow.Location = new System.Drawing.Point(7, 86);
            this.rBtnLRainbow.Name = "rBtnLRainbow";
            this.rBtnLRainbow.Size = new System.Drawing.Size(141, 24);
            this.rBtnLRainbow.TabIndex = 2;
            this.rBtnLRainbow.TabStop = true;
            this.rBtnLRainbow.Text = "Long Rainbow";
            this.rBtnLRainbow.UseVisualStyleBackColor = true;
            // 
            // rBtnSRainbow
            // 
            this.rBtnSRainbow.AutoSize = true;
            this.rBtnSRainbow.Location = new System.Drawing.Point(7, 56);
            this.rBtnSRainbow.Name = "rBtnSRainbow";
            this.rBtnSRainbow.Size = new System.Drawing.Size(145, 24);
            this.rBtnSRainbow.TabIndex = 1;
            this.rBtnSRainbow.Text = "Short Rainbow";
            this.rBtnSRainbow.UseVisualStyleBackColor = true;
            // 
            // rBtnGreyScale
            // 
            this.rBtnGreyScale.AutoSize = true;
            this.rBtnGreyScale.Location = new System.Drawing.Point(7, 26);
            this.rBtnGreyScale.Name = "rBtnGreyScale";
            this.rBtnGreyScale.Size = new System.Drawing.Size(116, 24);
            this.rBtnGreyScale.TabIndex = 0;
            this.rBtnGreyScale.Text = "Grey-Scale";
            this.rBtnGreyScale.UseVisualStyleBackColor = true;
            // 
            // grpBoxGridSize
            // 
            this.grpBoxGridSize.Controls.Add(this.rBtnSize256);
            this.grpBoxGridSize.Controls.Add(this.RBtnSize64);
            this.grpBoxGridSize.Controls.Add(this.rBtnSize16);
            this.grpBoxGridSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpBoxGridSize.Location = new System.Drawing.Point(811, 186);
            this.grpBoxGridSize.Name = "grpBoxGridSize";
            this.grpBoxGridSize.Size = new System.Drawing.Size(190, 117);
            this.grpBoxGridSize.TabIndex = 9;
            this.grpBoxGridSize.TabStop = false;
            this.grpBoxGridSize.Text = "Grid Size";
            // 
            // rBtnSize256
            // 
            this.rBtnSize256.AutoSize = true;
            this.rBtnSize256.Location = new System.Drawing.Point(7, 86);
            this.rBtnSize256.Name = "rBtnSize256";
            this.rBtnSize256.Size = new System.Drawing.Size(105, 24);
            this.rBtnSize256.TabIndex = 2;
            this.rBtnSize256.Text = "256 x 256";
            this.rBtnSize256.UseVisualStyleBackColor = true;
            // 
            // RBtnSize64
            // 
            this.RBtnSize64.AutoSize = true;
            this.RBtnSize64.Checked = true;
            this.RBtnSize64.Location = new System.Drawing.Point(7, 56);
            this.RBtnSize64.Name = "RBtnSize64";
            this.RBtnSize64.Size = new System.Drawing.Size(85, 24);
            this.RBtnSize64.TabIndex = 1;
            this.RBtnSize64.TabStop = true;
            this.RBtnSize64.Text = "64 x 64";
            this.RBtnSize64.UseVisualStyleBackColor = true;
            // 
            // rBtnSize16
            // 
            this.rBtnSize16.AutoSize = true;
            this.rBtnSize16.Location = new System.Drawing.Point(7, 26);
            this.rBtnSize16.Name = "rBtnSize16";
            this.rBtnSize16.Size = new System.Drawing.Size(85, 24);
            this.rBtnSize16.TabIndex = 0;
            this.rBtnSize16.Text = "16 x 16";
            this.rBtnSize16.UseVisualStyleBackColor = true;
            // 
            // txtBoxIterations
            // 
            this.txtBoxIterations.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtBoxIterations.Location = new System.Drawing.Point(568, 144);
            this.txtBoxIterations.Name = "txtBoxIterations";
            this.txtBoxIterations.Size = new System.Drawing.Size(190, 26);
            this.txtBoxIterations.TabIndex = 10;
            // 
            // lblIterations
            // 
            this.lblIterations.AutoSize = true;
            this.lblIterations.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblIterations.Location = new System.Drawing.Point(563, 121);
            this.lblIterations.Name = "lblIterations";
            this.lblIterations.Size = new System.Drawing.Size(86, 20);
            this.lblIterations.TabIndex = 11;
            this.lblIterations.Text = "Iterations";
            // 
            // lblSetRange
            // 
            this.lblSetRange.AutoSize = true;
            this.lblSetRange.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSetRange.Location = new System.Drawing.Point(856, 17);
            this.lblSetRange.Name = "lblSetRange";
            this.lblSetRange.Size = new System.Drawing.Size(95, 20);
            this.lblSetRange.TabIndex = 12;
            this.lblSetRange.Text = "Set Range";
            // 
            // txtBoxARange
            // 
            this.txtBoxARange.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtBoxARange.Location = new System.Drawing.Point(860, 40);
            this.txtBoxARange.Name = "txtBoxARange";
            this.txtBoxARange.Size = new System.Drawing.Size(190, 26);
            this.txtBoxARange.TabIndex = 13;
            // 
            // txtBoxBRange
            // 
            this.txtBoxBRange.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtBoxBRange.Location = new System.Drawing.Point(860, 92);
            this.txtBoxBRange.Name = "txtBoxBRange";
            this.txtBoxBRange.Size = new System.Drawing.Size(190, 26);
            this.txtBoxBRange.TabIndex = 14;
            // 
            // lblTo1
            // 
            this.lblTo1.AutoSize = true;
            this.lblTo1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTo1.Location = new System.Drawing.Point(791, 46);
            this.lblTo1.Name = "lblTo1";
            this.lblTo1.Size = new System.Drawing.Size(25, 20);
            this.lblTo1.TabIndex = 15;
            this.lblTo1.Text = "to";
            // 
            // lblTo2
            // 
            this.lblTo2.AutoSize = true;
            this.lblTo2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTo2.Location = new System.Drawing.Point(791, 95);
            this.lblTo2.Name = "lblTo2";
            this.lblTo2.Size = new System.Drawing.Size(25, 20);
            this.lblTo2.TabIndex = 16;
            this.lblTo2.Text = "to";
            // 
            // btnRunRange
            // 
            this.btnRunRange.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRunRange.Location = new System.Drawing.Point(811, 443);
            this.btnRunRange.Name = "btnRunRange";
            this.btnRunRange.Size = new System.Drawing.Size(190, 82);
            this.btnRunRange.TabIndex = 17;
            this.btnRunRange.Text = "Run Range Simulation";
            this.btnRunRange.UseVisualStyleBackColor = true;
            this.btnRunRange.Click += new System.EventHandler(this.btnRunRange_Click);
            // 
            // grpBoxSave
            // 
            this.grpBoxSave.Controls.Add(this.btnDontSave);
            this.grpBoxSave.Controls.Add(this.rBtnSave);
            this.grpBoxSave.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grpBoxSave.Location = new System.Drawing.Point(811, 320);
            this.grpBoxSave.Name = "grpBoxSave";
            this.grpBoxSave.Size = new System.Drawing.Size(190, 117);
            this.grpBoxSave.TabIndex = 18;
            this.grpBoxSave.TabStop = false;
            this.grpBoxSave.Text = "Save Image To Disk";
            // 
            // btnDontSave
            // 
            this.btnDontSave.AutoSize = true;
            this.btnDontSave.Checked = true;
            this.btnDontSave.Location = new System.Drawing.Point(7, 56);
            this.btnDontSave.Name = "btnDontSave";
            this.btnDontSave.Size = new System.Drawing.Size(115, 24);
            this.btnDontSave.TabIndex = 1;
            this.btnDontSave.TabStop = true;
            this.btnDontSave.Text = "Don\'t Save";
            this.btnDontSave.UseVisualStyleBackColor = true;
            // 
            // rBtnSave
            // 
            this.rBtnSave.AutoSize = true;
            this.rBtnSave.Location = new System.Drawing.Point(7, 26);
            this.rBtnSave.Name = "rBtnSave";
            this.rBtnSave.Size = new System.Drawing.Size(67, 24);
            this.rBtnSave.TabIndex = 0;
            this.rBtnSave.Text = "Save";
            this.rBtnSave.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1069, 559);
            this.Controls.Add(this.grpBoxSave);
            this.Controls.Add(this.btnRunRange);
            this.Controls.Add(this.lblTo2);
            this.Controls.Add(this.lblTo1);
            this.Controls.Add(this.txtBoxBRange);
            this.Controls.Add(this.txtBoxARange);
            this.Controls.Add(this.lblSetRange);
            this.Controls.Add(this.lblIterations);
            this.Controls.Add(this.txtBoxIterations);
            this.Controls.Add(this.grpBoxGridSize);
            this.Controls.Add(this.grpBoxColour);
            this.Controls.Add(this.grpBoxLaplacian);
            this.Controls.Add(this.lblBKill);
            this.Controls.Add(this.txtBoxBKill);
            this.Controls.Add(this.lblAFeed);
            this.Controls.Add(this.txtBoxAFeed);
            this.Controls.Add(this.btnGo);
            this.Controls.Add(this.displayPanel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grpBoxLaplacian.ResumeLayout(false);
            this.grpBoxLaplacian.PerformLayout();
            this.grpBoxColour.ResumeLayout(false);
            this.grpBoxColour.PerformLayout();
            this.grpBoxGridSize.ResumeLayout(false);
            this.grpBoxGridSize.PerformLayout();
            this.grpBoxSave.ResumeLayout(false);
            this.grpBoxSave.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel displayPanel;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button btnGo;
        private System.Windows.Forms.TextBox txtBoxAFeed;
        private System.Windows.Forms.Label lblAFeed;
        private System.Windows.Forms.TextBox txtBoxBKill;
        private System.Windows.Forms.Label lblBKill;
        private System.Windows.Forms.GroupBox grpBoxLaplacian;
        private System.Windows.Forms.RadioButton rBtnPerpendicular;
        private System.Windows.Forms.RadioButton rBtnConvolution;
        private System.Windows.Forms.RadioButton rBtnDelta;
        private System.Windows.Forms.GroupBox grpBoxColour;
        private System.Windows.Forms.RadioButton rBtnLRainbow;
        private System.Windows.Forms.RadioButton rBtnSRainbow;
        private System.Windows.Forms.RadioButton rBtnGreyScale;
        private System.Windows.Forms.GroupBox grpBoxGridSize;
        private System.Windows.Forms.RadioButton rBtnSize256;
        private System.Windows.Forms.RadioButton RBtnSize64;
        private System.Windows.Forms.RadioButton rBtnSize16;
        private System.Windows.Forms.TextBox txtBoxIterations;
        private System.Windows.Forms.Label lblIterations;
        private System.Windows.Forms.Label lblSetRange;
        private System.Windows.Forms.TextBox txtBoxARange;
        private System.Windows.Forms.TextBox txtBoxBRange;
        private System.Windows.Forms.Label lblTo1;
        private System.Windows.Forms.Label lblTo2;
        private System.Windows.Forms.Button btnRunRange;
        private System.Windows.Forms.GroupBox grpBoxSave;
        private System.Windows.Forms.RadioButton btnDontSave;
        private System.Windows.Forms.RadioButton rBtnSave;
    }
}


namespace WindowsFormsApp1
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
            this.candidatLabel = new System.Windows.Forms.Label();
            this.candidatTextBox = new System.Windows.Forms.TextBox();
            this.nrIntrebariTextBox = new System.Windows.Forms.TextBox();
            this.nrIntrebareLabel = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.intrebareLabel = new System.Windows.Forms.Label();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.punctajTextBox = new System.Windows.Forms.TextBox();
            this.punctajLabel = new System.Windows.Forms.Label();
            this.urmatoareaIntrebareButton = new System.Windows.Forms.Button();
            this.nrRaspCorecteTextBox = new System.Windows.Forms.TextBox();
            this.nrRaspCorectLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // candidatLabel
            // 
            this.candidatLabel.AutoSize = true;
            this.candidatLabel.Location = new System.Drawing.Point(63, 51);
            this.candidatLabel.Name = "candidatLabel";
            this.candidatLabel.Size = new System.Drawing.Size(49, 13);
            this.candidatLabel.TabIndex = 0;
            this.candidatLabel.Text = "Candidat";
            // 
            // candidatTextBox
            // 
            this.candidatTextBox.Enabled = false;
            this.candidatTextBox.Location = new System.Drawing.Point(115, 48);
            this.candidatTextBox.Name = "candidatTextBox";
            this.candidatTextBox.Size = new System.Drawing.Size(187, 20);
            this.candidatTextBox.TabIndex = 1;
            // 
            // nrIntrebariTextBox
            // 
            this.nrIntrebariTextBox.Enabled = false;
            this.nrIntrebariTextBox.Location = new System.Drawing.Point(433, 48);
            this.nrIntrebariTextBox.Name = "nrIntrebariTextBox";
            this.nrIntrebariTextBox.Size = new System.Drawing.Size(55, 20);
            this.nrIntrebariTextBox.TabIndex = 3;
            // 
            // nrIntrebareLabel
            // 
            this.nrIntrebareLabel.AutoSize = true;
            this.nrIntrebareLabel.Location = new System.Drawing.Point(317, 51);
            this.nrIntrebareLabel.Name = "nrIntrebareLabel";
            this.nrIntrebareLabel.Size = new System.Drawing.Size(89, 13);
            this.nrIntrebareLabel.TabIndex = 2;
            this.nrIntrebareLabel.Text = "Nr. intrebari / test";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(519, 26);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(115, 83);
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // intrebareLabel
            // 
            this.intrebareLabel.AutoSize = true;
            this.intrebareLabel.Location = new System.Drawing.Point(34, 105);
            this.intrebareLabel.Name = "intrebareLabel";
            this.intrebareLabel.Size = new System.Drawing.Size(0, 13);
            this.intrebareLabel.TabIndex = 5;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Location = new System.Drawing.Point(37, 137);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(597, 243);
            this.flowLayoutPanel1.TabIndex = 6;
            // 
            // punctajTextBox
            // 
            this.punctajTextBox.Enabled = false;
            this.punctajTextBox.Location = new System.Drawing.Point(91, 407);
            this.punctajTextBox.Name = "punctajTextBox";
            this.punctajTextBox.Size = new System.Drawing.Size(100, 20);
            this.punctajTextBox.TabIndex = 8;
            // 
            // punctajLabel
            // 
            this.punctajLabel.AutoSize = true;
            this.punctajLabel.Location = new System.Drawing.Point(39, 410);
            this.punctajLabel.Name = "punctajLabel";
            this.punctajLabel.Size = new System.Drawing.Size(43, 13);
            this.punctajLabel.TabIndex = 7;
            this.punctajLabel.Text = "Punctaj";
            // 
            // urmatoareaIntrebareButton
            // 
            this.urmatoareaIntrebareButton.Location = new System.Drawing.Point(547, 393);
            this.urmatoareaIntrebareButton.Name = "urmatoareaIntrebareButton";
            this.urmatoareaIntrebareButton.Size = new System.Drawing.Size(87, 47);
            this.urmatoareaIntrebareButton.TabIndex = 9;
            this.urmatoareaIntrebareButton.Text = "Urmatoarea intrebare";
            this.urmatoareaIntrebareButton.UseVisualStyleBackColor = true;
            // 
            // nrRaspCorecteTextBox
            // 
            this.nrRaspCorecteTextBox.Enabled = false;
            this.nrRaspCorecteTextBox.Location = new System.Drawing.Point(388, 407);
            this.nrRaspCorecteTextBox.Name = "nrRaspCorecteTextBox";
            this.nrRaspCorecteTextBox.Size = new System.Drawing.Size(100, 20);
            this.nrRaspCorecteTextBox.TabIndex = 10;
            // 
            // nrRaspCorectLabel
            // 
            this.nrRaspCorectLabel.AutoSize = true;
            this.nrRaspCorectLabel.Location = new System.Drawing.Point(259, 410);
            this.nrRaspCorectLabel.Name = "nrRaspCorectLabel";
            this.nrRaspCorectLabel.Size = new System.Drawing.Size(111, 13);
            this.nrRaspCorectLabel.TabIndex = 11;
            this.nrRaspCorectLabel.Text = "Nr. raspunsuri corecte";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(673, 450);
            this.Controls.Add(this.nrRaspCorectLabel);
            this.Controls.Add(this.nrRaspCorecteTextBox);
            this.Controls.Add(this.urmatoareaIntrebareButton);
            this.Controls.Add(this.punctajTextBox);
            this.Controls.Add(this.punctajLabel);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Controls.Add(this.intrebareLabel);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.nrIntrebariTextBox);
            this.Controls.Add(this.nrIntrebareLabel);
            this.Controls.Add(this.candidatTextBox);
            this.Controls.Add(this.candidatLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label candidatLabel;
        private System.Windows.Forms.TextBox candidatTextBox;
        private System.Windows.Forms.TextBox nrIntrebariTextBox;
        private System.Windows.Forms.Label nrIntrebareLabel;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label intrebareLabel;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.TextBox punctajTextBox;
        private System.Windows.Forms.Label punctajLabel;
        private System.Windows.Forms.Button urmatoareaIntrebareButton;
        private System.Windows.Forms.TextBox nrRaspCorecteTextBox;
        private System.Windows.Forms.Label nrRaspCorectLabel;
    }
}


namespace ex_2
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
            this.algorithmComboBox = new System.Windows.Forms.ComboBox();
            this.computeMACButton = new System.Windows.Forms.Button();
            this.verifyMACButton = new System.Windows.Forms.Button();
            this.ASCIIKeyTextBox = new System.Windows.Forms.TextBox();
            this.ASCIIPlainTextTextBox = new System.Windows.Forms.TextBox();
            this.ASCIIMACTextBox = new System.Windows.Forms.TextBox();
            this.HEXMACTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.ASCIIHashTextBox = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // algorithmComboBox
            // 
            this.algorithmComboBox.AutoCompleteCustomSource.AddRange(new string[] {
            "SHA1",
            "MD5",
            "RIPEMD",
            "SHA256",
            "SHA384",
            "SHA512"});
            this.algorithmComboBox.FormattingEnabled = true;
            this.algorithmComboBox.Items.AddRange(new object[] {
            "SHA1",
            "MD5",
            "RIPEMD",
            "SHA256",
            "SHA384",
            "SHA512"});
            this.algorithmComboBox.Location = new System.Drawing.Point(53, 81);
            this.algorithmComboBox.Name = "algorithmComboBox";
            this.algorithmComboBox.Size = new System.Drawing.Size(121, 21);
            this.algorithmComboBox.TabIndex = 0;
            // 
            // computeMACButton
            // 
            this.computeMACButton.Location = new System.Drawing.Point(53, 172);
            this.computeMACButton.Name = "computeMACButton";
            this.computeMACButton.Size = new System.Drawing.Size(131, 39);
            this.computeMACButton.TabIndex = 1;
            this.computeMACButton.Text = "Compute MAC";
            this.computeMACButton.UseVisualStyleBackColor = true;
            this.computeMACButton.Click += new System.EventHandler(this.computeMACButton_Click);
            // 
            // verifyMACButton
            // 
            this.verifyMACButton.Location = new System.Drawing.Point(53, 273);
            this.verifyMACButton.Name = "verifyMACButton";
            this.verifyMACButton.Size = new System.Drawing.Size(131, 39);
            this.verifyMACButton.TabIndex = 2;
            this.verifyMACButton.Text = "Verify MAC";
            this.verifyMACButton.UseVisualStyleBackColor = true;
            this.verifyMACButton.Click += new System.EventHandler(this.verifyMACButton_Click);
            // 
            // ASCIIKeyTextBox
            // 
            this.ASCIIKeyTextBox.Location = new System.Drawing.Point(422, 81);
            this.ASCIIKeyTextBox.Name = "ASCIIKeyTextBox";
            this.ASCIIKeyTextBox.Size = new System.Drawing.Size(334, 20);
            this.ASCIIKeyTextBox.TabIndex = 3;
            // 
            // ASCIIPlainTextTextBox
            // 
            this.ASCIIPlainTextTextBox.Location = new System.Drawing.Point(422, 172);
            this.ASCIIPlainTextTextBox.Name = "ASCIIPlainTextTextBox";
            this.ASCIIPlainTextTextBox.Size = new System.Drawing.Size(334, 20);
            this.ASCIIPlainTextTextBox.TabIndex = 4;
            // 
            // ASCIIMACTextBox
            // 
            this.ASCIIMACTextBox.Location = new System.Drawing.Point(422, 273);
            this.ASCIIMACTextBox.Name = "ASCIIMACTextBox";
            this.ASCIIMACTextBox.Size = new System.Drawing.Size(334, 20);
            this.ASCIIMACTextBox.TabIndex = 5;
            // 
            // HEXMACTextBox
            // 
            this.HEXMACTextBox.Location = new System.Drawing.Point(422, 322);
            this.HEXMACTextBox.Name = "HEXMACTextBox";
            this.HEXMACTextBox.Size = new System.Drawing.Size(334, 20);
            this.HEXMACTextBox.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(419, 48);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(363, 81);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(34, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "ASCII";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(363, 175);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "ASCII";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(363, 273);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(34, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "ASCII";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(419, 142);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Plain Text";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(419, 240);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(30, 13);
            this.label6.TabIndex = 12;
            this.label6.Text = "MAC";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(363, 322);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(29, 13);
            this.label7.TabIndex = 13;
            this.label7.Text = "HEX";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(50, 48);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(119, 13);
            this.label8.TabIndex = 14;
            this.label8.Text = "Hash / HMAC algorithm";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(363, 389);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(34, 13);
            this.label9.TabIndex = 16;
            this.label9.Text = "ASCII";
            // 
            // ASCIIHashTextBox
            // 
            this.ASCIIHashTextBox.Location = new System.Drawing.Point(422, 389);
            this.ASCIIHashTextBox.Name = "ASCIIHashTextBox";
            this.ASCIIHashTextBox.Size = new System.Drawing.Size(334, 20);
            this.ASCIIHashTextBox.TabIndex = 15;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(419, 362);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(32, 13);
            this.label10.TabIndex = 17;
            this.label10.Text = "Hash";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.ASCIIHashTextBox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.HEXMACTextBox);
            this.Controls.Add(this.ASCIIMACTextBox);
            this.Controls.Add(this.ASCIIPlainTextTextBox);
            this.Controls.Add(this.ASCIIKeyTextBox);
            this.Controls.Add(this.verifyMACButton);
            this.Controls.Add(this.computeMACButton);
            this.Controls.Add(this.algorithmComboBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox algorithmComboBox;
        private System.Windows.Forms.Button computeMACButton;
        private System.Windows.Forms.Button verifyMACButton;
        private System.Windows.Forms.TextBox ASCIIKeyTextBox;
        private System.Windows.Forms.TextBox ASCIIPlainTextTextBox;
        private System.Windows.Forms.TextBox ASCIIMACTextBox;
        private System.Windows.Forms.TextBox HEXMACTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox ASCIIHashTextBox;
        private System.Windows.Forms.Label label10;
    }
}


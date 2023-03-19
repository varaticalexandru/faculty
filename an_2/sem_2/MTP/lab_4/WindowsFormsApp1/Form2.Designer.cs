namespace WindowsFormsApp1
{
    partial class Form2
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
            this.numeTextBox = new System.Windows.Forms.TextBox();
            this.numeLabel = new System.Windows.Forms.Label();
            this.CNPTextBox = new System.Windows.Forms.TextBox();
            this.CNPLabel = new System.Windows.Forms.Label();
            this.testLabel = new System.Windows.Forms.Label();
            this.incepeTestulButton = new System.Windows.Forms.Button();
            this.testeComboBox = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // numeTextBox
            // 
            this.numeTextBox.Location = new System.Drawing.Point(132, 62);
            this.numeTextBox.Name = "numeTextBox";
            this.numeTextBox.Size = new System.Drawing.Size(187, 20);
            this.numeTextBox.TabIndex = 3;
            // 
            // numeLabel
            // 
            this.numeLabel.AutoSize = true;
            this.numeLabel.Location = new System.Drawing.Point(69, 65);
            this.numeLabel.Name = "numeLabel";
            this.numeLabel.Size = new System.Drawing.Size(35, 13);
            this.numeLabel.TabIndex = 2;
            this.numeLabel.Text = "Nume";
            // 
            // CNPTextBox
            // 
            this.CNPTextBox.Location = new System.Drawing.Point(132, 100);
            this.CNPTextBox.Name = "CNPTextBox";
            this.CNPTextBox.Size = new System.Drawing.Size(187, 20);
            this.CNPTextBox.TabIndex = 5;
            this.CNPTextBox.MouseLeave += new System.EventHandler(this.CNPTextBox_MouseLeave);
            // 
            // CNPLabel
            // 
            this.CNPLabel.AutoSize = true;
            this.CNPLabel.Location = new System.Drawing.Point(69, 103);
            this.CNPLabel.Name = "CNPLabel";
            this.CNPLabel.Size = new System.Drawing.Size(29, 13);
            this.CNPLabel.TabIndex = 4;
            this.CNPLabel.Text = "CNP";
            // 
            // testLabel
            // 
            this.testLabel.AutoSize = true;
            this.testLabel.Location = new System.Drawing.Point(69, 144);
            this.testLabel.Name = "testLabel";
            this.testLabel.Size = new System.Drawing.Size(28, 13);
            this.testLabel.TabIndex = 6;
            this.testLabel.Text = "Test";
            // 
            // incepeTestulButton
            // 
            this.incepeTestulButton.Location = new System.Drawing.Point(132, 192);
            this.incepeTestulButton.Name = "incepeTestulButton";
            this.incepeTestulButton.Size = new System.Drawing.Size(158, 58);
            this.incepeTestulButton.TabIndex = 10;
            this.incepeTestulButton.Text = "Incepe testul";
            this.incepeTestulButton.UseVisualStyleBackColor = true;
            this.incepeTestulButton.Click += new System.EventHandler(this.incepeTestulButton_Click);
            // 
            // testeComboBox
            // 
            this.testeComboBox.FormattingEnabled = true;
            this.testeComboBox.Location = new System.Drawing.Point(132, 141);
            this.testeComboBox.Name = "testeComboBox";
            this.testeComboBox.Size = new System.Drawing.Size(187, 21);
            this.testeComboBox.TabIndex = 11;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(400, 296);
            this.Controls.Add(this.testeComboBox);
            this.Controls.Add(this.incepeTestulButton);
            this.Controls.Add(this.testLabel);
            this.Controls.Add(this.CNPTextBox);
            this.Controls.Add(this.CNPLabel);
            this.Controls.Add(this.numeTextBox);
            this.Controls.Add(this.numeLabel);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox numeTextBox;
        private System.Windows.Forms.Label numeLabel;
        private System.Windows.Forms.TextBox CNPTextBox;
        private System.Windows.Forms.Label CNPLabel;
        private System.Windows.Forms.Label testLabel;
        private System.Windows.Forms.Button incepeTestulButton;
        private System.Windows.Forms.ComboBox testeComboBox;
    }
}
namespace test_sapt_3
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
            this.ASCIIPlainTextTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.DESCipherTextTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.MD5HashTextBox = new System.Windows.Forms.TextBox();
            this.startEncryptionChainButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ASCIIPlainTextTextBox
            // 
            this.ASCIIPlainTextTextBox.Location = new System.Drawing.Point(290, 100);
            this.ASCIIPlainTextTextBox.Name = "ASCIIPlainTextTextBox";
            this.ASCIIPlainTextTextBox.Size = new System.Drawing.Size(415, 20);
            this.ASCIIPlainTextTextBox.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(186, 103);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(79, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "ASCII plain text";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(190, 308);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "DES ciphertext";
            // 
            // DESCipherTextTextBox
            // 
            this.DESCipherTextTextBox.Location = new System.Drawing.Point(294, 305);
            this.DESCipherTextTextBox.Name = "DESCipherTextTextBox";
            this.DESCipherTextTextBox.Size = new System.Drawing.Size(415, 20);
            this.DESCipherTextTextBox.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(190, 358);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(56, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "MD5 hash";
            // 
            // MD5HashTextBox
            // 
            this.MD5HashTextBox.Location = new System.Drawing.Point(294, 358);
            this.MD5HashTextBox.Name = "MD5HashTextBox";
            this.MD5HashTextBox.Size = new System.Drawing.Size(415, 20);
            this.MD5HashTextBox.TabIndex = 4;
            // 
            // startEncryptionChainButton
            // 
            this.startEncryptionChainButton.Location = new System.Drawing.Point(342, 186);
            this.startEncryptionChainButton.Name = "startEncryptionChainButton";
            this.startEncryptionChainButton.Size = new System.Drawing.Size(229, 60);
            this.startEncryptionChainButton.TabIndex = 6;
            this.startEncryptionChainButton.Text = "Start Encryption Chain";
            this.startEncryptionChainButton.UseVisualStyleBackColor = true;
            this.startEncryptionChainButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.startEncryptionChainButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.MD5HashTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.DESCipherTextTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ASCIIPlainTextTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox ASCIIPlainTextTextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox DESCipherTextTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox MD5HashTextBox;
        private System.Windows.Forms.Button startEncryptionChainButton;
    }
}


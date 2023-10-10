namespace WindowsFormsApplication20
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
            this.keyTextBox = new System.Windows.Forms.TextBox();
            this.ivTextBox = new System.Windows.Forms.TextBox();
            this.plainASCIITextBox = new System.Windows.Forms.TextBox();
            this.plainHEXTextBox = new System.Windows.Forms.TextBox();
            this.cipherASCIITextBox = new System.Windows.Forms.TextBox();
            this.cipherHEXTextBox = new System.Windows.Forms.TextBox();
            this.keyLabel = new System.Windows.Forms.Label();
            this.ivLabel = new System.Windows.Forms.Label();
            this.plainTextLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.cipherComboBox = new System.Windows.Forms.ComboBox();
            this.generateKeyAndIvbutton = new System.Windows.Forms.Button();
            this.encryptButton = new System.Windows.Forms.Button();
            this.decryptButton = new System.Windows.Forms.Button();
            this.getEncryptTimeButton = new System.Windows.Forms.Button();
            this.getDecryptTimeButton = new System.Windows.Forms.Button();
            this.encryptionTimeLabel = new System.Windows.Forms.Label();
            this.decryptionTimeLabel = new System.Windows.Forms.Label();
            this.encryptionTimeTextBox = new System.Windows.Forms.TextBox();
            this.decryptionTimeTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // keyTextBox
            // 
            this.keyTextBox.Location = new System.Drawing.Point(427, 55);
            this.keyTextBox.Name = "keyTextBox";
            this.keyTextBox.Size = new System.Drawing.Size(203, 20);
            this.keyTextBox.TabIndex = 0;
            // 
            // ivTextBox
            // 
            this.ivTextBox.Location = new System.Drawing.Point(427, 92);
            this.ivTextBox.Name = "ivTextBox";
            this.ivTextBox.Size = new System.Drawing.Size(203, 20);
            this.ivTextBox.TabIndex = 1;
            // 
            // plainASCIITextBox
            // 
            this.plainASCIITextBox.Location = new System.Drawing.Point(427, 163);
            this.plainASCIITextBox.Name = "plainASCIITextBox";
            this.plainASCIITextBox.Size = new System.Drawing.Size(203, 20);
            this.plainASCIITextBox.TabIndex = 2;
            // 
            // plainHEXTextBox
            // 
            this.plainHEXTextBox.Location = new System.Drawing.Point(427, 205);
            this.plainHEXTextBox.Name = "plainHEXTextBox";
            this.plainHEXTextBox.Size = new System.Drawing.Size(203, 20);
            this.plainHEXTextBox.TabIndex = 3;
            // 
            // cipherASCIITextBox
            // 
            this.cipherASCIITextBox.Location = new System.Drawing.Point(427, 281);
            this.cipherASCIITextBox.Name = "cipherASCIITextBox";
            this.cipherASCIITextBox.Size = new System.Drawing.Size(203, 20);
            this.cipherASCIITextBox.TabIndex = 4;
            // 
            // cipherHEXTextBox
            // 
            this.cipherHEXTextBox.Location = new System.Drawing.Point(427, 320);
            this.cipherHEXTextBox.Name = "cipherHEXTextBox";
            this.cipherHEXTextBox.Size = new System.Drawing.Size(203, 20);
            this.cipherHEXTextBox.TabIndex = 5;
            // 
            // keyLabel
            // 
            this.keyLabel.AutoSize = true;
            this.keyLabel.Location = new System.Drawing.Point(396, 55);
            this.keyLabel.Name = "keyLabel";
            this.keyLabel.Size = new System.Drawing.Size(25, 13);
            this.keyLabel.TabIndex = 6;
            this.keyLabel.Text = "Key";
            // 
            // ivLabel
            // 
            this.ivLabel.AutoSize = true;
            this.ivLabel.Location = new System.Drawing.Point(396, 92);
            this.ivLabel.Name = "ivLabel";
            this.ivLabel.Size = new System.Drawing.Size(17, 13);
            this.ivLabel.TabIndex = 7;
            this.ivLabel.Text = "IV";
            // 
            // plainTextLabel
            // 
            this.plainTextLabel.AutoSize = true;
            this.plainTextLabel.Location = new System.Drawing.Point(424, 137);
            this.plainTextLabel.Name = "plainTextLabel";
            this.plainTextLabel.Size = new System.Drawing.Size(54, 13);
            this.plainTextLabel.TabIndex = 8;
            this.plainTextLabel.Text = "Plain Text";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(387, 163);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(34, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "ASCII";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(387, 205);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 10;
            this.label2.Text = "HEX";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(424, 255);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "Cipher Text";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(387, 323);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "HEX";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(387, 281);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(34, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "ASCII";
            // 
            // cipherComboBox
            // 
            this.cipherComboBox.FormattingEnabled = true;
            this.cipherComboBox.Items.AddRange(new object[] {
            "DES",
            "3DES",
            "Rijndael"});
            this.cipherComboBox.Location = new System.Drawing.Point(27, 52);
            this.cipherComboBox.Name = "cipherComboBox";
            this.cipherComboBox.Size = new System.Drawing.Size(121, 21);
            this.cipherComboBox.TabIndex = 14;
            // 
            // generateKeyAndIvbutton
            // 
            this.generateKeyAndIvbutton.Location = new System.Drawing.Point(27, 92);
            this.generateKeyAndIvbutton.Name = "generateKeyAndIvbutton";
            this.generateKeyAndIvbutton.Size = new System.Drawing.Size(121, 23);
            this.generateKeyAndIvbutton.TabIndex = 15;
            this.generateKeyAndIvbutton.Text = "Generate Key and IV";
            this.generateKeyAndIvbutton.UseVisualStyleBackColor = true;
            this.generateKeyAndIvbutton.Click += new System.EventHandler(this.generateKeyAndIVbutton_Click);
            // 
            // encryptButton
            // 
            this.encryptButton.Location = new System.Drawing.Point(27, 163);
            this.encryptButton.Name = "encryptButton";
            this.encryptButton.Size = new System.Drawing.Size(121, 23);
            this.encryptButton.TabIndex = 16;
            this.encryptButton.Text = "Encrypt";
            this.encryptButton.UseVisualStyleBackColor = true;
            this.encryptButton.Click += new System.EventHandler(this.encryptButton_Click);
            // 
            // decryptButton
            // 
            this.decryptButton.Location = new System.Drawing.Point(27, 271);
            this.decryptButton.Name = "decryptButton";
            this.decryptButton.Size = new System.Drawing.Size(121, 23);
            this.decryptButton.TabIndex = 17;
            this.decryptButton.Text = "Decrypt";
            this.decryptButton.UseVisualStyleBackColor = true;
            this.decryptButton.Click += new System.EventHandler(this.decryptButton_Click);
            // 
            // getEncryptTimeButton
            // 
            this.getEncryptTimeButton.Location = new System.Drawing.Point(27, 372);
            this.getEncryptTimeButton.Name = "getEncryptTimeButton";
            this.getEncryptTimeButton.Size = new System.Drawing.Size(121, 23);
            this.getEncryptTimeButton.TabIndex = 18;
            this.getEncryptTimeButton.Text = "Get Encrypt Time";
            this.getEncryptTimeButton.UseVisualStyleBackColor = true;
            this.getEncryptTimeButton.Click += new System.EventHandler(this.getEncryptTimeButton_Click);
            // 
            // getDecryptTimeButton
            // 
            this.getDecryptTimeButton.Location = new System.Drawing.Point(27, 415);
            this.getDecryptTimeButton.Name = "getDecryptTimeButton";
            this.getDecryptTimeButton.Size = new System.Drawing.Size(121, 23);
            this.getDecryptTimeButton.TabIndex = 19;
            this.getDecryptTimeButton.Text = "Get Decrypt Time";
            this.getDecryptTimeButton.UseVisualStyleBackColor = true;
            this.getDecryptTimeButton.Click += new System.EventHandler(this.getDecryptTimeButton_Click);
            // 
            // encryptionTimeLabel
            // 
            this.encryptionTimeLabel.AutoSize = true;
            this.encryptionTimeLabel.Location = new System.Drawing.Point(387, 382);
            this.encryptionTimeLabel.Name = "encryptionTimeLabel";
            this.encryptionTimeLabel.Size = new System.Drawing.Size(141, 13);
            this.encryptionTimeLabel.TabIndex = 20;
            this.encryptionTimeLabel.Text = "Time/message at encryption";
            // 
            // decryptionTimeLabel
            // 
            this.decryptionTimeLabel.AutoSize = true;
            this.decryptionTimeLabel.Location = new System.Drawing.Point(387, 420);
            this.decryptionTimeLabel.Name = "decryptionTimeLabel";
            this.decryptionTimeLabel.Size = new System.Drawing.Size(141, 13);
            this.decryptionTimeLabel.TabIndex = 21;
            this.decryptionTimeLabel.Text = "Time/message at decryption";
            // 
            // encryptionTimeTextBox
            // 
            this.encryptionTimeTextBox.Location = new System.Drawing.Point(556, 379);
            this.encryptionTimeTextBox.Name = "encryptionTimeTextBox";
            this.encryptionTimeTextBox.Size = new System.Drawing.Size(74, 20);
            this.encryptionTimeTextBox.TabIndex = 22;
            // 
            // decryptionTimeTextBox
            // 
            this.decryptionTimeTextBox.Location = new System.Drawing.Point(556, 417);
            this.decryptionTimeTextBox.Name = "decryptionTimeTextBox";
            this.decryptionTimeTextBox.Size = new System.Drawing.Size(74, 20);
            this.decryptionTimeTextBox.TabIndex = 23;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(680, 513);
            this.Controls.Add(this.decryptionTimeTextBox);
            this.Controls.Add(this.encryptionTimeTextBox);
            this.Controls.Add(this.decryptionTimeLabel);
            this.Controls.Add(this.encryptionTimeLabel);
            this.Controls.Add(this.getDecryptTimeButton);
            this.Controls.Add(this.getEncryptTimeButton);
            this.Controls.Add(this.decryptButton);
            this.Controls.Add(this.encryptButton);
            this.Controls.Add(this.generateKeyAndIvbutton);
            this.Controls.Add(this.cipherComboBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.plainTextLabel);
            this.Controls.Add(this.ivLabel);
            this.Controls.Add(this.keyLabel);
            this.Controls.Add(this.cipherHEXTextBox);
            this.Controls.Add(this.cipherASCIITextBox);
            this.Controls.Add(this.plainHEXTextBox);
            this.Controls.Add(this.plainASCIITextBox);
            this.Controls.Add(this.ivTextBox);
            this.Controls.Add(this.keyTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox keyTextBox;
        private System.Windows.Forms.TextBox ivTextBox;
        private System.Windows.Forms.TextBox plainASCIITextBox;
        private System.Windows.Forms.TextBox plainHEXTextBox;
        private System.Windows.Forms.TextBox cipherASCIITextBox;
        private System.Windows.Forms.TextBox cipherHEXTextBox;
        private System.Windows.Forms.Label keyLabel;
        private System.Windows.Forms.Label ivLabel;
        private System.Windows.Forms.Label plainTextLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox cipherComboBox;
        private System.Windows.Forms.Button generateKeyAndIvbutton;
        private System.Windows.Forms.Button encryptButton;
        private System.Windows.Forms.Button decryptButton;
        private System.Windows.Forms.Button getEncryptTimeButton;
        private System.Windows.Forms.Button getDecryptTimeButton;
        private System.Windows.Forms.Label encryptionTimeLabel;
        private System.Windows.Forms.Label decryptionTimeLabel;
        private System.Windows.Forms.TextBox encryptionTimeTextBox;
        private System.Windows.Forms.TextBox decryptionTimeTextBox;
    }
}


using System.Windows.Forms;

namespace ex_7
{
    partial class JucatorNou
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
            this.detaliiJucatorGroupBox = new System.Windows.Forms.GroupBox();
            this.CNPTextBox = new System.Windows.Forms.TextBox();
            this.numeTextBox = new System.Windows.Forms.TextBox();
            this.CNPLabel = new System.Windows.Forms.Label();
            this.postLabel = new System.Windows.Forms.Label();
            this.numeLabel = new System.Windows.Forms.Label();
            this.adaugaJucatorButton = new System.Windows.Forms.Button();
            this.postComboBox = new System.Windows.Forms.ComboBox();
            this.echipaLabel = new System.Windows.Forms.Label();
            this.echipaComboBox = new System.Windows.Forms.ComboBox();
            this.detaliiJucatorGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // detaliiJucatorGroupBox
            // 
            this.detaliiJucatorGroupBox.Controls.Add(this.echipaComboBox);
            this.detaliiJucatorGroupBox.Controls.Add(this.echipaLabel);
            this.detaliiJucatorGroupBox.Controls.Add(this.postComboBox);
            this.detaliiJucatorGroupBox.Controls.Add(this.CNPTextBox);
            this.detaliiJucatorGroupBox.Controls.Add(this.numeTextBox);
            this.detaliiJucatorGroupBox.Controls.Add(this.CNPLabel);
            this.detaliiJucatorGroupBox.Controls.Add(this.postLabel);
            this.detaliiJucatorGroupBox.Controls.Add(this.numeLabel);
            this.detaliiJucatorGroupBox.Location = new System.Drawing.Point(48, 25);
            this.detaliiJucatorGroupBox.Name = "detaliiJucatorGroupBox";
            this.detaliiJucatorGroupBox.Size = new System.Drawing.Size(387, 216);
            this.detaliiJucatorGroupBox.TabIndex = 5;
            this.detaliiJucatorGroupBox.TabStop = false;
            this.detaliiJucatorGroupBox.Text = "Detalii jucator";
            // 
            // CNPTextBox
            // 
            this.CNPTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CNPTextBox.Location = new System.Drawing.Point(146, 146);
            this.CNPTextBox.Name = "CNPTextBox";
            this.CNPTextBox.Size = new System.Drawing.Size(195, 23);
            this.CNPTextBox.TabIndex = 13;
            // 
            // numeTextBox
            // 
            this.numeTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numeTextBox.Location = new System.Drawing.Point(146, 76);
            this.numeTextBox.Name = "numeTextBox";
            this.numeTextBox.Size = new System.Drawing.Size(195, 23);
            this.numeTextBox.TabIndex = 11;
            // 
            // CNPLabel
            // 
            this.CNPLabel.AutoSize = true;
            this.CNPLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CNPLabel.Location = new System.Drawing.Point(48, 146);
            this.CNPLabel.Name = "CNPLabel";
            this.CNPLabel.Size = new System.Drawing.Size(36, 17);
            this.CNPLabel.TabIndex = 8;
            this.CNPLabel.Text = "CNP";
            // 
            // postLabel
            // 
            this.postLabel.AutoSize = true;
            this.postLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.postLabel.Location = new System.Drawing.Point(48, 109);
            this.postLabel.Name = "postLabel";
            this.postLabel.Size = new System.Drawing.Size(36, 17);
            this.postLabel.TabIndex = 7;
            this.postLabel.Text = "Post";
            // 
            // numeLabel
            // 
            this.numeLabel.AutoSize = true;
            this.numeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numeLabel.Location = new System.Drawing.Point(48, 76);
            this.numeLabel.Name = "numeLabel";
            this.numeLabel.Size = new System.Drawing.Size(45, 17);
            this.numeLabel.TabIndex = 6;
            this.numeLabel.Text = "Nume";
            // 
            // adaugaJucatorButton
            // 
            this.adaugaJucatorButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaJucatorButton.Location = new System.Drawing.Point(176, 264);
            this.adaugaJucatorButton.Name = "adaugaJucatorButton";
            this.adaugaJucatorButton.Size = new System.Drawing.Size(117, 26);
            this.adaugaJucatorButton.TabIndex = 6;
            this.adaugaJucatorButton.Text = "Adauga";
            this.adaugaJucatorButton.UseVisualStyleBackColor = true;
            this.adaugaJucatorButton.Click += new System.EventHandler(this.adaugaJucatorButton_Click);
            // 
            // postComboBox
            // 
            this.postComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.postComboBox.FormattingEnabled = true;
            this.postComboBox.Items.AddRange(new object[] {
            "Portar",
            "Fundas",
            "Mijlocas",
            "Atacant"});
            this.postComboBox.Location = new System.Drawing.Point(146, 109);
            this.postComboBox.Name = "postComboBox";
            this.postComboBox.Size = new System.Drawing.Size(195, 24);
            this.postComboBox.TabIndex = 14;
            // 
            // echipaLabel
            // 
            this.echipaLabel.AutoSize = true;
            this.echipaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.echipaLabel.Location = new System.Drawing.Point(48, 41);
            this.echipaLabel.Name = "echipaLabel";
            this.echipaLabel.Size = new System.Drawing.Size(51, 17);
            this.echipaLabel.TabIndex = 15;
            this.echipaLabel.Text = "Echipa";
            // 
            // echipaComboBox
            // 
            this.echipaComboBox.Enabled = false;
            this.echipaComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.echipaComboBox.FormattingEnabled = true;
            this.echipaComboBox.Location = new System.Drawing.Point(146, 38);
            this.echipaComboBox.Name = "echipaComboBox";
            this.echipaComboBox.Size = new System.Drawing.Size(195, 24);
            this.echipaComboBox.TabIndex = 16;
            // 
            // JucatorNou
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(482, 317);
            this.Controls.Add(this.adaugaJucatorButton);
            this.Controls.Add(this.detaliiJucatorGroupBox);
            this.Name = "JucatorNou";
            this.Text = "Jucator nou";
            this.Load += new System.EventHandler(this.JucatorNou_Load);
            this.detaliiJucatorGroupBox.ResumeLayout(false);
            this.detaliiJucatorGroupBox.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox detaliiJucatorGroupBox;
        private System.Windows.Forms.TextBox CNPTextBox;
        private System.Windows.Forms.TextBox numeTextBox;
        private System.Windows.Forms.Label CNPLabel;
        private System.Windows.Forms.Label postLabel;
        private System.Windows.Forms.Label numeLabel;
        private System.Windows.Forms.Button adaugaJucatorButton;
        private System.Windows.Forms.ComboBox postComboBox;
        private System.Windows.Forms.Label echipaLabel;
        private System.Windows.Forms.ComboBox echipaComboBox;
    }
}
namespace WindowsFormsApp1
{
    partial class Radiografie
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
            this.adaugaConsultatieButton = new System.Windows.Forms.Button();
            this.comentariiLabel = new System.Windows.Forms.Label();
            this.imagineTextBox = new System.Windows.Forms.TextBox();
            this.imagineLabel = new System.Windows.Forms.Label();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.dataLabel = new System.Windows.Forms.Label();
            this.CNPTextBox = new System.Windows.Forms.TextBox();
            this.CNPLabel = new System.Windows.Forms.Label();
            this.consultatieNouaLabel = new System.Windows.Forms.Label();
            this.selectButton = new System.Windows.Forms.Button();
            this.comentariiRichTextBox = new System.Windows.Forms.RichTextBox();
            this.diagnosticTextBox = new System.Windows.Forms.TextBox();
            this.diagnosticLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // adaugaConsultatieButton
            // 
            this.adaugaConsultatieButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.adaugaConsultatieButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaConsultatieButton.Location = new System.Drawing.Point(224, 468);
            this.adaugaConsultatieButton.Name = "adaugaConsultatieButton";
            this.adaugaConsultatieButton.Size = new System.Drawing.Size(190, 35);
            this.adaugaConsultatieButton.TabIndex = 47;
            this.adaugaConsultatieButton.Text = "Adauga consultatie";
            this.adaugaConsultatieButton.UseVisualStyleBackColor = false;
            this.adaugaConsultatieButton.Click += new System.EventHandler(this.adaugaConsultatieButton_Click);
            // 
            // comentariiLabel
            // 
            this.comentariiLabel.AutoSize = true;
            this.comentariiLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comentariiLabel.Location = new System.Drawing.Point(76, 292);
            this.comentariiLabel.Name = "comentariiLabel";
            this.comentariiLabel.Size = new System.Drawing.Size(80, 18);
            this.comentariiLabel.TabIndex = 45;
            this.comentariiLabel.Text = "Comentarii";
            // 
            // imagineTextBox
            // 
            this.imagineTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.imagineTextBox.Location = new System.Drawing.Point(262, 195);
            this.imagineTextBox.Name = "imagineTextBox";
            this.imagineTextBox.Size = new System.Drawing.Size(186, 24);
            this.imagineTextBox.TabIndex = 44;
            // 
            // imagineLabel
            // 
            this.imagineLabel.AutoSize = true;
            this.imagineLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.imagineLabel.Location = new System.Drawing.Point(76, 198);
            this.imagineLabel.Name = "imagineLabel";
            this.imagineLabel.Size = new System.Drawing.Size(59, 18);
            this.imagineLabel.TabIndex = 43;
            this.imagineLabel.Text = "Imagine";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePicker1.Location = new System.Drawing.Point(262, 140);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(186, 24);
            this.dateTimePicker1.TabIndex = 42;
            // 
            // dataLabel
            // 
            this.dataLabel.AutoSize = true;
            this.dataLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dataLabel.Location = new System.Drawing.Point(76, 143);
            this.dataLabel.Name = "dataLabel";
            this.dataLabel.Size = new System.Drawing.Size(39, 18);
            this.dataLabel.TabIndex = 41;
            this.dataLabel.Text = "Data";
            // 
            // CNPTextBox
            // 
            this.CNPTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CNPTextBox.Location = new System.Drawing.Point(262, 84);
            this.CNPTextBox.Name = "CNPTextBox";
            this.CNPTextBox.Size = new System.Drawing.Size(186, 24);
            this.CNPTextBox.TabIndex = 40;
            // 
            // CNPLabel
            // 
            this.CNPLabel.AutoSize = true;
            this.CNPLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CNPLabel.Location = new System.Drawing.Point(76, 87);
            this.CNPLabel.Name = "CNPLabel";
            this.CNPLabel.Size = new System.Drawing.Size(91, 18);
            this.CNPLabel.TabIndex = 39;
            this.CNPLabel.Text = "CNP pacient";
            // 
            // consultatieNouaLabel
            // 
            this.consultatieNouaLabel.AutoSize = true;
            this.consultatieNouaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.consultatieNouaLabel.Location = new System.Drawing.Point(232, 27);
            this.consultatieNouaLabel.Name = "consultatieNouaLabel";
            this.consultatieNouaLabel.Size = new System.Drawing.Size(169, 24);
            this.consultatieNouaLabel.TabIndex = 38;
            this.consultatieNouaLabel.Text = "Radiografie noua";
            // 
            // selectButton
            // 
            this.selectButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.selectButton.Location = new System.Drawing.Point(463, 193);
            this.selectButton.Name = "selectButton";
            this.selectButton.Size = new System.Drawing.Size(75, 26);
            this.selectButton.TabIndex = 48;
            this.selectButton.Text = "select";
            this.selectButton.UseVisualStyleBackColor = true;
            this.selectButton.Click += new System.EventHandler(this.selectButton_Click);
            // 
            // comentariiRichTextBox
            // 
            this.comentariiRichTextBox.Location = new System.Drawing.Point(262, 293);
            this.comentariiRichTextBox.Name = "comentariiRichTextBox";
            this.comentariiRichTextBox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.ForcedVertical;
            this.comentariiRichTextBox.Size = new System.Drawing.Size(276, 125);
            this.comentariiRichTextBox.TabIndex = 49;
            this.comentariiRichTextBox.Text = "";
            // 
            // diagnosticTextBox
            // 
            this.diagnosticTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.diagnosticTextBox.Location = new System.Drawing.Point(262, 239);
            this.diagnosticTextBox.Name = "diagnosticTextBox";
            this.diagnosticTextBox.Size = new System.Drawing.Size(186, 24);
            this.diagnosticTextBox.TabIndex = 51;
            // 
            // diagnosticLabel
            // 
            this.diagnosticLabel.AutoSize = true;
            this.diagnosticLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.diagnosticLabel.Location = new System.Drawing.Point(76, 242);
            this.diagnosticLabel.Name = "diagnosticLabel";
            this.diagnosticLabel.Size = new System.Drawing.Size(78, 18);
            this.diagnosticLabel.TabIndex = 50;
            this.diagnosticLabel.Text = "Diagnostic";
            // 
            // Radiografie
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(611, 546);
            this.Controls.Add(this.diagnosticTextBox);
            this.Controls.Add(this.diagnosticLabel);
            this.Controls.Add(this.comentariiRichTextBox);
            this.Controls.Add(this.selectButton);
            this.Controls.Add(this.adaugaConsultatieButton);
            this.Controls.Add(this.comentariiLabel);
            this.Controls.Add(this.imagineTextBox);
            this.Controls.Add(this.imagineLabel);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.dataLabel);
            this.Controls.Add(this.CNPTextBox);
            this.Controls.Add(this.CNPLabel);
            this.Controls.Add(this.consultatieNouaLabel);
            this.Name = "Radiografie";
            this.Text = "Radiografie";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button adaugaConsultatieButton;
        private System.Windows.Forms.Label comentariiLabel;
        private System.Windows.Forms.TextBox imagineTextBox;
        private System.Windows.Forms.Label imagineLabel;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label dataLabel;
        private System.Windows.Forms.TextBox CNPTextBox;
        private System.Windows.Forms.Label CNPLabel;
        private System.Windows.Forms.Label consultatieNouaLabel;
        private System.Windows.Forms.Button selectButton;
        private System.Windows.Forms.RichTextBox comentariiRichTextBox;
        private System.Windows.Forms.TextBox diagnosticTextBox;
        private System.Windows.Forms.Label diagnosticLabel;
    }
}
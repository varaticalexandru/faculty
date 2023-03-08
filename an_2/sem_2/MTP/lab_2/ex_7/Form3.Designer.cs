namespace ex_7
{
    partial class EchipaNoua
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
            this.echipaLabel = new System.Windows.Forms.Label();
            this.adaugaEchipaButton = new System.Windows.Forms.Button();
            this.adaugaTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // echipaLabel
            // 
            this.echipaLabel.AutoSize = true;
            this.echipaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.echipaLabel.Location = new System.Drawing.Point(43, 37);
            this.echipaLabel.Name = "echipaLabel";
            this.echipaLabel.Size = new System.Drawing.Size(51, 17);
            this.echipaLabel.TabIndex = 2;
            this.echipaLabel.Text = "Echipa";
            // 
            // adaugaEchipaButton
            // 
            this.adaugaEchipaButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaEchipaButton.Location = new System.Drawing.Point(118, 80);
            this.adaugaEchipaButton.Name = "adaugaEchipaButton";
            this.adaugaEchipaButton.Size = new System.Drawing.Size(117, 26);
            this.adaugaEchipaButton.TabIndex = 7;
            this.adaugaEchipaButton.Text = "Adauga";
            this.adaugaEchipaButton.UseVisualStyleBackColor = true;
            this.adaugaEchipaButton.Click += new System.EventHandler(this.adaugaEchipaButton_Click);
            // 
            // adaugaTextBox
            // 
            this.adaugaTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaTextBox.Location = new System.Drawing.Point(118, 36);
            this.adaugaTextBox.Name = "adaugaTextBox";
            this.adaugaTextBox.Size = new System.Drawing.Size(207, 23);
            this.adaugaTextBox.TabIndex = 8;
            // 
            // EchipaNoua
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(350, 132);
            this.Controls.Add(this.adaugaTextBox);
            this.Controls.Add(this.adaugaEchipaButton);
            this.Controls.Add(this.echipaLabel);
            this.Name = "EchipaNoua";
            this.Text = "Echipa noua";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label echipaLabel;
        private System.Windows.Forms.Button adaugaEchipaButton;
        private System.Windows.Forms.TextBox adaugaTextBox;
    }
}
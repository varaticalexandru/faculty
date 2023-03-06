namespace WindowsFormsApp1
{
    partial class Form3
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
            this.parolaTextBox = new System.Windows.Forms.TextBox();
            this.parolaLabel = new System.Windows.Forms.Label();
            this.utilizatorLabel = new System.Windows.Forms.Label();
            this.inregistrareLabel = new System.Windows.Forms.Label();
            this.utilizatorTextBox = new System.Windows.Forms.TextBox();
            this.salveazaButton = new System.Windows.Forms.Button();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // parolaTextBox
            // 
            this.parolaTextBox.Location = new System.Drawing.Point(170, 163);
            this.parolaTextBox.Name = "parolaTextBox";
            this.parolaTextBox.Size = new System.Drawing.Size(228, 20);
            this.parolaTextBox.TabIndex = 9;
            // 
            // parolaLabel
            // 
            this.parolaLabel.AutoSize = true;
            this.parolaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.parolaLabel.Location = new System.Drawing.Point(66, 164);
            this.parolaLabel.Name = "parolaLabel";
            this.parolaLabel.Size = new System.Drawing.Size(49, 17);
            this.parolaLabel.TabIndex = 7;
            this.parolaLabel.Text = "Parola";
            // 
            // utilizatorLabel
            // 
            this.utilizatorLabel.AutoSize = true;
            this.utilizatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.utilizatorLabel.Location = new System.Drawing.Point(52, 112);
            this.utilizatorLabel.Name = "utilizatorLabel";
            this.utilizatorLabel.Size = new System.Drawing.Size(63, 17);
            this.utilizatorLabel.TabIndex = 6;
            this.utilizatorLabel.Text = "Utilizator";
            // 
            // inregistrareLabel
            // 
            this.inregistrareLabel.AutoSize = true;
            this.inregistrareLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inregistrareLabel.Location = new System.Drawing.Point(166, 35);
            this.inregistrareLabel.Name = "inregistrareLabel";
            this.inregistrareLabel.Size = new System.Drawing.Size(115, 24);
            this.inregistrareLabel.TabIndex = 5;
            this.inregistrareLabel.Text = "Inregistrare";
            // 
            // utilizatorTextBox
            // 
            this.utilizatorTextBox.Location = new System.Drawing.Point(170, 112);
            this.utilizatorTextBox.Name = "utilizatorTextBox";
            this.utilizatorTextBox.Size = new System.Drawing.Size(228, 20);
            this.utilizatorTextBox.TabIndex = 10;
            // 
            // salveazaButton
            // 
            this.salveazaButton.BackColor = System.Drawing.Color.PaleGreen;
            this.salveazaButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.salveazaButton.Location = new System.Drawing.Point(170, 236);
            this.salveazaButton.Name = "salveazaButton";
            this.salveazaButton.Size = new System.Drawing.Size(107, 38);
            this.salveazaButton.TabIndex = 11;
            this.salveazaButton.Text = "Salveaza";
            this.salveazaButton.UseVisualStyleBackColor = false;
            this.salveazaButton.Click += new System.EventHandler(this.salveazaButton_Click);
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(90, 325);
            this.progressBar.Maximum = 20;
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(290, 23);
            this.progressBar.TabIndex = 12;
            // 
            // timer
            // 
            this.timer.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(458, 442);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.salveazaButton);
            this.Controls.Add(this.utilizatorTextBox);
            this.Controls.Add(this.parolaTextBox);
            this.Controls.Add(this.parolaLabel);
            this.Controls.Add(this.utilizatorLabel);
            this.Controls.Add(this.inregistrareLabel);
            this.Name = "Form3";
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.Form3_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox parolaTextBox;
        private System.Windows.Forms.Label parolaLabel;
        private System.Windows.Forms.Label utilizatorLabel;
        private System.Windows.Forms.Label inregistrareLabel;
        private System.Windows.Forms.TextBox utilizatorTextBox;
        private System.Windows.Forms.Button salveazaButton;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Timer timer;
    }
}
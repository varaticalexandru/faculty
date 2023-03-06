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
            this.loginLabel = new System.Windows.Forms.Label();
            this.utilizatorLabel = new System.Windows.Forms.Label();
            this.parolaLabel = new System.Windows.Forms.Label();
            this.utilizatorComboBox = new System.Windows.Forms.ComboBox();
            this.parolaTextBox = new System.Windows.Forms.TextBox();
            this.autentificarebutton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.inregistrareButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // loginLabel
            // 
            this.loginLabel.AutoSize = true;
            this.loginLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.loginLabel.Location = new System.Drawing.Point(197, 37);
            this.loginLabel.Name = "loginLabel";
            this.loginLabel.Size = new System.Drawing.Size(62, 24);
            this.loginLabel.TabIndex = 0;
            this.loginLabel.Text = "Login";
            // 
            // utilizatorLabel
            // 
            this.utilizatorLabel.AutoSize = true;
            this.utilizatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.utilizatorLabel.Location = new System.Drawing.Point(54, 115);
            this.utilizatorLabel.Name = "utilizatorLabel";
            this.utilizatorLabel.Size = new System.Drawing.Size(63, 17);
            this.utilizatorLabel.TabIndex = 1;
            this.utilizatorLabel.Text = "Utilizator";
            // 
            // parolaLabel
            // 
            this.parolaLabel.AutoSize = true;
            this.parolaLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.parolaLabel.Location = new System.Drawing.Point(68, 167);
            this.parolaLabel.Name = "parolaLabel";
            this.parolaLabel.Size = new System.Drawing.Size(49, 17);
            this.parolaLabel.TabIndex = 2;
            this.parolaLabel.Text = "Parola";
            // 
            // utilizatorComboBox
            // 
            this.utilizatorComboBox.FormattingEnabled = true;
            this.utilizatorComboBox.Location = new System.Drawing.Point(172, 114);
            this.utilizatorComboBox.Name = "utilizatorComboBox";
            this.utilizatorComboBox.Size = new System.Drawing.Size(228, 21);
            this.utilizatorComboBox.TabIndex = 3;
            // 
            // parolaTextBox
            // 
            this.parolaTextBox.Location = new System.Drawing.Point(172, 166);
            this.parolaTextBox.Name = "parolaTextBox";
            this.parolaTextBox.Size = new System.Drawing.Size(228, 20);
            this.parolaTextBox.TabIndex = 4;
            // 
            // autentificarebutton
            // 
            this.autentificarebutton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.autentificarebutton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.autentificarebutton.Location = new System.Drawing.Point(46, 251);
            this.autentificarebutton.Name = "autentificarebutton";
            this.autentificarebutton.Size = new System.Drawing.Size(107, 38);
            this.autentificarebutton.TabIndex = 5;
            this.autentificarebutton.Text = "Autentificare";
            this.autentificarebutton.UseVisualStyleBackColor = false;
            this.autentificarebutton.Click += new System.EventHandler(this.autentificarebutton_Click);
            // 
            // cancelButton
            // 
            this.cancelButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.cancelButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cancelButton.Location = new System.Drawing.Point(188, 251);
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.Size = new System.Drawing.Size(107, 38);
            this.cancelButton.TabIndex = 6;
            this.cancelButton.Text = "Cancel";
            this.cancelButton.UseVisualStyleBackColor = false;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // inregistrareButton
            // 
            this.inregistrareButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.inregistrareButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inregistrareButton.Location = new System.Drawing.Point(335, 251);
            this.inregistrareButton.Name = "inregistrareButton";
            this.inregistrareButton.Size = new System.Drawing.Size(107, 38);
            this.inregistrareButton.TabIndex = 7;
            this.inregistrareButton.Text = "Inregistrare";
            this.inregistrareButton.UseVisualStyleBackColor = false;
            this.inregistrareButton.Click += new System.EventHandler(this.inregistrareButton_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(481, 359);
            this.Controls.Add(this.inregistrareButton);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.autentificarebutton);
            this.Controls.Add(this.parolaTextBox);
            this.Controls.Add(this.utilizatorComboBox);
            this.Controls.Add(this.parolaLabel);
            this.Controls.Add(this.utilizatorLabel);
            this.Controls.Add(this.loginLabel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form2";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label loginLabel;
        private System.Windows.Forms.Label utilizatorLabel;
        private System.Windows.Forms.Label parolaLabel;
        private System.Windows.Forms.ComboBox utilizatorComboBox;
        private System.Windows.Forms.TextBox parolaTextBox;
        private System.Windows.Forms.Button autentificarebutton;
        private System.Windows.Forms.Button cancelButton;
        private System.Windows.Forms.Button inregistrareButton;
    }
}
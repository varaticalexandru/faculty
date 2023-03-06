namespace ex_6
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
            this.MLabel = new System.Windows.Forms.Label();
            this.NLabel = new System.Windows.Forms.Label();
            this.MTextBox = new System.Windows.Forms.TextBox();
            this.NTextBox = new System.Windows.Forms.TextBox();
            this.generareButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // MLabel
            // 
            this.MLabel.AutoSize = true;
            this.MLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MLabel.Location = new System.Drawing.Point(36, 37);
            this.MLabel.Name = "MLabel";
            this.MLabel.Size = new System.Drawing.Size(22, 18);
            this.MLabel.TabIndex = 0;
            this.MLabel.Text = "m";
            // 
            // NLabel
            // 
            this.NLabel.AutoSize = true;
            this.NLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NLabel.Location = new System.Drawing.Point(36, 73);
            this.NLabel.Name = "NLabel";
            this.NLabel.Size = new System.Drawing.Size(17, 18);
            this.NLabel.TabIndex = 1;
            this.NLabel.Text = "n";
            // 
            // MTextBox
            // 
            this.MTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MTextBox.Location = new System.Drawing.Point(113, 34);
            this.MTextBox.Name = "MTextBox";
            this.MTextBox.Size = new System.Drawing.Size(71, 24);
            this.MTextBox.TabIndex = 2;
            // 
            // NTextBox
            // 
            this.NTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.NTextBox.Location = new System.Drawing.Point(113, 73);
            this.NTextBox.Name = "NTextBox";
            this.NTextBox.Size = new System.Drawing.Size(71, 24);
            this.NTextBox.TabIndex = 3;
            // 
            // generareButton
            // 
            this.generareButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.generareButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.generareButton.Location = new System.Drawing.Point(39, 125);
            this.generareButton.Name = "generareButton";
            this.generareButton.Size = new System.Drawing.Size(145, 49);
            this.generareButton.TabIndex = 4;
            this.generareButton.Text = "Generare";
            this.generareButton.UseVisualStyleBackColor = false;
            this.generareButton.Click += new System.EventHandler(this.generareButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.generareButton);
            this.Controls.Add(this.NTextBox);
            this.Controls.Add(this.MTextBox);
            this.Controls.Add(this.NLabel);
            this.Controls.Add(this.MLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label MLabel;
        private System.Windows.Forms.Label NLabel;
        private System.Windows.Forms.TextBox MTextBox;
        private System.Windows.Forms.TextBox NTextBox;
        private System.Windows.Forms.Button generareButton;
    }
}


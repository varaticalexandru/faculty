namespace ex_5
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
            this.numeLabel = new System.Windows.Forms.Label();
            this.numeLabelTextBox = new System.Windows.Forms.TextBox();
            this.XTextBox = new System.Windows.Forms.TextBox();
            this.YTextBox = new System.Windows.Forms.TextBox();
            this.pozitieLabel = new System.Windows.Forms.Label();
            this.generareButton = new System.Windows.Forms.Button();
            this.XLabel = new System.Windows.Forms.Label();
            this.YLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // numeLabel
            // 
            this.numeLabel.AutoSize = true;
            this.numeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numeLabel.Location = new System.Drawing.Point(60, 51);
            this.numeLabel.Name = "numeLabel";
            this.numeLabel.Size = new System.Drawing.Size(153, 18);
            this.numeLabel.TabIndex = 0;
            this.numeLabel.Text = "Nume label generat";
            // 
            // numeLabelTextBox
            // 
            this.numeLabelTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.numeLabelTextBox.Location = new System.Drawing.Point(31, 91);
            this.numeLabelTextBox.Name = "numeLabelTextBox";
            this.numeLabelTextBox.Size = new System.Drawing.Size(207, 24);
            this.numeLabelTextBox.TabIndex = 1;
            // 
            // XTextBox
            // 
            this.XTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.XTextBox.Location = new System.Drawing.Point(52, 231);
            this.XTextBox.Name = "XTextBox";
            this.XTextBox.Size = new System.Drawing.Size(186, 24);
            this.XTextBox.TabIndex = 2;
            // 
            // YTextBox
            // 
            this.YTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.YTextBox.Location = new System.Drawing.Point(52, 299);
            this.YTextBox.Name = "YTextBox";
            this.YTextBox.Size = new System.Drawing.Size(186, 24);
            this.YTextBox.TabIndex = 3;
            // 
            // pozitieLabel
            // 
            this.pozitieLabel.AutoSize = true;
            this.pozitieLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pozitieLabel.Location = new System.Drawing.Point(60, 181);
            this.pozitieLabel.Name = "pozitieLabel";
            this.pozitieLabel.Size = new System.Drawing.Size(161, 18);
            this.pozitieLabel.TabIndex = 4;
            this.pozitieLabel.Text = "Pozitie label generat";
            // 
            // generareButton
            // 
            this.generareButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.generareButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.generareButton.Location = new System.Drawing.Point(30, 362);
            this.generareButton.Name = "generareButton";
            this.generareButton.Size = new System.Drawing.Size(208, 54);
            this.generareButton.TabIndex = 5;
            this.generareButton.Text = "Generare Label";
            this.generareButton.UseVisualStyleBackColor = false;
            this.generareButton.Click += new System.EventHandler(this.generareButton_Click);
            // 
            // XLabel
            // 
            this.XLabel.AutoSize = true;
            this.XLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.XLabel.Location = new System.Drawing.Point(27, 234);
            this.XLabel.Name = "XLabel";
            this.XLabel.Size = new System.Drawing.Size(19, 18);
            this.XLabel.TabIndex = 6;
            this.XLabel.Text = "X";
            // 
            // YLabel
            // 
            this.YLabel.AutoSize = true;
            this.YLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.YLabel.Location = new System.Drawing.Point(27, 302);
            this.YLabel.Name = "YLabel";
            this.YLabel.Size = new System.Drawing.Size(18, 18);
            this.YLabel.TabIndex = 7;
            this.YLabel.Text = "Y";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.YLabel);
            this.Controls.Add(this.XLabel);
            this.Controls.Add(this.generareButton);
            this.Controls.Add(this.pozitieLabel);
            this.Controls.Add(this.YTextBox);
            this.Controls.Add(this.XTextBox);
            this.Controls.Add(this.numeLabelTextBox);
            this.Controls.Add(this.numeLabel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label numeLabel;
        private System.Windows.Forms.TextBox numeLabelTextBox;
        private System.Windows.Forms.TextBox XTextBox;
        private System.Windows.Forms.TextBox YTextBox;
        private System.Windows.Forms.Label pozitieLabel;
        private System.Windows.Forms.Button generareButton;
        private System.Windows.Forms.Label XLabel;
        private System.Windows.Forms.Label YLabel;
    }
}


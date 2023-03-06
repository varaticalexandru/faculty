namespace WindowsFormsApp1
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
            this.claseLabel = new System.Windows.Forms.Label();
            this.claseComboBox = new System.Windows.Forms.ComboBox();
            this.eleviFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.dateListBox = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // claseLabel
            // 
            this.claseLabel.AutoSize = true;
            this.claseLabel.Location = new System.Drawing.Point(63, 51);
            this.claseLabel.Name = "claseLabel";
            this.claseLabel.Size = new System.Drawing.Size(84, 13);
            this.claseLabel.TabIndex = 0;
            this.claseLabel.Text = "Clase din scoala";
            // 
            // claseComboBox
            // 
            this.claseComboBox.FormattingEnabled = true;
            this.claseComboBox.Location = new System.Drawing.Point(171, 48);
            this.claseComboBox.Name = "claseComboBox";
            this.claseComboBox.Size = new System.Drawing.Size(67, 21);
            this.claseComboBox.TabIndex = 1;
            this.claseComboBox.SelectedIndexChanged += new System.EventHandler(this.claseComboBox_SelectedIndexChanged);
            // 
            // eleviFlowLayoutPanel
            // 
            this.eleviFlowLayoutPanel.Location = new System.Drawing.Point(38, 99);
            this.eleviFlowLayoutPanel.Name = "eleviFlowLayoutPanel";
            this.eleviFlowLayoutPanel.Size = new System.Drawing.Size(252, 289);
            this.eleviFlowLayoutPanel.TabIndex = 3;
            // 
            // dateListBox
            // 
            this.dateListBox.FormattingEnabled = true;
            this.dateListBox.Location = new System.Drawing.Point(337, 98);
            this.dateListBox.Name = "dateListBox";
            this.dateListBox.Size = new System.Drawing.Size(285, 290);
            this.dateListBox.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(670, 446);
            this.Controls.Add(this.dateListBox);
            this.Controls.Add(this.eleviFlowLayoutPanel);
            this.Controls.Add(this.claseComboBox);
            this.Controls.Add(this.claseLabel);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label claseLabel;
        private System.Windows.Forms.ComboBox claseComboBox;
        private System.Windows.Forms.FlowLayoutPanel eleviFlowLayoutPanel;
        private System.Windows.Forms.ListBox dateListBox;
    }
}


namespace ex_4
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
            this.controlsFlowLayoutPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.controlDoritComboBox = new System.Windows.Forms.ComboBox();
            this.controlDoritLabel = new System.Windows.Forms.Label();
            this.generateButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // controlsFlowLayoutPanel
            // 
            this.controlsFlowLayoutPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.controlsFlowLayoutPanel.Location = new System.Drawing.Point(269, 24);
            this.controlsFlowLayoutPanel.Name = "controlsFlowLayoutPanel";
            this.controlsFlowLayoutPanel.Size = new System.Drawing.Size(505, 404);
            this.controlsFlowLayoutPanel.TabIndex = 0;
            // 
            // controlDoritComboBox
            // 
            this.controlDoritComboBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.controlDoritComboBox.FormattingEnabled = true;
            this.controlDoritComboBox.Items.AddRange(new object[] {
            "Button",
            "Text Box",
            "Radio Button",
            "List Box",
            "Label",
            "Check Box",
            "Group Box"});
            this.controlDoritComboBox.Location = new System.Drawing.Point(35, 183);
            this.controlDoritComboBox.Name = "controlDoritComboBox";
            this.controlDoritComboBox.Size = new System.Drawing.Size(188, 26);
            this.controlDoritComboBox.TabIndex = 1;
            this.controlDoritComboBox.SelectedIndexChanged += new System.EventHandler(this.controlDoritComboBox_SelectedIndexChanged);
            // 
            // controlDoritLabel
            // 
            this.controlDoritLabel.AutoSize = true;
            this.controlDoritLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.controlDoritLabel.Location = new System.Drawing.Point(74, 145);
            this.controlDoritLabel.Name = "controlDoritLabel";
            this.controlDoritLabel.Size = new System.Drawing.Size(111, 18);
            this.controlDoritLabel.TabIndex = 2;
            this.controlDoritLabel.Text = "Tip control dorit";
            // 
            // generateButton
            // 
            this.generateButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.generateButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.generateButton.Location = new System.Drawing.Point(22, 227);
            this.generateButton.Name = "generateButton";
            this.generateButton.Size = new System.Drawing.Size(216, 67);
            this.generateButton.TabIndex = 3;
            this.generateButton.Text = "Generare Control";
            this.generateButton.UseVisualStyleBackColor = false;
            this.generateButton.Click += new System.EventHandler(this.generateButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.generateButton);
            this.Controls.Add(this.controlDoritLabel);
            this.Controls.Add(this.controlDoritComboBox);
            this.Controls.Add(this.controlsFlowLayoutPanel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel controlsFlowLayoutPanel;
        private System.Windows.Forms.ComboBox controlDoritComboBox;
        private System.Windows.Forms.Label controlDoritLabel;
        private System.Windows.Forms.Button generateButton;
    }
}


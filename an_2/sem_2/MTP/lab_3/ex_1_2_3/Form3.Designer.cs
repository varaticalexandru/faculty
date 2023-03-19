namespace ex_1
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
            this.citireXML = new System.Windows.Forms.Button();
            this.citireJSON = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // citireXML
            // 
            this.citireXML.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.citireXML.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.citireXML.Location = new System.Drawing.Point(37, 297);
            this.citireXML.Name = "citireXML";
            this.citireXML.Size = new System.Drawing.Size(122, 71);
            this.citireXML.TabIndex = 11;
            this.citireXML.Text = "Citire XML";
            this.citireXML.UseVisualStyleBackColor = false;
            this.citireXML.Click += new System.EventHandler(this.citireXML_Click);
            // 
            // citireJSON
            // 
            this.citireJSON.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.citireJSON.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.citireJSON.Location = new System.Drawing.Point(197, 297);
            this.citireJSON.Name = "citireJSON";
            this.citireJSON.Size = new System.Drawing.Size(122, 71);
            this.citireJSON.TabIndex = 12;
            this.citireJSON.Text = "Citire JSON";
            this.citireJSON.UseVisualStyleBackColor = false;
            this.citireJSON.Click += new System.EventHandler(this.citireJSON_Click);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(353, 394);
            this.Controls.Add(this.citireJSON);
            this.Controls.Add(this.citireXML);
            this.Name = "Form3";
            this.Text = "Form3";
            this.Load += new System.EventHandler(this.Form3_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button citireXML;
        private System.Windows.Forms.Button citireJSON;
    }
}
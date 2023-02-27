namespace WindowsFormsApp3
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
            this.salariuBrutLabel = new System.Windows.Forms.Label();
            this.salariuBrutTextBox = new System.Windows.Forms.TextBox();
            this.calculeazaButton = new System.Windows.Forms.Button();
            this.angajatLabel = new System.Windows.Forms.Label();
            this.cfsLabel = new System.Windows.Forms.Label();
            this.casLabel = new System.Windows.Forms.Label();
            this.cassLabel = new System.Windows.Forms.Label();
            this.impozitAngajatLabel = new System.Windows.Forms.Label();
            this.angajatorLabel = new System.Windows.Forms.Label();
            this.casAngajatorLabel = new System.Windows.Forms.Label();
            this.cfsAngajatorLabel = new System.Windows.Forms.Label();
            this.cfciAngajatorLabel = new System.Windows.Forms.Label();
            this.cfgpcsAngajatorLabel = new System.Windows.Forms.Label();
            this.cassAngajatorLabel = new System.Windows.Forms.Label();
            this.cfambpAngajatorLabel = new System.Windows.Forms.Label();
            this.cfsTextBox = new System.Windows.Forms.TextBox();
            this.casTextBox = new System.Windows.Forms.TextBox();
            this.cassTextBox = new System.Windows.Forms.TextBox();
            this.casAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.cfsAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.cfciAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.cfgpcsAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.cassAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.cfambpAngajatorTextBox = new System.Windows.Forms.TextBox();
            this.impozitTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // salariuBrutLabel
            // 
            this.salariuBrutLabel.AutoSize = true;
            this.salariuBrutLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.salariuBrutLabel.Location = new System.Drawing.Point(33, 45);
            this.salariuBrutLabel.Name = "salariuBrutLabel";
            this.salariuBrutLabel.Size = new System.Drawing.Size(84, 13);
            this.salariuBrutLabel.TabIndex = 0;
            this.salariuBrutLabel.Text = "Salariu BRUT";
            // 
            // salariuBrutTextBox
            // 
            this.salariuBrutTextBox.Location = new System.Drawing.Point(144, 42);
            this.salariuBrutTextBox.Name = "salariuBrutTextBox";
            this.salariuBrutTextBox.Size = new System.Drawing.Size(205, 20);
            this.salariuBrutTextBox.TabIndex = 1;
            // 
            // calculeazaButton
            // 
            this.calculeazaButton.Location = new System.Drawing.Point(383, 39);
            this.calculeazaButton.Name = "calculeazaButton";
            this.calculeazaButton.Size = new System.Drawing.Size(114, 23);
            this.calculeazaButton.TabIndex = 2;
            this.calculeazaButton.Text = "Calculeaza";
            this.calculeazaButton.UseVisualStyleBackColor = true;
            this.calculeazaButton.Click += new System.EventHandler(this.calculeazaButton_Click);
            // 
            // angajatLabel
            // 
            this.angajatLabel.AutoSize = true;
            this.angajatLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.angajatLabel.Location = new System.Drawing.Point(33, 96);
            this.angajatLabel.Name = "angajatLabel";
            this.angajatLabel.Size = new System.Drawing.Size(63, 13);
            this.angajatLabel.TabIndex = 3;
            this.angajatLabel.Text = "ANGAJAT";
            // 
            // cfsLabel
            // 
            this.cfsLabel.AutoSize = true;
            this.cfsLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cfsLabel.Location = new System.Drawing.Point(33, 124);
            this.cfsLabel.Name = "cfsLabel";
            this.cfsLabel.Size = new System.Drawing.Size(179, 13);
            this.cfsLabel.TabIndex = 4;
            this.cfsLabel.Text = "Contributia la Fondul de Somaj (CFS)";
            // 
            // casLabel
            // 
            this.casLabel.AutoSize = true;
            this.casLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.casLabel.Location = new System.Drawing.Point(33, 152);
            this.casLabel.Name = "casLabel";
            this.casLabel.Size = new System.Drawing.Size(187, 13);
            this.casLabel.TabIndex = 5;
            this.casLabel.Text = "Contributia la Asigurarile Sociale (CAS)";
            // 
            // cassLabel
            // 
            this.cassLabel.AutoSize = true;
            this.cassLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cassLabel.Location = new System.Drawing.Point(33, 180);
            this.cassLabel.Name = "cassLabel";
            this.cassLabel.Size = new System.Drawing.Size(255, 13);
            this.cassLabel.TabIndex = 6;
            this.cassLabel.Text = "Contributia la Asigurarile Sociale de Sanatate (CASS)";
            // 
            // impozitAngajatLabel
            // 
            this.impozitAngajatLabel.AutoSize = true;
            this.impozitAngajatLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.impozitAngajatLabel.Location = new System.Drawing.Point(33, 207);
            this.impozitAngajatLabel.Name = "impozitAngajatLabel";
            this.impozitAngajatLabel.Size = new System.Drawing.Size(81, 13);
            this.impozitAngajatLabel.TabIndex = 7;
            this.impozitAngajatLabel.Text = "Impozit pe venit";
            // 
            // angajatorLabel
            // 
            this.angajatorLabel.AutoSize = true;
            this.angajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.angajatorLabel.Location = new System.Drawing.Point(33, 258);
            this.angajatorLabel.Name = "angajatorLabel";
            this.angajatorLabel.Size = new System.Drawing.Size(81, 13);
            this.angajatorLabel.TabIndex = 8;
            this.angajatorLabel.Text = "ANGAJATOR";
            // 
            // casAngajatorLabel
            // 
            this.casAngajatorLabel.AutoSize = true;
            this.casAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.casAngajatorLabel.Location = new System.Drawing.Point(33, 288);
            this.casAngajatorLabel.Name = "casAngajatorLabel";
            this.casAngajatorLabel.Size = new System.Drawing.Size(157, 13);
            this.casAngajatorLabel.TabIndex = 9;
            this.casAngajatorLabel.Text = "Contributia la Asigurarile Sociale";
            // 
            // cfsAngajatorLabel
            // 
            this.cfsAngajatorLabel.AutoSize = true;
            this.cfsAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cfsAngajatorLabel.Location = new System.Drawing.Point(33, 318);
            this.cfsAngajatorLabel.Name = "cfsAngajatorLabel";
            this.cfsAngajatorLabel.Size = new System.Drawing.Size(150, 13);
            this.cfsAngajatorLabel.TabIndex = 10;
            this.cfsAngajatorLabel.Text = "Contributia la Fondul de Somaj";
            // 
            // cfciAngajatorLabel
            // 
            this.cfciAngajatorLabel.AutoSize = true;
            this.cfciAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cfciAngajatorLabel.Location = new System.Drawing.Point(33, 349);
            this.cfciAngajatorLabel.Name = "cfciAngajatorLabel";
            this.cfciAngajatorLabel.Size = new System.Drawing.Size(230, 13);
            this.cfciAngajatorLabel.TabIndex = 11;
            this.cfciAngajatorLabel.Text = "Contributia la Fondul de Concedii si Indemnizatii";
            // 
            // cfgpcsAngajatorLabel
            // 
            this.cfgpcsAngajatorLabel.AutoSize = true;
            this.cfgpcsAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cfgpcsAngajatorLabel.Location = new System.Drawing.Point(33, 378);
            this.cfgpcsAngajatorLabel.Name = "cfgpcsAngajatorLabel";
            this.cfgpcsAngajatorLabel.Size = new System.Drawing.Size(298, 13);
            this.cfgpcsAngajatorLabel.TabIndex = 12;
            this.cfgpcsAngajatorLabel.Text = "Contributia la Fondul de Garantare al Platii Creantelor Salariale";
            // 
            // cassAngajatorLabel
            // 
            this.cassAngajatorLabel.AutoSize = true;
            this.cassAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cassAngajatorLabel.Location = new System.Drawing.Point(33, 408);
            this.cassAngajatorLabel.Name = "cassAngajatorLabel";
            this.cassAngajatorLabel.Size = new System.Drawing.Size(218, 13);
            this.cassAngajatorLabel.TabIndex = 13;
            this.cassAngajatorLabel.Text = "Contributia la Asigurarile Sociale de Sanatate";
            // 
            // cfambpAngajatorLabel
            // 
            this.cfambpAngajatorLabel.AutoSize = true;
            this.cfambpAngajatorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cfambpAngajatorLabel.Location = new System.Drawing.Point(33, 441);
            this.cfambpAngajatorLabel.Name = "cfambpAngajatorLabel";
            this.cfambpAngajatorLabel.Size = new System.Drawing.Size(314, 13);
            this.cfambpAngajatorLabel.TabIndex = 14;
            this.cfambpAngajatorLabel.Text = "Contributia la Fondul de Accidente de Munca si Boli Prrofesionale";
            // 
            // cfsTextBox
            // 
            this.cfsTextBox.Location = new System.Drawing.Point(421, 117);
            this.cfsTextBox.Name = "cfsTextBox";
            this.cfsTextBox.Size = new System.Drawing.Size(99, 20);
            this.cfsTextBox.TabIndex = 15;
            // 
            // casTextBox
            // 
            this.casTextBox.Location = new System.Drawing.Point(421, 149);
            this.casTextBox.Name = "casTextBox";
            this.casTextBox.Size = new System.Drawing.Size(99, 20);
            this.casTextBox.TabIndex = 16;
            // 
            // cassTextBox
            // 
            this.cassTextBox.Location = new System.Drawing.Point(421, 177);
            this.cassTextBox.Name = "cassTextBox";
            this.cassTextBox.Size = new System.Drawing.Size(99, 20);
            this.cassTextBox.TabIndex = 17;
            // 
            // casAngajatorTextBox
            // 
            this.casAngajatorTextBox.Location = new System.Drawing.Point(421, 281);
            this.casAngajatorTextBox.Name = "casAngajatorTextBox";
            this.casAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.casAngajatorTextBox.TabIndex = 18;
            // 
            // cfsAngajatorTextBox
            // 
            this.cfsAngajatorTextBox.Location = new System.Drawing.Point(421, 315);
            this.cfsAngajatorTextBox.Name = "cfsAngajatorTextBox";
            this.cfsAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.cfsAngajatorTextBox.TabIndex = 19;
            // 
            // cfciAngajatorTextBox
            // 
            this.cfciAngajatorTextBox.Location = new System.Drawing.Point(421, 346);
            this.cfciAngajatorTextBox.Name = "cfciAngajatorTextBox";
            this.cfciAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.cfciAngajatorTextBox.TabIndex = 20;
            // 
            // cfgpcsAngajatorTextBox
            // 
            this.cfgpcsAngajatorTextBox.Location = new System.Drawing.Point(421, 375);
            this.cfgpcsAngajatorTextBox.Name = "cfgpcsAngajatorTextBox";
            this.cfgpcsAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.cfgpcsAngajatorTextBox.TabIndex = 21;
            // 
            // cassAngajatorTextBox
            // 
            this.cassAngajatorTextBox.Location = new System.Drawing.Point(421, 405);
            this.cassAngajatorTextBox.Name = "cassAngajatorTextBox";
            this.cassAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.cassAngajatorTextBox.TabIndex = 22;
            // 
            // cfambpAngajatorTextBox
            // 
            this.cfambpAngajatorTextBox.Location = new System.Drawing.Point(421, 438);
            this.cfambpAngajatorTextBox.Name = "cfambpAngajatorTextBox";
            this.cfambpAngajatorTextBox.Size = new System.Drawing.Size(99, 20);
            this.cfambpAngajatorTextBox.TabIndex = 23;
            // 
            // impozitTextBox
            // 
            this.impozitTextBox.Location = new System.Drawing.Point(421, 207);
            this.impozitTextBox.Name = "impozitTextBox";
            this.impozitTextBox.Size = new System.Drawing.Size(99, 20);
            this.impozitTextBox.TabIndex = 24;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 522);
            this.Controls.Add(this.impozitTextBox);
            this.Controls.Add(this.cfambpAngajatorTextBox);
            this.Controls.Add(this.cassAngajatorTextBox);
            this.Controls.Add(this.cfgpcsAngajatorTextBox);
            this.Controls.Add(this.cfciAngajatorTextBox);
            this.Controls.Add(this.cfsAngajatorTextBox);
            this.Controls.Add(this.casAngajatorTextBox);
            this.Controls.Add(this.cassTextBox);
            this.Controls.Add(this.casTextBox);
            this.Controls.Add(this.cfsTextBox);
            this.Controls.Add(this.cfambpAngajatorLabel);
            this.Controls.Add(this.cassAngajatorLabel);
            this.Controls.Add(this.cfgpcsAngajatorLabel);
            this.Controls.Add(this.cfciAngajatorLabel);
            this.Controls.Add(this.cfsAngajatorLabel);
            this.Controls.Add(this.casAngajatorLabel);
            this.Controls.Add(this.angajatorLabel);
            this.Controls.Add(this.impozitAngajatLabel);
            this.Controls.Add(this.cassLabel);
            this.Controls.Add(this.casLabel);
            this.Controls.Add(this.cfsLabel);
            this.Controls.Add(this.angajatLabel);
            this.Controls.Add(this.calculeazaButton);
            this.Controls.Add(this.salariuBrutTextBox);
            this.Controls.Add(this.salariuBrutLabel);
            this.Name = "Form1";
            this.Text = "Calculator Salariu";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label salariuBrutLabel;
        private System.Windows.Forms.TextBox salariuBrutTextBox;
        private System.Windows.Forms.Button calculeazaButton;
        private System.Windows.Forms.Label angajatLabel;
        private System.Windows.Forms.Label cfsLabel;
        private System.Windows.Forms.Label casLabel;
        private System.Windows.Forms.Label cassLabel;
        private System.Windows.Forms.Label impozitAngajatLabel;
        private System.Windows.Forms.Label angajatorLabel;
        private System.Windows.Forms.Label casAngajatorLabel;
        private System.Windows.Forms.Label cfsAngajatorLabel;
        private System.Windows.Forms.Label cfciAngajatorLabel;
        private System.Windows.Forms.Label cfgpcsAngajatorLabel;
        private System.Windows.Forms.Label cassAngajatorLabel;
        private System.Windows.Forms.Label cfambpAngajatorLabel;
        private System.Windows.Forms.TextBox cfsTextBox;
        private System.Windows.Forms.TextBox casTextBox;
        private System.Windows.Forms.TextBox cassTextBox;
        private System.Windows.Forms.TextBox casAngajatorTextBox;
        private System.Windows.Forms.TextBox cfsAngajatorTextBox;
        private System.Windows.Forms.TextBox cfciAngajatorTextBox;
        private System.Windows.Forms.TextBox cfgpcsAngajatorTextBox;
        private System.Windows.Forms.TextBox cassAngajatorTextBox;
        private System.Windows.Forms.TextBox cfambpAngajatorTextBox;
        private System.Windows.Forms.TextBox impozitTextBox;
    }
}


namespace WindowsFormsApp1
{
    partial class Pacienti
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
            this.PacientiLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cautaNumeTextBox = new System.Windows.Forms.TextBox();
            this.cautaNumeButton = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.adaugaPacientButton = new System.Windows.Forms.Button();
            this.adaugaRadiografieButton = new System.Windows.Forms.Button();
            this.adaugaConsultatieButton = new System.Windows.Forms.Button();
            this.vizualizareFisaMedicalaButton = new System.Windows.Forms.Button();
            this.inchidereAplicationButton = new System.Windows.Forms.Button();
            this.vizualizarePacientiButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // PacientiLabel
            // 
            this.PacientiLabel.AutoSize = true;
            this.PacientiLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PacientiLabel.Location = new System.Drawing.Point(338, 25);
            this.PacientiLabel.Name = "PacientiLabel";
            this.PacientiLabel.Size = new System.Drawing.Size(103, 24);
            this.PacientiLabel.TabIndex = 0;
            this.PacientiLabel.Text = "PACIENTI";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(37, 91);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(180, 18);
            this.label1.TabIndex = 1;
            this.label1.Text = "Introduceti numele cautat: ";
            // 
            // cautaNumeTextBox
            // 
            this.cautaNumeTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cautaNumeTextBox.Location = new System.Drawing.Point(223, 88);
            this.cautaNumeTextBox.Name = "cautaNumeTextBox";
            this.cautaNumeTextBox.Size = new System.Drawing.Size(351, 24);
            this.cautaNumeTextBox.TabIndex = 2;
            // 
            // cautaNumeButton
            // 
            this.cautaNumeButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.cautaNumeButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cautaNumeButton.Location = new System.Drawing.Point(616, 83);
            this.cautaNumeButton.Name = "cautaNumeButton";
            this.cautaNumeButton.Size = new System.Drawing.Size(138, 35);
            this.cautaNumeButton.TabIndex = 5;
            this.cautaNumeButton.Text = "Cauta";
            this.cautaNumeButton.UseVisualStyleBackColor = false;
            this.cautaNumeButton.Click += new System.EventHandler(this.cautaNumeButton_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(40, 153);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(736, 182);
            this.dataGridView1.TabIndex = 6;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // adaugaPacientButton
            // 
            this.adaugaPacientButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.adaugaPacientButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaPacientButton.Location = new System.Drawing.Point(55, 384);
            this.adaugaPacientButton.Name = "adaugaPacientButton";
            this.adaugaPacientButton.Size = new System.Drawing.Size(190, 35);
            this.adaugaPacientButton.TabIndex = 7;
            this.adaugaPacientButton.Text = "Adauga pacient";
            this.adaugaPacientButton.UseVisualStyleBackColor = false;
            this.adaugaPacientButton.Click += new System.EventHandler(this.adaugaPacientButton_Click);
            // 
            // adaugaRadiografieButton
            // 
            this.adaugaRadiografieButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.adaugaRadiografieButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaRadiografieButton.Location = new System.Drawing.Point(586, 384);
            this.adaugaRadiografieButton.Name = "adaugaRadiografieButton";
            this.adaugaRadiografieButton.Size = new System.Drawing.Size(168, 35);
            this.adaugaRadiografieButton.TabIndex = 8;
            this.adaugaRadiografieButton.Text = "Adauga Radiografie";
            this.adaugaRadiografieButton.UseVisualStyleBackColor = false;
            this.adaugaRadiografieButton.Click += new System.EventHandler(this.adaugaRadiografieButton_Click);
            // 
            // adaugaConsultatieButton
            // 
            this.adaugaConsultatieButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.adaugaConsultatieButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.adaugaConsultatieButton.Location = new System.Drawing.Point(314, 384);
            this.adaugaConsultatieButton.Name = "adaugaConsultatieButton";
            this.adaugaConsultatieButton.Size = new System.Drawing.Size(190, 35);
            this.adaugaConsultatieButton.TabIndex = 9;
            this.adaugaConsultatieButton.Text = "Adauga Consultatie";
            this.adaugaConsultatieButton.UseVisualStyleBackColor = false;
            this.adaugaConsultatieButton.Click += new System.EventHandler(this.adaugaConsultatieButton_Click);
            // 
            // vizualizareFisaMedicalaButton
            // 
            this.vizualizareFisaMedicalaButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vizualizareFisaMedicalaButton.Location = new System.Drawing.Point(55, 460);
            this.vizualizareFisaMedicalaButton.Name = "vizualizareFisaMedicalaButton";
            this.vizualizareFisaMedicalaButton.Size = new System.Drawing.Size(190, 35);
            this.vizualizareFisaMedicalaButton.TabIndex = 10;
            this.vizualizareFisaMedicalaButton.Text = "Vizualizare fisa medicala";
            this.vizualizareFisaMedicalaButton.UseVisualStyleBackColor = true;
            this.vizualizareFisaMedicalaButton.Click += new System.EventHandler(this.vizualizareFisaMedicalaButton_Click);
            // 
            // inchidereAplicationButton
            // 
            this.inchidereAplicationButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.inchidereAplicationButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inchidereAplicationButton.Location = new System.Drawing.Point(586, 460);
            this.inchidereAplicationButton.Name = "inchidereAplicationButton";
            this.inchidereAplicationButton.Size = new System.Drawing.Size(168, 35);
            this.inchidereAplicationButton.TabIndex = 11;
            this.inchidereAplicationButton.Text = "Inchidere Aplicatie";
            this.inchidereAplicationButton.UseVisualStyleBackColor = false;
            this.inchidereAplicationButton.Click += new System.EventHandler(this.inchidereAplicationButton_Click);
            // 
            // vizualizarePacientiButton
            // 
            this.vizualizarePacientiButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.vizualizarePacientiButton.Location = new System.Drawing.Point(314, 460);
            this.vizualizarePacientiButton.Name = "vizualizarePacientiButton";
            this.vizualizarePacientiButton.Size = new System.Drawing.Size(190, 35);
            this.vizualizarePacientiButton.TabIndex = 12;
            this.vizualizarePacientiButton.Text = "Vizualizare pacienti";
            this.vizualizarePacientiButton.UseVisualStyleBackColor = true;
            this.vizualizarePacientiButton.Click += new System.EventHandler(this.vizualizarePacientiButton_Click);
            // 
            // Pacienti
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 523);
            this.Controls.Add(this.vizualizarePacientiButton);
            this.Controls.Add(this.inchidereAplicationButton);
            this.Controls.Add(this.vizualizareFisaMedicalaButton);
            this.Controls.Add(this.adaugaConsultatieButton);
            this.Controls.Add(this.adaugaRadiografieButton);
            this.Controls.Add(this.adaugaPacientButton);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.cautaNumeButton);
            this.Controls.Add(this.cautaNumeTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.PacientiLabel);
            this.Name = "Pacienti";
            this.Text = "Pacienti";
            this.Load += new System.EventHandler(this.Pacienti_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label PacientiLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox cautaNumeTextBox;
        private System.Windows.Forms.Button cautaNumeButton;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button adaugaPacientButton;
        private System.Windows.Forms.Button adaugaRadiografieButton;
        private System.Windows.Forms.Button adaugaConsultatieButton;
        private System.Windows.Forms.Button vizualizareFisaMedicalaButton;
        private System.Windows.Forms.Button inchidereAplicationButton;
        private System.Windows.Forms.Button vizualizarePacientiButton;
    }
}
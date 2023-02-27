namespace WindowsFormsApp2
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
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "",
            "raz",
            "dva",
            "tri"}, -1);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem(new string[] {
            "",
            "porc",
            "cal",
            "veverita"}, -1);
            this.numeTextBox = new System.Windows.Forms.TextBox();
            this.varstaTextBox = new System.Windows.Forms.TextBox();
            this.prenumeTextBox = new System.Windows.Forms.TextBox();
            this.numeLabel = new System.Windows.Forms.Label();
            this.prenumeLabel = new System.Windows.Forms.Label();
            this.varstaLabel = new System.Windows.Forms.Label();
            this.datePersGroupBox = new System.Windows.Forms.GroupBox();
            this.judeteListBox = new System.Windows.Forms.ListBox();
            this.judetGroupBox = new System.Windows.Forms.GroupBox();
            this.sexGroupBox = new System.Windows.Forms.GroupBox();
            this.radioButtonSexF = new System.Windows.Forms.RadioButton();
            this.radioButtonSexM = new System.Windows.Forms.RadioButton();
            this.limbajeGroupBox = new System.Windows.Forms.GroupBox();
            this.javaCheckBox = new System.Windows.Forms.CheckBox();
            this.cSharpCheckBox = new System.Windows.Forms.CheckBox();
            this.pythonCheckBox = new System.Windows.Forms.CheckBox();
            this.cppCheckBox = new System.Windows.Forms.CheckBox();
            this.cCheckBox = new System.Windows.Forms.CheckBox();
            this.trimiteButton = new System.Windows.Forms.Button();
            this.dateFinaleGroupBox = new System.Windows.Forms.GroupBox();
            this.dateFinaleListBox = new System.Windows.Forms.ListBox();
            this.listView1 = new System.Windows.Forms.ListView();
            this.datePersGroupBox.SuspendLayout();
            this.judetGroupBox.SuspendLayout();
            this.sexGroupBox.SuspendLayout();
            this.limbajeGroupBox.SuspendLayout();
            this.dateFinaleGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // numeTextBox
            // 
            this.numeTextBox.AcceptsReturn = true;
            this.numeTextBox.AcceptsTab = true;
            this.numeTextBox.Location = new System.Drawing.Point(144, 36);
            this.numeTextBox.Name = "numeTextBox";
            this.numeTextBox.Size = new System.Drawing.Size(100, 20);
            this.numeTextBox.TabIndex = 1;
            // 
            // varstaTextBox
            // 
            this.varstaTextBox.AcceptsReturn = true;
            this.varstaTextBox.AcceptsTab = true;
            this.varstaTextBox.Location = new System.Drawing.Point(144, 131);
            this.varstaTextBox.Name = "varstaTextBox";
            this.varstaTextBox.Size = new System.Drawing.Size(100, 20);
            this.varstaTextBox.TabIndex = 3;
            this.varstaTextBox.TextChanged += new System.EventHandler(this.varstaTextBox_TextChanged);
            // 
            // prenumeTextBox
            // 
            this.prenumeTextBox.AcceptsReturn = true;
            this.prenumeTextBox.AcceptsTab = true;
            this.prenumeTextBox.Location = new System.Drawing.Point(144, 82);
            this.prenumeTextBox.Name = "prenumeTextBox";
            this.prenumeTextBox.Size = new System.Drawing.Size(100, 20);
            this.prenumeTextBox.TabIndex = 2;
            // 
            // numeLabel
            // 
            this.numeLabel.AutoSize = true;
            this.numeLabel.Location = new System.Drawing.Point(39, 39);
            this.numeLabel.Name = "numeLabel";
            this.numeLabel.Size = new System.Drawing.Size(35, 13);
            this.numeLabel.TabIndex = 3;
            this.numeLabel.Text = "Nume";
            // 
            // prenumeLabel
            // 
            this.prenumeLabel.AutoSize = true;
            this.prenumeLabel.Location = new System.Drawing.Point(39, 89);
            this.prenumeLabel.Name = "prenumeLabel";
            this.prenumeLabel.Size = new System.Drawing.Size(49, 13);
            this.prenumeLabel.TabIndex = 4;
            this.prenumeLabel.Text = "Prenume";
            // 
            // varstaLabel
            // 
            this.varstaLabel.AutoSize = true;
            this.varstaLabel.Location = new System.Drawing.Point(39, 138);
            this.varstaLabel.Name = "varstaLabel";
            this.varstaLabel.Size = new System.Drawing.Size(37, 13);
            this.varstaLabel.TabIndex = 5;
            this.varstaLabel.Text = "Varsta";
            // 
            // datePersGroupBox
            // 
            this.datePersGroupBox.Controls.Add(this.prenumeTextBox);
            this.datePersGroupBox.Controls.Add(this.varstaLabel);
            this.datePersGroupBox.Controls.Add(this.numeTextBox);
            this.datePersGroupBox.Controls.Add(this.prenumeLabel);
            this.datePersGroupBox.Controls.Add(this.varstaTextBox);
            this.datePersGroupBox.Controls.Add(this.numeLabel);
            this.datePersGroupBox.Location = new System.Drawing.Point(72, 33);
            this.datePersGroupBox.Name = "datePersGroupBox";
            this.datePersGroupBox.Size = new System.Drawing.Size(299, 174);
            this.datePersGroupBox.TabIndex = 6;
            this.datePersGroupBox.TabStop = false;
            this.datePersGroupBox.Text = "Date Personale";
            // 
            // judeteListBox
            // 
            this.judeteListBox.FormattingEnabled = true;
            this.judeteListBox.Items.AddRange(new object[] {
            "Arad",
            "Alba",
            "Hunedoara",
            "Olt",
            "Mehedinti",
            "Caras-Severin",
            "Timis"});
            this.judeteListBox.Location = new System.Drawing.Point(28, 31);
            this.judeteListBox.Name = "judeteListBox";
            this.judeteListBox.Size = new System.Drawing.Size(120, 95);
            this.judeteListBox.TabIndex = 4;
            // 
            // judetGroupBox
            // 
            this.judetGroupBox.Controls.Add(this.judeteListBox);
            this.judetGroupBox.Location = new System.Drawing.Point(80, 237);
            this.judetGroupBox.Name = "judetGroupBox";
            this.judetGroupBox.Size = new System.Drawing.Size(291, 141);
            this.judetGroupBox.TabIndex = 4;
            this.judetGroupBox.TabStop = false;
            this.judetGroupBox.Text = "Judet";
            // 
            // sexGroupBox
            // 
            this.sexGroupBox.Controls.Add(this.radioButtonSexF);
            this.sexGroupBox.Controls.Add(this.radioButtonSexM);
            this.sexGroupBox.Location = new System.Drawing.Point(80, 409);
            this.sexGroupBox.Name = "sexGroupBox";
            this.sexGroupBox.Size = new System.Drawing.Size(291, 72);
            this.sexGroupBox.TabIndex = 5;
            this.sexGroupBox.TabStop = false;
            this.sexGroupBox.Text = "Sex";
            // 
            // radioButtonSexF
            // 
            this.radioButtonSexF.AutoSize = true;
            this.radioButtonSexF.Location = new System.Drawing.Point(151, 35);
            this.radioButtonSexF.Name = "radioButtonSexF";
            this.radioButtonSexF.Size = new System.Drawing.Size(61, 17);
            this.radioButtonSexF.TabIndex = 6;
            this.radioButtonSexF.TabStop = true;
            this.radioButtonSexF.Text = "Feminin";
            this.radioButtonSexF.UseVisualStyleBackColor = true;
            // 
            // radioButtonSexM
            // 
            this.radioButtonSexM.AutoSize = true;
            this.radioButtonSexM.Location = new System.Drawing.Point(26, 35);
            this.radioButtonSexM.Name = "radioButtonSexM";
            this.radioButtonSexM.Size = new System.Drawing.Size(67, 17);
            this.radioButtonSexM.TabIndex = 5;
            this.radioButtonSexM.TabStop = true;
            this.radioButtonSexM.Text = "Masculin";
            this.radioButtonSexM.UseVisualStyleBackColor = true;
            // 
            // limbajeGroupBox
            // 
            this.limbajeGroupBox.Controls.Add(this.javaCheckBox);
            this.limbajeGroupBox.Controls.Add(this.cSharpCheckBox);
            this.limbajeGroupBox.Controls.Add(this.pythonCheckBox);
            this.limbajeGroupBox.Controls.Add(this.cppCheckBox);
            this.limbajeGroupBox.Controls.Add(this.cCheckBox);
            this.limbajeGroupBox.Location = new System.Drawing.Point(437, 33);
            this.limbajeGroupBox.Name = "limbajeGroupBox";
            this.limbajeGroupBox.Size = new System.Drawing.Size(291, 174);
            this.limbajeGroupBox.TabIndex = 7;
            this.limbajeGroupBox.TabStop = false;
            this.limbajeGroupBox.Text = "Limbaje de programare";
            // 
            // javaCheckBox
            // 
            this.javaCheckBox.AutoSize = true;
            this.javaCheckBox.Location = new System.Drawing.Point(110, 131);
            this.javaCheckBox.Name = "javaCheckBox";
            this.javaCheckBox.Size = new System.Drawing.Size(49, 17);
            this.javaCheckBox.TabIndex = 11;
            this.javaCheckBox.Text = "Java";
            this.javaCheckBox.UseVisualStyleBackColor = true;
            // 
            // cSharpCheckBox
            // 
            this.cSharpCheckBox.AutoSize = true;
            this.cSharpCheckBox.Location = new System.Drawing.Point(110, 108);
            this.cSharpCheckBox.Name = "cSharpCheckBox";
            this.cSharpCheckBox.Size = new System.Drawing.Size(40, 17);
            this.cSharpCheckBox.TabIndex = 10;
            this.cSharpCheckBox.Text = "C#";
            this.cSharpCheckBox.UseVisualStyleBackColor = true;
            // 
            // pythonCheckBox
            // 
            this.pythonCheckBox.AutoSize = true;
            this.pythonCheckBox.Location = new System.Drawing.Point(110, 85);
            this.pythonCheckBox.Name = "pythonCheckBox";
            this.pythonCheckBox.Size = new System.Drawing.Size(59, 17);
            this.pythonCheckBox.TabIndex = 9;
            this.pythonCheckBox.Text = "Python";
            this.pythonCheckBox.UseVisualStyleBackColor = true;
            // 
            // cppCheckBox
            // 
            this.cppCheckBox.AutoSize = true;
            this.cppCheckBox.Location = new System.Drawing.Point(110, 62);
            this.cppCheckBox.Name = "cppCheckBox";
            this.cppCheckBox.Size = new System.Drawing.Size(45, 17);
            this.cppCheckBox.TabIndex = 8;
            this.cppCheckBox.Text = "C++";
            this.cppCheckBox.UseVisualStyleBackColor = true;
            // 
            // cCheckBox
            // 
            this.cCheckBox.AutoSize = true;
            this.cCheckBox.Location = new System.Drawing.Point(110, 39);
            this.cCheckBox.Name = "cCheckBox";
            this.cCheckBox.Size = new System.Drawing.Size(33, 17);
            this.cCheckBox.TabIndex = 7;
            this.cCheckBox.Text = "C";
            this.cCheckBox.UseVisualStyleBackColor = true;
            // 
            // trimiteButton
            // 
            this.trimiteButton.Location = new System.Drawing.Point(526, 285);
            this.trimiteButton.Name = "trimiteButton";
            this.trimiteButton.Size = new System.Drawing.Size(120, 40);
            this.trimiteButton.TabIndex = 12;
            this.trimiteButton.Text = "Trimite";
            this.trimiteButton.UseVisualStyleBackColor = true;
            this.trimiteButton.Click += new System.EventHandler(this.trimiteButton_Click);
            // 
            // dateFinaleGroupBox
            // 
            this.dateFinaleGroupBox.Controls.Add(this.dateFinaleListBox);
            this.dateFinaleGroupBox.Location = new System.Drawing.Point(437, 381);
            this.dateFinaleGroupBox.Name = "dateFinaleGroupBox";
            this.dateFinaleGroupBox.Size = new System.Drawing.Size(291, 160);
            this.dateFinaleGroupBox.TabIndex = 13;
            this.dateFinaleGroupBox.TabStop = false;
            this.dateFinaleGroupBox.Text = "Date Finale";
            // 
            // dateFinaleListBox
            // 
            this.dateFinaleListBox.FormattingEnabled = true;
            this.dateFinaleListBox.Location = new System.Drawing.Point(28, 31);
            this.dateFinaleListBox.Name = "dateFinaleListBox";
            this.dateFinaleListBox.Size = new System.Drawing.Size(257, 95);
            this.dateFinaleListBox.TabIndex = 13;
            // 
            // listView1
            // 
            this.listView1.HideSelection = false;
            listViewItem1.Tag = "numaram";
            listViewItem2.Tag = "animale";
            this.listView1.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2});
            this.listView1.Location = new System.Drawing.Point(899, 237);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(121, 97);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged_1);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1251, 633);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.dateFinaleGroupBox);
            this.Controls.Add(this.trimiteButton);
            this.Controls.Add(this.limbajeGroupBox);
            this.Controls.Add(this.sexGroupBox);
            this.Controls.Add(this.judetGroupBox);
            this.Controls.Add(this.datePersGroupBox);
            this.Name = "Form2";
            this.Text = "Introducere date";
            this.datePersGroupBox.ResumeLayout(false);
            this.datePersGroupBox.PerformLayout();
            this.judetGroupBox.ResumeLayout(false);
            this.sexGroupBox.ResumeLayout(false);
            this.sexGroupBox.PerformLayout();
            this.limbajeGroupBox.ResumeLayout(false);
            this.limbajeGroupBox.PerformLayout();
            this.dateFinaleGroupBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox numeTextBox;
        private System.Windows.Forms.TextBox varstaTextBox;
        private System.Windows.Forms.TextBox prenumeTextBox;
        private System.Windows.Forms.Label numeLabel;
        private System.Windows.Forms.Label prenumeLabel;
        private System.Windows.Forms.Label varstaLabel;
        private System.Windows.Forms.GroupBox datePersGroupBox;
        private System.Windows.Forms.ListBox judeteListBox;
        private System.Windows.Forms.GroupBox judetGroupBox;
        private System.Windows.Forms.GroupBox sexGroupBox;
        private System.Windows.Forms.RadioButton radioButtonSexF;
        private System.Windows.Forms.RadioButton radioButtonSexM;
        private System.Windows.Forms.GroupBox limbajeGroupBox;
        private System.Windows.Forms.CheckBox javaCheckBox;
        private System.Windows.Forms.CheckBox cSharpCheckBox;
        private System.Windows.Forms.CheckBox pythonCheckBox;
        private System.Windows.Forms.CheckBox cppCheckBox;
        private System.Windows.Forms.CheckBox cCheckBox;
        private System.Windows.Forms.Button trimiteButton;
        private System.Windows.Forms.GroupBox dateFinaleGroupBox;
        private System.Windows.Forms.ListBox dateFinaleListBox;
        private System.Windows.Forms.ListView listView1;
    }
}
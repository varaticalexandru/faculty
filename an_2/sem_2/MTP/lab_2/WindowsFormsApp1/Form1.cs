using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        private void incarcaClase()
        {
            claseComboBox.Items.Clear();
            eleviFlowLayoutPanel.Controls.Clear();

            // iteram prin dir-urile din cwd
            foreach (string dirPath in Directory.EnumerateDirectories(Application.StartupPath))
            {
                // adauga nume dir (clasa) in comboBox
                string dirName = (new DirectoryInfo(dirPath)).Name;
                claseComboBox.Items.Add(dirName);

            }
        }

        private void incarcaEleviClasa(string clasa)
        {
            eleviFlowLayoutPanel.Controls.Clear();

            string path = Application.StartupPath+ "\\" + clasa;

            // iteram prin fiecare file .cls din path
            foreach (var filename in Directory.EnumerateFiles(path, "*.cls"))
            {
                using (StreamReader sr = new StreamReader(filename))
                {
                    string cnp = Path.GetFileNameWithoutExtension(filename);
                    string nume = sr.ReadLine();
                    string adresa = sr.ReadLine();

                    Persoana p = new Persoana(cnp, nume, adresa);

                    // creare buton cu numele elevului
                    Button btn = new Button();
                    btn.Text = p.Nume;
                    btn.Width = 200;
                    btn.Tag = p;

                    // adaugare buton la flowLayoutPanel
                    eleviFlowLayoutPanel.Controls.Add(btn);

                    // adaugare handler pt. click
                    btn.Click += Btn_Click;

                }
            }
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            // afisare date persoana in listBox
            dateListBox.Items.Clear();

            Button btn = (Button)sender;
            Persoana p = (Persoana) btn.Tag;

            dateListBox.Items.Add($"Nume: {(string) p.Nume}");
            dateListBox.Items.Add($"CNP: {(string) p.Cnp}");
            dateListBox.Items.Add($"Adresa: {(string) p.Adresa}");

        }

        public Form1()
        {
            InitializeComponent();

            incarcaClase();

        }

       

        private void claseComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {

            incarcaEleviClasa(claseComboBox.Text);
        }

       
    }
}

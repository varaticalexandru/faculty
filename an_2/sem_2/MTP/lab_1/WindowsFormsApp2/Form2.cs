using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void trimiteButton_Click(object sender, EventArgs e)
        {
            string nume = numeTextBox.Text;
            string prenume = prenumeTextBox.Text;
            string varsta = varstaTextBox.Text;
            string judet = judeteListBox.SelectedItem.ToString();

            string sex;

            if (radioButtonSexF.Checked == true)
                sex = radioButtonSexF.Text;
            else
                sex = radioButtonSexM.Text;


            // verificare campuri goale
            if (nume == "" || prenume == "" || varsta == "")
            {
                MessageBox.Show("Completati toate campurile !");
            }
            else
            {
                // verificare - sa contina doar litere
                if (!Regex.Match(nume, "^[A-Z][a-zA-Z]*$").Success || !Regex.Match(prenume, "^[A-Z][a-zA-Z]*$").Success)
                {
                    // numele e incorect
                    MessageBox.Show("Nume/Prenume invalid", "Mesaj", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            // lista de limbaje de programare
            string lp = "";

            if (cCheckBox.Checked)
                lp = lp + " " + cCheckBox.Text;
            if (cppCheckBox.Checked)
                lp = lp + " " + cppCheckBox.Text;
            if (javaCheckBox.Checked)
                lp = lp + " " + javaCheckBox.Text;
            if (pythonCheckBox.Checked)
                lp = lp + " " + pythonCheckBox.Text;
            if (cSharpCheckBox.Checked)
                lp = lp + " " + cSharpCheckBox.Text;


            dateFinaleListBox.Items.Add(nume);
            dateFinaleListBox.Items.Add(prenume);
            dateFinaleListBox.Items.Add(judet);
            dateFinaleListBox.Items.Add(sex);
            dateFinaleListBox.Items.Add(lp);
        }

        private void varstaTextBox_TextChanged(object sender, EventArgs e)
        {
            if (!System.Text.RegularExpressions.Regex.IsMatch(varstaTextBox.Text, @"^[0-9]*$")) {
                MessageBox.Show("Introduceti o varsta valida !");
                varstaTextBox.Text = "";
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged_1(object sender, EventArgs e)
        {

        }
    }
}

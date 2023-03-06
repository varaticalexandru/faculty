using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        private void readUsers()
        {
            // citire & incarcare utilizatori in utilizatorCombobox
            string[] userRecords = File.ReadAllLines("users.txt");
            foreach (string record in userRecords)
            {
                string[] credentials = record.Split(':');
                string user = credentials[0];
                string password = credentials[1];

                utilizatorComboBox.Items.Add(user);
            }
        }
        

        public Form2()
        {
            InitializeComponent();

             
        }

        private void autentificarebutton_Click(object sender, EventArgs e)
        {
            int record_idx = utilizatorComboBox.SelectedIndex;  // idx-ul item-ului selectat din utilizatoriCombobox

            if (record_idx != -1)
            {
                string[] userRecords = File.ReadAllLines("users.txt");

                // verificam daca parola introdusa este corecta
                if (parolaTextBox.Text == (userRecords[record_idx].Split(':')[1])) {

                    MessageBox.Show("Autentificare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    this.Hide();    // ascundem forma curenta

                    Form f = new Form1();   // apel constructor forma noua
                    f.Closed += (s, args) => this.Close();
                    f.ShowDialog();
                }
                else
                {
                    MessageBox.Show("Autentificare esuata !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            readUsers();

        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            //this.Close();
            Application.Exit();
        }

        private void inregistrareButton_Click(object sender, EventArgs e)
        {
            Form f = new Form3();
            f.ShowDialog();
        }
    }
}

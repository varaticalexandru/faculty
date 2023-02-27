using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void autentButton_Click(object sender, EventArgs e)
        {
            // daca autentificare cu succes
            if (userTextBox.Text == "user" && passTextBox.Text == "pass") {
                this.Hide();
                Form f = new Form2();
                f.ShowDialog();
            }
            else
            {
                MessageBox.Show("Eroare ! Introduceti user/password corecte !");
            }
        }
    }
}

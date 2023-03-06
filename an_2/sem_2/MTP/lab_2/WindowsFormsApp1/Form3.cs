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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void salveazaButton_Click(object sender, EventArgs e)
        {
            timer.Start();

            using (StreamWriter sw = File.AppendText("users.txt"))
            {
                sw.WriteLine(utilizatorTextBox.Text + ":" + parolaTextBox.Text);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            progressBar.Value += 10;
            progressBar.Value -= 1;
            progressBar.Value += 1;

            if (progressBar.Value == progressBar.Maximum)
            {
                timer.Stop();
                MessageBox.Show("Inregistrare reusita !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Application.Restart();
            }


        }
    }
}

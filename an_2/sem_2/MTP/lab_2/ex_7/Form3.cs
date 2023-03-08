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

namespace ex_7
{
    public partial class EchipaNoua : Form
    {
        public EchipaNoua()
        {
            InitializeComponent();
        }

        private void adaugaEchipaButton_Click(object sender, EventArgs e)
        {
            string dirPath = Application.StartupPath + "\\";
            Directory.CreateDirectory(dirPath + adaugaTextBox.Text);

            MessageBox.Show("Adaugare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
            
        }
    }
}

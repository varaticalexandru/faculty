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

        string nume;    // candidate name
        string filename;    // test filename

        public Form1(string nume, string test)
        {
            InitializeComponent();

            nume = this.nume;
            test = this.filename;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            List<Intrebare> list = new List<Intrebare>();

            using (StreamReader sr = new StreamReader(test+".txt"))
            {
                while ()
            }
        }
    }
}

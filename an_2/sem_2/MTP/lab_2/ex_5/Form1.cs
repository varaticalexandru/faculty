using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex_5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void generareButton_Click(object sender, EventArgs e)
        {
            Label lbl = new Label();
            lbl.Location =  new Point(int.Parse(XTextBox.Text), int.Parse(YTextBox.Text));
            lbl.Text = numeLabelTextBox.Text;

            this.Controls.Add(lbl);
        }
    }
}

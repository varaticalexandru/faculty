using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex_6
{
    public partial class Form1 : Form
    {

        // declare TableLayoutPanel
        TableLayoutPanel dynamicTableLayoutPanel;
       
        public Form1()
        {
            InitializeComponent();

            // initialize TableLayoutPanel

            // define/allocate TableLayoutPanel
            dynamicTableLayoutPanel = new TableLayoutPanel();
            dynamicTableLayoutPanel.Location = new Point(273, 34);
            dynamicTableLayoutPanel.Name = "tableLayoutPanel1";
            dynamicTableLayoutPanel.Size = new Size(479, 394);
        }

        private void generareButton_Click(object sender, EventArgs e)
        {

            int m = int.Parse(MTextBox.Text);   // randuri
            int n = int.Parse(NTextBox.Text);   // coloane

            int n_st_dr = m - 2;

            if (m < 2 || n < 2)
            {
                MessageBox.Show("Dimensiuni invalide !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                // rows, columns number
                int r = int.Parse((string)MTextBox.Text);
                int c = int.Parse((string)NTextBox.Text);

                if (r < 1 || c < 2)
                    return;

                // clear
                dynamicTableLayoutPanel.Controls.Clear();
                
                // add rows and columns
                dynamicTableLayoutPanel.RowCount = r;
                dynamicTableLayoutPanel.ColumnCount = c;


                // add child controls to TableLayoutPanel, specify row and column
                for (int i = 0; i < c; i++)
                {
                    dynamicTableLayoutPanel.Controls.Add(new Button(), 0, i);
                    dynamicTableLayoutPanel.Controls.Add(new Button(), r-1, i);
                }

                for (int i = 1; i < r-1; i++)
                {
                    dynamicTableLayoutPanel.Controls.Add(new Button(), i, 0);
                    dynamicTableLayoutPanel.Controls.Add(new Button(), i, c-1);
                }

                this.Controls.Add(dynamicTableLayoutPanel);
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }
    }
}

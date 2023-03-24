using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form5 : Form
    {

        // membri
        public int n;
        public Button[,] matrix;
        TableLayoutPanel tabla = new TableLayoutPanel();    // tabla de sah

        public Form5()
        {
            InitializeComponent();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            // clear
            tabla.Controls.Clear();

            tabla.Location = new Point(180, 34);
            tabla.Size = new Size(550, 550);

            n = int.Parse(nTextBox.Text);   // read n

             // alocare matrice
            this.matrix = new Button[n, n];

            
            this.Controls.Add(tabla);

            // set n x n
            tabla.RowCount = n;
            tabla.ColumnCount = n;

            // set colors
            for (int i = 0; i < n; i++)
            {

                tabla.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / n));
                tabla.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100f / n));

                for (int j = 0; j < n; j++)
                {
                    var button = new Button
                    {
                        Dock = DockStyle.Fill,
                        TextAlign = ContentAlignment.MiddleCenter,
                        Font = new Font(FontFamily.GenericSansSerif, 24),
                        BackColor = ((i + j) % 2 == 0) ? Color.White : Color.Black, // suma indecsi - para => alb;  suma indecsi - impara => neagra
                    };

                    tabla.Controls.Add(button, j, i);

                    matrix[i, j] = button;  // add button to matrix
                    matrix[i, j].Click += Button_Click; // event handler
                    matrix[i, j].Tag = new Point(i, j);
                }
            }
            


        }

        private void Button_Click(object sender, EventArgs e)
        {

            // colorare drumuri nebun
           
            var clickedButton = (Button)sender;
            var clickedButtonPos = (Point)clickedButton.Tag;


            // clear colors
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i, j].BackColor = ((i + j) % 2 == 0) ? Color.White : Color.Black;
                }
            }

            // set colors
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i - j == clickedButtonPos.X - clickedButtonPos.Y || i + j == clickedButtonPos.X + clickedButtonPos.Y)
                    {
                        (matrix[i, j] as Button).BackColor = Color.BlueViolet;
                    }
                }
            }


        }
    }
}

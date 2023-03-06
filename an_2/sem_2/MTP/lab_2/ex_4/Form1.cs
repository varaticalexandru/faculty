using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex_4
{
    public partial class Form1 : Form
    {
        private int lbl_count;

        public Form1()
        {
            InitializeComponent();
            lbl_count = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void controlDoritComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void generateButton_Click(object sender, EventArgs e)
        {
            

            switch (controlDoritComboBox.Text)
            {
                case "Button":
                {
                    controlsFlowLayoutPanel.Controls.Add(new Button());
                }
                break;

                case "Text Box":
                {
                    controlsFlowLayoutPanel.Controls.Add(new TextBox());
                }
                break;

                case "Radio Button":
                {
                    controlsFlowLayoutPanel.Controls.Add(new RadioButton());
                }
                break;

                case "List Box":
                {
                    controlsFlowLayoutPanel.Controls.Add(new ListBox());
                }
                break;

                case "Label":
                {
                    Label lbl = new Label();
                    controlsFlowLayoutPanel.Controls.Add(lbl);
                    lbl.Text = "label " + lbl_count.ToString();
                    lbl_count++;
                }
                break;

                case "Check Box":
                {
                    controlsFlowLayoutPanel.Controls.Add(new CheckBox());
                }
                break;

                case "Group Box":
                {
                    controlsFlowLayoutPanel.Controls.Add(new GroupBox());
                }
                break;

                default:
                {
                    MessageBox.Show("Optiune nedefinita !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);    
                }
                break;
            }
        }
    }
}

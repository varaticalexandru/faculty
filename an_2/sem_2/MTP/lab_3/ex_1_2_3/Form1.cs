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
using System.Xml;

namespace ex_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // citeste un fisier XML si genereaza controale

            FileStream fs = new FileStream("controls.xml", FileMode.Open, FileAccess.Read);
            
            XmlDocument xmldoc = new XmlDocument();

            FlowLayoutPanel flowLayoutPanel = new FlowLayoutPanel();
            flowLayoutPanel.Location = new Point(30, 30);
            /*flowLayoutPanel.Size = new Size(500, 100);*/
            flowLayoutPanel.AutoSize = true;
            flowLayoutPanel.FlowDirection = FlowDirection.TopDown;
            flowLayoutPanel.WrapContents = true;
            flowLayoutPanel.AutoScroll = true;
            flowLayoutPanel.MinimumSize = new Size(100, 100);
            this.Controls.Add(flowLayoutPanel);

            xmldoc.Load(fs);

            foreach (XmlNode node in xmldoc.ChildNodes[1])
            {
                switch (node.Name)
                {
                    case "textBox":
                        {
                            TextBox textBox = new TextBox();
                            textBox.Name = node.Attributes.Item(0).Value;
                            textBox.Text = node.Attributes.Item(1).Value;

                            flowLayoutPanel.Controls.Add(textBox);
                            
                        }
                    break;

                    case "radioButton":
                        {
                            Label label = new Label();
                            label.Size = new Size(200, 40);
                            label.TextAlign = ContentAlignment.BottomCenter;
                            label.Name = node.Attributes.Item(0).Value;
                            label.Text = node.Attributes.Item(1).Value;

                            flowLayoutPanel.Controls.Add(label);

                            for (int i = 0; i < node.ChildNodes.Count; i++)
                            {

                                RadioButton radioButton = new RadioButton();
                                radioButton.Name = node.ChildNodes[i].InnerText;
                                radioButton.Text = node.ChildNodes[i].InnerText;

                                flowLayoutPanel.Controls.Add(radioButton);
                            }

                        }
                    break;

                    case "checkBox":
                        {
                            Label label = new Label();
                            label.Size = new Size(200, 40);
                            label.TextAlign = ContentAlignment.BottomCenter;
                            label.Name = node.Attributes.Item(0).Value;
                            label.Text = node.Attributes.Item(1).Value;

                            flowLayoutPanel.Controls.Add(label);

                            for (int i = 0; i < node.ChildNodes.Count; i++)
                            {
                                CheckBox checkBox = new CheckBox();
                                checkBox.Name = node.ChildNodes[i].InnerText;
                                checkBox.Text = node.ChildNodes[i].InnerText;

                                flowLayoutPanel.Controls.Add(checkBox);
                            }

                        }
                    break;

                    case "listBox":
                        {
                            Label label = new Label();
                            label.Size = new Size(200, 40);
                            label.TextAlign = ContentAlignment.BottomCenter;
                            label.Name = node.Attributes.Item(0).Value;
                            label.Text = node.Attributes.Item(1).Value;

                            ListBox listBox = new ListBox();
                            listBox.Name = label.Name + "ListBox";

                            flowLayoutPanel.Controls.Add(label);

                            for (int i = 0; i < node.ChildNodes.Count; i++)
                            {
                                listBox.Items.Add(node.ChildNodes[i].InnerText);
                            }

                            flowLayoutPanel.Controls.Add(listBox);

                        }
                    break;



                    default:
                        {

                        }
                    break;
                }

                
            }




        }
    }
}

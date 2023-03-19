using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Serialization;

namespace ex_1
{
    public partial class Form2 : Form
    {

        public void initColors()
        {
            Random rnd = new Random();  // random number generator

            foreach (Control c in this.Controls)
            {
                if (c.GetType() == typeof(System.Windows.Forms.Button) && c.Name != "scriereXML" && c.Name != "serializareJSON")
                {
                    int R = rnd.Next(256);
                    int G = rnd.Next(256);
                    int B = rnd.Next(256);

                    c.BackColor = Color.FromArgb(R, G, B);    // sets random color to the button 
                }
            }
        }

        public void initTags()
        {
            // init buttons tags (1-10)
            foreach (Control c in this.Controls)
            {
                if (c.GetType() == typeof(System.Windows.Forms.Button) && c.Name != "scriereXML" && c.Name != "serializareJSON")
                {
                    c.Tag = 0;
                }
            }
        }

        public Form2()
        {
            InitializeComponent();
            initColors();
            initTags();
            
        }

        /*private void scriereXML_Click(object sender, EventArgs e)
        {
            XmlWriter xmlwriter = XmlWriter.Create("butoane.xml");

            xmlwriter.WriteStartDocument();

            xmlwriter.WriteStartElement("buttons"); // root

            // iterate through all numbered buttons (1-10) on the form
            foreach (Control c in this.Controls)
            {
                if (c.GetType() == typeof(System.Windows.Forms.Button) && c.Name != "scriereXML" && c.Name != "serializareJSON")
                {
                    // write data to XML
                    xmlwriter.WriteStartElement(c.Name);    // button name

                    xmlwriter.WriteStartElement("culoare"); // button color
                    xmlwriter.WriteString(c.BackColor.Name);
                    xmlwriter.WriteEndElement();

                    xmlwriter.WriteStartElement("click-uri");   // button's click counter
                    xmlwriter.WriteString(c.Tag.ToString());
                    xmlwriter.WriteEndElement();

                    xmlwriter.WriteEndElement();
                }
            }

            xmlwriter.WriteEndElement();
            xmlwriter.WriteEndDocument();
            xmlwriter.Close();

            MessageBox.Show("Scriere cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }*/

        private void scriereXML_Click(object sender, EventArgs e)
        {
            List<Buton> butoane = new List<Buton>();  // "Buton"s list
            XmlSerializer serializer = new XmlSerializer(typeof(List<Buton>));

            // iterate through every button
            foreach (Control c in this.Controls)
            {
                if (c.GetType() == typeof(System.Windows.Forms.Button) && c.Name != "scriereXML" && c.Name != "serializareJSON")
                {
                    butoane.Add(new Buton(c.Name, c.BackColor.Name, c.Tag.ToString()));   // add button to list
                }
            }

            butoane.Sort((a, b) => a.Nume.CompareTo(b.Nume));  // sort list

            // write to XML (serialize)
            using (var writer = new StreamWriter("butoane_.xml"))
            using (var xmlWriter = XmlWriter.Create(writer, new XmlWriterSettings { Indent = true }))  
            {
                serializer.Serialize(xmlWriter, butoane);
                MessageBox.Show("Scriere cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

        }

        private void button_Click(object sender, EventArgs e)
        {
            Button b = (Button) sender;

            b.Tag = (int)b.Tag + 1; // increment button's click counter

            colorDialog1.FullOpen = true;
            colorDialog1.AllowFullOpen = true;
            colorDialog1.ShowDialog();
            b.BackColor = colorDialog1.Color;   // set button's color
        }

        private void serializareJSON_Click(object sender, EventArgs e)
        {
            List<Buton> butoane = new List<Buton>();    // "Buton"s list

            butoane.Sort((a, b) => b.Nume.CompareTo(a.Nume));   // sort list

            foreach (Control c in this.Controls)
            {
                if (c.GetType() == typeof(System.Windows.Forms.Button) && c.Name != "scriereXML" && c.Name != "serializareJSON" )
                {
                    butoane.Add(new Buton(c.Text, c.BackColor.Name, c.Tag.ToString()));    // add button to list
                }
            }


            var options = new JsonSerializerOptions { WriteIndented = true };
            string jsonString = JsonSerializer.Serialize(butoane, options);  // serialize to json string

            // write to file
            String filename = "butoane.json";
            File.WriteAllText(filename, jsonString);

            MessageBox.Show("Serializare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
    }

}
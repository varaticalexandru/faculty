using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            /* List<string> list = new List<string>();

             list.Add("Sasha");
             list.Add("Vanya");
             list.Add("Alex");
             list.Add("Marin");

             XmlDocument xml = new XmlDocument();    // doc
             XmlDeclaration xml_declaration = xml.CreateXmlDeclaration("1.0", "utf-8", "");  // declaration

             xml.AppendChild(xml_declaration);   // append declaration

             XmlNode root = xml.CreateNode(XmlNodeType.Element, "students", "");    // root

             xml.AppendChild(root); // append root

             // iteram prin fiecare student din lista
             foreach (string student in list)
             {
                 XmlNode tmpNode = xml.CreateNode(XmlNodeType.Element, "student", "");
                 tmpNode.InnerText = student;
                 root.AppendChild(tmpNode);
             }

             xml.Save("students.xml");

             MessageBox.Show("Succes");*/


            List<string> list = new List<string>();

            list.Add("Sasha, 3, 21, Info");
            list.Add("Vanya, 1, 20, Fizica");
            list.Add("Alex, 3, 22, Istorie");
            list.Add("Marin, 4, 24, Arhitectura");
            list.Add("Ioana, 2, 20, Drept");

            XmlDocument xml = new XmlDocument(); // doc
            XmlNode root = xml.CreateNode(XmlNodeType.Element, "students", ""); // root
            xml.AppendChild(root); // append root

            // iteram prin lista
            foreach (string line in list)
            {
                string[] stInfo = line.Split(',');

                XmlNode studentNode = xml.CreateNode(XmlNodeType.Element, "student", ""); // student

                // create attributes
                XmlAttribute an = xml.CreateAttribute("an");
                an.Value = stInfo[1].Trim();

                XmlAttribute varsta = xml.CreateAttribute("varsta");
                varsta.Value = stInfo[2].Trim();

                // append attributes
                studentNode.Attributes.Append(an);
                studentNode.Attributes.Append(varsta);

                // nume
                XmlNode numeNode = xml.CreateNode(XmlNodeType.Element, "nume", "");
                numeNode.InnerText = stInfo[0].Trim();

                // specialitate
                XmlNode specNode = xml.CreateNode(XmlNodeType.Element, "spec", "");
                specNode.InnerText = stInfo[3].Trim();

                // append nume, spec
                studentNode.AppendChild(numeNode);
                studentNode.AppendChild(specNode);

                // add student to root
                root.AppendChild(studentNode);
            }

            // save . xml file
            xml.Save("studenti_1.xml");

            MessageBox.Show("Succes !");
        }
    }
}

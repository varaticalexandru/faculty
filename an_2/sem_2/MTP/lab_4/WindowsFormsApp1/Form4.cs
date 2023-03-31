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
using System.Xml.Linq;
using System.Xml.Serialization;
using HtmlAgilityPack;
using HtmlDocument = HtmlAgilityPack.HtmlDocument;


namespace WindowsFormsApp1
{
    public partial class Form4 : Form
    {

        // members
        List<State> states = new List<State>();  // lista state

        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {

            
        }

        private void scrapButton_Click(object sender, EventArgs e)
        {
            
            // Load the webpage
            HtmlWeb web = new HtmlWeb();
            HtmlDocument doc = web.Load("https://www.jagranjosh.com/general-knowledge/list-of-states-in-usa-1663078166-1");

            // Select all <tr> nodes
            var rows = doc.DocumentNode.SelectNodes("//table//tr");

            // if rows aren't empty
            if (rows != null && rows.Count > 0)
            {
                int k = 0;  // aux counter

                // iterate through every <tr>
                foreach (var row in rows)
                {
                    if (k == 0) { k++; continue; }   // skip first row (Sl.No, State, Capital)

                    // get <td>'s list
                    var cells = row.SelectNodes(".//td");

                    var id = int.Parse(cells[0].SelectSingleNode(".//p//span").InnerText);
                    string name = cells[1].SelectSingleNode(".//p//span").InnerText;
                    string capital = cells[2].SelectSingleNode(".//p//span").InnerText;

                    states.Add(new State(id, name, capital));   // add State to the list

                    k++;    // inc counter

                }
            }


            dataGridView1.DataSource = states;

            MessageBox.Show("Scrapped the web successfully!");
        }

        private void serializeButton_Click(object sender, EventArgs e)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<State>));

            using (var writer = new StreamWriter("states.xml"))
            using (var xmlwriter = XmlWriter.Create(writer, new XmlWriterSettings { Indent = true }))
            {
                serializer.Serialize(xmlwriter, states);
            }

            MessageBox.Show("Serializare cu succes !");
        }


   
    }
}

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
using HtmlAgilityPack;
using HtmlDocument = HtmlAgilityPack.HtmlDocument;


namespace WindowsFormsApp1
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {

            List<State> states = new List<State>();  // lista state

            // Load the webpage
            HtmlWeb web = new HtmlWeb();
            HtmlDocument doc = web.Load("https://www.jagranjosh.com/general-knowledge/list-of-states-in-usa-1663078166-1");

            // Select all <tr> nodes
            var rows = doc.DocumentNode.SelectNodes("//table//tr");

            // if rows aren't empty
            if (rows != null && rows.Count > 0 )
            {
                // iterate through every <tr>
                foreach (var row in rows)
                {
                    // get <td>'s list
                    var cells = row.SelectNodes(".//td");

                    var id = int.Parse(cells[0].SelectSingleNode(".//p//span").InnerText);
                    string name = cells[1].SelectSingleNode(".//p//span").InnerText;
                    string capital = cells[2].SelectSingleNode(".//p//span").InnerText;
                        
                    states.Add(new State(id, name, capital));   // add State to the list

                }
            }


            
            dataGridView1.DataSource= states;

            MessageBox.Show("States list saved to states.xml");
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace ex_1
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
            
        }

        private void citireXML_Click(object sender, EventArgs e)
        {
            // citire (deserializare) XML

            List<Buton> butoane = new List<Buton>();
            XmlSerializer xmlSerializer= new XmlSerializer(typeof(List<Buton>));

            using (FileStream fs = new FileStream("butoane_.xml", FileMode.Open, FileAccess.Read))
            {
                butoane = xmlSerializer.Deserialize(fs) as List<Buton>; // deserializare
            }

            // afisare
            FlowLayoutPanel flowLayoutPanel = new FlowLayoutPanel();
            this.Controls.Add(flowLayoutPanel);
            flowLayoutPanel.FlowDirection = FlowDirection.TopDown;
            flowLayoutPanel.Location = new Point(flowLayoutPanel.Location.X + 80, flowLayoutPanel.Location.Y + 60);
            flowLayoutPanel.Size = new Size(295, 200);
            flowLayoutPanel.AutoScroll = true;
            flowLayoutPanel.WrapContents = true;

            //flowLayoutPanel.AutoSize = true;

            foreach (Buton b in butoane)
            {
                Button button = new Button();
                flowLayoutPanel.Controls.Add(button);
                button.Text = b.NClicks;
                button.Size = new Size(98, 32);
                button.Font = new Font("Microsoft Sans Serif", 10, FontStyle.Bold);

                if (Regex.IsMatch(b.Culoare, "^[A-Z].*$"))  // culoare - cuvant
                {
                    button.BackColor = Color.FromName(b.Culoare);
                }
                else  // culoare - HEX (ARGB)
                {
                    button.BackColor = Color.FromArgb(Int32.Parse(b.Culoare, System.Globalization.NumberStyles.HexNumber));
                }
                
            }

        }

        private void Form3_Load(object sender, EventArgs e)
        {
            
        }

        private void citireJSON_Click(object sender, EventArgs e)
        {
            // citire (deserializare) JSON

            String filename = "butoane.json";
            String jsonString = File.ReadAllText(filename);

            List<Buton> butoane = new List<Buton>();

            butoane = JsonSerializer.Deserialize<List<Buton>>(jsonString);

            // afisare
            FlowLayoutPanel flowLayoutPanel = new FlowLayoutPanel();
            this.Controls.Add(flowLayoutPanel);
            flowLayoutPanel.FlowDirection = FlowDirection.TopDown;
            flowLayoutPanel.Location = new Point(flowLayoutPanel.Location.X + 80, flowLayoutPanel.Location.Y + 60);
            flowLayoutPanel.Size = new Size(295, 200);
            flowLayoutPanel.AutoScroll = true;
            flowLayoutPanel.WrapContents = true;

            //flowLayoutPanel.AutoSize = true;

            foreach (Buton b in butoane)
            {
                Button button = new Button();
                flowLayoutPanel.Controls.Add(button);
                button.Text = b.NClicks;
                button.Size = new Size(98, 32);
                button.Font = new Font("Microsoft Sans Serif", 10, FontStyle.Bold);

                if (Regex.IsMatch(b.Culoare, "^[A-Z].*$"))  // culoare - cuvant
                {
                    button.BackColor = Color.FromName(b.Culoare);
                }
                else  // culoare - HEX (ARGB)
                {
                    button.BackColor = Color.FromArgb(Int32.Parse(b.Culoare, System.Globalization.NumberStyles.HexNumber));
                }

            }

        }
    }
}

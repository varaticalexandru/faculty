using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // creare baza de date

            List <Date> list = new List<Date>();

            list.Add(new Date() { ID = 1, Nume = "Caldare", Prenume = "Sanya" });
            list.Add(new Date() { ID = 2, Nume = "Var", Prenume = "Vanya" });
            list.Add(new Date() { ID = 3, Nume = "Dar", Prenume = "Ion" });

            // serializer
            XmlSerializer serial = new XmlSerializer(typeof(List<Date>));

            // scriere
            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\" + "BD.xml", FileMode.Create, FileAccess.Write))
            {
                serial.Serialize(fs, list);
                MessageBox.Show("Baza de date creata !");
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            // citire baza de date

            List <Date> list = new List<Date>();

            //serializer
            XmlSerializer serial = new XmlSerializer(typeof(List<Date>));

            // citire
            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\BD.xml", FileMode.Open, FileAccess.Read))
            {
                list = serial.Deserialize(fs) as List<Date>;
            }

            dataGridView1.DataSource = list;
        }
    }
}

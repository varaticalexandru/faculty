using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace ex_1
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {

            XmlSerializer serializer = new XmlSerializer(typeof(List<Book>), new XmlRootAttribute("Catalog"));
            List<Book> books;

            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\books.xml", FileMode.Open, FileAccess.Read))
            {
                
                books = (List<Book>) serializer.Deserialize(fs);
            }

            dataGridView1.DataSource = books;


        }
    }
}

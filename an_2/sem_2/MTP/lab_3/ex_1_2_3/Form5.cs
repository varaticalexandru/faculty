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
using System.Xml.Serialization;

namespace ex_1
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void Form5_Load(object sender, EventArgs e)
        {
            List<Book> books = new List<Book>();

            XmlSerializer serializer = new XmlSerializer(typeof(List<Book>), new XmlRootAttribute("Catalog"));

            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\books.xml", FileMode.Open, FileAccess.Read))
            {
                books = serializer.Deserialize(fs) as List<Book>;   // deserialize
            }

            foreach (Book book in books)
            {
                book.Price = book.Price * (float) 1.1;  // add 10% to each book's price
            }

            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\books_out.xml", FileMode.OpenOrCreate, FileAccess.Write))
            {
                serializer.Serialize(fs, books); // serialize
            }

            MessageBox.Show("Scriere reusita !");

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace ex_1
{
    [XmlType("Book")]
    public class Book
    {
        public Book() { }

        // proprietati
        [XmlAttribute]
        public string Id { get; set; }

        [XmlElement("Title")]
        public string Title { get; set; }

        [XmlElement("Description")]
        public string Description { get; set; }

        [XmlElement("Author")]
        public string Author { get; set; }

        [XmlElement("Genre")]
        public string Genre { get; set; }

        [XmlElement("Price")]
        public float Price { get; set; }

        [XmlElement("Publish_date")]
        public DateTime Publish_date { get; set; }
    }
}

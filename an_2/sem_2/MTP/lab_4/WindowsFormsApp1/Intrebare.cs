using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WindowsFormsApp1
{
    [XmlType("Intrebare")]
    public class Intrebare
    {
        
        public Intrebare() { }

        // proprietati

        [XmlElement("Idx")]
        public int Idx { get; set; }

        [XmlElement("Tip")]
        public string Tip { get ; set; }

        [XmlElement("Text")]
        public string Text { get; set; }

        [XmlElement("Nr_var_rs")]
        public int Nr_var_rs { get; set; }

        [XmlArrayItem("Varianta", Type = typeof(String))]
        [XmlArray]
        public List<string> Var_rs { get; set; }

        [XmlElement("Link_poza")]
        public string Link_poza { get; set; }

        [XmlElement("Rs_corect")]
        public string Rs_corect { get; set; }
    }
}

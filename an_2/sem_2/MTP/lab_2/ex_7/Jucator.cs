using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ex_7
{
    internal class Jucator
    {
        string nume;
        string cnp;
        string post;

        // consstructor
        public Jucator(string nume, string cnp, string post) 
        {
            this.nume = nume;
            this.cnp = cnp;
            this.post = post;
        }

        // proprietati
        public string Nume { get => nume;  set => nume = value; }

        public string Cnp { get => cnp; set => cnp = value; }

        public string Post { get => post; set => post = value; }
        
    }
}

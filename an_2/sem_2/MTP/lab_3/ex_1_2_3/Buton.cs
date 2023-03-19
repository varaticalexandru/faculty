using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex_1
{
    public class Buton
    {
        // membri 
        private String nume;
        private String culoare;
        private String nClicks;

        // constructori
        public Buton(string nume, string culoare, string nClicks)
        {
            this.Nume = nume;
            this.Culoare = culoare;
            this.NClicks = nClicks;
        }

        public Buton() { }


        // proprietati
        public string Nume { get => nume; set => nume = value; }
        public string Culoare { get => culoare; set => culoare = value; }
        public string NClicks { get => nClicks; set => nClicks = value; }

    }

}

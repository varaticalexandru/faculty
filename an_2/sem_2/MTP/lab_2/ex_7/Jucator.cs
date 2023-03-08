using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ex_7
{
    internal class Jucator
    {
        // enumerare posturi jucator
        internal enum post
        {
            default_ = 0,
            Portar = 1,
            Fundas = 2,
            Mijlocas = 3,
            Atacant = 4
        }

        // membri
        string nume;
        string cnp;
        post pozitie;

        

        // constructor
        public Jucator(string nume, string cnp, post pozitie) 
        {
            this.nume = nume;
            this.cnp = cnp;
            this.pozitie = pozitie;
        }

        // proprietati
        public string Nume { get => nume;  set => nume = value; }

        public string Cnp { get => cnp; set => cnp = value; }

        public post Pozitie { get => pozitie; set => pozitie = value; }
        
        // conversie pozitie: string -> post (enum)
        static public post stringToPost(string pozitie_string)
        {
            post pozitie = post.default_;

            switch (pozitie_string)
            {
                case "Portar": // portar
                    pozitie = post.Portar;
                    break;

                case "Fundas": // fundas
                    pozitie = post.Fundas;
                    break;

                case "Mijlocas": // mijlocas
                    pozitie = post.Mijlocas;
                    break;

                case "Atacant": // atacant
                    pozitie = post.Atacant;
                    break;

                default:
                break;
            }

            return pozitie;
        }

}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class State
    {
        // constructors
        public State() { }

        public State(int id, string name, string capital)
        {
            Id = id;
            Name = name;
            Capital = capital;
        }




        // properties

        public int Id { get; set; }
        public String Name { get; set; }
        public String Capital { get; set; }
    }
}

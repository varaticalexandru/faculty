using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    internal class Intrebare
    {
        // membri
        int idx;
        string tip;
        string text;
        int nr_var_rs;
        string[] var_rs;
        string linkPoza;
        string rs_corect;

        // contructori
        public Intrebare(int idx, string tip, string text, int nr_var_rs, string[] var_rs, string linkPoza, string rs_corect)
        {
            this.idx = idx;
            this.tip = tip;
            this.text = text;
            this.nr_var_rs = nr_var_rs;
            this.var_rs = var_rs;
            this.linkPoza = linkPoza;
            this.rs_corect = rs_corect;
        }

        public Intrebare() { }

        // proprietati

        public int Idx { get => idx; set => idx = value; }
        public string Tip { get => tip; set => tip = value; }
        public string Text { get => text; set => text = value; }
        public int Nr_var_rs { get => nr_var_rs; set => nr_var_rs = value; }
        public string[] Var_rs { get => var_rs; set => var_rs = value; }
        public string LinkPoza { get => linkPoza; set => linkPoza = value; }
        public string Rs_corect { get => rs_corect; set => rs_corect = value; }
    }
}

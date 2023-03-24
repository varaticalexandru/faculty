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
using System.Windows.Forms.VisualStyles;
using System.Xml.Serialization;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        // membri
        string nume;    // nume candidat
        string filename;    // test filename

        List<Intrebare> intrebari = new List<Intrebare>();  // lista intrebari
        string[] raspunsuri;    // array raspunsuri user
        List<Rezultat> rezultate = new List<Rezultat>();    // lista rezultate

        public int total_intrebari;
        public float punctaj = 0;
        public int nr_rs_corecte = 0;
        public int intrebare_curenta = 0;


        public Form1(string nume, string filename)
        {
            InitializeComponent();

            candidatTextBox.Text =  this.nume = nume;
            testTextBox.Text = this.filename = filename;
            punctajTextBox.Text = "0.00";
            nrRaspCorecteTextBox.Text = "0";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            getQuestionsXML();

            this.total_intrebari = intrebari.Count();
            totalTextBox.Text = (this.total_intrebari - 1).ToString();

            this.raspunsuri = new string[total_intrebari];


            loadQuestion(intrebare_curenta);

        }

        private void getQuestionsText()
        {
            using (StreamReader sr = new StreamReader(filename + ".txt"))
            {
                string line;

                // citeste fiecare linie din fisier
                while ((line = sr.ReadLine()) != null)
                {
                    // daca intalnim "\n"
                    if (string.IsNullOrEmpty(line))
                    {
                        continue;
                    }

                    Intrebare q= new Intrebare();   // apelare constructor default Intrebare

                    q.Idx = int.Parse(line);
                    q.Tip = sr.ReadLine();
                    q.Text = sr.ReadLine();
                    q.Nr_var_rs = int.Parse(sr.ReadLine());

                    // citire variante de rs
                    for (int i = 0; i < q.Nr_var_rs; i++)
                    {
                        q.Var_rs.Add(sr.ReadLine());
                    }

                    q.Link_poza = sr.ReadLine();
                    q.Rs_corect = sr.ReadLine();

                    intrebari.Add(q);   // adaugare Intrebare la lista
                }
            }

        }



        private void getQuestionsXML()
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Intrebare>), new XmlRootAttribute("TestGrila"));

            using (FileStream fs = new FileStream(Environment.CurrentDirectory + "\\grila.xml", FileMode.Open, FileAccess.Read))
            {
                intrebari = serializer.Deserialize(fs) as List<Intrebare>;  // deserializare
            }
        }

        public void loadQuestion(int idx)
        {
            // clear
            flowLayoutPanel1.Controls.Clear();
            pictureBox1.Image = null;

            idxIntrebareTextBox.Text = idx.ToString();
            intrebareLabel.Text = $"-- {intrebari[idx].Text}";

            if (!intrebari[idx].Link_poza.Equals("0"))
                pictureBox1.Image = new Bitmap(Image.FromFile(intrebari[idx].Link_poza), new Size(289, 157));

            if (intrebari[idx].Tip == "single")
            {
                // radio buttons
                for (int i = 0; i < intrebari[idx].Nr_var_rs; i++)
                {
                    RadioButton rb = new RadioButton();
                    rb.Text = intrebari[idx].Var_rs[i];
                    flowLayoutPanel1.Controls.Add(rb);
                }
            }
            else if (intrebari[idx].Tip == "multiple")
            {
                // checkboxes
                for (int i = 0; i < intrebari[idx].Nr_var_rs; i++)
                {
                    CheckBox cb = new CheckBox();
                    cb.Text = intrebari[idx].Var_rs[i];
                    flowLayoutPanel1.Controls.Add(cb);
                }
            }
            else
            {
                MessageBox.Show("Tip de intrebare invalid", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }


        }

        private bool evalAnswer(int idx)
        {

            // adaugare raspuns(-uri) utilizator in lista
            for (int i = 0; i < flowLayoutPanel1.Controls.Count; i++)
            {
                Control c = flowLayoutPanel1.Controls[i];

                if ((c as RadioButton) != null && (c as RadioButton).Checked == true || (c as CheckBox) != null && (c as CheckBox).Checked == true)
                {
                    raspunsuri[intrebare_curenta] += i + " ";
                }

            }

            // adaugare rezultat in lista
            Rezultat rez = new Rezultat();
            rez.Text = intrebari[idx].Text;
            rez.Rs_user = raspunsuri[idx];
            rez.Rs_corecte = intrebari[idx].Rs_corect;

            rezultate.Add(rez);
            

            // verificare tip intrebare
            if (intrebari[idx].Tip == "single")
            {
                // radio buttons
                int id_rs_corect = int.Parse(intrebari[idx].Rs_corect);
                RadioButton rb = flowLayoutPanel1.Controls[id_rs_corect] as RadioButton;
                if (rb.Checked)
                {
                    this.punctaj += 1;
                    nr_rs_corecte++;
                    return true;
                }
            }
            else if (intrebari[idx].Tip == "multiple")
            {
                float punctaj_acumulat = 0;

                float cuantum = 1 / (float)intrebari[idx].Var_rs.Count;

                // checkboxes
                string[] rs_corecte = intrebari[idx].Rs_corect.Split(',').Select(f => f.Trim()).ToArray();

                // iteram prin toate variantele de rs
                for (int i = 0; i < intrebari[idx].Var_rs.Count(); i++)
                {
                    CheckBox cb = flowLayoutPanel1.Controls[i] as CheckBox;

                    // daca se afla in lista de rs corecte si e marcat ca true
                    if (rs_corecte.Contains(i.ToString()) && cb.Checked)
                    {
                        punctaj_acumulat = punctaj_acumulat + cuantum;
                    }
                }

                this.punctaj += punctaj_acumulat;

                if (Math.Abs(1 - punctaj_acumulat) < 0.1)
                {
                    nr_rs_corecte++;
                    return true;
                }
                    
                                
            }

            return false;
        }


        private void urmatoareaIntrebareButton_Click(object sender, EventArgs e)
        {
            // clean 
            raspCorectTextBox.Clear();

            // verifica corectitudinea raspunsului
            bool eval = evalAnswer(intrebare_curenta);

            punctajTextBox.Text = this.punctaj.ToString("0.00");  // actualizare punctaj

            if (eval)
            {
                nrRaspCorecteTextBox.Text = this.nr_rs_corecte.ToString();  // actualizare nr raspunsuri corecte
            }

            // verifica daca s-a ajuns la ultma intrebare
            if (intrebare_curenta + 1 == total_intrebari)
            {
                MessageBox.Show("Ati ajuns la capatul testului !");
                Form3 form3 = new Form3(intrebari, raspunsuri, rezultate);
                form3.ShowDialog();
            }
            else
            {
                // incrementare contor intrebare
                intrebare_curenta++;
                loadQuestion(intrebare_curenta);
            }
        }

        
        

        private void afiseazaRaspunsButton_Click(object sender, EventArgs e)
        {
            List<int> idx_rs_corect = intrebari[intrebare_curenta].Rs_corect.Split(',').Select(s => s.Trim()).ToList<string>().Select(s => int.Parse(s)).ToList<int>();

            idx_rs_corect.ForEach(item => raspCorectTextBox.Text = raspCorectTextBox.Text + " " + intrebari[intrebare_curenta].Var_rs[item]);
            
        }
    }
}

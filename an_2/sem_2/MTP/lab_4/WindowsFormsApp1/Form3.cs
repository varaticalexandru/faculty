using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Serialization;

namespace WindowsFormsApp1
{
    public partial class Form3 : Form
    {

        // membri
        public List<Intrebare> intrebari = new List<Intrebare>();
        public string[] raspunsuri;
        public List<Rezultat> rezultate = new List<Rezultat>();

        public Form3(List<Intrebare> intrebari, string[] raspunsuri, List<Rezultat> rezultate)
        {
            InitializeComponent();

            this.intrebari = intrebari;
            this.raspunsuri = raspunsuri;
            this.rezultate = rezultate;
        }

        public void loadAllQuestions()
        {
            for (int i = 0; i < intrebari.Count; i++)
            {
                loadQuestion(i);
            }
        }

        public void loadQuestion(int idx)
        {
            // parsing raspunsuri user
            string[] rs_user_init = raspunsuri[idx].Split(' ').Select(s => s.Trim(' ')).ToArray<string>();
            string[] rs_user_fixed = rs_user_init.Where(str => !string.IsNullOrEmpty(str)).ToArray();   // elimina sirurile nule
            int[] rs_user = Array.ConvertAll(rs_user_fixed, s => int.Parse(s)); // arr indecsi rs user

            // parsing raspunsuri corecte
            string[] rs_corecte_init = intrebari[idx].Rs_corect.Split(',').Select(s => s.Trim(' ')).ToArray<string>();
            int[] rs_corecte = Array.ConvertAll(rs_corecte_init, s => int.Parse(s));   // arr indecsi rs corecte


            // label
            Label intrebareLabel = new Label();
            intrebareLabel.Size = new Size(200, 30);
            flowLayoutPanel2.Controls.Add(intrebareLabel);

            intrebareLabel.Text = $"-- {intrebari[idx].Text}";

            
            // link poza
            if (!intrebari[idx].Link_poza.Equals("0"))
            {
                PictureBox pictureBox2 = new PictureBox();
                flowLayoutPanel2.Controls.Add(pictureBox2);
                pictureBox2.Size= new Size(200, 100);
                pictureBox2.Image = new Bitmap(Image.FromFile(intrebari[idx].Link_poza), new Size(200, 100));

            }

            // verificare tip intrebare
            if (intrebari[idx].Tip == "single")
            {
                // radio buttons
                for (int i = 0; i < intrebari[idx].Nr_var_rs; i++)
                {
                    RadioButton rb = new RadioButton();
                    rb.Text = intrebari[idx].Var_rs[i];
                    flowLayoutPanel2.Controls.Add(rb);

                    // marcare daca a fost selectat de user ca rs
                    if (i == rs_user[0])
                        rb.Checked = true;

                }
            }
            else if (intrebari[idx].Tip == "multiple")
            {
                // checkboxes
                for (int i = 0; i < intrebari[idx].Nr_var_rs; i++)
                {
                    CheckBox cb = new CheckBox();
                    cb.Text = intrebari[idx].Var_rs[i];
                    flowLayoutPanel2.Controls.Add(cb);

                    // marcare daca a fost selectat de user ca rs
                    if (rs_user.Contains(i))
                        cb.Checked = true;
                }
            }
            else
            {
                MessageBox.Show("Tip de intrebare invalid", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            // rs. user
            Label rsUserLabel = new Label();
            flowLayoutPanel2.Controls.Add(rsUserLabel);
            rsUserLabel.Size = new Size(200, 30);

            // scrie rs user in label
            rsUserLabel.Text = "Raspuns(-uri) user: ";
            foreach (int rs_idx in rs_user)
            {
                rsUserLabel.Text += intrebari[idx].Var_rs[rs_idx] + " ";
            }

            // rs. corect
            Label rsCorectLabel = new Label();
            flowLayoutPanel2.Controls.Add(rsCorectLabel);
            rsCorectLabel.Size = new Size(200, 30);

            // scrie rs corecte in label
            rsCorectLabel.Text = "Raspuns(-uri) corecte: ";
            foreach (int rs_idx in rs_corecte)
            {
                rsCorectLabel.Text += intrebari[idx].Var_rs[rs_idx] + " ";
            }


            // spatiere
            flowLayoutPanel2.Controls.Add(new Label());
            flowLayoutPanel2.Controls.Add(new Label());
        }


        void serializareRezultate()
        {
            // scriere in fisier XML (serializare)

            XmlSerializer serializer = new XmlSerializer(typeof(List<Rezultat>));

            using (var writer = new StreamWriter("rezultate.log.xml"))
            using (var xmlWriter = XmlWriter.Create(writer, new XmlWriterSettings { Indent = true }))
            {
                serializer.Serialize(xmlWriter, rezultate);
                MessageBox.Show("Serializare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            loadAllQuestions();
            serializareRezultate();

        }

        private void flowLayoutPanel2_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}

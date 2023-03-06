using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ex_7
{
    public partial class LPF : Form
    {
        // incarca echipele in ComboBox
        private void loadEchipe()
        {
            // iteram prin toate dir-urile din cwd/pwd
            foreach (string dirPath in Directory.EnumerateDirectories(Application.StartupPath))
            {
                // adauga nume echipa in ComboBox
                string dirName = (new DirectoryInfo(dirPath)).Name;
                echipeComboBox.Items.Add(dirName);
            }
        }

        // incarca jucatorii din echipa selectata in FlowLayoutPanel
        private void loadJucatori(string echipa)
        {
            string path = Application.StartupPath + "\\" + echipa;

            // iteram prin fiecare file .lpf din path
            foreach (string filename in Directory.EnumerateFiles(path, "*.lpf"))
            {
                using (StreamReader sr = new StreamReader(filename))
                {
                    string cnp = Path.GetFileNameWithoutExtension(filename);
                    string nume = sr.ReadLine();
                    string post = sr.ReadLine();

                    // instantiere clasa Jucator
                    Jucator jucator = new Jucator(nume, cnp, post);

                    // creeare buton cu numele jucatorului
                    Button btn = new Button();
                    btn.Text = nume;
                    btn.Width = 200;
                    btn.Tag = jucator;

                    // adaugare buton la FlowLayoutPanel
                    jucatoriFlowLayoutPanel.Controls.Add(btn);

                    // adaugare handler click
                    btn.Click += Btn_Click;
                }

            }
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            // clear
            numeTextBox.Clear();
            postTextBox.Clear();
            CNPTextBox.Clear();
            varstaTextBox.Clear();

            // preluare date sender (buton)
            Button btn = (Button) sender;
            Jucator jucator = (Jucator) btn.Tag;

            // scriere date in textbox-uri
            numeTextBox.Text = jucator.Nume;
            postTextBox.Text = jucator.Post;
            CNPTextBox.Text = jucator.Cnp;


            // obtine data nasterii din CNP
            string an = jucator.Cnp.Substring(1, 2);
            string luna = jucator.Cnp.Substring(3, 2);
            string zi = jucator.Cnp.Substring(5, 2);

            // verificare secol, prefixare an
            string prefix;

            int int_an = int.Parse(an);
            if (int_an > 25)
                prefix = "19";
            else
                prefix = "20";

            an = prefix + an;

            // data finala
            string data = $"{zi}.{luna}.{an}";

            // scriere data in DateTimePicker
            DateTime dt = DateTime.ParseExact(data, "dd.MM.yyyy", CultureInfo.InvariantCulture);
            dateTimePicker.Value = dt;

            // calculare, scriere varsta
            int varsta = int.Parse(DateTime.Now.Year.ToString()) - int.Parse(an);
            varstaTextBox.Text = varsta.ToString();
        }

        public LPF()
        {
            InitializeComponent();
            loadEchipe();

            dateTimePicker.Format = DateTimePickerFormat.Custom;
            dateTimePicker.CustomFormat = "dd.MM.yyyy";
        }

        private void echipeComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            // clear
            jucatoriFlowLayoutPanel.Controls.Clear();

            loadJucatori(echipeComboBox.Text);

        }
    }
}

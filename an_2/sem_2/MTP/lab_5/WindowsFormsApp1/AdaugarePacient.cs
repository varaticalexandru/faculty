using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Globalization;
using MySql.Data.MySqlClient;

namespace WindowsFormsApp1
{
    public partial class AdaugarePacient : Form
    {
        public AdaugarePacient()
        {
            InitializeComponent();
        }

        // parse data nasterii from CNP
        public static DateTime parseDataNasteriiCNP(String cnp)
        {
            
            String aa = cnp.Substring(1, 2);
            String ll = cnp.Substring(3, 2);
            String zz = cnp.Substring(5, 2);

            String aa_cur = DateTime.Now.Year.ToString().Substring(2, 2);

            String prefix;

            if (int.Parse(aa) <= int.Parse(aa_cur))
                prefix = "20";
            else
                prefix = "19";

            String aa_full = prefix + aa;

            DateTime data_nasterii = DateTime.ParseExact($"{aa_full}-{ll}-{zz}", "yyyy-MM-dd", CultureInfo.InvariantCulture);

            return data_nasterii;
        }

        // verifica validitate cnp
        public static bool isValid(string cnp)
        {
            
            string defaultCnp = "279146358279";
            int sum = 0;
            int k = 0;  // defaultCnp counter

            for (int i = 0; i < 12; i++)
            {
                sum += int.Parse(cnp[i].ToString()) * int.Parse(defaultCnp[i].ToString());
            }

            bool condition_1 = Regex.IsMatch(cnp, "^[1256]\\d{12}$");
            bool condition_2 = 
                (sum % 11 == 10) ? (int.Parse(cnp[cnp.Length - 1].ToString()) == 1)
                : int.Parse(cnp[cnp.Length - 1].ToString()) == (sum % 11);

            return condition_1 && condition_2;
        }


        private void salveazaPacientButton_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(CNPTextBox.Text))
            {
                MessageBox.Show("Nu ati introdus CNP-ul !");
                return;
            }

            String connect_string = @"Server=127.0.0.1; Port=3306; Database=pediatrie; Uid=root; Pwd=sandu2002;";
            MySqlConnection cnn = new MySqlConnection(connect_string);
            cnn.Open();

            String insert_string =
                "insert into pacienti " +
                "(CNP, Nume, Prenume, Sex, Nume_mama, Nume_tata, Data_nasterii, Locul_nasterii, APGAR, Medic_familie, Antecedente) " +
                "values (@cnp, @n, @p, @s, @nm, @nt, @dn, @ln, @apgar, @mf, @a);";

            MySqlCommand msc = new MySqlCommand(insert_string, cnn);
            msc.Parameters.AddWithValue("@cnp", CNPTextBox.Text);
            msc.Parameters.AddWithValue("@n", numeTextBox.Text);
            msc.Parameters.AddWithValue("@p", prenumeTextBox.Text);
            msc.Parameters.AddWithValue("@s", sexTextBox.Text);
            msc.Parameters.AddWithValue("@nm", numeMamaTextBox.Text);
            msc.Parameters.AddWithValue("@nt", numeTataTextBox.Text);
            msc.Parameters.AddWithValue("@dn", dateTimePicker1.Value.ToString("yyyy-MM-dd"));
            msc.Parameters.AddWithValue("@ln", loculNasteriiTextBox.Text);
            msc.Parameters.AddWithValue("@apgar", APGARTextBox.Text);
            msc.Parameters.AddWithValue("mf", medicFamilieTextBox.Text);
            msc.Parameters.AddWithValue("a", antecedenteTextBox.Text);

            msc.ExecuteNonQuery();
            cnn.Close();

            this.DialogResult = DialogResult.OK;
            this.Close();

        }

        private void CNPTextBox_MouseLeave(object sender, EventArgs e)
        {
            if (CNPTextBox.Text.Length == 13)
            {
                if (!isValid(CNPTextBox.Text))
                {
                    MessageBox.Show("CNP invalid !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            else
                return;


            DateTime data_nasterii = parseDataNasteriiCNP(CNPTextBox.Text);
            dateTimePicker1.Value = data_nasterii;  // set data nasterii

            varstaTextBox.Text = (DateTime.Now.Year - data_nasterii.Year).ToString();   // set varsta


        }
    }
}

using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Fisa : Form
    {

        public void getPacientData(String cnp)
        {
            String connect_string = @"Server=127.0.0.1; Port=3306; Database=pediatrie; Uid=root; Pwd=sandu2002;";
            MySqlConnection cnn = new MySqlConnection(connect_string);
            cnn.Open();

            // data from table 'pacienti' 
            String select_string =
                "select Nume, Prenume, Sex, Nume_mama, Nume_tata, Data_nasterii, Locul_nasterii, APGAR, Medic_familie, Antecedente " +
                "from pacienti " +
                $"where CNP = '{cnp}';";

            MySqlDataAdapter da = new MySqlDataAdapter(select_string, cnn);
            DataSet ds = new DataSet();
            da.Fill(ds, "pacienti");

            DataTable table = ds.Tables["pacienti"];    // get the table from the dataset

            // get each column from the table
            DataColumn col_nume = table.Columns["Nume"];
            DataColumn col_prenume = table.Columns["Prenume"];
            DataColumn col_sex = table.Columns["Sex"];
            DataColumn col_nm = table.Columns["Nume_mama"];
            DataColumn col_nt = table.Columns["Nume_tata"];
            DataColumn col_dn = table.Columns["Data_nasterii"];
            DataColumn col_ln = table.Columns["Locul_nasterii"];
            DataColumn col_apgar = table.Columns["APGAR"];
            DataColumn col_mf = table.Columns["Medic_familie"];
            DataColumn col_a = table.Columns["Antecedente"];

            // loop through the rows in the table and get values from each column
            foreach (DataRow row in table.Rows)
            {
                numeTextBox.Text = row[col_nume].ToString();
                prenumeTextBox.Text = row[col_prenume].ToString();
                sexTextBox.Text = row[col_sex].ToString();
                numeMamaTextBox.Text = row[col_nm].ToString();
                numeTataTextBox.Text = row[col_nt].ToString();
                dateTimePicker1.Value = DateTime.Parse(row[col_dn].ToString());
                loculNasteriiTextBox.Text = row[col_ln].ToString();
                APGARTextBox.Text = row[col_apgar].ToString();
                medicFamilieTextBox.Text = row[col_mf].ToString();
                antecedenteTextBox.Text = row[col_a].ToString();
            }


            // data from table 'consultatii'
            select_string =
                "select Data, Simptome, Diagnostic, Tratament " +
                "from consultatii " +
                $"where CNP = '{cnp}';";

            da = new MySqlDataAdapter(select_string, cnn);
            ds = new DataSet();
            da.Fill(ds, "consultatii");
            table = ds.Tables["consultatii"];

            dataGridView1.DataSource = table.DefaultView;

            // data from table 'radiografii'
            select_string =
                "select Nume_imagine " +
                "from radiografii ";

            da = new MySqlDataAdapter(select_string, cnn);
            ds = new DataSet();
            da.Fill(ds, "radiografii");
            table = ds.Tables["radiografii"];

                // adaugarea radiografiilor in flowLayoutPanel1

            DataColumn col_radiografie = table.Columns["Nume_imagine"];

            foreach (DataRow row in table.Rows)
            {
                PictureBox pictureBox = new PictureBox();
                pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                pictureBox.ImageLocation = row[col_radiografie].ToString();
                flowLayoutPanel1.Controls.Add(pictureBox);
                pictureBox.Show();

                pictureBox.Click += PictureBox_Click;   // abonare la metoda
            }


            

            cnn.Close();

        }

        private void PictureBox_Click(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            radiografiePictureBox.Image = pictureBox.Image;
        }

        public Fisa(String cnp)
        {
            InitializeComponent();

            CNPTextBox.Text = cnp;

            DateTime data_nasterii = AdaugarePacient.parseDataNasteriiCNP(cnp);
            dateTimePicker1.Value = data_nasterii;
            varstaTextBox.Text = (DateTime.Now.Year - data_nasterii.Year).ToString();

            getPacientData(cnp);
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
        }
    }
}

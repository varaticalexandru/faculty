using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace WindowsFormsApp1
{
    public partial class Pacienti : Form
    {
        public Pacienti()
        {
            InitializeComponent();
        }

        // incarca si afiseaza tabelul pacienti
        public void loadPacienti()
        {
            String connect = @"Server=127.0.0.1; Port=3306; Database=pediatrie; Uid=root; Pwd=sandu2002;";
            MySqlConnection cnn = new MySqlConnection(connect);
            cnn.Open();

            String tabel_pacienti = "select * from pacienti";
            MySqlDataAdapter da = new MySqlDataAdapter(tabel_pacienti, connect);

            DataSet ds = new DataSet();
            da.Fill(ds, "pacienti");
            dataGridView1.DataSource = ds.Tables["pacienti"].DefaultView;

            cnn.Close();
        }

        private void Pacienti_Load(object sender, EventArgs e)
        {
            loadPacienti();
        }

        private void inchidereAplicationButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void cautaNumeButton_Click(object sender, EventArgs e)
        {
            String connect = @"Server=127.0.0.1;Database=Pediatrie;Uid=root;Pwd=sandu2002;";
            MySqlConnection cnn = new MySqlConnection(connect);
            cnn.Open();

            String select = $"select * from pacienti where Nume = '{cautaNumeTextBox.Text}'";
            MySqlDataAdapter da = new MySqlDataAdapter(select, connect);
            DataSet ds = new DataSet();
            da.Fill(ds , "pacienti");
            dataGridView1.DataSource = ds.Tables["pacienti"].DefaultView;
            cnn.Close();
            da.Dispose();
            ds.Dispose();

        }

        private void vizualizarePacientiButton_Click(object sender, EventArgs e)
        {
            loadPacienti();
        }

        private void adaugaPacientButton_Click(object sender, EventArgs e)
        {
            AdaugarePacient adaugarePacient_form = new AdaugarePacient();
            adaugarePacient_form.ShowDialog();
        }

        private void adaugaConsultatieButton_Click(object sender, EventArgs e)
        {
            // call Consultatie form with CNP as parameter
            int selected_row = dataGridView1.SelectedCells[0].RowIndex;
            int cnp_idx = 0;

            String cnp = dataGridView1.Rows[selected_row].Cells[cnp_idx].Value.ToString();

            Consultatie consultatie_form = new Consultatie(cnp);
            consultatie_form.ShowDialog();
            
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            
        }

        private void adaugaRadiografieButton_Click(object sender, EventArgs e)
        {
            int selected_row = dataGridView1.SelectedCells[0].RowIndex;
            int cnp_idx = 0;

            String cnp = dataGridView1.Rows[selected_row].Cells[cnp_idx].Value.ToString();

            Radiografie radiografie_form = new Radiografie(cnp);
            radiografie_form.ShowDialog();
        }

        private void vizualizareFisaMedicalaButton_Click(object sender, EventArgs e)
        {
            int selected_row = dataGridView1.SelectedCells[0].RowIndex;
            int cnp_idx = 0;

            String cnp = dataGridView1.Rows[selected_row].Cells[cnp_idx].Value.ToString();

            Fisa fisa_form = new Fisa(cnp);
            fisa_form.ShowDialog();
        }
    }
}

using MySql.Data.MySqlClient;
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

namespace WindowsFormsApp1
{
    public partial class Radiografie : Form
    {

        public Radiografie(String cnp)
        {
            InitializeComponent();

            CNPTextBox.Text = cnp;
        }

        private void selectButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                
                imagineTextBox.Text = Path.GetFileName(ofd.FileName);
            }
        }

        private void adaugaConsultatieButton_Click(object sender, EventArgs e)
        {
            String connect_string = @"Server=127.0.0.1; Port=3306; Database=pediatrie; Uid=root; Pwd=sandu2002;";
            MySqlConnection cnn = new MySqlConnection(connect_string);
            cnn.Open();

            String insert_string =
                "insert into radiografii " +
                "(CNP, Data, Nume_imagine, Diagnostic, Comentarii) " +
                "values (@cnp, @da, @n, @di, @c);";

            MySqlCommand msc = new MySqlCommand(insert_string, cnn);

            msc.Parameters.AddWithValue("@cnp", CNPTextBox.Text);
            msc.Parameters.AddWithValue("@da", dateTimePicker1.Value.ToString("yyyy-MM-dd"));
            msc.Parameters.AddWithValue("@n", imagineTextBox.Text);
            msc.Parameters.AddWithValue("@di", diagnosticTextBox.Text);
            msc.Parameters.AddWithValue("@c", comentariiRichTextBox.Text);

            msc.ExecuteNonQuery();
            cnn.Close();

            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}

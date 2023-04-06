using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace WindowsFormsApp1
{
    public partial class Autentificare : Form
    {
        // members

        private int user_idx;
        List<Credential> credentials;

        public Autentificare()
        {
            InitializeComponent();
        }

        // load (deserialize) credentials data from json file
        public void deserializeCredentials(String json_filename)
        {
            

            String jsonString = File.ReadAllText(json_filename);

            credentials = JsonSerializer.Deserialize<List<Credential>>(jsonString);

            // display usernames in ComboBox
            foreach (Credential c in credentials)
            {
                userComboBox.Items.Add(c.Username);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            user_idx = userComboBox.SelectedIndex;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            deserializeCredentials("credentials.json");
            
            

        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            // if credentials not entered
            if (String.IsNullOrEmpty(userComboBox.Text) || String.IsNullOrEmpty(passTextBox.Text))
            {
                MessageBox.Show("Introduceti credentialele !", "Atentie", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            
            // if password doesn't match
            if (passTextBox.Text != credentials[user_idx].Password)
            {
                MessageBox.Show("Parola incorecta !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            MessageBox.Show("Autentificare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);

            Pacienti pacienti_form = new Pacienti();
            pacienti_form.ShowDialog();
        
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}

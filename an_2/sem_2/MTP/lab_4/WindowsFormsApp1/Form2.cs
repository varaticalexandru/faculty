using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        public static bool isValid(string cnp)
        {
            // verifica validitate cnp
            string defaultCnp = "279146358279";
            int sum = 0;
            int k = 0;  // defaultCnp counter

            for (int i = 0; i < 12; i++)
            {
                sum += int.Parse(cnp[i].ToString()) * int.Parse(defaultCnp[i].ToString());
            }

            bool condition_1 = Regex.IsMatch(cnp, "^[1256]\\d{12}$");
            bool condition_2 = int.Parse(cnp[cnp.Length - 1].ToString()) == sum % 11;

            return condition_1 && condition_2;
        }

        private void CNPTextBox_MouseLeave(object sender, EventArgs e)
        {
            if (CNPTextBox.Text.Length == 13)
                if (!isValid(CNPTextBox.Text))
                    MessageBox.Show("CNP invalid !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // update list of test files in testeComboBox
            foreach (var file_name in Directory.GetFiles(".", "*.txt"))
            {
                testeComboBox.Items.Add(Path.GetFileNameWithoutExtension(file_name));
                
            }
        }

        private void incepeTestulButton_Click(object sender, EventArgs e)
        {

            if (String.IsNullOrWhiteSpace(numeTextBox.Text) || String.IsNullOrWhiteSpace(testeComboBox.Text) || !isValid(CNPTextBox.Text))
            {
                MessageBox.Show("Date invalide !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            string nume = numeTextBox.Text.Trim();
            string filename = testeComboBox.Text.Trim();

            Form1 form1= new Form1(nume, filename);
            form1.ShowDialog();
        }
    }
}

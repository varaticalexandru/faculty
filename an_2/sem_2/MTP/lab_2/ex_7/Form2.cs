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

namespace ex_7
{
    public partial class JucatorNou : Form
    {


        // ShowDialog overload (ComboBox, denumire echipa)
        public void ShowDialog(ref ComboBox echipaComboBox, ref FlowLayoutPanel jucatoriFlowLayoutPanel)
        {
            this.echipaComboBox.Text = echipaComboBox.Text;
            this.ShowDialog();
        }

        


        public JucatorNou()
        {
            InitializeComponent();
        }

        private void JucatorNou_Load(object sender, EventArgs e)
        {
            
            
        }

        private void adaugaJucatorButton_Click(object sender, EventArgs e)
        {
            // citire date
            string nume = numeTextBox.Text;
            string pozitie = postComboBox.Text;
            string cnp = CNPTextBox.Text;

            // instantiere clasa Jucator
            Jucator jucator = new Jucator(nume, cnp, Jucator.stringToPost(pozitie));

            // creare buton cu numele jucatorului
            Button btn = new Button();
            btn.Text = nume;
            btn.Width = 200;
            btn.Tag = jucator;

            // path dir echipa
            string path = Application.StartupPath + "\\" + echipaComboBox.Text;

            // filename
            string filename = CNPTextBox.Text + ".lpf";

            // scriere in fisier
            File.WriteAllText(path + "\\" + filename, nume + "\n" + pozitie);


            MessageBox.Show("Creeare cu succes !", "Succes", MessageBoxButtons.OK, MessageBoxIcon.Information);

        }
    }
}

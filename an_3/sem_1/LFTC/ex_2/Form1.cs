using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Resources.ResXFileRef;

namespace ex_2
{
    public partial class Form1 : Form
    {
        ConversionHandler converter = new ConversionHandler();

        public Form1()
        {
            InitializeComponent();
        }

        private void computeMACButton_Click(object sender, EventArgs e)
        {
            MACHandler mh = new MACHandler(algorithmComboBox.Text);
            byte[] mac = mh.computeMAC(converter.StringToByteArray(ASCIIPlainTextTextBox.Text), converter.StringToByteArray(ASCIIKeyTextBox.Text));
            ASCIIMACTextBox.Text = converter.ByteArrayToString(mac);
            HEXMACTextBox.Text = converter.ByteArrayToHexString(mac);

            ASCIIHashTextBox.Text = converter.ByteArrayToString(mh.computeHash(converter.StringToByteArray(ASCIIPlainTextTextBox.Text)));
        }

        private void verifyMACButton_Click(object sender, EventArgs e)
        {
            MACHandler mh = new MACHandler(algorithmComboBox.Text);
            if (mh.checkAuthenticity(converter.StringToByteArray(ASCIIPlainTextTextBox.Text), converter.HexStringToByteArray(HEXMACTextBox.Text), converter.StringToByteArray(ASCIIKeyTextBox.Text)) == true)
            {
                System.Windows.Forms.MessageBox.Show("MAC OK !!!");
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("MAC NOT OK !!!");
            }

        }
    }
}

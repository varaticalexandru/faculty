using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApplication20;

namespace test_sapt_3
{
    public partial class Form1 : Form
    {
        ConversionHandler myConverter = new ConversionHandler();
        SymmetricAlgorithm mySymmetricAlg;
        MD5CryptoServiceProvider myMD5 = new MD5CryptoServiceProvider();
        RandomNumberGenerator rnd = RandomNumberGenerator.Create();

        public Form1()
        {
            InitializeComponent();
        }

        public void generate()
        {
            // DES
            mySymmetricAlg = DES.Create();

            mySymmetricAlg.GenerateIV();
            mySymmetricAlg.GenerateKey();
        }

        public byte[] Encrypt(byte[] mess)
        {
            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms, mySymmetricAlg.CreateEncryptor(), CryptoStreamMode.Write);
            cs.Write(mess, 0, mess.Length);
            cs.Close();
            return ms.ToArray();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            generate();

            // DES
            byte[] ciphertext = Encrypt(myConverter.StringToByteArray(ASCIIPlainTextTextBox.Text));
            DESCipherTextTextBox.Text = myConverter.ByteArrayToString(ciphertext);

            // MD5
            byte[] hash = myMD5.ComputeHash(ciphertext);
            MD5HashTextBox.Text = myConverter.ByteArrayToString(hash);


        }
    }
}

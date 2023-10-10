using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Security.Cryptography;
using System.IO;

namespace WindowsFormsApplication20
{
    public partial class Form1 : Form
    {
        ConversionHandler myConverter = new ConversionHandler();
        SymmetricAlgorithm mySymmetricAlg;

        public Form1()
        {
            InitializeComponent();
        }

        public void generate(string cipher)
        {
            switch (cipher)
            {
                case "DES":
                    mySymmetricAlg = DES.Create();
                    break;
                case "3DES":
                    mySymmetricAlg = TripleDES.Create();
                    break;
                case "Rijndael":
                    mySymmetricAlg = Rijndael.Create();
                    break;
            }
            mySymmetricAlg.GenerateIV();
            mySymmetricAlg.GenerateKey();
        }

        public byte[] Encrypt(byte[] mess, byte[] key, byte[] iv)
        {
            mySymmetricAlg.Key = key;
            mySymmetricAlg.IV = iv;
            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms, mySymmetricAlg.CreateEncryptor(), CryptoStreamMode.Write);
            cs.Write(mess, 0, mess.Length);
            cs.Close();
            return ms.ToArray();
        }

        public byte[] Decrypt(byte[] mess, byte[] key, byte[] iv)
        {
            byte[] plaintext = new byte[mess.Length];
            mySymmetricAlg.Key = key;
            mySymmetricAlg.IV = iv;
            MemoryStream ms = new MemoryStream(mess);
            CryptoStream cs = new CryptoStream(ms, mySymmetricAlg.CreateDecryptor(), CryptoStreamMode.Read);
            cs.Read(plaintext, 0, mess.Length);
            cs.Close();
            return plaintext;
        }

        private void generateKeyAndIVbutton_Click(object sender, EventArgs e)
        {
            generate(cipherComboBox.Text);
            keyTextBox.Text = myConverter.ByteArrayToHexString(mySymmetricAlg.Key);
            ivTextBox.Text = myConverter.ByteArrayToHexString(mySymmetricAlg.IV);
        }

        private void encryptButton_Click(object sender, EventArgs e)
        {
            byte[] ciphertext =
            Encrypt(myConverter.StringToByteArray(plainASCIITextBox.Text),
            myConverter.HexStringToByteArray(keyTextBox.Text),
            myConverter.HexStringToByteArray(ivTextBox.Text));

            cipherASCIITextBox.Text = myConverter.ByteArrayToString(ciphertext);
            cipherHEXTextBox.Text = myConverter.ByteArrayToHexString(ciphertext);
            plainHEXTextBox.Text = myConverter.ByteArrayToHexString(myConverter.StringToByteArray(plainASCIITextBox.Text));
        }

        private void decryptButton_Click(object sender, EventArgs e)
        {
            byte[] plaintext =
            Decrypt(myConverter.HexStringToByteArray(cipherHEXTextBox.Text),
            myConverter.HexStringToByteArray(keyTextBox.Text),
            myConverter.HexStringToByteArray(ivTextBox.Text));

            plainASCIITextBox.Text = myConverter.ByteArrayToString(plaintext);

            plainHEXTextBox.Text = myConverter.ByteArrayToHexString(plaintext);
        }

        private void getEncryptTimeButton_Click(object sender, EventArgs e)
        {
            // mySymmetricAlg.GenerateIV(); // generates a fresh IV
            // mySymmetricAlg.GenerateKey(); // generates a fresh Key
            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms, mySymmetricAlg.CreateEncryptor(), CryptoStreamMode.Write);
            byte[] mes_block = new byte[8];
            long start_time = DateTime.Now.Ticks;
            int count = 10000000;
            for (int i = 0; i < count; i++)
            {
                cs.Write(mes_block, 0, mes_block.Length);
            }
            cs.Close();
            double operation_time = (DateTime.Now.Ticks - start_time);
            operation_time = operation_time / (10 * count); // 1 tick is 100 ns,i.e., 1/10 of 1 us
            encryptionTimeTextBox.Text = operation_time.ToString() + " us";
        }

        private void getDecryptTimeButton_Click(object sender, EventArgs e)
        {
            byte[] plaintext = new byte[myConverter.HexStringToByteArray(cipherHEXTextBox.Text).Length];

            MemoryStream ms = new MemoryStream(myConverter.HexStringToByteArray(cipherHEXTextBox.Text));
            CryptoStream cs = new CryptoStream(ms, mySymmetricAlg.CreateDecryptor(), CryptoStreamMode.Read);

            long start_time = DateTime.Now.Ticks;

            byte[] mes_block = new byte[8];
            int count = 10000000;

            for (int i = 0; i < count; i++)
            {
                cs.Read(mes_block, 0, mes_block.Length);
            }

            cs.Read(plaintext, 0, myConverter.HexStringToByteArray(cipherHEXTextBox.Text).Length);
            cs.Close();
            double operation_time = (DateTime.Now.Ticks - start_time);
            operation_time = operation_time / (10 * count); // 1 tick is 100 ns,i.e., 1/10 of 1 us
            decryptionTimeTextBox.Text = operation_time.ToString() + " us";
        }



    }
}

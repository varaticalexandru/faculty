using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            RSACryptoServiceProvider myrsa = new RSACryptoServiceProvider(1600);
            System.Diagnostics.Stopwatch swatch = new
           System.Diagnostics.Stopwatch();
            int size;
            int count = 100;
            swatch.Start();
            for (int i = 0; i < count; i++)
            {
                myrsa = new RSACryptoServiceProvider(2048);
                size = myrsa.KeySize;
            }
            swatch.Stop();
            /*Console.WriteLine("Generation time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");*/
            MessageBox.Show("Generation time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");

            byte[] plain = new byte[20];
            byte[] ciphertext = myrsa.Encrypt(plain, true);
            swatch.Reset();
            swatch.Start();

            for (int i = 0; i < count; i++)
            {
                ciphertext = myrsa.Encrypt(plain, true);
            }
            swatch.Stop();
            /*Console.WriteLine("Encryption time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");*/
            MessageBox.Show("Encryption time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");
            swatch.Reset();
            swatch.Start();
            for (int i = 0; i < count; i++)
            {
                plain = myrsa.Decrypt(ciphertext, true);
            }
            swatch.Stop();
            /*Console.WriteLine("Decryption time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");*/
            MessageBox.Show("Decryption time at 1024 bit ... " + (swatch.ElapsedTicks / (10 * count)).ToString() + " ms");

        }
    }
}

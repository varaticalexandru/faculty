using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ex_2
{
    internal class MACHandler
    {

        private HMAC myHMAC;

        private HashAlgorithm myHashAlgorithm; // MD5, SHA1, SHA256, SHA384, SHA512, RIPEMD160

        HMAC MyHmac { get; set; }

        HashAlgorithm MyHashAlgorithm { get; set; }

        public MACHandler(string hashFunctionName)
        {
            switch (hashFunctionName)
            {
                case "SHA1":
                    this.myHMAC = new HMACSHA1();
                    this.myHashAlgorithm = new SHA1CryptoServiceProvider();
                    break;

                case "MD5":
                    this.myHMAC = new HMACMD5();
                    this.myHashAlgorithm = new MD5CryptoServiceProvider();
                    break;

                case "RIPEMD":
                    this.myHMAC = new HMACRIPEMD160();
                    this.myHashAlgorithm = new RIPEMD160Managed();
                    break;

                case "SHA256":
                    this.myHMAC = new HMACSHA256();
                    this.myHashAlgorithm = new SHA256CryptoServiceProvider();
                    break;

                case "SHA384":
                    this.myHMAC = new HMACSHA384();
                    this.myHashAlgorithm = new SHA384CryptoServiceProvider();
                    break;

                case "SHA512":
                    this.myHMAC = new HMACSHA512();
                    this.myHashAlgorithm = new SHA512CryptoServiceProvider();
                    break;

            }
        }

        public void setHashFunction(string hashFunctionName)
        {
            switch (hashFunctionName)
            {
                case "SHA1":
                    this.myHMAC = new HMACSHA1();
                    break;

                case "MD5":
                    this.myHMAC = new HMACMD5();
                    break;

                case "RIPEMD":
                    this.myHMAC = new HMACRIPEMD160();
                    break;

                case "SHA256":
                    this.myHMAC = new HMACSHA256();
                    break;

                case "SHA384":
                    this.myHMAC = new HMACSHA384();
                    break;

                case "SHA512":
                    this.myHMAC = new HMACSHA512();
                    break;

            }
        }

        public bool checkAuthenticity(byte[] mes, byte[] mac, byte[] key)
        {
            myHMAC.Key = key;
            if (compareByteArrays(myHMAC.ComputeHash(mes), mac, myHMAC.HashSize / 8) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public byte[] computeMAC(byte[] mes, byte[] key)
        {
            myHMAC.Key = key;
            return myHMAC.ComputeHash(mes);
        }

        public byte[] computeHash(byte[] mes)
        {
            return myHashAlgorithm.ComputeHash(mes);
        }

        public bool compareByteArrays(byte[] a, byte[] b, int length)
        {
            for (int i = 0; i < length; i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }
            return true;
        }

        public int MACByteLength()
        {
            return myHMAC.HashSize / 8;
        }
    }
}

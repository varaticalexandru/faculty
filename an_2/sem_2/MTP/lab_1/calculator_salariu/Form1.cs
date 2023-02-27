using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void calculeazaButton_Click(object sender, EventArgs e)
        {
            

            try
            {
                // daca salariul contine cel putin o litera
                if (Regex.Match(salariuBrutTextBox.Text, "[a-zA-Z]").Success)
                    throw new Exception("Eroare ! Salariul nu poate contine litere !");

                string salariuBrut_ = salariuBrutTextBox.Text;
                float salariuBrut = float.Parse(salariuBrutTextBox.Text);

                // calcul date
                // angajat
                float cfsAngajat = (float) (salariuBrut * 0.005);
                float casAngajat = (float) (salariuBrut * 0.105);
                float cassAngajat = (float) (salariuBrut * 0.055);
                float impozitAngajat = (float) ((salariuBrut - cfsAngajat - casAngajat - cassAngajat - 180) * 0.16);

                // angajator
                float casAngajator = (float) (salariuBrut * 0.208);
                float cfsAngajator = (float) (salariuBrut * 0.05);
                float cfci = (float) (salariuBrut * 0.085);
                float cfgpcs = (float) (salariuBrut * 0.0025);
                float cassAngajator = (float) (salariuBrut * 0.052);
                float cfambp = (float) (salariuBrut * 0.004);

                // scriere date
                cfsTextBox.Text = cfsAngajat.ToString();
                casTextBox.Text = casAngajat.ToString();
                cassTextBox.Text = cassAngajat.ToString();
                impozitTextBox.Text = impozitAngajat.ToString();

                casAngajatorTextBox.Text = casAngajator.ToString();
                cfsAngajatorTextBox.Text = cfsAngajator.ToString();
                cfciAngajatorTextBox.Text = cfci.ToString();
                cfgpcsAngajatorTextBox.Text = cfgpcs.ToString();
                cassAngajatorTextBox.Text = cassAngajator.ToString();
                cfambpAngajatorTextBox.Text = cfambp.ToString();

                // afisare salariu brut cu cuvinte
                string salariuWord = ConvertNumber(salariuBrut_);
                MessageBox.Show($"Salariul brut:\n{salariuWord}", "Salariul brut", MessageBoxButtons.OK, MessageBoxIcon.Information);


            }
            catch (Exception error)
            {
                MessageBox.Show(error.Message, "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                // throw;
            }

            
        }

        private static String unitati(String Number)
        {
            int _Number = Convert.ToInt32(Number);
            String name = "";
            switch (_Number)
            {
                
                case 1:
                    name = "Una";
                    break;
                case 2:
                    name = "Doa";
                    break;
                case 3:
                    name = "Trei";
                    break;
                case 4:
                    name = "Patru";
                    break;
                case 5:
                    name = "Cinci";
                    break;
                case 6:
                    name = "Sase";
                    break;
                case 7:
                    name = "Sapte";
                    break;
                case 8:
                    name = "Opt";
                    break;
                case 9:
                    name = "Noua";
                    break;
            }
            return name;
        }

        private static String zeci(String Number)
        {
            int _Number = Convert.ToInt32(Number);
            String name = null;
            switch (_Number)
            {
                case 10:
                    name = "Zece";
                    break;
                case 11:
                    name = "Unsprezece";
                    break;
                case 12:
                    name = "Doisprezece";
                    break;
                case 13:
                    name = "Treisprezece";
                    break;
                case 14:
                    name = "Patrusprezece";
                    break;
                case 15:
                    name = "Cincisprezece";
                    break;
                case 16:
                    name = "Saisprezece";
                    break;
                case 17:
                    name = "Saptesprezece";
                    break;
                case 18:
                    name = "Optsprezece";
                    break;
                case 19:
                    name = "Nouasprezece";
                    break;
                case 20:
                    name = "Douazeci";
                    break;
                case 30:
                    name = "Treizeci";
                    break;
                case 40:
                    name = "Patruzeci";
                    break;
                case 50:
                    name = "Cincizeci";
                    break;
                case 60:
                    name = "Saizeci";
                    break;
                case 70:
                    name = "Saptezeci";
                    break;
                case 80:
                    name = "Optzeci";
                    break;
                case 90:
                    name = "Nouazeci";
                    break;
                default:
                    if (_Number > 0)
                    {
                        // apel recursiv
                        name = zeci(Number.Substring(0, 1) + "0") + " si " + unitati(Number.Substring(1));
                    }
                    break;
            }
            return name;
        }


        private static String ConvertNumber(String Number)
        {
            string word = "";

            try
            {
                bool beginsZero = false;    //tests for 0XX    
                bool isDone = false;    //test if already translated    
                int intNumber = (Convert.ToInt32(Number));
                   
                if (intNumber > 0)
                {//test for zero or digit zero in a nuemric    
                    beginsZero = Number.StartsWith("0");

                    int numDigits = Number.Length;  // length
                    int pos = 0;//store digit grouping    
                    String place = "";//digit grouping name: mii,sute, zeci, etc
                                      //
                    switch (numDigits)
                    {
                        case 1: // domeniu unitati 
                            word = unitati(Number);
                            isDone = true;
                            break;

                        case 2: // domeniu zeci
                            word = zeci(Number);
                            isDone = true;
                            break;

                        case 3: // domeniu sute 
                            pos = (numDigits % 3) + 1;
                            place = " Sute ";
                            break;

                        // domeniu mii
                        case 4:     
                        case 5:
                        case 6:
                            pos = (numDigits % 4) + 1;
                            place = " Mii ";
                            break;
                        
                        // domeniu milioane
                        case 7:
                        case 8:
                        case 9:
                            pos = (numDigits % 7) + 1;
                            place = " Millioane ";
                            break;
                        
                        // domeniu miliarde
                        case 10:    
                        case 11:
                        case 12:
                            pos = (numDigits % 10) + 1;
                            place = " Miliarde ";
                            break;

                        // caz extra pentru > miliard
                        default:
                            isDone = true;
                            break;
                    }

                    // daca transformarea nu e gata => apel recursiv)    
                    if (!isDone)
                    {
                        if (Number.Substring(0, pos) != "0" && Number.Substring(pos) != "0")
                        {
                            try
                            {
                                word = ConvertNumber(Number.Substring(0, pos)) + place + ConvertNumber(Number.Substring(pos));
                            }
                            catch { }
                        }
                        // base case
                        else
                        { 
                            word = ConvertNumber(Number.Substring(0, pos)) + ConvertNumber(Number.Substring(pos));
                        }

                        //check for trailing zeros    
                        //if (beginsZero) word = " and " + word.Trim();    
                    }
                    //ignore digit grouping names    
                    if (word.Trim().Equals(place.Trim())) word = "";
                }
            }
            catch { }
            return word.Trim();
        }



    }


}

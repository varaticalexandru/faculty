

/*
    - Fisierele unu.txt si doi.txt contin pe mai multe linii cate un cuvant. 
    
    - Sa se concateneze continutul celor doua fisiere in fisierul trei.txt.  
 */

using System.IO;

// citire
string text_unu = File.ReadAllText("unu.txt");
string text_doi = File.ReadAllText("doi.txt");

// scriere
using StreamWriter sw = new StreamWriter("trei.txt");
sw.WriteLine(text_unu);
sw.WriteLine(text_doi);

sw.Close();

Console.WriteLine("Scriere cu succes. Iesire . . .");

Console.Read();
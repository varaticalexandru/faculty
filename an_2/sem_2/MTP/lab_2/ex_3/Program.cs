using System.IO;
using System.Numerics;

/*
    Fisierul date.in contine mai multe numere pe mai multe linii. Sa se ordoneze crescator sirul 
    de numere si sa se tipareasca in fisierul date.out.
*/

List<int> list = new List<int>();

// citire
string[] lines = File.ReadAllLines("date.in");

foreach (var line in lines)
{
    list.Add(int.Parse(line));
}

// sortare
list.Sort();

// scriere
using StreamWriter sw = new StreamWriter("date.out");

foreach(var number in list)
{
    sw.WriteLine(number.ToString());
}


// sw.Close();

Console.WriteLine("Scriere terminata. Iesire . . . ");
Console.Read();


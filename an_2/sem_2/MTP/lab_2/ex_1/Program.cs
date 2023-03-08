

/*
     - Se citeste un numar natural n

     - Sa se scrie in fisierul patrate.in toate patratele numerelor 
        naturale cuprinse intre 1 si n. 
*/

void writeSquares(int n)
{
    int[] squares = new int[n];

    using StreamWriter sw = new StreamWriter("patrate.in");

    for(int i = 0; i < n-1; i++)
    {
        squares[i] = (i + 1) * (i + 1);         // calculare patrat
        sw.WriteLine(squares[i].ToString());    // scriere in fisier
    }

    //sw.Close();
}


Console.Write("n: ");

int n = int.Parse(Console.ReadLine());

writeSquares(n);

Console.WriteLine("Scriere cu succes. Incheiere program . . . ");

Console.ReadKey();

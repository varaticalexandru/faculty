#include <iostream>

using namespace std;

class Carte
{
    string titlu;
    string autor;
    string editura;
    int an_pub;

    public:
        Carte(string titlu="", string autor="", string editura="", int an_pub=0)
        {
            this->titlu = titlu;
            this->autor = autor;
            this->editura = editura;
            this->an_pub = an_pub;
        }
        
        friend ostream & operator << (ostream &, Carte &);
        friend istream & operator >> (istream &, Carte &);

};

ostream & operator << (ostream & out, Carte & c)
{
    out << "Titlu: " << c.titlu << endl;
    out << "Autor: " << c.autor << endl;
    out << "Editura: " << c.editura << endl;
    out << "An publicare: " << c.an_pub << endl;
    out << endl;

    return out;
}


istream & operator >> (istream & in, Carte & c)
{
    cout << "Titlu: ";
    getline(in, c.titlu);

    cout << "Autor: ";
    getline(in, c.autor);

    cout << "Editura: ";
    getline(in, c.editura);

    cout << "An publicare: ";
    in >> c.an_pub;

    cout << "\n";

    return in;
}


int main(int argc, char** argv)
{
    Carte obj;

    cin >> obj;

    cout << obj;


    return 0;
}
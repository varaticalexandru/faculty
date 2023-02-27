#include <iostream>

using namespace std;

class Baza
{
    int pret;

    public:
        int static suma;
        int static contor;

        // constructor
        Baza(int pret)
        {
            this->pret = pret;
            contor++;
        }

        // afiseaza contorul si pretul
        virtual void Afisare()
        {
            cout << "pret: " << pret << "\t" << "contor: " << contor << endl;
        }

        // calculeaza suma
        void static inc(Baza* p)
        {
            suma += p->pret;
        }
};

// init membri statici
int Baza::suma = 0;
int Baza::contor = 0;


int main(int argc, char** argv)
{
    Baza* p1 = new Baza(5);
    p1->Afisare();
    Baza::inc(p1);
    cout << "suma: " << Baza::suma << endl << endl;

    Baza* p2 = new Baza(7);
    p2->Afisare();
    Baza::inc(p2);
    cout << "suma: " << Baza::suma << endl << endl;

    Baza* p3 = new Baza(7);
    p3->Afisare();
    Baza::inc(p3);
    cout << "suma: " << Baza::suma << endl << endl;

    return 0;
}
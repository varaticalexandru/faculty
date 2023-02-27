#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Menu()
{
    cout << "Meniu Interactiv" << endl;
    cout << "0. Iesire" << endl;
    cout << "1. Introducere articol" << endl;
    cout << "2. Afisarea articolelor dupa producator" << endl;
    cout << "3. Afisarea articolelor cu pret anumit" << endl;
    cout << "4. Stergerea articolelor cu producator anumit" << endl;
    cout << "Optiunea dvs: ";
};

// clasa de baza
class Electronic
{
    protected:
        string producator;
        int pret;

        Electronic(string producator, int pret)
        {
            this->producator = producator;
            this->pret = pret;
        }

        void PrintPP()
        {
            cout << "Producator: " << producator << "Pret: " << pret;
        }
 
};

// clase derivate
class Aragaz : protected Electronic 
{
    string culoare;

    public:
        Aragaz(string producator, int pret, string culoare) : Electronic(producator, pret)
        {
            this->culoare = culoare;
        }

        void PrintA()
        {
            PrintPP();
            cout << "Culoare: " << culoare << endl;
        }
};

class Cuptor : public Electronic
{
    int putere;

    public:
        Cuptor(string producator, int pret, int putere) : Electronic(producator, pret)
        {
            this->putere = putere;
        }

        void PrintC()
        {
            PrintPP();
            cout << "Putere" << putere << endl;
        }
};

typedef enum optiuni {
    iesire = 0,
    introducere = 1,
    afisare_producator = 2,
    afisare_pret = 3,
    sterge_producator = 4
} optiuni;


int main(int argc, char** argv)
{
    optiuni opt;

    Aragaz a1("sanya", 200, "black");
    Cuptor c1("vanya", 300, 1500);

    a1.PrintA();
    c1.PrintC();
    


    // do
    // {
    //     Menu();
    //     scanf("%d", &opt);

    //     switch (opt)
    //     {
    //     case iesire:
    //         exit(EXIT_SUCCESS);    
    //     break;

    //     case introducere:

    //     break;
        
    //     case afisare_producator:

    //     break;
        
    //     case afisare_pret:

    //     break;

    //     case sterge_producator:

    //     break;

    //     default:
    //         cout << "Eroare. Optiune nedefinita." << endl;
    //     break;
    //     }





    // } while (opt);
    





}
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class carte
{   
    public:
        string autor;
        string titlu;
        int imprumutat; // imprumutat: 1, neimprumutat: 0

        carte(string, string, int);
        virtual void afisare() {};
};


// constructor
carte::carte(string autor, string titlu, int imprumutat)
{
    this->autor = autor;
    this->titlu = titlu;
    this->imprumutat = imprumutat;
}


class tehnica : public carte
{
    int nr_ex;
    string limba;
    int an;

    tehnica* prim;
    tehnica* urm;

    public:
        tehnica(string, string, int, int, string, int);

        void afisare();
        void adaugare();
};


// constructor
tehnica::tehnica(string autor, string titlu, int imprumutat, int nr_ex, string limba, int an) :
    carte(autor, titlu, imprumutat)
{
    prim = NULL;
    this->nr_ex = nr_ex;
    this->limba = limba;
    this->an = an;
}

void tehnica::adaugare()
{
    string autor, titlu, limba;
    int imprumutat, nr_ex, an;

    cin.get();
    cout << "Autor: ";
    getline(cin, autor);

    cout << "Titlu: ";
    getline(cin, titlu);

    cout << "Stare (0-neimprumutata, 1-imprumutata): ";
    cin >> imprumutat;

    cout << "Nr. exemplare: ";
    cin >> nr_ex;

    cin.get();
    cout << "Limba: ";
    getline(cin, limba);

    cout << "An: ";
    cin >> an;

    tehnica* c = new tehnica(autor, titlu, imprumutat, nr_ex, limba, an);
    c->urm = tehnica::prim;
    prim = c;
}

void tehnica::afisare()
{   
    tehnica* c = tehnica::prim;

    while (c) {
        cout << "______________________\n";
        cout << "Autor: " << c->autor << endl;
        cout << "Titlu: " << c->titlu << endl;
        cout << "Stare (0-neimprumutata, 1-imprumutata): " << c->imprumutat << endl;
        cout << "Nr. exemplare: " << c->nr_ex << endl;
        cout << "Limba: " << c->limba << endl;
        cout << "An: " << c->an << endl;
        cout << "______________________\n";

        c = c->urm;
    }
}


class literatura : public carte 
{
    string tip_carte;

    literatura* prim;
    literatura* urm;

    public:
        literatura(string, string, int, string);
        void afisare();
        void adaugare();
};


// constructor
literatura::literatura(string autor, string titlu, int imprumutat, string tip_carte) : 
    carte(autor, titlu, imprumutat) 
{    
    prim = NULL;
    this->tip_carte = tip_carte;
}


void literatura::adaugare()
{   
    string autor, titlu, tip_carte;
    int imprumutat;

    cin.get();
    cout << "Autor: ";
    getline(cin, autor);

    cout << "Titlu: ";
    getline(cin, titlu);

    cout << "Stare (0-neimprumutata, 1-imprumutata): ";
    cin >> imprumutat;

    cin.get();
    cout << "Tip: ";
    getline(cin, tip_carte);

    literatura* c = new literatura(autor, titlu, imprumutat, tip_carte);
    c->urm = literatura::prim;
    prim = c;
}

void literatura::afisare()
{   
    literatura* c = literatura::prim;

    while (c) {
        cout << "______________________\n";
        cout << "Autor: " << c->autor << endl;
        cout << "Titlu: " << c->titlu << endl;
        cout << "Stare (0-neimprumutata, 1-imprumutata): " << c->imprumutat << endl;
        cout << "Tip: " << c->tip_carte << endl;
        cout << "______________________\n";

        c = c->urm;
    }
}

void Menu()
{
    cout << "\n0. Iesire" << endl;
    cout << "1. Adaugare carte tehnica" << endl;
    cout << "2. Afisare carte literatura" << endl;
    cout << "3. Afisare carti tehnice" << endl;
    cout << "4. Afisare carti literatura" << endl;
    cout << "Optiune: ";
}

int main()
{
    unsigned opt;
    tehnica* t = new tehnica("", "", 0, 0, "", 0);
    literatura* l = new literatura("", "", 0, "");

    system("cls");

    do
    {
        Menu();
        cin >> opt;
        cout << endl << endl;

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:
            t->adaugare();
        break;

        case 2:
            l->adaugare();
        break;
        
        case 3:
            t->afisare();
        break;

        case 4:
            l->afisare();
        break;

        default:
            cout << "Eroare. Optiune nedefinita.\n";
        break;
        }
    } while (opt);
    

    getchar();
    return 0;
}
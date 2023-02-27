#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class carte{
    
    public:
        string autor;
        string titlu;
        int imprumutat;

        carte* prim;
        carte* urm;

        carte(string, string, int);
        void adaugare();
        void afisare();
};


carte::carte(string autor, string titlu, int imprumutat){
    // constructor

    this->autor = autor;
    this->titlu = titlu;
    this->imprumutat = imprumutat;

    urm = NULL;
}

void carte::adaugare(){
    // adaugare nod la inceputul listei

    cin.get();
    cout << "autor: ";
    getline(cin, autor);

    
    cout << "titlu: ";
    getline(cin, titlu);

    cout << "stare (0-imprumutata, 1-neimprumutata): ";
    cin >> imprumutat;

    carte* c = new carte(autor, titlu, imprumutat);
    c->urm = prim;
    prim = c;
}

void carte::afisare(){
   carte* c = prim;

   while (c) {
    cout<< "____________" << endl;
    cout << "Titlu: " << c->titlu << endl;
    cout << "Autor: " << c->autor << endl;
    cout << "Imprumutat: " << c->imprumutat;
    cout<< "\n____________" << endl;
    
    c = c->urm;
   }
}

void Menu(){
    cout << "\n1. Adaugare carte" << endl;
    cout << "2. Afisare carte" << endl;
    cout << "0. Iesire" << endl;
    cout << "Optiune: " << endl;
}


int main()
{
    carte* c = new carte("", "", 0);
    int opt;

    do {
        Menu();
        cin >> opt;

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:
            // adaugare
            c->adaugare();
        break;

        case 2:
            // afisare
            c->afisare();
        break;
        
        default:
            cout << "Eroare.\n";
        break;
        }
    } while (opt);


    getchar();
    return 0;
}
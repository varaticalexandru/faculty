#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

class Electronic
{
    private:
        int pret;
        string producator;

    public:
        Electronic();
        Electronic(int pret, string producator)
        {
            this->pret = pret;
            this->producator = producator;
        }

        void AfisareEl()
        {
            cout << "Producator: " << producator << "\n";
            cout << "Pret: " << pret << "\n";
        }

        int getPret()
        {
            return pret;
        }

        string getProducator()
        {
            return producator;
        }
 
};

class Aragaz : public Electronic
{
    private:
        string culoare;

    public:
        Aragaz();
        Aragaz(int pret, string producator, string culoare) : Electronic(pret, producator)
        {
            this->culoare = culoare;
        }

        void AfisareAr()
        {
            Electronic::AfisareEl();
            cout << "Culoare: " << culoare << "\n";
        }

};

class Cuptor : public Electronic
{
    private:
        int putere;       

    public:
        Cuptor();
        Cuptor(int pret, string producator, int putere) : Electronic(pret, producator)
        {
            this->putere = putere;
        }

        void AfisareCu()
        {
            Electronic::AfisareEl();
            cout << "Putere: " << putere << "\n";
        }
        
};

typedef enum optiuni {
    iesire = 0,
    introducere = 1,
    afisare_prod = 2,
    afisare_pret = 3,
    sterge_prod = 4
} optiuni;

void Menu()
{
    cout << "\n\nMeniu Interactiv" << endl;
    cout << "0. Iesire" << endl;
    cout << "1. Introducere articol" << endl;
    cout << "2. Afisarea articolelor dupa producator" << endl;
    cout << "3. Afisarea articolelor cu pret anumit" << endl;
    cout << "4. Stergerea articolelor cu producator anumit" << endl;
    cout << "\nOptiunea dvs: ";
};

typedef enum tip {
    aragaz = 0,
    cuptor = 1
} tip;

void AddEl(Electronic** v, int* n)
{
    string prod, cul;
    int pret, put, opt;

    cout << "Tip (0-aragaz, 1-cuptor): ";
    cin >> opt;

    cin.get();
    cout << "Producator: ";
    getline(cin, prod);

    cout << "Pret: ";
    cin >> pret;

    cin.get();

    switch (opt)
    {
    case aragaz:
        cout << "Culoare: ";
        getline(cin, cul);
        v[*n] = new Aragaz(pret, prod, cul);
        (*n)++;
    break;

    case cuptor:
        cout << "Putere: ";
        cin >> put;
        v[*n] = new Aragaz(pret, prod, cul);
        (*n)++;
    break;
    
    default:
        cout << "Eorare. Optiune nedefinita.\n";
    break;
    }

}

void AfisProd(Electronic** v, int n)
{
    Electronic* aux = NULL;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (v[i]->getProducator() > v[j]->getProducator()) {
                aux =v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]:\n";
        v[i]->AfisareEl();
        cout << "\n";
    }
    
}

void AfisPret(Electronic** v, int n)
{

    int pret;

    cout << "Pretul cautat: ";
    cin >> pret;

    for (int i = 0; i < n; i++)
        if (v[i]->getPret() == pret) {
            cout << "[" << i << "]:\n";
            v[i]->AfisareEl();
            cout << "\n";
        }
    
}

void StergeProd(Electronic** v, int *n)
{
    string prod;
    int gasit = 0;

    cout << "Producatorul produsului sters: ";
    cin.get();
    getline(cin, prod);

    for (int i = 0; i < *n; i++) {
        if (v[i]->getProducator().compare(prod) == 0) {
            gasit = 1;
            for (int j = i; j < *n; j++)
                v[j] = v[j+1];
            (*n)--;
        }
    }

    if (!gasit) {
        cout << "Produs/e inexistente.\n";
    }

    for (int i = 0; i < *n; i++) {
        cout << "[" << i << "]:\n";
        v[i]->AfisareEl();
        cout << "\n";
    }
}

int main()
{
    Electronic* v[20];
    int n = 0;
    optiuni opt;

    do {
        Menu();
        scanf("%d", &opt);
        cout << "\n";

        switch (opt)
        {
        case iesire:
            exit(EXIT_SUCCESS);
        break;

        case introducere:
            AddEl(v, &n);
        break;

        case afisare_prod:
            AfisProd(v, n);
        break;

        case afisare_pret:
            AfisPret(v, n);
        break;  

        case sterge_prod:
            StergeProd(v, &n);
        break;

        
        default:
            cout << "Eroare. Optiune nedefinita.\n";  
        break;
        }
    }
    while (opt);
    


    return 0;
}
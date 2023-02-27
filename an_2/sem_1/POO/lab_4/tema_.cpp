#include <iostream>
#include <string.h>

using namespace std;

int i, j;

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
class ProdusElectr
{
private:
    int pret;
    string producator;

protected:
public:
    virtual void Afisare()
    {
        cout << "Producator: " << producator << endl;
        cout << "Pret: " << pret << endl;
    }
    ProdusElectr();
    ProdusElectr(int Pret, string Producator)
    {
        pret = Pret;
        producator = Producator;
    }
    string getProducator()
    {
        return producator;
    }
    int getPret()
    {
        return pret;
    }
};

// clase derivate
class Microunde : public ProdusElectr
{
private:
    int putere;

public:
    Microunde();
    Microunde(int Pret, string Producator, int Putere) : ProdusElectr(Pret, Producator)
    {
        putere = Putere;
    }
    void setPutere(int Putere)
    {
        putere = Putere;
    }
    int getPutere()
    {
        return putere;
    }
    void Afisare()
    {
        ProdusElectr::Afisare();
        cout << "Putere: " << putere << endl;
    }
};
class Aragaz : public ProdusElectr
{
private:
    string culoare;

public:
    Aragaz();
    Aragaz(int Pret, string Producator, string culoare) : ProdusElectr(Pret, Producator)
    {
        this->culoare = culoare;
    }
    void setCuloare(string Culoare)
    {
        culoare = Culoare;
    }
    string getCuloare()
    {
        return culoare;
    }

    void Afisare()
    {
        ProdusElectr::Afisare();
        cout << "Culoare: " << culoare << endl;
    }
};

typedef enum optiuni {
    iesire = 0,
    introducere = 1,
    afisare_producator = 2,
    afisare_pret = 3,
    sterge_producator = 4
} optiuni;



int main()
{
    optiuni opt;
    ProdusElectr *arr[20];
    ProdusElectr *aux;
    int liber = 0;
    string n, culoare, pren;
    int pret, putere, ok_, ok;
    do
    {
        Menu();
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:

            cout << "Aragaz-1, Cuptor-2" << endl;
            cout << "Optiunea dvs: " << endl;
            scanf("%d", &opt);
            if (opt == 1)
            {
                cin.get();
                cout << "Producator: ";
                getline(cin, n);
                cout << "Pret: ";
                cin >> pret;
                cout << "Putere: ";
                cin >> putere;
                arr[liber] = new Microunde(pret, n, putere);
                liber++;
                break;
            }
            else if (opt == 2)
            {
                cin.get();
                cout << "Producator: ";
                getline(cin, n);
                cout << "Pret: ";
                cin >> pret;
                cout << "Culoare: ";
                cin >> culoare;
                arr[liber] = new Aragaz(pret, n, culoare);
                liber++;
                break;
            }
            else
            {
                cout << "Eroare, optiune nedefinita." << endl;
                break;
            }
            break;
        case 2:
            for (int i = 0; i < liber; i++)
            {
                for (j = i + 1; j < liber; j++)
                {
                    if (arr[i]->getProducator() > arr[j]->getProducator())
                    {
                        aux = arr[i];
                        arr[i] = arr[j];
                        arr[j] = aux;
                    }
                }
            }
            for (i = 0; i < liber; i++)
            {
                arr[i]->Afisare();
            }

            break;
        case 3:
            fflush(stdin);
            cin.get();
            cout << "Pret cautat: ";
            cin >> pret;
            for (int i = 0; i < liber; i++)
            if (arr[i]->getPret() == pret)
                {
                    cout << "Produs gasit" << endl;
                    ok = 1;
                }
            if (ok == 0)
                cout << "Nu exista produsul" << endl;

            break;
        case 4:
            cin.get();
            cout << "Numele produsul sters: ";
            getline(cin, pren);
            for (int i = 0; i < liber; i++)
                if (pren.compare(arr[i]->getProducator()) == 0)
                {
                    for (int j = i; j < liber; j++)
                        arr[j] = arr[j + 1];
                    liber--;
                    ok_ = 1;
                }
            if (ok_ == 0)
                cout << "Producator inexistent." << endl;
            break;

        default:
            cout << "Optiune gresita. Eroare." << endl;
            break;
        }
    } while (1);
}
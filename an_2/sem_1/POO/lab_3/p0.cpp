#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// clasa baza
class Persoana
{
   string nume;
   string prenume;
   unsigned int varsta;

    public:
        // constructor vid pt declararea vectorului
        Persoana() {}

        // constructor pt init. var.
        Persoana(string nume, string prenume, unsigned int varsta)
        {
            this->nume = nume;
            this->prenume = prenume;
            this->varsta = varsta;
        }

        // functie de afisare
        void AfisPers()
        {
            cout << "Nume: " << nume << "\n";
            cout << "Prenume: " << prenume << "\n";
            cout << "Varsta: " << varsta << "\n";
        }

        // return nume pt functia de cautare
        string getNume() { return nume; }

        // return prenume pt functia de stergere
        string getPrenume() { return prenume; }
};

// clasa derivata (Persoana)
class Angajat : public Persoana
{
    unsigned int salariu;
    string departament;

    public:
        // constructor vid pt declararea vectorului
        Angajat() {}

        // constructor pt init var
        Angajat(string nume, string prenume, unsigned int varsta, unsigned int salariu, string departament) : Persoana(nume, prenume, varsta)
        {
            this->salariu = salariu;
            this->departament = departament;
        }
        
        // functia de afisare
        void AfisareAng()
        {
            Persoana::AfisPers();
            cout << "Salariu: " << salariu << "\n";
            cout << "Departament: " << departament << "\n";
            cout << "\n";
        }

};

void CitireAngajati(Angajat* a, int* nr)
{
    string n, p, d;
    int i, v, s;

    cout << "Numarul de angajati: ";
    cin >> *nr;
    
    for (i = 0; i < *nr; i++){

        // citire info pt fiecare angajat

        cout << "\nAngajat " << i << "\n";
        cin.get();
        cout << "Nume: ";
        getline(cin, n);

        cout << "Prenume: ";
        getline(cin, p);

        cout << "Varsta: ";
        cin >> v;

        cin.get();
        cout << "Departament: ";
        getline(cin, d);

        cout << "Salariu: ";
        cin >> s;

        // apelare constructor pt fiecare angajat
        a[i] = Angajat(n, p, v, s, d);
    }
}

void AfisareAngajati(Angajat* a, int nr)
{
    int i;

    for (i = 0; i < nr; i++){
        cout << "[" << i << "]:\n";
        a[i].AfisareAng();
    }

    cout << "\n";
}

void CautareAngajat(Angajat* a, int nr)
{
    string nume;
    int gasit = 0;

    cin.get();    
    cout << "Dati numele cautat: ";
    getline(cin, nume);

    for (int i = 0; i < nr; i++)
        if (!(nume.compare(a[i].getNume()))) {
            gasit = 1;
            cout << "Angajat gasit.\n";
            cout << "[" << i << "]:\n";
            a[i].AfisareAng();
        }

    if (!gasit) {
        cout << "Angajat inexistent.\n";
    }
}

void StergereAngajat(Angajat* a, int* nr)
{
    string prenume;
    int gasit = 0;

    cin.get();
    cout << "Prenumele angajatului sters: ";
    getline(cin, prenume);

    for (int i = 0; i < *nr; i++)
        if (!(prenume.compare(a[i].getPrenume())))
        {
            gasit = 1;

            for (int j = i; j < *nr; j++)
                a[j] = a[j+1];

            (*nr)--;
        }

    if (!gasit)
        printf("Angajat inexistent.");
}

void Menu()
{
    cout << "\nMeniu Interactiv\n";
    cout << "0. Iesire\n";
    cout << "1. Introducere angajati\n";
    cout << "2. Afisare angajati\n";
    cout << "3. Cautare angajati\n";
    cout << "4. Stergere angajati\n\n";
    cout << "Optiunea dvs: ";
}

int main()
{
   Angajat angajati[20];
   int nr;
   int opt;

   system("cls");
   do {
        Menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:
            // iesire
            exit(EXIT_SUCCESS);
        break;

        case 1:
            // citire
            CitireAngajati(angajati, &nr);
        break;

        case 2:
            // afisare
            AfisareAngajati(angajati, nr);
        break;

        case 3:
            // cautare
            CautareAngajat(angajati, nr);
        break;

        case 4:
            // stergere
            StergereAngajat(angajati, &nr);
        break;
        
        default:
            cout << "Eroare. Optiune nedefinita.\n";
        break;
        }

   } while (opt);


    return 0;
}
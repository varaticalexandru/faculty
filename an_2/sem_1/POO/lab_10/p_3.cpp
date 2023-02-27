#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
    Să se realizeze un program care să gestioneze următoarele informații despre articolele 
dintr-un magazin. Se va folosi STL (Standard Template Library).

- Telefon Fix cu următoarele variable: Producător, Culoare, Dimensiune 
- Telefon Mobil cu următoarele variabile: Producător, Culoare, Sistem operare.

Creaţi din informaţiile date o clasă de bază şi două clase derivate şi implementaţi 
următoarele funcţii prin intermediul unui meniu interactiv, folosind 
container/containere din STL (Standard Template Library):

1. Citirea din fișier
2. Adaugarea de informatii in gestiunea magazinului 
3. Afisarea stocului și salvarea în fișier
4. Vânzarea unui articol
5. Căutarea unui articol după producător
6. Ieșire.
*/

// clasa de baza telefon
class telefon
{
private:

protected:
    int tip;
    string producator;
    string culoare;

public:
    telefon(int tip, string producator, string culoare);
    virtual void afisare();
    string getProducator() { return producator; }
    int getTip() { return tip; }
    string getCuloare() { return culoare; }
    virtual string getDimensiune() { return " "; }
    virtual string getSistemOperare() { return " "; }
};


// constructor
telefon::telefon(int tip, string producator, string culoare)
{
    this->tip = tip;
    this->producator = producator;
    this->culoare = culoare;
}

// afiare data telefon
void telefon::afisare()
{
    cout << "\nProducator: " << producator << "\n";
    cout << "Culoare: " << culoare << "\n";
}




// clasa derivata telefon fix
class fix : public telefon
{
private:
    string dimensiune;

protected:

public:
    fix(int tip, string producator, string culoare, string dimensiune); 
    void afisare();
    string getDimensiune() { return dimensiune; }
};

// constructor
fix::fix(int tip, string producator, string culoare, string dimensiune) : telefon(tip, producator, culoare)
{
    this->dimensiune = dimensiune;
}

// afisare date telefon fix
void fix::afisare()
{
    telefon::afisare();
    cout << "Dimensiune: " << dimensiune << "\n\n";
}






// clasa derivata telefon mobil
class mobil : public telefon
{
private:
    string sistem_operare;

protected:

public:
    mobil(int tip, string producator, string culoare, string sistem_operare);
    void afisare();
    string getSistemOperare() { return sistem_operare; }
};

// constructor
mobil::mobil(int tip, string producator, string culoare, string sistem_operare) : telefon(tip, producator, culoare)
{
    this->sistem_operare = sistem_operare;
}

// afisare date telefon mobil
void mobil::afisare()
{
    telefon::afisare();
    cout << "Sistem operare: " << sistem_operare << "\n";
}




// citire date telefon
telefon* citireTelefon(int tip)
{
    string producator, culoare;
    telefon* p = NULL;

    cout << "\n-- Inserati date telefon --\n";

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);

    cout << "Culoare: ";
    cin.get();
    getline(cin, culoare);

    if (!tip) {     // fix
        string dimensiune;
        fix* a = NULL;

        cout << "Dimensiune: ";
        cin.get();
        getline(cin, dimensiune);

        a = new fix(tip, producator, culoare, dimensiune);
        p = a;
        return p;
    }
    else {    // mobil
        string sistem_operare;
        mobil* q = NULL;

        cout << "Sistem operare: ";
        cin.get();
        getline(cin, sistem_operare);

        q = new mobil(tip, producator, culoare, sistem_operare);
        p = q;
        return p;
    }
}

// citire data din fisier
void citireFisier(vector <telefon*>* v)
{
    ifstream f;
    char tip;
    string producator, culoare;
    telefon* p = NULL;
    
    f.open("file.txt");

    if (f.is_open()) {
        cout << "\nFisier deschis cu succes.\n";

        while (!f.eof()) {
            f >> tip;
            f >> producator;
            f >> culoare;

            if (tip == 'f') {                   // telefon fix
                string dimensiune;
                fix* a = NULL;
                
                f >> dimensiune;

                a = new fix(0, producator, culoare, dimensiune);
                p = a;

                v->push_back(p);
            }
            else if (tip == 'm') {              // telefon mobil
                string sistem_operare;
                mobil* q = NULL;

                f >> sistem_operare;

                q = new mobil(1, producator, culoare, sistem_operare);
                p = q;

                v->push_back(p);
            }
        }

        cout << "\nCitire date din fisier cu succes.\n";
    }
    else
        cout << "\nEroare la deschiderea fisierului.\n";
}

// salvare date in fisier
void salvareFisier(vector <telefon*>* v)
{
    ofstream f;
    fix* q;
    mobil* a;
    telefon* p;


    f.open("file_out.txt");

    if (f.is_open()) {
        cout << "Fisier deschis cu succes.\n";

        vector <telefon*>::iterator i;

        for (i = v->begin(); i != v->end(); i++) {

            if (!(*i)->getTip())
                f << "f ";
            else
                f << "m ";

            f << (*i)->getProducator() << " ";
            f << (*i)->getCuloare() << " ";
            
            if ((*i)->getTip() == 'f')      // fix
                f << (*i)->getDimensiune();
            else                            // mobil
                f << (*i)->getSistemOperare();

            f << "\n";
        }
                
        cout << "\nSalvare date in fisier cu succes.\n";
    }
    else
        cout << "Eroare deschidere fisier.\n";
}

// vanzare articol
void vanzareArticol(vector <telefon*>* v)
{
    string nume;
    int flag = 0;

    cout << "Inroduceti nume producator articol vandut: ";
    cin.get();
    getline(cin, nume);

    vector <telefon*>::iterator i;

    for (i = v->begin(); i != v->end(); i++)
        if ((*i)->getProducator() == nume) {
            flag = 1;
            cout << "\nTelefon gasit.\n";
            v->erase(i);
            cout << "Vanzare cu succes.\n";
        }

    if (!flag) {
        cout << "\nTelefon inexistent.\n";
        cout << "Vanzare esuata.\n";
    }
}

void menu()
{
    cout << "\n----------- Meniu Interactiv -----------\n";
    cout << "1. Citirea datelor din fisier\n";
    cout << "2. Adaugarea de info in gestiunea magazinului\n";
    cout << "3. Afisarea stocului si salvarea datelor in fisier\n";
    cout << "4. Vanzarea unui articol\n";
    cout << "5. Cautarea unui articol dupa producator\n";
    cout << "6. Iesire\n";
    cout << "--------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

int main(int argc, char *argv[])
{
    int opt;
    vector <telefon*> v;

    do
    {
        menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 1:     // citire date din fisier
        {
            citireFisier(&v);
        }    
        break;

        case 2:     // adaugare informatii in gestiunea magazinului
        {
            telefon* p = NULL;
            int tip;

            cout << "Tip(0-fix, 1-mobil): ";
            cin >> tip;

            if (!tip)
                p = citireTelefon(0);
            else if (tip == 1)
                p = citireTelefon(1);

            v.push_back(p);
        }    
        break;

        case 3:     // afisarea stocului si salvarea datelor in fisier
        {
            cout << "\n-- Stoc Disponibil --\n";
            for (auto i: v)
                i->afisare();

            salvareFisier(&v);
        }    
        break;

        case 4:     // Vanzarea unui articol
        {
            vanzareArticol(&v);
        }    
        break;

        case 5:     // Cautarea unui articol dupa producator
        {
            
        }    
        break;

        case 6:     // iesire
        {
            exit(EXIT_SUCCESS);
        }    
        break;

        default:
        {
            cout << "Eroare. Optiune nedefinita.\n";
        }    
        break;
        }
    } while (opt != 6);
    
    fgetc(stdin);

    return 0;
}
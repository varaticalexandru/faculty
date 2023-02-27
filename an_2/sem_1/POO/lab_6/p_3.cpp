#include <iostream>

using namespace std;

/*
    Realizaţi un program care să gestioneze următoarele informaţii despre articolele dintr-un magazin foto:

    Rama foto cu următoarele variabile: Producător, Preţ, Rezoluţia, Diagonala, Format afişare;
    Aparat foto cu următoarele variabile: Producător, Preţ, Rezoluţia, Tip aparat (compact, D-SLR), Tip senzor.

    Creaţi din informaţiile date o clasă de bază şi două clase derivate şi implementaţi următoarele 
    funcţii prin intermediul unui meniu interactiv, cu liste simplu înlănţuite:

    1. Adăugare ramă foto într-o listă, ordonat.
    2. Adăugare aparat foto într-o listă, ordonat.
    3. Afişare rame foto.
    4. Afişare aparat foto.
    5. Ieşire
*/

class Lista;

class Produs
{
    string producator;
    float pret;
    int rezolutie;

    Produs* next;

    public:
        // constructor
        Produs(string producator, float pret, int rezolutie)
        {
            this->producator = producator;
            this->pret;
            this->rezolutie = rezolutie;
            this->next = NULL;
        }
        
        virtual void Afisare()
        {
            cout << "Producator: " << producator << endl;
            cout << "Pret: " << pret << endl;
            cout << "Rezolutie: " << rezolutie << endl;
        }

        friend class Lista;
};

class Rama : public Produs
{
    float diagonala;
    string format_afis;

    public:
        // constructor
        Rama(string producator, float pret, int rezolutie, float diagonala, string format_afis)
            : Produs(producator, pret, rezolutie)
        {
            this->diagonala = diagonala;
            this->format_afis = format_afis;
        }
        
        void Afisare()
        {
            Produs::Afisare();
            cout << "Diagonala: " << diagonala << endl;
            cout << "Format afis: " << format_afis << endl << endl;
        }

        friend class Lista;
};


class Aparat : public Produs
{
    string tip_aparat;
    string tip_senzor;

    public:
        Aparat(string producator, float pret, int rezolutie, string tip_aparat, string tip_senzor)
            : Produs(producator, pret, rezolutie)
        {
            this->tip_aparat = tip_aparat;
            this->tip_senzor = tip_senzor;
        }

        void Afisare()
        {
            Produs::Afisare();
            cout << "Tip aparat: " << tip_aparat << endl;
            cout << "Tip senzor: " << tip_senzor << endl << endl;
        }

        friend class Lista;
};

class Lista
{
    public:
        Produs* head;

        void Adaugare(Produs* a)     // adaugare ordonata in lista (dupa producator)
        {
            Produs* p = head;

            if (!p)     // daca lista e vida
                head = a;
            else {
                if (a->producator < p->producator) {    // daca nodul inserat < capul listei
                    head = a;
                    a->next = p;
                }
                
                // cautam pozitia pentru inserat
                while (p->next && p->next->producator < a->producator)
                    p = p->next;
                
                // inseram
                a->next = p->next;
                p->next = a;
            }
        }
        
        void AfisareLista()        // afisare lista
        {
            Produs* p = head;

            if (!p)
                cout << "Lista e vida.\n";
            else {
                while (p) {
                    p->Afisare();
                    p = p->next;
                }
            }
        }
};

void Menu()
{
    cout << "\n----------------- Meniu -----------------\n";
    cout << "1. Adaugare rama fota in lista, ordonat dupa producator\n";
    cout << "2. Adaugare aparat foto in lista, ordonat dupa producator\n";
    cout << "3. Afisare articole din magazin\n";
    cout << "------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

// introducere info in nod, apoi in lista
void Introducere(Lista &L, int sel)
{
    Produs* p = NULL;
    string producator, format_afis, tip_aparat, tip_senzor;
    float pret, diagonala;
    int rezolutie;

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);

    cout << "Pret: ";
    cin >> pret;

    cout << "Rezolutie: ";
    cin >> rezolutie;

    if (sel == 0){
        // Rama

        cout << "Diagonala: ";
        cin >> diagonala;

        cout << "Format afis: ";
        cin.get();
        getline(cin, format_afis);

        Rama* r = new Rama(producator, pret, rezolutie, diagonala, format_afis);
        p = r;
        L.Adaugare(p);
    }
    
    if (sel == 1){
        // Aparat

        cout << "Tip aparat: ";
        cin.get();
        getline(cin, tip_aparat);

        cout << "Tip senzor: ";
        cin.get();
        getline(cin, tip_senzor);

        Aparat* a = new Aparat(producator, pret, rezolutie, tip_aparat, tip_senzor);
        p = a;
        L.Adaugare(p);
    }

}

int main(int argc, char** argv)
{
    Lista L;
    L.head = NULL;
    int opt;

    do
    {
        Menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:     // adaugare rama foto in lista ordonata
            Introducere(L, 0);
        break;

        case 2:     // adaugare aparat foto in lista ordonata
            Introducere(L, 1);
        break;

        case 3:     // afisare lista
            L.AfisareLista();
        break;

        default:
            cout << "Eroare.\n";
        break;
        }



    } while (opt);
    




    return 0;
}
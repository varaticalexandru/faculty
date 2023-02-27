#include <iostream>
#include <string>

using namespace std;

class Lista;

class Articol
{
    int tip_derivat;    // 0 - scaner, 1 - imprimanta

    string producator;
    int cod_produs;
    string rezolutie;
    string dimensiuni;

    Articol* next;

    public:
        // constructor
        Articol(int tip_derivat, string producator, int cod_produs, string rezolutie, string dimensiuni)
        {
            this->producator = producator;
            this->cod_produs = cod_produs;
            this->rezolutie = rezolutie;
            this->dimensiuni = dimensiuni;
            this->next = NULL;
        }

        virtual void Afisare()
        {
            cout << "Producator: " << producator << endl;
            cout << "Cod produs: " << cod_produs << endl;
            cout << "Reezolutie: " << rezolutie << endl;
            cout << "Dimensiuni: " << dimensiuni << endl;
        }

    friend class Lista;
};



class Scaner : public Articol
{
    string soft_inclus;
    int viteza_scan;

    public:
        // constructor
        Scaner(int tip_derivat, string producator, int cod_produs, string rezolutie, string dimensiuni, 
                string soft_inclus, int viteza_scan
        )   
            : Articol(tip_derivat, producator, cod_produs, rezolutie, dimensiuni)
        {
            this->soft_inclus = soft_inclus;
            this->viteza_scan = viteza_scan;
        }

        void Afisare()
        {
            Articol::Afisare();
            cout << "Soft inclus: " << soft_inclus << "\n";
            cout << "Viteza scanare: " << viteza_scan << "\n";
        }

    friend class Lista;
};



class Imprimanta : public Articol
{
    string format;
    string tip;

    public:
        // constructor
        Imprimanta(int tip_derivat, string producator, int cod_produs, string rezolutie, string dimensiuni,
                    string format, string tip
        )
            : Articol(tip_derivat, producator, cod_produs, rezolutie, dimensiuni)
        {
            this->format = format;
            this->tip = tip;
        }


        void Afisare()
        {
            Articol::Afisare();
            cout << "Format: " << format << "\n";
            cout << "Tip: " << tip << "\n\n";
        }

    friend class Lista;
};


class Lista
{
    public:

        Articol* head;

        void Adaugare(Articol* a)   // adaugare nod in lista ordonata (dupa producator)
        {
            Articol* p = head;

            if (!p)     // daca lista e vida
                head = a;
            else {
                if (a->producator < p->producator) {    // daca nodul adaugat < capul listei
                    a->next = head;
                    head = a;
                }

                // gasim locul pentru inserarea nodului
                while (p->next && p->next->producator < a->producator)
                    p = p->next;

                // insearm nodul
                a->next = p->next;
                p->next = a;
            }
        }

        void Afisare()
        {
            Articol* p = head;

            if (!p)
                cout << "Eroare. Lista e vida.\n";
            else{
                while (p){
                    p->Afisare();
                    p = p->next;
                }
            }
        }
};


class Overload  // clasa pt. supraincarcarea operatorilor
{
    public:
        string producator;
        int cod_produs;
        string rezolutie;
        string dimensiuni;

        friend ostream & operator << (ostream &, Overload &);
        friend istream & operator >> (istream &, Overload &);
};

// supraincarcare operator de scriere (afisarea unui mesaj)
ostream & operator << (ostream & out, Overload & a)
{
    cout << "Vom citi datele pentru scanere si imprimante:" << endl;
    cout << endl;

    return out;
}

// supraincarcare operator de citire (citirea datelor clasei de baza)
istream & operator >> (istream & in, Overload & a)
{
    cout << "Producator: ";
    cin >> a.producator;

    cout << "Cod de produs: ";
    cin >> a.cod_produs;

    cout << "Rezolutie: ";
    cin >> a.rezolutie;

    cout << "Dimensiuni: ";
    cin >> a.dimensiuni;

    return in;
}


// introducere info in nod, nod in lista
void Introducere(Lista & L, int sel)
{
    int tip_derivat;    // 0 - scaner, 1 - imprimanta

    string soft_inclus;
    int viteza_scan;

    string format;
    string tip;

    Articol *p = NULL;     // pointer la clasa de baza

    Overload ol;

    cout << ol;     // supraincarcarea scrierii
    cin >> ol;      // supraincarcarea citirii


    if (!sel){      // scaner

        cout << "Soft inclus: ";
        cin.get();
        getline(cin, soft_inclus);

        cout << "Viteza scanare: ";
        cin >> viteza_scan;

        Scaner* s = new Scaner(sel, ol.producator, ol.cod_produs, ol.rezolutie, ol.dimensiuni, soft_inclus, viteza_scan);
        p = s;
        L.Adaugare(p);
    }
    else if (sel == 1){     // imprimanta

        cout << "Format: ";
        cin.get();
        getline(cin, format);

        cout << "Tip: ";
        cin.get();
        getline(cin, tip);

        Imprimanta* i = new Imprimanta(sel, ol.producator, ol.cod_produs, ol.rezolutie, ol.dimensiuni, format, tip);
        p = i;
        L.Adaugare(p);
    }

}


void Menu()
{
    cout << "--------------------- Meniu Interactiv ---------------------\n";
    cout << "0. Iesire\n";
    cout << "1. Adaugare scanere in lista, ordonat dupa producator\n";
    cout << "2. Adaugare imprimante in lista, ordonat dupa producator\n";
    cout << "3. Afisare articole din magazin\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Optiunea dvs: ";
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

        case 1:     // adaugare scaner
            Introducere(L, 0);
        break;

        case 2:     // adaugare imprimanta
            Introducere(L, 1);
        break;

        case 3:     // afisare lista
            L.Afisare();
        break;
        
        default:
            cout << "Eroare. Optiune nedefinita\n";
        break;
        }
    } while (opt);
    

    return 0;
}
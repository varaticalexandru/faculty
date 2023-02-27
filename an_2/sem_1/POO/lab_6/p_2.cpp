#include <iostream>
#include <string>

using namespace std;

/*
    Realizaţi un program care să gestioneze următoarele informaţii despre articolele dintr-un magazin:
    Scanere cu următoarele variabile: Producător, Cod produs, Rezoluţie, Dimensiuni, Soft_inclus, 
    Viteza_scanare(sec/pagina) 
    Imprimante cu următoarele variabile: Producător, Cod produs, Rezoluţie, Dimensiuni, Format 
    (A3/A4), Tip (Color/Monocrom)
    Creaţi din informaţiile date o clasă de bază şi două clase derivate şi implementaţi următoarele funcţii 
    prin intermediul unui meniu interactive, cu liste simplu înlănţuite:
    1. Adăugare scanere în lista, ordonat după producător.
    2. Adăugare imprimante în lista, ordonat după producător.
    3. Afişare articole din magazin.
    4. Afisare scanere cu un anumit Soft_inclus citit de la tastatură. 
    5. Ştergere articol după producător.
    6. Ieşire
*/



class Lista;

class Produs    // clasa de baza
{
    int tip_derivat;    // 0 - scaner, 1 - imprimanta
    string producator;
    int cod_produs;

    Produs* next;

    public:
        // constructor
        Produs(int tip_derivat, string producator, int cod_produs)
        {
            this->tip_derivat = tip_derivat;
            this->producator = producator;
            this->cod_produs = cod_produs;
            next = NULL;
        }
        
        virtual void Afisare()  // afisare elemente clasa de baza
        {
            cout << "\nProducator: " << producator << endl;
            cout << "Cod produs: " << cod_produs << endl;
        }

        friend class Lista;     
};

// clasa derivata din Produs
class Scaner : public Produs
{
    string soft_inclus;
    float viteza_scanare;

    public:
        // constructor
        Scaner(int tip_derivat, string producator, int cod_produs,
                string soft_inclus, float viteza_scanare        
        ) 
            : Produs(tip_derivat, producator, cod_produs)
        {
            this->soft_inclus = soft_inclus;
            this->viteza_scanare = viteza_scanare;
        }

        // afisare element din clasa Scaner
        void Afisare()
        {
            Produs::Afisare();
            cout << "Soft inclus: " << soft_inclus << endl;
            cout << "Viteza scanare: " << viteza_scanare << endl << endl;
        }

        friend class Lista;
};


// clasa derivata din Produs
class Imprimanta : public Produs
{
    string format;
    string tip;

    public:
        // constructor
        Imprimanta(int tip_derivat, string producator, int cod_produs,
                    string format, string tip
        )
            :  Produs(tip_derivat, producator, cod_produs)
        {
            this->format = format;
            this->tip = tip;
        }
        
        // afisare element din clasa Imprimanta
        void Afisare()
        {
            Produs::Afisare();
            cout << "Format: " << format << endl;
            cout << "Tip: " << tip << endl << endl;
        }

        friend class Lista;
};

// clasa Lista
class Lista
{
    public:
        Produs* head;   // capul listei
        void Adaugare(Produs*); // adaugare ordonata in lista
        void AfisareLista();         // afisare 
};

// adaugare ordonata in lista
void Lista::Adaugare(Produs* a)
{
    // a - nodul adaugat
    Produs* p = NULL;   // p - nod parcurgere

    p = head;

    if (!p) {    // daca lista e vida
        head = a;
    }
    else {
        if (a->producator < p->producator) {    // daca nodul inserat < capul listei
            head = a;
            a->next = p;
        }

        while (p->next && p->next->producator < a->producator)  // iteram lista pentru a gasit pozitia pentru isertie
            p = p->next;
        
        a->next = p->next;
        p->next = a; 
    }
}

void Lista::AfisareLista()
{
    Produs* p;

    p = head;

    if (!p) {   // daca lista e vida
        cout << "Lista e vida !\n";
    }
    else
        while (p) {
            p->Afisare();
            p = p->next;
        }
}

// introducere info in nod, apoi in lista
void Introducere(Lista &L, int sel)
{
    int tip_derivat, cod_produs;
    string producator, soft_inclus, format, tip;
    float viteza_scanare;
    Produs* p;

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);
    
    cout << "Cod produs: ";
    cin >> cod_produs;

    switch (sel)
    {
    case 0:     // scaner 
        Scaner* s;

        cout << "Soft inclus: ";
        cin.get();
        getline(cin, soft_inclus);

        cout << "Viteza scanare: ";
        cin >> viteza_scanare;

        s = new Scaner(sel, producator, cod_produs, soft_inclus, viteza_scanare);
        p = s;  // cast pentru clasa de baza
        L.Adaugare(p);  // se adauga nodul
    break;
    
    case 1:     // imprimanta 
        Imprimanta* i;

        cout << "Format: ";
        cin.get();
        getline(cin, format);

        cout << "Tip: ";
        cin.get();
        getline(cin, tip);

        i = new Imprimanta(sel, producator, cod_produs, format, tip);
        p = i;  // cast pentru clasa de baza      
        L.Adaugare(p);  // se adauga nodul

    break;

    default:
        cout << "Eroare.\n";
    break;
    } 


}


void Menu()
{
    cout << "\n----------------- Meniu -----------------\n";
    cout << "1. Adaugare scanere in lista, ordonat dupa producator\n";
    cout << "2. Adaugare imprimante in lista, ordonat dupa producator\n";
    cout << "3. Afisare articole din magazin\n";
    cout << "------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

int main(int argc, char** argv)
{
    int opt;
    Lista L;
    L.head = NULL;

    do {
        Menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:
            Introducere(L, 0);
        break;

        case 2:
            Introducere(L, 1);
        break;

        case 3:
            L.AfisareLista();
        break;
        
        default:
            cout << "Eroare.\n";
        break;
        }
        
    } while (opt);


    return 0;
}
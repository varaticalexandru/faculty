#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyException
{
    public:
        int n;
        string s;
        
        MyException() { n = 0; s = ""; }
        MyException(int n, string s)
        {
            this->n = n;
            this->s = s;
        }
};

class Lista;

class Agentie
{
    int tip;

    string nume;
    int pret;
    int tenis;

    Agentie* next;

    public:
        // constuctor clasa de baza
        Agentie(int tip, string nume, int pret, int tenis)
        {
            this->tip = tip;
            this->nume = nume;
            this->pret = pret;
            this->tenis = tenis;
            this->next = NULL;
        }

        // afisare elemente din clasa de baza
        virtual void Afisare()
        {
            cout << endl;
            cout << "Nume: " << nume << endl;
            cout << "Pret: " << pret << endl;
            cout << "Tenis: " << tenis << endl;
        }

    friend class Lista;
};

// clasa derivata
class Hotel : public Agentie
{
    int nr_stele;
    int piscina;
    int sauna;

    public:
        // constructor clasa derivata
        Hotel(int tip, string nume, int pret, int tenis, 
                int nr_stele, int piscina, int sauna
        )
            : Agentie(tip, nume, pret, tenis)
        {
            this->nr_stele = nr_stele;
            this->piscina = piscina;
            this->sauna = sauna;
        }

        // afisare elemente din clasa derivata (Hotel)
        void Afisare()
        {
            Agentie::Afisare();
            cout << "Nr. stele: " << nr_stele << endl;
            cout << "Piscina: " << piscina << endl;
            cout << "Sauna: " << sauna << endl;
            cout << endl;
        }

    friend class Lista;
};

// clasa derivata
class Pensiune : public Agentie
{
    int nr_margarete;
    int gradina;

    public:
        // constructor clasa derivata (Pensiune)
        Pensiune(int tip, string nume, int pret, int tenis,
                    int nr_margarete, int gradina
        )
            : Agentie(tip, nume, pret, tenis)
        {
            this->nr_margarete = nr_margarete;
            this->gradina = gradina;
        }

        // afisare elemente clasa derivata (Pensiune)
        void Afisare()
        {
            Agentie::Afisare();
            cout << "Nr. margarete: " << nr_margarete << endl;
            cout << "Gradina: " << gradina << endl;
            cout << endl;
        }

    friend class Lista;
};


// clasa Lista
class Lista
{
    public:
        Agentie* head;  // capul listei

        void Adaugare(Agentie*);
        void AfisareLista();
};

void Lista::Adaugare(Agentie* a)
{   
    Agentie* p = NULL;

    p = head;

    if (!p)     // daca lista e vida, capul e nodul adaugat
        head = a;
    else {
        if (p->nume < a->nume) {    // daca nodul introdus < capul listei (primul nod din lista)
            a->next = p;
            head = a;
        }
        else {
            // gasim pozitia pentru insertia nodului
            while (p->next && a->nume < p->next->nume)
                p = p->next;

            // inseram nodul
            a->next = p->next;
            p->next = a;
        }
    }
}

void Lista::AfisareLista()
{
    Agentie* p = NULL;

    p = head;

    if (!p)
        cout << "Lista este vida. \n";
    else{
        while (p) {     // cat sunt elemente in lista
            p->Afisare();
            p = p->next;
        }
    }
}

// clasa pt. supraincarcare operatori
class Overload
{
    public:
        string nume;
        int pret;
        int tenis;

        friend istream & operator >> (istream &, Overload &);
};

// supraincarcare operator de citire (<<) pentru datele clasei de baza
istream & operator >> (istream & in, Overload & o)
{
    cout << "Nume: ";
    cin.get();
    getline(in, o.nume);

    LBL_try:
        try {
            cout << "Pret: ";
            in >> o.pret;

            if (o.pret < 0)
                throw MyException(o.pret, "Pretul nu este pozitiv");
        }
        catch (MyException e) {     // prinde eroarea
            cout << e.s << " : " << e.n << endl;
            goto LBL_try;
        }

    cout << "Tenis: ";
    in >> o.tenis;

    return in;
}

void Introducere(Lista & L, int sel)
{
    Agentie* p = NULL;
    Hotel* h = NULL;
    Pensiune* ps = NULL;

    Overload o;

    int nr_stele;
    int piscina;
    int sauna;

    int nr_margarete;
    int gradina;

    cin >> o;

    switch (sel)
    {
    case 0:     // introducere hotel
        cout << "Nr. stele: ";
        cin >> nr_stele;

        cout << "Piscina: ";
        cin >> piscina;

        cout << "Sauna: ";
        cin >> sauna;

        h = new Hotel(sel, o.nume, o.pret, o.tenis, nr_stele, piscina, sauna);
        p = h;      // cast pointer clasa de baza la clasa derivata
        L.Adaugare(p);
    break;

    case 1:     // introducere pensiune
        cout << "Nr. margarete: ";
        cin >> nr_margarete;

        cout << "Gradina: ";
        cin >> gradina;

        ps = new Pensiune(sel, o.nume, o.pret, o.tenis, nr_margarete, gradina);
        p = ps;     // cast pointer clasa de baza la clasa derivata
        L.Adaugare(p);
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita. \n";
    break;
    }


}

void Menu()
{
    cout << "-------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Adaugare oferta hotel\n";
    cout << "2. Adaugare oferta pensiune\n";
    cout << "3. Afisare oferte\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

int main(int argc, char** argv)
{
    int opt;
    Lista L;
    L.head = NULL;

    do
    {
        Menu();
        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 0:
            exit(EXIT_FAILURE);
        break;

        case 1:     // adaugare oferta hotel
            Introducere(L, 0);
        break;

        case 2:     // adaugare oferta pensiune
            Introducere(L, 1);
        break;

        case 3:     // afisare oferte
            L.AfisareLista();
        break;
        
        default:
            cout << "Eroare. Optiune nedefinita. \n";
        break;
        }
    } while (opt);
    

    return 0;
}
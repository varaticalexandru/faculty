#include <iostream>
#include <conio.h>

using namespace std;

class Nod {
    int info;
    Nod* urm;

    Nod* prim = NULL, *ultim = NULL;  

    public:
        void AfisareLista();
        void AdaugareInFata();
        void AdaugareInSpate();
        void AdaugareOrdonata();
        void StergereElement();
        void InserareDupaEl();
        void InserareInainteEl();
        void Ordonare();
        void InfoSwap(Nod*, Nod*);
};

void Nod::AfisareLista()
{
    Nod* q = prim;

    while (q) {
        cout << q->info << "\n";
        q = q->urm;
    }
}

void Nod::AdaugareInFata() {
    Nod* c;

    if (!prim) {
        // daca lista e vida
        prim = new Nod;
        cout << "Info: ";
        cin >> prim->info;

        // ultimul si primul nod coincid (la creare)
        ultim = prim;

        ultim->urm = NULL;
    }
    else {
        // se adauga la inceput
        c = new Nod;
        cout << "Info: ";
        cin >> c->info;

        c->urm = prim;
        prim = c; 
    }
}

void Nod::AdaugareInSpate() {
    Nod* c;

    if (!prim) {
        // daca lista e vida
        prim = new Nod;
        cout << "Info: ";
        cin >> prim->info;

        // ultimul si primul nod coincid (la creare)
        ultim = prim;
    }
    else {
         // se adauga la sfarsit
        c = new Nod;
        cout << "Info: ";
        cin >> c->info;

        ultim->urm = c;
        ultim = c;
    }

    ultim->urm = NULL;
}

void Nod::AdaugareOrdonata() {
    Nod *c, *q;
    int n;

    cout << "Info: ";
    cin >> n;

    if (!prim) {
        // daca lista e vida
        prim = new Nod;
        prim->info = n;
        ultim = prim;
        ultim->urm = NULL;
    }

    else if (n < prim->info) {
        // se adauga inaintea primului nod
        c = new Nod;
        c->info = n;

        c->urm = prim;
        prim = c;
    }

    
    else {
        // inserare pe parcurs
        q = prim;
        while (q->urm && (q->urm->info < n))
            q = q->urm;

        c = new Nod;
        c->info = n;

        c->urm = q->urm;
        q->urm = c;
    }
}

void Nod::StergereElement() {
    Nod *c = NULL;
    Nod *a = NULL;  // nodul sters
    int val;

    cout << "Info nod sters: ";
    cin >> val;

    c = prim;

    if (c->info == val) {
        // daca nodul sters este primul
        a = prim;
        prim = c->urm;
        delete a;
    }
    else {
        // daca nu e primul
        while (c->urm->info != val && c)
            c = c->urm;
        
        a = c->urm;
        c->urm = c->urm->urm;

        // daca se sterge ultimul nod
        if (!a)
            ultim = c;

        delete a;
    }
}

void Nod::InserareDupaEl()
{
    Nod *a = NULL;  // nod inserat
    Nod *c = NULL;
    int val;

    cout << "Info element dupa care inserati: ";
    cin >> val;

    c = prim;
    
    // verificam existenta informatiei in lista
    while (c) {
        if (c->info != val)
            c = c->urm;
        else
            break;
    }

    if (c) {
        c = prim;
        while (c->info != val && c->urm)
            c = c->urm;
        
        a = new Nod;
        cout << "Info: ";
        cin >> a->info;

        a->urm = c->urm;
        c->urm = a;

        // daca adaugam nodul la sfarsit
        if (c == ultim)
            ultim = a;
    }
    else
        cout << "Info nu exista.\n";
}

void Nod::InserareInainteEl()
{
    Nod *a = NULL;  // nod inserat
    Nod *c = NULL;
    int val;

    cout << "Info element inaintea caruia inserati: ";
    cin >> val;

    c = prim;

    // verificam existenta informatiei din lista
    while (c) {
        if (c->info != val)
            c = c->urm;
        else
            break;
    }

    if (c) {
        c = prim;
        
        if (c->info == val) {
            // daca inseram inaintea lui prim

            a = new Nod;
            cout << "Info: ";
            cin >> a->info;

            a->urm = c;
            prim = a;
        }
        else {
            // daca nu inseram inaintea lui prim

            while (c->urm->info != val && c)
                c = c->urm;
            
            a = new Nod;
            cout << "Info: ";
            cin >> a->info;

            a->urm = c->urm;
            c->urm = a;
        }
    }
    else
        cout << "Info nu exista.\n";
}

void Nod::InfoSwap(Nod* n1, Nod* n2)
{
    int aux = n1->info;
    n1->info = n2->info;
    n2->info = aux;
}



void Nod::Ordonare()
{
    int ok;
    Nod* c;

    do {
        ok = 1;
        c = prim;
        
        while (c->urm) {
            if (c->info > c->urm->info) {
                // info swap
                this->InfoSwap(c, c->urm);
                ok = 0;
            }

            c = c->urm;
        }
    } while(!ok);
}

int main()
{
    Nod lista;

    system("cls");

    lista.AdaugareInSpate();
    lista.AdaugareInSpate();
    lista.AdaugareInSpate();
    lista.AdaugareInSpate();

    lista.AfisareLista();

    lista.Ordonare();

    cout << endl;
    lista.AfisareLista();

    return 0;
}
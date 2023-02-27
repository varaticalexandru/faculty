#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

/*
Să se realizeze un program care să asigure gestiunea unei biblioteci universitare cu cărţi în 
diferite domenii (literatură, informatică, fizică, matematică, mecanică etc.). La fiecare carte se 
cunoaşte: autor, titlu, cota, editura, anul_apariţiei, nr_ediţie, împrumutată (câmp care poate lua 
următoarele valori:t 0 dacă nu este împrumutată şi data până când este împrumutată).
La pornirea aplicaţiei va fi afişat următorul meniu:
1. Încărcare bibliotecă dintr-un fişier.
2. Creare domeniu nou.
3. Adăugare carte la un anumit domeniu.
4. Căutare carte în bibliotecă.
5. Ştergere carte din bibliotecă.
6. Salvare în fişier a bibliotecii.
7. Ieşire
Aplicaţia va fi implementată folosind clase tipar.
*/

using namespace std;

class domeniu;
class carte;
class biblioteca;

typedef struct calendar{
    int zi, luna, an;
} calendar;




// clasa template lista
template <class T> class lista
{
private:
    T* root;
    T* point;

public:
    lista();
    ~lista();
    void adaugare(T* a);
    T* cautare(string nume);
    int stergere(string nume);
    T* prim();
    T* next();
    int vida();
    void elibereaza();
    void afisare();
};

// initializare radacina
template <class T> lista<T>::lista()
{   
    root = NULL;
}

// stergere lista
template <class T> void lista<T>::elibereaza()
{
    if (!root){
        cout << "Lista vida\n";
        return;
    }
    else {
        T* p, *q;
        for (p = root; p; p = q) {
            q = p->next;
            delete p;
        }
        root = NULL;
    }
}

// destructorul care sterge lista
template <class T> lista<T>::~lista()
{
    elibereaza();
}

// adaugare nod in lista (ordonata)
template <class T> void lista<T>::adaugare(T* a)
{
    if (!root)
        root = a;
    else {
        if (a->nume < root->nume) {     // daca nodul inserat < radacina (primul nod)
            a->next = root;
            root = a;
        }
        else {
            T* p;
            // cautare loc insertie
            for (p = root; p->next; p = p->next)
                if (p->next->nume > a->nume)
                    break;

            /*
                p = root;
                while (p->next && a->nume > p->next->nume) {
                    p = p->next;
                }
            */

            a->next = p->next;
            p->next = a;
        }

    }
}

// cautare nod in lista
template <class T> T* lista<T>::cautare(string nume)
{
    T* p = NULL;

    for (p = root; p; p = p->next)
        if (p->nume == nume)
            break;
    
    return p;
}

// stergere nod din lista
template <class T> int lista<T>::stergere(string nume)
{
    if (!root) {    // daca lista e vida
        cout << "Lista vida\n";
        return 0;
    }
    else if (root->nume == nume) {  // daca se sterge radacina (primul nod)
        T* q = NULL;
        
        q = root;
        root = root->next;
        delete q;

        return 1;
    }
    else {  // daca se sterge un nod in interiorul listei
        T *p = NULL;
        for (p = root; p->next; p = p->next) {
            if (p->next->nume == nume) {
                T* q = NULL;
                q = p->next;
                p = p->next->next;
                delete q;
                return 1;
            }
        }
    }

    return 0;
}

// returneaza radacina (primul nod)
template <class T> T* lista<T>::prim()
{
    point = root;
    return point;
}

// returneaza urmatorul nod
template <class T> T* lista<T>::next()
{
    if (point)
        point = point->next;
    return point;
}

// returneaza daca lista (radacina) este vida
template <class T> int lista<T>::vida()
{
    return (!root) ? 1 : 0;
}

// afiseaza lista
template <class T> void lista<T>::afisare()
{
    T* p;
    for (p = root; p; p = p->next)
        p->afisare();
}




// clasa carte
class carte
{
    // nume (titlu), autor, cota, editura, anul_apariţiei, nr_ediţie, împrumutată
private:
    string nume;
    string autor;
    string cota;
    string editura;
    int an;
    int nr;
    calendar impr;

    carte* next;

public:
    
    carte(string, string, string, string, int, int, calendar);
    void afisare();
    string getNume() { return nume; }
    string getAutor() { return autor; }
    string getCota() { return cota; }
    string getEditura() { return editura; }
    int getAn() { return an; }
    int getNr() { return nr; }
    calendar getImpr() { return impr; }

friend class lista <carte>;
};

// constructor 
carte::carte(string nume, string autor, string cota, string editura, int an, int nr, calendar impr)
{
    this->nume = nume;
    this->autor = autor;
    this->cota = cota;
    this->editura = editura;
    this->an = an;
    this->nr = nr;
    this->impr = impr;
    this->next = NULL;
}

// afisare date carte
void carte::afisare()
{
    cout << endl;
    cout << "Titlu: " << nume << endl;
    cout << "Autor: " << autor << endl;
    cout << "Cota: " << cota << endl;
    cout << "Editura: " << editura << endl;
    cout << "An: " << an << endl;
    cout << "Nr: " << nr << endl;
    cout << "Imprumutata (0/calendar): ";
    if (!impr.zi)
        cout << impr.zi << endl;
    else
        cout << impr.zi << "/" << impr.luna << "/" << impr.an << endl;
}




// clasa domeniu
class domeniu
{
protected:
    string nume;
    lista <carte> carti;    // lista de carti
    domeniu* next;

public:
    domeniu(string);
    void adaugareCarte(carte* a);
    carte* cautareCarte(string nume);
    int stergereCarte(string nume);
    carte* primaCarte() { return carti.prim(); }
    carte* nextCarte() { return carti.next(); }
    string getNume() { return nume; }
    virtual void afisare();
    friend class lista <domeniu>;
};

domeniu::domeniu(string nume)
{
    this->nume = nume;
    this->next = NULL;
}

void domeniu::adaugareCarte(carte* a)
{
    carti.adaugare(a);
}

carte* domeniu::cautareCarte(string nume)
{
    carte* p = NULL;
    p = carti.cautare(nume);
    return p;
}

int domeniu::stergereCarte(string nume)
{
    return carti.stergere(nume);
}

void domeniu::afisare()
{
    cout << "\nDomeniu: " << nume << endl;
    carti.afisare();
}





// clasa bibilioteca
class biblioteca
{
private:
    lista <domeniu> domenii;

public:
    void adaugareDomeniu(domeniu* a);
    domeniu* cautareDomeniu(string nume);
    int stergereDomeniu(string nume);
    domeniu* primulDomeniu() { return domenii.prim(); }
    domeniu* nextDomeniu() { return domenii.next(); }
    void afisare();
};

void biblioteca::adaugareDomeniu(domeniu* a)
{
    domenii.adaugare(a);
}

domeniu* biblioteca::cautareDomeniu(string nume)
{
    return domenii.cautare(nume);
}

int biblioteca::stergereDomeniu(string nume)
{
    return domenii.stergere(nume);
}

void biblioteca::afisare()
{
    cout << "\n";
    domenii.afisare();
    cout << "\n";
}


// meniu
void Menu()
{
    cout << "\n------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Incarcare biblioteca dintr-un fisier\n";
    cout << "2. Creare domeniu nou\n";
    cout << "3. Adaugare carte la un domeniu\n";
    cout << "4. Cautare carte in biblioteca\n";
    cout << "5. Stergere carte din biblioteca\n";
    cout << "6. Salvare in fisier a bibliotecii\n";
    cout << "7. Afisare\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

// citire carte
carte* citireCarte()
{
    string nume;
    string autor;
    string cota;
    string editura;
    int an;
    int nr;
    calendar impr;

    carte* c = NULL;

    cout << "-- Introduceti date carte --\n";
    
    cout << "Titlu: ";
    //cin.get();
    getline(cin, nume);

    cout << "Autor: ";
    //cin.get();
    getline(cin, autor);

    cout << "Cota: ";
    //cin.get();
    getline(cin, cota);

    cout << "Editura: ";
    //cin.get();
    getline(cin, editura);

    cout << "An aparitie: ";
    cin >> an;

    cout << "Numar editie: ";
    cin >> nr;

    cout << "Imprumutata: (0 / calendar - zi luna an): ";
    cin >> impr.zi;

    if (!impr.zi) {
        impr.an = impr.luna = 0;
    }
    else {
        cin >> impr.luna;
        cin >> impr.an;
    }
   
    c = new carte(nume, autor, cota, editura, an, nr, impr);
    return c;
}

// citire date din fisier
void citireFisier(biblioteca* b)
{
    domeniu* d = NULL;
    carte* c = NULL;
    ifstream f;

    char aux;
    string nume, autor, editura, cota;
    calendar impr;
    int an, nr;

    f.open("biblioteca.txt");
    if (f.is_open()) {
        while (!f.eof()) {

        aux = f.get();

        if (aux == 'd') {   // domeniu
            f.ignore(1);
            getline(f, nume);
            d = new domeniu(nume);
            b->adaugareDomeniu(d);
        }
        
        if (aux == 'c') {   // carte
            f.ignore(1);
            f >> autor;
            f >> nume;
            f >> cota;
            f >> editura;
            f >> an;
            f >> nr;
            f >> impr.zi;

            if (!impr.zi)
                impr.luna = impr.an = 0;
            else {
                f >> impr.luna;
                f >> impr.an;
            }

            c = new carte(nume, autor, cota, editura, an, nr, impr);
            if (d)
                d->adaugareCarte(c);
            f.ignore(1000, '\n');
        }
    }

        f.close();
    }

}

void salvare_fisier(biblioteca* b)
{
    domeniu* d;
    carte* c;
    ofstream f;

    f.open("biblioteca.txt");
    d = b->primulDomeniu();

    while (d) {
        f << "d ";
        f << d->getNume() << "\n";
        c = d->primaCarte();
        while (c) {
            f << "c " << c->getAutor() << " " << c->getNume() << " " << c->getCota() << " ";
            f << c->getEditura() << " " << c->getAn() << " " << c->getNr() << " ";
            if (!c->getImpr().zi)
                f << c->getImpr().zi << "\n";
            else
                f << c->getImpr().zi << " " << c->getImpr().luna << " " << c->getImpr().an << "\n";

            c = d->nextCarte();
        }
        d = b->nextDomeniu();
    }

}

int main(int argc, char** argv)
{
    int opt, x;
    carte* c = NULL;
    domeniu* d = NULL;
    biblioteca b;
    string aux;

    do
    {
        Menu();
        cin >> opt;

        switch (opt)
        {
        case 0:     // iesire
            exit(EXIT_SUCCESS);
        break;
        
        case 1:     // incarcare biblioteca din fisier
            citireFisier(&b);
            b.afisare();
        break;

        case 2:     // creare domeniu nou
            cout << "Domeniu: ";
            cin.get();
            getline(cin, aux);
            d = b.cautareDomeniu(aux);
            if (d)
                cout << "Domeniu exista deja.\n";
            else {
                d = new domeniu(aux);
                b.adaugareDomeniu(d);
                cout << "Domeniul a fost adaugat.\n";
            }
            d = NULL;
        break;

        case 3:     // adaugare carte la un domeniu
            cout << "Domeniu: ";
            cin.get();
            getline(cin, aux);
            d = b.cautareDomeniu(aux);
            if (!d)
                cout << "Domeniu inexistent.\n";
            else {
                c = citireCarte();
                d->adaugareCarte(c);
                cout << "Cartea a fost adaugata.\n";
            }
        break;

        case 4:     // cautare carte in biblioteca
            cout << "Domeniu: ";
            cin.get();
            getline(cin, aux);
            if (!(d = b.cautareDomeniu(aux)))
                cout << "Domeniu inexistent.\n";
            else {
                cout << "Titlu: ";
                //cin.get();
                getline(cin, aux);
                if (!(c = d->cautareCarte(aux)))
                    cout << "Carte inexistenta in biblioteca.\n";
                else {
                    cout << "Carte existenta in biblioteca.\n";
                    c->afisare();
                }
            }
            cout << endl;
        break;

        case 5:     // sterge carte din biblioteca
            cout << "Domeniu: ";
            cin.get();
            getline(cin, aux);
            if (!(d = b.cautareDomeniu(aux)))
                cout << "Domeniu inexistent.\n";
            else {
                cout << "Titlu: ";
                //cin.get();
                getline(cin, aux);
                if ((x = d->stergereCarte(aux)) != 1)
                    cout << "Carte inexistenta, stergere esuata.\n";
                else
                    cout << "Carte stearsa cu succes.\n";

            }
            cout << endl;
        break;

        case 6:     // salvare in fisier biblioteca
            salvare_fisier(&b);
        break;

        case 7:     // afisare biblioteca (domenii si carti aferente)
            b.afisare();
            cout << "Datele au fost salvate in fisie cu succes\n";
        break;
        
        default:
            cout << "Eroare. Optiune nedefinita\n";
        break;
        }
    } while (opt);
    


    return 0;
}
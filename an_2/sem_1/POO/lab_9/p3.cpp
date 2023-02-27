#include <iostream>
#include <fstream>

using namespace std;

// clasa template lista (omogena)
template <class T> class lista
{
    T* head;
    T* tail;
    T* point;

    public:
        lista();
        ~lista();
        void adaugare(T* a);
        T* cautare(string nume);
        T* cautareSisOper(string sis_oper);
        int stergere(string nume);
        T* getHead();
        T* getNext();
        int vida();
        void elibereaza();
        void afisare();
};

// initializare lista
template <class T> lista<T>::lista()
{
    head = NULL;
    tail = NULL;
}

template <class T> void lista<T>::elibereaza()
{
    T* p = NULL, *q = NULL;

    for (p = head; p; p = q) {
        q = p->next;
        delete p;
    }
    head = NULL;
    tail = NULL;
}

// destructor (sterge lista)
template <class T> lista<T>::~lista()
{
    elibereaza();
}

// adaugare nod in lista (in spate)
template <class T> void lista<T>::adaugare(T* a)
{
    if (!head) {    // daca lista e vida
        head = a;
        tail = head;
    }
    else {
        // ultimul nod (locul insertiei)
        tail->next = a;
        tail = a;
    }

    tail->next = NULL;
    
}

// cautare nod in lista
template <class T> T* lista<T>::cautare(string nume)
{
    T* p = NULL;

    for (p = head; p; p = p->next)
        if (p->nume == nume)
            break;
    
    return p;
}

// stergere nod din lista
template <class T> int lista<T>::stergere(string nume)
{
    T* p = NULL;
    T* q = NULL;
    
    if (!head) {    // daca lista e vida
        cout << "Lista e vida.\n";
        return 0;
    }
    
    if (head->nume == nume) {       // daca se sterge capul listei
        q = head;
        head = head->next;
        delete q;
        return 1;
    }
    else {                          // daca nu e primul nod
        for (p = head; p->next; p = p->next)
        if (p->next->nume == nume)
            break;

        q = p->next;                // se tine nodul de sters
        p->next = p->next->next;
        
        if (q == tail)              // daca se sterge coada (ultimul nod)
            tail = p;

        delete q;
        return 1;
    }

    return 0;
}

// primul nod din lista (capul)
template <class T> T* lista<T>::getHead()
{
    point = head;
    return point;
}

// urmatorul nod din lista (next)
template <class T> T* lista<T>::getNext()
{
    if (point)
        point = point->next;

    return point;
}

// testeaza daca lista e vida
template <class T> int lista<T>::vida()
{
    return (!head) ? 1 : 0;
}

// afisare lista
template <class T> void lista<T>::afisare()
{
    T* p = NULL;

    if (!head) {
        cout << "Lista vida.\n";
        return;
    }

    for (p = head; p; p = p->next)
        p->afisare();
}

// cautare nod in lista (dupa sistemul de operare)
template <class T> T* lista<T>::cautareSisOper(string sis_oper)
{
    T* p = NULL;

    for (p = head; p; p = p->next)
        if (p->sis_oper == sis_oper)
            break;
    
    return p;
}




// clasa telefon (baza)
class telefon
{
    private:
        
    protected:
        string nume;
        string producator;
        string culoare;

    public:
        telefon(string nume, string producator, string culoare);
        virtual void afisare();
        string getNume() { return nume; }
        string getProducator() { return producator; }
        string getCuloare() { return culoare; }

};

telefon::telefon(string nume, string producator, string culoare)
{
    this->nume = nume;
    this->producator = producator; 
    this->culoare = culoare;
}

void telefon::afisare()
{
    cout << "\nNume: " << nume << "\n";
    cout << "Producator: " << producator << "\n";
    cout << "Culoare: " << culoare << "\n";
}






// clasa fix (derivata)
class fix : public telefon
{
    private:
        string dimensiune;
        fix* next;

    protected:

    public:
        fix(string nume, string producator, string culoare, string dimensiune);
        void afisare();
        string getDimensiune() { return dimensiune; }

    friend class lista<fix>;
};

fix::fix(string nume, string producator, string culoare, string dimensiune) : telefon(nume, producator, culoare)
{
    this->dimensiune = dimensiune;
    next = NULL;
}

void fix::afisare()
{
    telefon::afisare();
    cout << "Dimensiune: " << dimensiune << "\n\n";
}








// clasa mobil (derivata)
class mobil : public telefon
{
    private:
        string sis_oper;
        mobil* next;

    protected:

    public:
        mobil(string nume, string producator, string culoare, string sis_oper);
        void afisare();
        string getSisOper() { return sis_oper; }

    friend class lista<mobil>;

};

mobil::mobil(string nume, string producator, string culoare, string sis_oper) : telefon(nume, producator, culoare)
{
    this->sis_oper = sis_oper;
    next = NULL;
}

void mobil::afisare()
{
    telefon::afisare();
    cout << "Sistem de operare: " << sis_oper << "\n\n";
}





// citire date telefon fix
fix* citireFix()
{
    string nume, producator, culoare, dimensiune;
    fix* p = NULL;

    cout << "\n-- Introduceti date fix --\n";

    cout << "Nume: ";
    cin.get();
    getline(cin, nume);

    cout << "Producator: ";
    //cin.get();
    getline(cin, producator);

    cout << "Culoare: ";
    //cin.get();
    getline(cin, culoare);

    cout << "Dimensiune: ";
    //cin.get();
    getline(cin, dimensiune);

    p = new fix(nume, producator, culoare, dimensiune);
    return p;
}

// citire date telefon mobil
mobil* citireMobil()
{
    string nume, producator, culoare, sis_oper;
    mobil* p = NULL;

    cout << "\n-- Introduceti date mobil --\n";

    cout << "Nume: ";
    cin.get();
    getline(cin, nume);

    cout << "Producator: ";
    //cin.get();
    getline(cin, producator);

    cout << "Culoare: ";
    //cin.get();
    getline(cin, culoare);

    cout << "Sistem de operare: ";
    //cin.get();
    getline(cin, sis_oper);

    p = new mobil(nume, producator, culoare, sis_oper);
    return p;
}

// citire date din fisier
void citireFisier(lista <fix> *fixe, lista <mobil> *mobile)
{
    ifstream f;
    char aux;


    string nume, producator, culoare, dimensiune, sis_oper;

    f.open("telefoane.txt");
    if (f.is_open()) {

        while (!f.eof()) {

            f.get(aux);

            if (aux == 'f') {       // fix
                f.ignore(1);
                f >> nume;
                f >> producator;
                f >> culoare;
                f >> dimensiune;
                f.ignore(1000, '\n');

                fix* p = new fix(nume, producator, culoare, dimensiune);
                fixe->adaugare(p);

            }

            else if (aux == 'm') {  // mobil
                f.ignore(1);
                f >> nume;
                f >> producator;
                f >> culoare;
                f >> sis_oper;
                f.ignore(1000, '\n');

                mobil* p = new mobil(nume, producator, culoare, sis_oper);
                mobile->adaugare(p);
            }
        }

        f.close();
    }

}

// salvare date in fisier
void salvareFisier(lista <fix> *fixe, lista <mobil> *mobile)
{
    ofstream f;
    fix* p = NULL;
    mobil* q = NULL;

    f.open("telefoane.txt");

    if (f.is_open()) {      // daca s-a deschis fisierul cu succes

        // scriere date telefoane fixe
        p = fixe->getHead();
        while (p) {
            f << "f ";
            f << p->getNume() << " ";
            f << p->getProducator() << " ";
            f << p->getCuloare() << " ";
            f << p->getDimensiune() << "\n";

            p = fixe->getNext();
        }

        // scriere date telefoane mobile
        q = mobile->getHead();
        while (q) {
            f << "m ";
            f << q->getNume() << " ";
            f << q->getProducator() << " ";
            f << q->getCuloare() << " ";
            f << q->getSisOper() << "\n";

            q = mobile->getNext();
        }

        cout << "Date salvate in fisier cu succes.\n";
        f.close();      // inchidem fisierul
    }
}

// meniu
void Menu()
{
    cout << "\n------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Incarcare date din fisier\n";
    cout << "2. Adaugare telefon fix in spatele listei\n";
    cout << "3. Adaugare telefon mobil in spatele listei\n";
    cout << "4. Cautare telefon mobil dupa sistem de operare\n";
    cout << "5. Stergere telefon\n";
    cout << "6. Salvare in fisier a datelor\n";
    cout << "7. Afisare\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

// functie principala
int main(int argc, char** argv)
{   
    int opt;
    lista <fix> fixe;
    lista <mobil> mobile;

    fix* p = NULL;
    mobil* q = NULL;

    string aux;
    int sel;


    do
    {
        Menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:                     // iesire
            exit(EXIT_SUCCESS);
        break;

        case 1:                     // incarcare date din fisier
            citireFisier(&fixe, &mobile);
        break;

        case 2:                     // adaugare telefon fix in spatele listei
            p = citireFix();
            fixe.adaugare(p);
            p = NULL;
        break;

        case 3:                     // adaugare telefon mobil in spatele listei
            q = citireMobil();
            mobile.adaugare(q);
            q = NULL;
        break;

        case 4:                     // cautare telefon mobil dupa sistem de operare
            cout << "Introduceti SO telefon cautat: ";
            cin.get();
            getline(cin, aux);
            if (!(q = mobile.cautareSisOper(aux)))
                cout << "Telefon inexistent.\n";
            else {
                cout << "Telefon gasit.\n";
                q->afisare();
            }

            q = NULL;
        break;

        case 5:                     // stergere telefon
            cout << "Introduceti tip telefon (0-fix / 1-mobil): ";
            cin >> sel;

            cout << "\nIntroduceti nume telefon sters: ";
            cin.get();
            getline(cin, aux);
            
            if (!sel) {     // fix
                if (!(p = fixe.cautare(aux)))
                    cout << "Nume inexistent.\n";
                else {
                    cout << "Telefon gasit.\n";
                    if (fixe.stergere(aux))
                        cout << "Stergere cu succes.\n";
                    else
                        cout << "Sergere esuata.\n";
                }

            }
            else if (sel == 1) {    // mobil
                if (!(q = mobile.cautare(aux)))
                    cout << "Nume inexistent.\n";
                else {
                    cout << "Telefon gasit.\n";
                    if (mobile.stergere(aux))
                        cout << "Stergere cu succes.\n";
                    else 
                        cout << "Stergere esuata.\n";
                }
            }
            
            p = NULL;
            q = NULL;
        break;

        case 6:                     // salvare in fisier a datelor
            salvareFisier(&fixe, &mobile);
        break;

        case 7:                     // afisare
            cout << "\n-- Telefoane Fixe --\n";
            fixe.afisare();
            cout << "\n\n-- Telefoane Mobile --\n";
            mobile.afisare();
        break;
        
        default:
            cout << "Eroare. Optiune nedefinita.\n";
        break;
        }

    } while (opt);
    

    
    return 0;
}
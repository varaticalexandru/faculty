#include <iostream>
#include <fstream>

using namespace std;

/*
Realizaţi un program care să gestioneze următoarele informaţii despre electrocasnicele dintrun magazin:
- Maşină de spălat cu următoarele variabile: Producător, Preţ, Nr_programe;
- Aragaz cu următoarele variabile: Producător, Preţ, Tip arzătoare.
Creaţi pe baza informaţiilor furnizate o clasă de bază şi două clase derivate şi implementaţi 
următoarele funcţii prin intermediul unui meniu interactiv:
1. Citirea informațiilor existente în fișier
2. Adăugare maşină spălat sau aragaz
3. Afişare electrocasnice.
4. Căutare aragaz după “tip arzătoare”.
5. Salvare carte de telefoane în fişier
6. Ieşire
Problema se va rezolva folosind liste eterogene și se vor prevedea cel puțin două situații de 
tratare a excepțiilor.
*/

// clasa exceptie
class exceptie
{
private:
    string s;

protected:

public:
    exceptie(string s="") { this->s = s; }
    void afisareExceptie() { cout << "\nExceptie: " << s << "\n"; }
};



// clasa template : lista eterogena
template <class T> class lista
{
private:
    T* head;
    T* tail;
    T* point;

protected:

public:
    lista();
    ~lista();
    void eliberare();
    T* getHead();
    T* getTail();
    T* getNext();
    void adaugareOrdine(T* a);
    void adaugareFata(T* a);
    void adaugareSpate(T* a);
    void afisare();
    T* cautare(string nume);
    int stergere(string nume);
};

// constructor: initializare lista
template <class T> lista<T>::lista()
{
    head = NULL;
    tail = NULL;
}

// elibereaza/sterge lista
template <class T> void lista<T>::eliberare()
{
    if (!head)      // daca lista e vida
        return;
    
    T* p = NULL, *q = NULL;

    p = head;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }

    head = NULL;
    tail = NULL;
}

// destructor: stergere/eliberare lista
template <class T> lista<T>::~lista()
{
    eliberare();
}

// returneaza capul listei
template <class T> T* lista<T>::getHead()
{
    point = head;
    return point;
}

// returneaza coada listei
template <class T> T* lista<T>::getTail()
{
    point = tail;
    return point;
}

// returneaza urmatorul nod din lista
template <class T> T* lista<T>::getNext()
{
    if (point)
        point = point->next;
    return point;
}

// afisare lista
template <class T> void lista<T>::afisare()
{
    if (!head) {
        cout << "Lista e vida.\n";
        return;
    }

    T* p = NULL;
    
    p = head;
    while (p) {
        p->afisare();
        p = p->next;
    }
}

// adaugare nod in ordine
template <class T> void lista<T>::adaugareOrdine(T* a)
{
    if (!head) {    // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    if (a->producator < head->producator) {     // daca nodul adaugat < capul listei (primul nod)
        a->next = head;
        head = a;
    }
    else if (a->producator > tail->producator) {        // daca nodul adaugat > coada listei (ultimul nod)
        tail->next = a;
        tail = a;
    }
    else {                          // daca nodul adaugat e in interiorul listei

        T* p = NULL, *q = NULL;

        // gasim pozitia pentru inserat
        p = head;
        while (p->next && a->producator > p->next->producator)
            p = p->next;
        
        // insearam nodul
        a->next = p->next;
        p->next = a;
    }
}

// adaugare nod in fata
template <class T> void lista<T>::adaugareFata(T* a)
{
    if (!head) {        // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    // inseram nodul
    a->next = head;
    head = a;
}

// adaugare nod in spate
template <class T> void lista<T>::adaugareSpate(T* a)
{
     if (!head) {        // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    // inseram nodul
    tail->next = a;
    tail = a;
}

// cautare nod in lista
template <class T> T* lista<T>::cautare(string nume)
{
    if (!head) {        // daca lista e vida
        return NULL;
    }

    if (head->producator == nume)     // daca nodul cautat e capul listei
        return head;

    if (tail->producator == nume)     // daca nodul cautat e capul listei
        return tail;
    
    T* p = NULL;

    p = head;
    while (p && !(p->producator == nume))
        p = p->next;
    
    if (p->numproducatore == nume)
        return p;
    
    return NULL;
}

// stergere nod din lista
template <class T> int lista<T>::stergere(string nume)
{
    if (!head) {
        cout << "Lista e vida.\n";
        return 0;
    }
     T* p = NULL, *q = NULL;

    if (head->nume == nume) {       // daca se sterge capul listei (primul nod)
        q = head;
        head = head->next;
        delete q;
        return 1;
    }

    while (p->next && !(p->next->nume == nume))
        p = p->next;
    
    if (p->next->nume == nume) {
        q = p->next;
        p->next = p->next->next;

        if (q == tail)      // daca se sterge coada listei (ultimul nod)
            tail = p;

        delete q;
        return 1;
    }

    return 0;
}




// clasa electrocasnic (baza)
class electrocasnic
{
private:
    electrocasnic* next;

protected:
    int tip;
    string producator;
    float pret;

public:
    electrocasnic(int tip, string producator, float pret);
    virtual void afisare();
    int getTip() { return tip; }
    string getProducator() { return producator; }
    float getPret() { return pret; }
    virtual string getTipArzator() {};
    virtual int getNrPrograme() {};

friend class lista <electrocasnic>;
};

// constructor electrocasnic
electrocasnic::electrocasnic(int tip=0, string producator="", float pret=0.0)
{
    this->tip = tip;
    this->producator = producator;
    this->pret = pret;
    this->next = NULL;
}

// afisare date electrocasnic
void electrocasnic::afisare()
{
    cout << "\nTip: " << tip << "\n";
    cout << "Producator: " << producator << "\n";
    cout << "Pret: " << pret << "\n";
}





// clasa masina_spalat (derivata)
class masina_spalat : public electrocasnic
{
private:
    int nr_programe;

protected:

public:
    masina_spalat(int tip, string producator, float pret, int nr_program);
    void afisare();
    int getNrPrograme() { return nr_programe; }

friend istream & operator >> (istream & in, masina_spalat & obj);
};

// constructor masina_spalat
masina_spalat::masina_spalat(int tip=0, string producator="", float pret=0.0f, int nr_programe=0) : electrocasnic(tip, producator, pret)
{
    this->nr_programe = nr_programe;
}

// afisare date masina_spalat
void masina_spalat::afisare()
{
    electrocasnic::afisare();
    cout << "Nr. programe: " << nr_programe << "\n\n";
}





// clasa aragaz (derivata)
class aragaz : public electrocasnic
{
private:
    string tip_arzator;

protected:

public:
    aragaz(int tip, string producator, float pret, string tip_arzator);
    void afisare();
    string getTipArzator() { return tip_arzator; }

friend istream & operator >> (istream & in, aragaz & obj);
};

// constructor aragaz
aragaz::aragaz(int tip=1, string producator="", float pret=0.0, string tip_arzator="") : electrocasnic(tip, producator, pret)
{
    this->tip_arzator = tip_arzator;
}

// afisare date aragaz
void aragaz::afisare()
{
    electrocasnic::afisare();
    cout << "Tip arzator: " << tip_arzator << "\n\n";
}



// overload operator de extragere (>>)
istream & operator >> (istream & in, masina_spalat & obj)
{
    cout << "\n-- Introduceti date masina de spalat --";
    cout << "\nProducator: ";
    in.get();
    getline(in, obj.producator);

    cout << "Pret: ";
    in >> obj.pret;

    cout << "Nr. programe: ";
    in >> obj.nr_programe;
    cout << "\n";
    in.get();
}

istream & operator >> (istream & in, aragaz & obj)
{
    cout << "\n-- Introduceti date aragaz --";
    cout << "\nProducator: ";
    in.get();
    getline(in, obj.producator);

    cout << "Pret: ";
    in >> obj.pret;

    cout << "Tip arzator: ";
    in >> obj.tip_arzator;
    cout << "\n";
}

// citire electrocasnic (masina_spalat / aragaz)
electrocasnic* citireElectrocasnic(int sel)
{
    electrocasnic* p = NULL;

    masina_spalat* q = NULL;
    aragaz* a = NULL;

    if (!sel) {
        q = new masina_spalat;
        cin >> *q;
        p = q;
        return p;
    }
    else if (sel == 1) {
        a = new aragaz;
        cin >> *a;
        p = a;
        return p;
    }
}

// meniu
void menu()
{
    cout << "\n------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Citirea informatiilor existente in fisier\n";
    cout << "2. Adaugare electrocasnic\n";
    cout << "3. Afisare electrocasnice\n";
    cout << "4. Cautare aragaz dupa tip arzatoare\n";
    cout << "5. Salvare informatii in fisier\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

// citire date din fisier
void citireFisier(lista<electrocasnic>* electrocasnice)
{
    ifstream f;
    char c;
    electrocasnic* p = NULL;
    int tip;
    string producator;
    float pret;


    try {
        f.open("electrocasnice.txt");
        if (!f.is_open())
            throw (exceptie("Eroare deschidere fisier intrare."));  
    }
    catch (exceptie e) {        // prinde exceptia
        e.afisareExceptie();
        return;
    }
    
    while (!f.eof()) {

        f >> c;

        if (c == 'm') {         // masina de spalat
            int nr_programe;
            masina_spalat* q = NULL;

            tip = 0;
            f >> producator;
            f >> pret;
            f >> nr_programe;

            q = new masina_spalat(tip, producator, pret, nr_programe);
            p = q;
            electrocasnice->adaugareSpate(p);

            p = NULL;
            q = NULL;
        }
        else if (c == 'a') {    // aragaz
            string tip_arzator;
            aragaz* a = NULL;
            
            tip = 1;
            f >> producator;
            f >> pret;
            f >> tip_arzator;

            a = new aragaz(tip, producator, pret, tip_arzator);
            p = a;
            electrocasnice->adaugareSpate(p);

            p = NULL;
            a = NULL;
        }


    }

    cout << "\nCitire date din fisier cu succes.\n";
    f.close();
}

// salvare date in fisier
void salvareFisier(lista<electrocasnic>* electrocasnice)
{
    ofstream f;

    try {
        f.open("electrocasnice_out.txt");
        if (!f.is_open())
            throw exceptie("Eroare deschidere fisier iesire.");
    }
    catch (exceptie e) {
        e.afisareExceptie();
        return;
    }

    electrocasnic* p = NULL;

    for (p = electrocasnice->getHead(); p; p = electrocasnice->getNext()) {
        if (!p->getTip()) {     // masina de spalat
            f << "m ";
            f << p->getProducator() << " ";
            f << p->getPret() << " ";
            f << p->getNrPrograme() << '\n';
        }
        else if (p->getTip() == 1) {    // aragaz
            f << "f ";
            f << p->getProducator() << " ";
            f << p->getPret() << " ";
            f << p->getTipArzator() << '\n';
        }
    }

    cout << "Scriere date in fisier cu succes.\n";
    f.close();
}

// functie principala
int main(int argc, char** argv)
{
    system("cls");
    
    lista<electrocasnic> electrocasnice;
    int opt, sel;
    electrocasnic* p = NULL;
    string aux;



    do
    {
        menu();
        cin >> opt;
        cout << "\n";

         switch (opt)
        {
        case 0:     // iesire
        {
            exit(EXIT_SUCCESS);
        }    
        break;

        case 1:     // citire date din fisier
        {
            citireFisier(&electrocasnice);
        }    
        break;

        case 2:     // adaugare electrocasnic
        {
            cout << "\n-- Introduceti date electrocasnic --\n";
            cout << "Tip(0-masina de spalat / 1 - aragaz): ";
            cin >> sel;
            p = citireElectrocasnic(sel);
            electrocasnice.adaugareSpate(p);

            p = NULL;
        }    
        break;

        case 3:     // afisare electrocasnice
        {
            cout << "\n-- Electrocasnice --\n";
            electrocasnice.afisare();
        }    
        break;

        case 4:     // cautare aragaz dupa tip arzatoare
        {
            int flag = 0;

            cout << "\nIntroduceti tip arzator: ";
            cin.get();
            getline(cin, aux);

            for (p = electrocasnice.getHead(); p; p = electrocasnice.getNext()) {
                if (p->getTip() == 1)
                    if ((p->getTipArzator()) == aux) {
                        flag = 1;
                        cout << "\nAragaz gasit.\n";
                        p->afisare();
                    }
            }

            if (!flag)
                cout << "Aragaz inexistent.\n";

            p = NULL;
        }    
        break;

        case 5:     // salvare date in fisier
        {
            salvareFisier(&electrocasnice);
        }    
        break;
        
        default:
        {
            cout << "Eroare. Optiune nedefinita.\n";
        }
        break;
        }
        
    } while (opt);
    



    return 0;
}
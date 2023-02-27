#include <iostream>
#include <string>

using namespace std;

/*
    Realizați un program care să gestioneze următoarele informaţii despre monitoarele dintr-o 
    unitate implementând-ul cu două liste omogene:
    - Monitoare LCD cu următoarele informații: Producator, Diagonala, Pret, Timp de 
    raspuns, Tip ecran, Conectori
    - Monitoare LED cu următoarele informații: Producator, Diagonala, Pret, Format 
    ecran, Iluminare, Boxe integrate.
    Creaţi din informaţiile date o clasă de bază şi două clase derivate şi implementaţi următoarele 
    funcţii prin intermediul unui meniu interactiv, cu liste simplu înlănţuite:
    1. Adăugarea unui monitor LED/LCD.
    2. Afișare monitoare LED/LCD.
    3. Ștergere monitor LED/LCD.
    4. Căutare monitor LED/LCD.
    5. Ordonare monioare LCD/LED.
    6. Ieșire
*/

// clasa template lista
template <class T> class lista
{
private:
    T* head;    // capul listei (fata)
    T* tail;    // coada listei (spate)
    T* point;   

public:
    lista();
    ~lista();
    void eliberare();
    void afisare();
    void adaugareOrdine(T* a);
    void adaugareFata(T* a);
    void adaugareSpate(T* a);
    int stergere(string producator);
    T* cautare(string producator);
    void ordonare();
    T* getHead();
    T* getTail();
    T* getNext();
    int vida();
};

// initializeaza lista
template <class T> lista<T>::lista()
{
    head = NULL;
    tail = NULL;
}

// elibereaza lista (sterge toate nodurile)
template <class T> void lista<T>::eliberare()
{
    if (!head)
        return;
    else {
        T* p = NULL;
        T* q = NULL;

        for (p = head; p; p = q) {
            q = p->next;
            delete p;
        }

        head = NULL;
        tail = NULL;
    }
}

// destructor (sterge/elibereaza lista)
template <class T> lista<T>::~lista()
{
    eliberare();
}

// afiseaza lista
template <class T> void lista<T>::afisare()
{
    if (!head)
        cout << "Lista este vida.\n";
    else {
        T* p = NULL;
        for (p = head; p; p = p->next)
            p->afisare();
    }
}

// adauga nod in lista (ordonata)
template <class T> void lista<T>::adaugareOrdine(T* a)
{
    if (!head) {    // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    if (a->producator < head->producator) {    // daca nodul adaugat < primul nod (capul listei)   
        a->next = head;
        head = a;
    }
    else if (a->producator > tail->producator) {      // daca nodul > ultimul nod (coada listei)
        tail->next = a;
        tail = a;
    }
    else {                                // daca nodul adaugat e in interiorul listei
        
        T* p = NULL, *q = NULL;

        // cautam locul potrivit pentru isertie
        p = head;
        while (p->next && a->producator > p->next->producator)
            p = p->next;
        
        // inseram nodul
        a->next = p->next;
        p->next = a;
    }   
}

// adauga nod in lista (fata)
template <class T> void lista<T>::adaugareFata(T* a)
{
    if (!head) {    // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    // inseram nodul
    a->next = head;
    head = a;
}

// adauga nod in lista (spate)
template <class T> void lista<T>::adaugareSpate(T* a)
{
    if (!head) {    // daca lista e vida
        head = a;
        tail = head;
        return;
    }

    // inseram nodul
    tail->next = a;
    tail = a;
}

// cautare nod in lista
template <class T> T* lista<T>::cautare(string producator)
{
    if (!head)
        cout << "Lista e vida.\n";
    else {
        T* p = NULL;

        p = head;
        while (p && !(p->producator == producator))
            p = p->next;
        
        if (p->producator == producator) return p;
    }

    return NULL;
}

// stergere nod din lista
template <class T> int lista<T>::stergere(string producator)
{
    if (!head) {
        cout << "Lista e vida.\n";
        return 0;
    }

    T* p = NULL, *q = NULL;
        
    if (head->producator == producator) {   // daca nodul sters e primul (capul listei)
        q = head;
        head = head->next;
        delete q;
        return 1;
    }
    else {
         // se cauta nodul de sters
        while (p->next && !(p->next->producator == producator))
            p = p->next;

        if (p->next->nume != nume)
            return 0;
        
        q = p->next;
        p->next = p->next->next;

        if (q == tail)      /// daca se sterge ultimul nod (coada)
            tail = p;

        delete q;
        return 1;
    }

    return 0;
}

// returneaza primul nod (capul listei)
template <class T> T* lista<T>::getHead()
{
    point = head;
    return point;
}

// returneaza urmatorul nod
template <class T> T* lista<T>::getTail()
{
    point = tail;
    return point;
}

// returneaza urmatorul nod
template <class T> T* lista<T>::getNext()
{
    if (point)
        point = point->next;

    return point;
}

// testeaza dca lista e vida
template <class T> int lista<T>::vida()
{
    return (!head) ? 1 : 0;
}

// ordonare noduri in lista
template <class T> void lista<T>::ordonare()
{
    if (!head)
        return;
    
    T* p = NULL, *q = NULL;
    int ok;

    do {
        ok = 1;
        p = head;

        while (p->next) {
            if (p->producator > p->next->producator) {
                ok = 0;
                p->swap(p->next);
            }

            p = p->next;
        }
    } while (!ok);
}


// clasa monitor (baza)
class monitor
{
private:

protected:
    string producator;
    int diagonala;
    float pret;

public:
    monitor(string producator, int diagonala, float pret);
    virtual void afisare();
};

// constructor
monitor::monitor(string producator, int diagonala, float pret)
{
    this->producator = producator;
    this->diagonala = diagonala;
    this->pret = pret;
}

// afisare date monitor
void monitor::afisare()
{
    cout << "\nProducator: " << producator << "\n";
    cout << "Diagonala: " << diagonala << "\n";
    cout << "Pret: " << pret << "\n";
}



// clasa LCD (derivata)
class LCD : public monitor
{
private:
    float timp_rs;
    string tip_ecran;
    int conectori;
    LCD* next;
    
protected:

public:
    LCD(string producator, int diagonala, float pret, float timp_rs, string tip_ecran, int conectori);
    void afisare();
    void swap(LCD* obj);

friend istream & operator >> (istream & in, LCD & obj);
friend class lista<LCD>;
};

// constructor monitor LCD
LCD::LCD(string producator="", int diagonala=0, float pret=0.0f, float timp_rs=0.0f, string tip_ecran="", int conectori=0) : monitor(producator, diagonala, pret)
{
    this->timp_rs = timp_rs;
    this->tip_ecran = tip_ecran;
    this->conectori = conectori;
    next = NULL;
}

// afisare date monitor LCD
void LCD::afisare()
{
    monitor::afisare();
    cout << "Timp raspuns: " << timp_rs << "\n";
    cout << "Tip ecran: " << tip_ecran << "\n";
    cout << "Conectori: " << conectori << "\n\n";
}

// swap
void LCD::swap(LCD* obj)
{
    LCD temp;

    // copiem datele din this in temp
    temp.producator = this->producator;
    temp.diagonala = this->diagonala;
    temp.pret = this->pret;
    temp.timp_rs = this->timp_rs;
    temp.tip_ecran = this->tip_ecran;
    temp.conectori = this->conectori;

    // copiem datele din obj in this
    this->producator = obj->producator;
    this->diagonala = obj->diagonala;
    this->pret = obj->pret;
    this->timp_rs = obj->timp_rs;
    this->tip_ecran = obj->tip_ecran;
    this->conectori = obj->conectori;

    // copiem datele din temp in obj
    obj->producator = temp.producator;
    obj->diagonala = temp.diagonala;
    obj->pret = temp.pret;
    obj->timp_rs = temp.timp_rs;
    obj->tip_ecran = temp.tip_ecran;
    obj->conectori = temp.conectori;
}

// clasa LED (derivata)
class LED : public monitor
{
private:
    string format_ecran;
    string iluminare;
    string boxe_integrate;
    LED* next;

protected:

public:
    LED(string producator, int diagonala, float pret, string format_ecran, string iluminare, int boxe_integrate);
    void afisare();
    void swap(LED* obj);

friend istream & operator >> (istream & in, LED & obj);
friend class lista<LED>;
};


// constructor monitor LED
LED::LED(string producator="", int diagonala=0, float pret=0.0f, string format_ecran="", string iluminare="", int boxe_integrate=0) : monitor(producator, diagonala, pret)
{
    this->format_ecran = format_ecran;
    this->iluminare = iluminare;
    this->boxe_integrate = boxe_integrate;
    next = NULL;
}

// afisare date monitor LED
void LED::afisare()
{
    monitor::afisare();
    cout << "Format ecran: " << format_ecran << "\n";
    cout << "Iluminare: " << iluminare << "\n";
    cout << "Boxe integrate: " << boxe_integrate << "\n\n";
}

// swap
void LED::swap(LED* obj)
{
    LED temp;

    // copiem datele din this in temp
    temp.producator = this->producator;
    temp.diagonala = this->diagonala;
    temp.pret = this->pret;
    temp.format_ecran = this->format_ecran;
    temp.iluminare = this->iluminare;
    temp.boxe_integrate = this->boxe_integrate;

    // copiem datele din obj in this
    this->producator = obj->producator;
    this->diagonala = obj->diagonala;
    this->pret = obj->pret;
    this->format_ecran = obj->format_ecran;
    this->iluminare = obj->iluminare;
    this->boxe_integrate = obj->boxe_integrate;

    // copiem datele din temp in obj
    obj->producator = temp.producator;
    obj->diagonala = temp.diagonala;
    obj->pret = temp.pret;
    obj->format_ecran = temp.format_ecran;
    obj->iluminare = temp.iluminare;
    obj->boxe_integrate = temp.boxe_integrate;
}




// supraincarcare operator extragere
istream & operator >> (istream & in, LCD & obj)
{
    cout << "\nProducator: ";
    in.get();
    getline(in, obj.producator);

    cout << "Diagonala: ";
    in >> obj.diagonala;
    
    cout << "Pret: ";
    in >> obj.pret;

    cout << "Timp raspuns: ";
    in >> obj.timp_rs;
    
    cout << "Tip ecran: ";
    in.get();
    getline(in, obj.tip_ecran);
    
    cout << "Conectori: ";
    in >> obj.conectori;

    return in;
}

istream & operator >> (istream & in, LED & obj)
{
    cout << "\nProducator: ";
    in.get();
    getline(in, obj.producator);

    cout << "Diagonala: ";
    in >> obj.diagonala;
    
    cout << "Pret: ";
    in >> obj.pret;

    cout << "Format ecran: ";
    in.get();
    getline(in, obj.format_ecran);
    
    cout << "Iluminare: ";
    in.get();
    getline(in, obj.iluminare);
    
    cout << "Boxe integrate: ";
    in.get();
    getline(in, obj.boxe_integrate);

    return in;
}


// citire dat LCD
LCD* citireLCD()
{
    LCD* p = NULL;
    LCD obj;

    cout << "\n --Introduceti date monitor LCD -- \n";
    cin >> obj;

    p = new LCD(obj);
    return p;
}

// citire date LED
LED* citireLED()
{
    LED* p = NULL;
    LED obj;

    cout << "\n --Introduceti date monitor LED -- \n";
    cin >> obj;

    p = new LED(obj);
    return p;
}

// meniu
void menu()
{
    cout << "\n------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Adaugare monitor\n";
    cout << "2. Afisare monitoare\n";
    cout << "3. Stergere monitor\n";
    cout << "4. Cautare monitor\n";
    cout << "5. Ordonare monitor\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}


int main()
{
    system("cls");  

    lista <LCD> lcds;
    lista <LED> leds;

    int opt, sel;
    string aux;
    LCD* p = NULL;
    LED* q = NULL;



    do {
        menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:
            exit(EXIT_SUCCESS);
        break;

        case 1:     // adaugare monitor (LED/LCD)
        {
            cout << "0-LCD / 1-LED: ";
            cin >> sel;
            if (!sel) {
                p = citireLCD();
                lcds.adaugareSpate(p);
                p = NULL;
            }
            else if (sel == 1) {
                q = citireLED();
                leds.adaugareSpate(q);
                q = NULL;
            }
        }
        break;

        case 2:     // afisare monitoare (LED/LCD)
        {
             cout << "0-LCD / 1-LED: ";
            cin >> sel;
            if (!sel) {
                cout << "\n -- Monitoare LCD --\n";
                lcds.afisare();
            }
            else if (sel == 1) {
                cout << "\n -- Monitoare LED --\n";
                leds.afisare();
            }
        }
        break;

        case 3:     // stergere monitor (LED/LCD)
        {
            cout << "0-LCD / 1-LED: ";
            cin >> sel;

            cout << "Introduceti nume producator: ";
            cin.get();
            getline(cin, aux);


            if (!sel) {
                if (!(p = lcds.cautare(aux)))
                    cout << "Monitor inexistent.\n";
                else {
                    cout << "Monitor gasit.\n";
                    lcds.stergere(aux);
                    cout << "Monitor sters cu succes.\n";
                    p = NULL;
                }
            }
            else if (sel == 1) {
                if (!(q = leds.cautare(aux)))
                    cout << "Monitor inexistent.\n";
                else {
                    cout << "Monitor gasit.\n";
                    leds.stergere(aux);
                    cout << "Monitor sters cu succes.\n";
                    q = NULL;
                }
            }
        }
        break;

        case 4:     // cautare monitor (LED/LCD)
        {
            cout << "0-LCD / 1-LED: ";
            cin >> sel;

            cout << "Introduceti nume producator: ";
            cin.get();
            getline(cin, aux);

            if (!sel) {
                if (!(p = lcds.cautare(aux)))
                    cout << "Monitor inexistent.\n";
                else {
                    cout << "Monitor gasit.\n";
                    p->afisare();
                    p = NULL;
                }
            }
            else if (sel == 1) {
                if (!(q = leds.cautare(aux)))
                    cout << "Monitor inexistent.\n";
                else {
                    cout << "Monitor gasit.\n";
                    q->afisare();
                    q = NULL;
                }
            }
        }
        break;

        case 5:     // ordonare monitoare (LED/LCD)
        {
            cout << "0-LCD / 1-LED: ";
            cin >> sel;

            if (!sel) {
                lcds.ordonare();
            }
            else if (sel == 1) {
                leds.ordonare();
            }
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
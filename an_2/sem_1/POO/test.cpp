#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class myException
{
    string s;

public:
    myException(string s) { this-> s = s; }
    void afisare() { cout << "\nEroare: " << s << "\n"; }
};

// clasa articol (baza)
class articol
{
private:

protected:
    char tip;
    string producator;

public:
    articol(char tip, string producator);
    virtual void afisare();
    string getProducator() { return producator; }

};

// constructor articol
articol::articol(char tip, string producator)
{
    this->producator = producator;
    this->tip = tip;
}

// afisare date articol
void articol::afisare()
{
    cout << "\nTip: " << tip << "\n";
    cout << "Producator: " << producator << "\n";
}



// clasa aragaz (derivata)
class aragaz : public articol
{
private:
    string culoare;

protected:

public:
    aragaz(char tip, string producator, string culoare);
    void afisare();
};

// constructor aragaz
aragaz::aragaz(char tip, string producator, string culoare) : articol(tip, producator)
{
    this->culoare = culoare;
}

// afisare date aragaz
void aragaz::afisare()
{
    articol::afisare();
    cout << "Culoare: " << culoare << "\n\n";
}



// clasa cuptor (derivata)
class cuptor : public articol
{
private:
    int putere;

protected:

public:
    cuptor(char tip, string producator, int putere);
    void afisare();
};

// afisare date cuptor
void cuptor::afisare()
{
    articol::afisare();
    cout << "Putere: " << putere << "\n\n";
}

// constructor cuptor
cuptor::cuptor(char tip, string producator, int putere) : articol(tip, producator)
{
    this->putere = putere;
}




// citire articol
articol* citireArticol(char tip)
{
    string producator;
    articol* p = NULL;

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);

    if (tip == 'a') {   // aragaz

        string culoare;
        aragaz* a = NULL;

        cout << "Culoare: ";
        cin.get();
        getline(cin, culoare);

        a = new aragaz(tip, producator, culoare);
        p = a;
        return p;
    }   
    else {              // cuptor

        int putere;
        cuptor* q = NULL;

       
        LBL_try:
        try
        {
            
            cout << "Putere: ";
            cin >> putere;

            if (putere <= 0)
                throw (myException("puterea trebuie sa fie pozitiv !"));
        }
        catch(myException e)
        {
            e.afisare();
            goto LBL_try;
        }
        

        q = new cuptor(tip, producator, putere);
        p = q;
        return p;
    }
}

// adaugare ordonata articol in vector (dupa nume producator)
void adaugareArticol(vector <articol*> & v, articol* a)
{
    if (v.empty())
    {
        v.push_back(a);
    }
    else
    {

        auto it = v.begin();
        for(auto i : v)
        {

            if (i->getProducator() > a->getProducator())
            {
                v.insert(it, a);
                    break;
            }
            it++;
            if(it == v.end())
            {
                v.push_back(a);
                break;
            }
        }
    }
}

// citire date din fisier
void citireFisier(vector <articol*> & v)
{
    ifstream f;
    
    char tip;
    string producator;
    articol* p = NULL;

    f.open("file.txt");

    if (f.is_open()) {
        cout << "\nFisier deschis cu succes.\n";

        while (!f.eof()) {
            f >> tip;
            f >> producator;

            if (tip == 'a') {   // aragaz
                string culoare;
                aragaz* a = NULL;

                f >> culoare;

                a = new aragaz(tip, producator, culoare);
                p = a;
                adaugareArticol(v, p);
            }
            else {              // cuptor
                int putere;
                cuptor* q = NULL;

                f >> putere;

                q = new cuptor(tip, producator, putere);
                p = q;
                adaugareArticol(v, q);
            }
        }

        cout << "Citire date din fisier cu succes.\n";
    }
    else
        cout << "\nEroare la deschidere fisierului.\n";
}

// stergere articole dupa producator
void stergeArticol(vector <articol*> & v, string & nume)
{
    vector <articol*>::iterator i;

    for (i = v.begin(); i != v.end(); i++)
        if ((*i)->getProducator() == nume) {
  
            cout << "\nArticol gasit.\n";
            if (i == v.end()) 
                v.erase(i-1);
            else
                v.erase(i);
            cout << "Articol sters.\n";
        }
}


void menu()
{
    cout << "\n--------------- Meniu Interactiv ---------------\n";
    cout << "0. Iesire\n";
    cout << "1. Citire date din fisier.\n";
    cout << "2. Introducere articol nou\n";
    cout << "3. Afisare articole in ordinea producatorului\n";
    cout << "4. Stergere articole dupa producator\n";
    cout << "---------------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

int main()
{
    int opt;
    vector <articol*> v;


    do
    {
        menu();
        cin >> opt;
        cout << "\n";

        switch (opt)
        {
        case 0:         // iesire
        {
            exit(EXIT_SUCCESS);
        }
        break;

        case 1:         // citire date din fisier
        {
            citireFisier(v);
        }
        break;

        case 2:         // introducere articol nou
        {
            articol* p = NULL;
            char tip;

            cout << "\n-- Introducere date articol --\n";
            cout << "Tip (a - aragaz / c - cuptor): ";
            cin.get();
            cin.get(tip);
            
            p = citireArticol(tip);
            adaugareArticol(v, p);

            
        }
        break;

        case 3:         // afisare articole in ordinea producatorului
        {
           vector <articol*>::iterator i;

            for (i = v.begin(); i != v.end(); i++)
                (*i)->afisare();
                
        }
        break;

        case 4:         // stergere articole dupa producator
        {
            string nume;

            cout << "\nIntroduceti nume producator: ";
            cin.get();
            getline(cin, nume);

            for (int i = 0; i < v.size(); i++)
                stergeArticol(v, nume);
        }
        break;
        
        default:        // eroare
        {
            cout << "\nEroare. Optiune nedefinita.\n";
        }
        break;
        }
    } while (opt);
    


    return 0;
}
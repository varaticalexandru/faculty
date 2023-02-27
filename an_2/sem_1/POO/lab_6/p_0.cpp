#include <iostream>

using namespace std;


class Forma
{
    public:
        virtual void Afisare()
        {
            cout << "Forma -> clasa de baza" << endl;
        }
};


class Punct : public Forma
{
    public:
        void Afisare()
        {
            cout << "Punct -> clasa derivata Punct" << endl;
        }
};



int main(int argc, char** argv)
{
    // functii apelate prin pointer la Forma
    Forma* pf = new Forma();
    pf->Afisare();

    // functii apelate prin pointer la Forma, initializat prin pointer la Punct
    Punct* pp = new Punct();
    pf = pp;
    // comportament polimorfic
    pf->Afisare();

    // functii apelate prin obiect de tip Forma
    Forma f;
    f.Afisare();

    // functii apelate prin obiect de tip Punct
    Punct p;
    p.Afisare();










    return 0;
}
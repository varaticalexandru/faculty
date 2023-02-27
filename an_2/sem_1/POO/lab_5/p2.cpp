#include <iostream>

using namespace std;

class Forma
{
    

    public:
        virtual void afisare();

};

Forma::afisare();

class Punct : public Forma
{


    public:
        void afisare();
};

Forma::afisare()
{

}
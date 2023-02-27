#include <iostream>

using namespace std;

// crearea clasei template
template <class TipVector> class Vector {
    TipVector v[20];   // elementele vectorului
    int index;          // index

    public:
        // constructor
        Vector()
        {
            index = 0;
        }

        // introducere obiect in vector
        void Introducere(TipVector ob); 

        // afisare obiect(e) din vector
        void Afisare();
};

template <class TipVector> void Vector<TipVector>::Introducere(TipVector ob)
{
    v[index] = ob;
    index++;
}

template <class TipVector> void Vector<TipVector>::Afisare()
{
    if (!index)
        cout << "Vectorul este gol !\n";
    else
        for (int i = 0; i < index; i++)
            cout << v[i] << " ";
}


int main(int argc, char** argv)
{
    // creare vectori de caractere

    Vector <char> v1;

    v1.Introducere('s');
    v1.Introducere('a');
    v1.Introducere('n');
    v1.Introducere('y');
    v1.Introducere('a');

    v1.Afisare();

    Vector <int> v2;

    v2.Introducere(3);
    v2.Introducere(4);
    v2.Introducere(0);

    v2.Afisare();



    return 0;
}
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Persoana
{
    string nume;
    string prenume;
    unsigned varsta;

    public:
        Persoana(string, string, unsigned);

};

class Profesor : public Persoana
{
    string departament;
    string grad;
    int salariu;

    public:
        Profesor(string, string, unsigned, string, string, unsigned);
};

class Student : public Persoana
{
    unsigned nr_matricol;
    string camin;
    float medie_anuala;

    public:
        Student(string, string, unsigned, unsigned, string, float);
};

Persoana::Persoana(string nume, string prenume, unsigned varsta)
{   
    // constructor

    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
}

Profesor::Profesor(string nume, string prenume, unsigned varsta, string departament, string grad, unsigned salariu)
    : Persoana(nume, prenume, varsta)
{
    // constructor

    this->departament = departament;
    this->grad = grad;
    this->salariu = salariu;
}

Student::Student(string nume, string prenume, unsigned varsta, unsigned nr_matricol, string camin, float medie_anuala)
    : Persoana(nume, prenume, varsta)
{
    this->nr_matricol = nr_matricol;
    this->camin = camin;
    this->medie_anuala = medie_anuala;
}








int main(int argc, char** argv)
{
    

    


    return 0;
}
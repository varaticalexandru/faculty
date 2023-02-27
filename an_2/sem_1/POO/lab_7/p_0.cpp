#include <iostream>
#include <string>

using namespace std;

class Student
{
    public:
        string nume;
        string prenume;
        unsigned varsta;
        unsigned nr_matricol;

        // constructor
        Student(string nume="", string prenume="", unsigned varsta=0, unsigned nr_matricol=0)
        
        {
            this->nume = nume;
            this->prenume = prenume;
            this->varsta = varsta;
            this->nr_matricol = nr_matricol;
        }

        friend ostream & operator << (ostream &, Student &);
        friend istream & operator >> (istream &, Student &);
};

// supraincarcarea operatorului << (inserare)
ostream & operator << (ostream & out, Student & st)
{   
    out << "Nume: " << st.nume << endl;
    out << "Prenume: " << st.prenume << endl;
    out << "Varsta: " << st.varsta << endl;
    out << "Nume: " << st.nr_matricol << endl << endl;

    return out;
}

// supraincarcarea operatorului >> (extragere)
istream & operator >> (istream & in, Student & st)
{
    cout << "Nume: ";
    getline(in, st.nume);

    cout << "Prenume: ";
    getline(in, st.prenume);

    cout << "Varsta: ";
    in >> st.varsta;

    cout << "Nr. matricol: ";
    in >> st.nr_matricol;

    cout << "\n";

    return in;
}


int main(int argc, char** argv)
{
    Student obj_1, obj_2;

    cin >> obj_1;
    cout << obj_1;


    return 0;
}
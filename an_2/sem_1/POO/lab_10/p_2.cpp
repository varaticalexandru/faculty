#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

// clasa student
class student
{
private:
    string nume, rol, adresa, cod_postal;

protected:

public:
    student(string nume, string rol, string adresa, string cod_postal);
    ~student();
    void afisare();

};

// constructor student
student::student(string nume="", string rol="", string adresa="", string cod_postal="")
{
    this->nume = nume;
    this->rol = rol;
    this->adresa = adresa;
    this->cod_postal = cod_postal;
}

// destructor student
student::~student()
{
    cout << "\nDatele studentului au fost eliberate din memorie.\n";
}

// afisare date student
void student::afisare()
{
    cout << "\nNume: " << nume << "\n";
    cout << "Rol: " << rol << "\n";
    cout << "Adresa: " << adresa << "\n";
    cout << "Cod postal: " << cod_postal << "\n";
}


// meniu
void menu()
{
    cout << "\n------------- Meniu Interactiv -------------\n";
    cout << "0. Iesire\n";
    cout << "1. Adaugare studenti\n";
    cout << "2. Afisare studenti\n";
    cout << "----------------------------------------------\n";
    cout << "Optiunea dvs: ";
}

int main(int argc, char** argv)
{
    system("cls");

    list <student*> l;                  // lista de ptr la student
    int i = 0;
    student* s = NULL;
    int opt;
    string nume, rol, adresa, cod_postal;

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

        case 1:     // adaugare student in lista
        {
            cout << "\n-- Introduceti date student --\n";
            
            cout << "Nume: ";
            cin.get();
            getline(cin, nume);

            cout << "Rol: ";
            cin.get();
            getline(cin, rol);

            cout << "Adresa: ";
            cin.get();
            getline(cin, adresa);

            cout << "Cod postal: ";
            cin.get();
            getline(cin, cod_postal);

            s = new student(nume, rol, adresa, cod_postal);
            l.push_back(s);
        }    
        break;

        case 2:     // afisare lista studenti
        {
            cout << "\n-- Lista studenti --\n";

            for (auto p: l)
                p->afisare();
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
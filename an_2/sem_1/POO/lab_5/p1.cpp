#include <iostream>
#include <string.h>
#include <conio.h>
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

class Monitor
{
    protected:
        string producator;
        float diagonala;
        float pret;

    public:
        Monitor(string, float, float);
        //virtual void Afisare() {};

};

Monitor::Monitor(string producator, float diagonala, float pret)
{
    this->producator = producator;
    this->diagonala = diagonala;
    this->pret = pret;
}

class LCD : public Monitor
{
    float timp_rs;
    string tip_ecran;
    int nr_conectori;

    LCD* head;
    LCD* next;

    public:
        LCD(string, float, float, float, string, int);
        void Adaugare();
        void Afisare();
        void Stergere();
        void Cautare();
        void Ordonare();
        void Swap(LCD*, LCD*);
};

LCD::LCD(string producator, float diagonala, float pret, float timp_rs, string tip_ecran, int nr_conectori)
    : Monitor(producator, diagonala, pret)
{   
    this->timp_rs = timp_rs;
    this->tip_ecran = tip_ecran;
    this->nr_conectori = nr_conectori;
    this->next = NULL;
}


class LED : public Monitor
{
    string format_ecran;
    string iluminare;
    string boxe_integrate;

    LED* head;
    LED* next;

    public:
        LED(string, float, float, string, string, string);
        void Afisare();
        void Adaugare();
        void Stergere();
        void Cautare();
        void Ordonare();
        void Swap(LED*, LED*);
};

LED::LED(string producator, float diagonala, float pret, string format_ecran, string iluminare, string boxe_integrate)
    : Monitor(producator, diagonala, pret)
{
    this->format_ecran = format_ecran;
    this->iluminare = iluminare;
    this->boxe_integrate = boxe_integrate;
    this->next = NULL;
}


void LCD::Adaugare()
{
    string producator, tip_ecran;
    float diagonala, pret, timp_rs;
    int nr_conectori;
    LCD* p = NULL;

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);

    cout << "Diagonala: ";
    cin >> diagonala;

    cout << "Pret: ";
    cin >> pret;

    cout << "Timp raspuns: ";
    cin >> timp_rs;

    cout << "Tip ecran: ";
    cin.get();
    getline(cin, tip_ecran);

    cout << "Nr. conectori: ";
    cin >> nr_conectori;

    p = new LCD(producator, diagonala, pret, timp_rs, tip_ecran, nr_conectori);
    p->next = head;
    head = p;
}

void LCD::Afisare()
{
    LCD* p = head;
    int i = 0;

    while (p) {

        cout << "[" << i << "]:\n";

        cout << "Producator: " << p->producator << endl;

        cout << "Diagonala: " << p->diagonala << endl;

        cout << "Pret: " << p->pret << endl;

        cout << "Timp raspuns: " << p->timp_rs << endl;

        cout << "Tip ecran: " << p->tip_ecran << endl;

        cout << "Nr. conectori: " << p->nr_conectori << endl;

        cout << endl << endl;
        
        p = p->next;
    }
}

void LCD::Stergere()
{
    LCD* p = head;
    string prod;

    cout << "Introduceti producatorul monitorului sters: ";
    cin.get();
    getline(cin, prod);
    
    if (p)
        while (p->next && p->next->producator.compare(prod)){
            p = p->next;
        }
    
    if (p->next->producator.compare(prod)) {
        cout << "Eroare. Nu s-a gasit monitorul. \n";
    }
    else{
        cout << "Monitor gasit. \n";
        LCD* temp = p->next;
        p->next = p->next->next;
        delete temp;
        cout << "Monitor sters. \n";
    }
}

void LCD::Cautare()
{
    LCD* p = head;
    string prod;
    int gasit = 0;

    cout << "Introduceti producatorul monitorului cautat: ";
    cin.get();
    getline(cin, prod);

    while (p){
        if (!p->producator.compare(prod)) {
            gasit = 1;
            cout << "Monitor gasit.\n";

            cout << "Producator: " << p->producator << endl;

            cout << "Diagonala: " << p->diagonala << endl;

            cout << "Pret: " << p->pret << endl;

            cout << "Timp raspuns: " << p->timp_rs << endl;

            cout << "Tip ecran: " << p->tip_ecran << endl;

            cout << "Nr. conectori: " << p->nr_conectori << endl;

            cout << endl << endl;

            break;
            
        }

        p = p->next;
    }

    if (!gasit) {
         cout << "Monitorul inexistent.\n";
    }
}

void LCD::Swap(LCD* p1, LCD* p2)
{
    string producator_temp, tip_ecran_temp;
    float diagonala_temp, pret_temp, timp_rs_temp;
    int nr_conectori_temp;

    producator_temp = p1->producator;
    tip_ecran_temp = p1->tip_ecran;
    diagonala_temp = p1->diagonala;
    pret_temp = p1->pret;
    timp_rs_temp = p1->timp_rs;
    nr_conectori_temp = p1->nr_conectori;

    p1->producator = p2->producator;
    p1->tip_ecran = p2->tip_ecran;
    p1->diagonala = p2->diagonala;
    p1->pret = p2->pret;
    p1->timp_rs = p2->timp_rs;
    p1->nr_conectori = p2->nr_conectori;

    p2->producator = producator_temp;
    p2->tip_ecran = tip_ecran_temp;
    p2->diagonala = diagonala_temp;
    p2->pret = pret_temp;
    p2->timp_rs = timp_rs_temp;
    p2->nr_conectori = nr_conectori_temp;
    
}

void LCD::Ordonare()
{
    int ok;

    LCD *p = head;

    if (!p)
        return;
    
    do
    {
        ok = 1;
        p = head;

        while (p->next){
            if (p->producator > p->next->producator) {
                ok = 0;
                Swap(p, p->next);
            }

            p = p->next;
        }

    } while (!ok);
    
}




void LED::Adaugare()
{
    string producator, format_ecran, iluminare, boxe_integrate;
    float diagonala, pret;
    LED* p = NULL;

    cout << "Producator: ";
    cin.get();
    getline(cin, producator);

    cout << "Diagonala: ";
    cin >> diagonala;

    cout << "Pret: ";
    cin >> pret;

    cout << "Format ecran: ";
    cin.get();
    getline(cin, format_ecran);

    cout << "Iluminare: ";
    cin.get();
    getline(cin, iluminare);

    cout << "Boxe integrate: ";
    cin.get();
    getline(cin, boxe_integrate);

    p = new LED(producator, diagonala, pret, format_ecran, iluminare, boxe_integrate);
    p->next = head;
    head = p;
}

void LED::Afisare()
{
    LED* p = head;
    int i = 0;

    while (p) {

        cout << "[" << i << "]:\n";

        cout << "Producator: " << p->producator << endl;

        cout << "Diagonala: " << p->diagonala << endl;

        cout << "Pret: " << p->pret << endl;

        cout << "Format ecran: " << p->format_ecran << endl;

        cout << "Iluminare: " << p->iluminare << endl;

        cout << "Boxe integrate: " << p->boxe_integrate << endl;

        cout << endl << endl;

        i++;
        p = p->next;
    }
}

void LED::Stergere()
{
    LED* p = head;
    string prod;

    cout << "Introduceti producatorul monitorului sters: ";
    cin.get();
    getline(cin, prod);
    
    if (p)
        while (p->next && p->next->producator.compare(prod)){
            p = p->next;
        }
    
    if (p->next->producator.compare(prod)) {
        cout << "Eroare. Nu s-a gasit monitorul. \n";
    }
    else{
        cout << "Monitor gasit. \n";
        LED* temp = p->next;
        p->next = p->next->next;
        delete temp;
        cout << "Monitor sters. \n";
    }
}

void LED::Cautare()
{
    LED* p = head;
    string prod;
    int gasit = 0;

    cout << "Introduceti producatorul monitorului cautat: ";
    cin.get();
    getline(cin, prod);

    while (p){
        if (!p->producator.compare(prod)) {
            gasit = 1;
            cout << "Monitor gasit.\n";

            cout << "Producator: " << p->producator << endl;

            cout << "Diagonala: " << p->diagonala << endl;

            cout << "Pret: " << p->pret << endl;

            cout << "Format ecran: " << p->format_ecran << endl;

            cout << "Iluminare: " << p->iluminare << endl;

            cout << "Boxe integrate: " << p->boxe_integrate << endl;

            cout << endl << endl;

            break;
            
        }

        p = p->next;
    }

    if (!gasit) {
         cout << "Monitorul inexistent.\n";
    }
}

void LED::Swap(LED* p1, LED* p2)
{
    string producator_temp, format_ecran_temp, iluminare_temp, boxe_integrate_temp;
    float diagonala_temp, pret_temp;

    producator_temp = p1->producator;
    format_ecran_temp = p1->format_ecran;
    diagonala_temp = p1->diagonala;
    pret_temp = p1->pret;
    iluminare_temp = p1->iluminare;
    boxe_integrate_temp = p1->boxe_integrate;

    p1->producator = p2->producator;
    p1->format_ecran = p2->format_ecran;
    p1->diagonala = p2->diagonala;
    p1->pret = p2->pret;
    p1->iluminare = p2->iluminare;
    p1->boxe_integrate = p2->boxe_integrate;

    p2->producator = producator_temp;
    p2->format_ecran = format_ecran_temp;
    p2->diagonala = diagonala_temp;
    p2->pret = pret_temp;
    p2->iluminare = iluminare_temp;
    p2->boxe_integrate = boxe_integrate_temp;
    
}

void LED::Ordonare()
{
    int ok;

    LED *p = head;

    if (!p)
        return;
    
    do
    {
        ok = 1;
        p = head;

        while (p->next){
            if (p->producator > p->next->producator) {
                ok = 0;
                Swap(p, p->next);
            }

            p = p->next;
        }

    } while (!ok);

}


void SelectAdaugare(LCD* lcd, LED* led)
{
    int sel;

    cout << "0 - LCD, 1 - LED: ";
    cin >> sel;
    cout << endl;

    switch (sel)
    {
    case 0:
        lcd->Adaugare();
    break;

    case 1:
        led->Adaugare();
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita.\n";
    break;
    }
}

void SelectAfisare(LCD* lcd, LED* led)
{
    int sel;

    cout << "0 - LCD, 1 - LED: ";
    cin >> sel;
    cout << endl;

    switch (sel)
    {
    case 0:
        lcd->Afisare();
    break;

    case 1:
        led->Afisare();
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita.\n";
    break;
    }
}

void SelectStergere(LCD* lcd, LED* led)
{
    int sel;

    cout << "0 - LCD, 1 - LED: ";
    cin >> sel;
    cout << endl;

    switch (sel)
    {
    case 0:
        lcd->Stergere();
    break;

    case 1:
        led->Stergere();
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita.\n";
    break;
    }
}

void SelectCautare(LCD* lcd, LED* led)
{
    int sel;

    cout << "0 - LCD, 1 - LED: ";
    cin >> sel;
    cout << endl;

    switch (sel)
    {
    case 0:
        lcd->Cautare();
    break;

    case 1:
        led->Cautare();
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita.\n";
    break;
    }
}

void SelectOrdonare(LCD* lcd, LED* led)
{
    int sel;

    cout << "0 - LCD, 1 - LED: ";
    cin >> sel;
    cout << endl;

    switch (sel)
    {
    case 0:
        lcd->Ordonare();
    break;

    case 1:
        led->Ordonare();
    break;
    
    default:
        cout << "Eroare. Optiune nedefinita.\n";
    break;
    }
}

void Menu()
{
    printf("\n-------------------- Meniu Interactiv --------------------\n"
            "1. Adaugare monitor LED/LCD\n"
            "2. Afisare monitoare LED/LDC\n"
            "3. Stergere monitor LED/LCD\n"
            "4. Cautare monitor LED/LDC\n"
            "5. Ordonare monitoare LED/LCD\n"
            "6. Iesire\n"
            "---------------------------------------------------------\n"
            "Optiunea dvs: "
    );
}

int main() 
{
    int opt;
    LCD* lcd = new LCD("", 0, 0, 0, "", 0);
    LED* led = new LED("", 0, 0, "", "", ""); 


    do
    {
        Menu();
        cin >> opt;
        printf("\n");

        switch (opt)
        {
        case 1:     // adaugare
            SelectAdaugare(lcd, led);
        break;
        
        case 2:     // afisare
            SelectAfisare(lcd, led);
        break;

        case 3:     // stergere
            SelectStergere(lcd, led);
        break;

        case 4:     // cautare
            SelectCautare(lcd, led);
        break;
        
        case 5:     // ordonare
            SelectOrdonare(lcd, led);
        break;

        case 6:     // iesire
            exit(EXIT_SUCCESS);
        break;

        default:
            printf("Eroare. Optiune nedefinita. \n");
        break;
       } 
    } while (opt != 6);
    
    
    return 0;
}



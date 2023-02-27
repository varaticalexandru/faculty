#include <iostream>
#include <vector>

using namespace std;





int main(int argc, char** argv)
{
    system("cls");

    vector <int> v;     // vector care va stoca int
    int i;

    // afisarea dimensiunii vectorului
    cout << v.size() << "\n";

    // adaugare de 5 valori in vector
    for (int i = 0; i < 5; i++)
        v.push_back(i);

    // afisarea elementelor vectorului (iterator)
    vector<int>::iterator it = v.begin();

    while (it != v.end()) {
        cout << *it << " ";
        it++;
    }

    cout << "\n";

    // afisarea elementelor vectorului (iterator)
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << "\n";

    // afisarea dimensiunii vectorului extins
    cout << v.size() << "\n";


    return 0;
}
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// afiseaza elementele listei STL list<int>
void showList(list <int> l)
{
    list<int>::iterator it;

    cout << "\n";

    for (it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    
    cout << "\n";
}



int main(int argc, char** argv)
{
    system("cls");


    list <int> l1, l2;

    for (int i = 0; i < 10; i++) {
        l1.push_back(i * 2);
        l2.push_front(i * 3);
    }

    cout << "List 1:\n";
    showList(l1);

    cout << "head-ul listei 1: " << l1.front() << "\n";
    cout << "tail-ul listei 1: " << l1.back() << "\n";

    cout << "List 1 reversed:\n";
    l1.reverse();
    showList(l1);

    cout << "\nList 2:\n";
    showList(l2);

    cout << "head-ul listei 2: " << l2.front() << "\n";
    cout << "tail-ul listei 2: " << l2.back() << "\n";

    cout << "List 2 sorted:\n";
    l2.sort();
    showList(l2);


    return 0;
}
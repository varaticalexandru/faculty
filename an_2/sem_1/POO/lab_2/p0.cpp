#include <iostream>

using namespace std;

void neg(int *);
void neg_(int &i);
void swap(int &, int &);

int main(int argc, char** argv)
{
    int in = 100;
    int a = 2, b = 0;

    system("cls");

    swap(a, b);
    cout << a << b << endl;


    return 0;
}

void neg(int *i)
{
    *i =  -(*i);
}

void neg_(int &i)
{
    i = -i;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
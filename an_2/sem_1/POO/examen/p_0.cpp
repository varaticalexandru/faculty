#include <exception>
#include <iostream>
#include <conio.h>

using namespace std;

class baza
{
	int i;

public:
	baza(int i=0) { this->i = i; }
	int get_i() { return i; }
	int adunare(int x, int y) { cout << "Adunare din clasa de baza\n"; }
};

class derivat : public baza
{
public:
	derivat(int i=0) : baza(i) {} 
	//int adunare(float x, float y) { cout << "Adunare din clasa de derivat\n"; }
	int adunare(int x, int y) { cout << "Adunare din clasa de derivat 2\n"; }
};


int main()
{
	baza ob = 5;
	cout << ob.get_i();

	_getch();
	return 0;
}

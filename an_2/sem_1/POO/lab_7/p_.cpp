#include <iostream>

using namespace std;

class Complex
{
    int real, imag;

    public:
        Complex(int real = 0, int imag = 0)
        {
            this->real = real;
            this->imag = imag;
        }

        friend ostream & operator << (ostream &, Complex &);
        friend istream & operator >> (istream &, Complex &);
};

ostream & operator << (ostream & out, Complex & c)
{
    out << c.real;
    out << "+i" << c.imag << endl;
    
    return out;
}

istream & operator >> (istream & in, Complex & c)
{
    cout << "real part: ";
    in >> c.real;

    cout << "imaginary part: ";
    in >> c.imag;

    return in;
}



int main(int argc, char** argv)
{
    Complex z1, z2, z3;

    cin >> z1;
    cout << z1;



    return 0;
}
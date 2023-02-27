#include <iostream>
using namespace std;

class cl {
    
    public:
        int i;
        cl(void) {i = 0;}
        cl(int i) {this->i = i;}
        int get_i(void) {return this->i;}
};

int main(int argc, char** argv)
{
    // cl arr[3];
    cl ob = cl(1);
    int* p = NULL;

    p = &ob.i;
    cout << *p;

    return 0;
}
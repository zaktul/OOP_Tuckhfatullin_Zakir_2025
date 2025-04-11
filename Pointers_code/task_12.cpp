#include <iostream>
using namespace std;

const int MAX = 100;
float fmemory[MAX]; // симулируемая память под float
int pmemory[MAX];   // симулируемая память под указатели
int fmem_top = 0;
int pmem_top = 0;

class Float {
private:
    int addr;

public:
    Float(float value) {
        addr = fmem_top++;
        fmemory[addr] = value;
    }

    int operator&() {
        return addr;
    }
};

class ptrFloat {
private:
    int addr;

public:
    ptrFloat(int a) {
        addr = pmem_top++;
        pmemory[addr] = a;
    }

    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.234f;
    Float var2 = 5.678f;

    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7.123f;
    *ptr2 = 8.456f;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}

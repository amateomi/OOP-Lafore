#include <iostream>

using namespace std;

float fmemory[1000];
int fmem_top = 0;
int pmemory[1000];
int pmem_top;

class Float {
private:
    int addr;

public:
    Float(float f) {
        fmemory[fmem_top] = f;
        addr = fmem_top++;
    }

    int operator&() const {
        return addr;
    }
};

class PtrFloat {
private:
    int addr;

public:
    PtrFloat(int i) {
        pmemory[pmem_top] = i;
        addr = pmem_top++;
    }

    float &operator*() const {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    Float var1 = 1.2;
    Float var2 = 5.6;

    PtrFloat ptr1 = &var1;
    PtrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    *ptr1 = 7;
    *ptr2 = 8;

    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}

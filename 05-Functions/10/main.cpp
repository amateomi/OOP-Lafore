#include <iostream>

using namespace std;

int globalCount;

void foo1() {
    cout << "foo1 was called " << globalCount++ << " times." << endl;
}

void foo2() {
    static int localCount;

    cout << "foo2 was called " << localCount++ << " times." << endl;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        foo1();
        foo2();
    }

    return 0;
}

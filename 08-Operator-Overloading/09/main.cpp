#include <cstdlib>
#include <iostream>

using namespace std;

class Array {
private:
    static const int LIMIT = 100;

    int array[LIMIT];

    int minIndex;

    int maxIndex;

public:
    Array() : array(), minIndex(0), maxIndex(LIMIT - 1) {}

    Array(int minInd, int maxInd) : array() {
        int range = maxInd - minInd;
        if (range >= LIMIT) {
            cout << endl << "Buffer is too little!" << endl;
            exit(1);
        }

        minIndex = minInd;
        maxIndex = maxInd;
    }

    int &operator[](int i) {
        if (i < minIndex || i > maxIndex) {
            cout << endl << "Index out of range!" << endl;
        }

        return array[i - minIndex];
    }
};

int main() {
    Array array(-50, 49);

    array[0] = 123;

    cout << array[0];

    return 0;
}

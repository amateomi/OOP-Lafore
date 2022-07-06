#include <iostream>
#include <cstdlib>

using namespace std;

class Array {
protected:
    static const int MAX_ARRAY_SIZE = 100;

private:
    int array[MAX_ARRAY_SIZE];

public:
    Array() : array() {}

    int &operator[](int i) {
        if (i < 0 || i >= MAX_ARRAY_SIZE) {
            cout << "Incompatible index!" << endl;
            exit(1);
        }
        return array[i];
    }
};

class SafeArray : public Array {
private:
    int minIndex;

    int maxIndex;

public:
    SafeArray() : Array(), minIndex(0), maxIndex(MAX_ARRAY_SIZE - 1) {}

    SafeArray(int minInd, int maxInd) : Array() {
        int range = maxInd - minInd;
        if (range >= MAX_ARRAY_SIZE) {
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

        return Array::operator[](i - minIndex);
    }
};

int main() {
    SafeArray safeArray(1000, 1100);

    safeArray[1050] = 7;

    cout << safeArray[1050] << endl;

    return 0;
}

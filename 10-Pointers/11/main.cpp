#include <cstdlib>
#include <iostream>

using namespace std;

class Array {
protected:
    static const int NUM_ARRAYS = 10;

    static const int ARRAY_SIZE = 10;

private:
    int *array[NUM_ARRAYS];

public:
    Array() : array() {
        for (int i = 0; i < NUM_ARRAYS; ++i) {
            *(array + i) = new int[ARRAY_SIZE];
        }
    }

    ~Array() {
        for (int i = 0; i < NUM_ARRAYS; ++i) {
            delete[] *(array + i);
        }
    }

    int &operator[](int n) {
        int i = n / ARRAY_SIZE;
        int j = n % ARRAY_SIZE;

        if (i >= NUM_ARRAYS) {
            cout << "An attempt to overstep the bounds of an array!" << endl;
            exit(1);
        }

        return *(*(array + i) + j);
    }

    static int getArraySize() {
        return NUM_ARRAYS * ARRAY_SIZE;
    }
};

int main() {
    Array array;

    for (int i = 0; i < Array::getArraySize(); ++i) {
        array[i] = i;
    }

    for (int i = 0; i < Array::getArraySize(); ++i) {
        cout << array[i] << ' ';
    }

    return 0;
}

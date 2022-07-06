#include <iostream>
#include <cmath>

using namespace std;

class Array {
private:
    static const int MAX_SIZE = 100;

    int array[MAX_SIZE];

public:
    void put(int i, int n) {
        if (i > 0 && i < MAX_SIZE) {
            array[i] = n;
        } else {
            cout << endl << "Incompatible index!" << endl;
        }
    }

    int get(int i) const {
        if (i > 0 && i < MAX_SIZE) {
            return array[i];
        } else {
            cout << endl << "Incompatible index!" << endl;
        }
    }
};

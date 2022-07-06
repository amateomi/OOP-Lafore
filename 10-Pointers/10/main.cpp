#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    const int ARRAY_SIZE = 10;
    const int NUM_ARRAYS = 10;

    int *ap[NUM_ARRAYS];
    for (int i = 0; i < NUM_ARRAYS; ++i) {
        *(ap + i) = new int[ARRAY_SIZE];
    }

    for (int i = 0; i < NUM_ARRAYS; ++i) {
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            ap[i][j] = (i + j) * (i + j);
        }
    }

    for (int i = 0; i < NUM_ARRAYS; ++i) {
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            cout << setw(4) << ap[i][j];
        }
        cout << endl;
    }

    return 0;
}

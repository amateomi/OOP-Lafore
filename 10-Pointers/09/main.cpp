#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;

    int a0[SIZE];
    int a1[SIZE];
    int a2[SIZE];
    int a3[SIZE];
    int a4[SIZE];
    int a5[SIZE];
    int a6[SIZE];
    int a7[SIZE];
    int a8[SIZE];
    int a9[SIZE];

    int *ap[SIZE] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            ap[i][j] = i + j;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << ap[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

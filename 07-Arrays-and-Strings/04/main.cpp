#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int maxInt(const int array[], const int SIZE) {
    int max = array[0];
    int indexMax;

    for (int i = 0; i < SIZE; ++i) {
        if (max < array[i]) {
            max = array[i];
            indexMax = i;
        }
    }

    return indexMax;
}

int main() {
    const int SIZE = 15;
    int array[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        array[i] = rand() % 20 + 1;
        cout << array[i] << ' ';
    }
    cout << endl;

    cout << array[maxInt(array, SIZE)];

    return 0;
}

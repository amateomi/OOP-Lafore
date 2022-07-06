#include <iostream>

using namespace std;

template<class T>
T arrayMax(T array[], int size) {
    T max = array[0];

    for (int i = 1; i < size; ++i) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    return max;
}

int main() {
    int arr1[] = {3, 7, 9, 11};

    cout << arrayMax(arr1, 4) << endl;

    return 0;
}

#include <iostream>

using namespace std;

void addArrays(float *arr1, float *arr2, float *arr3, size_t size) {
    for (int i = 0; i < size; ++i) {
        *arr3++ = *arr1++ + *arr2++;
    }
}

int main() {
    const size_t size = 5;

    float arr1[size] = {1, 2, 3, 4, 5};
    float arr2[size] = {1, 3, 5, 7, 9};
    float arr3[size];

    addArrays(arr1, arr2, arr3, size);

    for (int i = 0; i < size; ++i) {
        cout << arr3[i] << ' ';
    }

    return 0;
}

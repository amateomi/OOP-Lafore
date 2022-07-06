#include <iostream>

using namespace std;

template<class T>
T getAverage(T array[], int size) {
    T average = 0;

    for (int i = 0; i < size; ++i) {
        average += array[i];
    }
    return average / size;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    long arr2[] = {1L, 2L, 3L, 4L, 5L, 6L};
    double arr3[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    char arr4[] = {1, 2, 3, 4, 5, 6};
    short arr5[6];

    cout << getAverage(arr1, 6) << endl;
    cout << getAverage(arr2, 6) << endl;
    cout << getAverage(arr3, 6) << endl;
    cout << getAverage(arr4, 6) << endl;
    cout << getAverage(arr5, 6) << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    const int SIZE = 4;
    float array[SIZE];
    float count = 0;
    float *ptr = array;

    for (ptr += SIZE - 1; ptr >= array; --ptr) {
        cout << "Enter number:" << endl;
        cin >> array[ptr - array];
        count += array[ptr - array];
    }
    cout << "Average is " << count / SIZE;

    return 0;
}

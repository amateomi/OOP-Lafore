#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    float array[20];
    for (int i = 0; i < 20; ++i) {
        array[i] = (rand() % 20) * 1.5;
        cout << array[i] << ' ';
    }
    cout << endl;
    cout << endl;

    sort(array, array + 20);

    for (int i = 0; i < 20; ++i) {
        cout << array[i] << ' ';
    }

    return 0;
}

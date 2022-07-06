#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int SIZE = 20;

    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i;
        cout << arr[i] << ' ';
    }
    cout << endl;

    int first1, last1, first2;
    cin >> first1 >> last1 >> first2;

    copy(arr + first1, arr + last1 + 1, arr + first2);

    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}


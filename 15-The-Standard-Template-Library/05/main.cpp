#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int array[5];
    set<int> set1;
    vector<int> vector1(10);

    for (int i = 0; i < 5; ++i) {
        array[i] = 2 * i;
        set1.insert(2 * i + 1);
    }

    cout << "Array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl << "Set:" << endl;
    for (set<int>::iterator i = set1.begin(); i != set1.end(); ++i) {
        cout << *i << ' ';
    }

    merge(array, array + 5, set1.begin(), set1.end(), vector1.begin());
    cout << endl << "Vector:" << endl;
    for (vector<int>::iterator i = vector1.begin(); i != vector1.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;

    return 0;
}

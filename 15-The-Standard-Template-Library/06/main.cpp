#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int SIZE = 10;
    vector<int> vec(SIZE);

    for (int i = 0; i < SIZE; ++i) {
        vec[i] = i;
    }

    vector<int>::iterator begin = vec.begin();
    vector<int>::reverse_iterator end = vec.rbegin();

    for (int i = 0; i < vec.size() / 2; ++i) {
        swap(*begin++, *end++);
    }

    vector<int>::iterator i;
    for (i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }

    return 0;
}


#include <iostream>

using namespace std;

void swap(int &n, int &m);

int main() {
    int n = 5;
    int m = 8;

    cout << n << ' ' << m << endl;

    swap(n, m);

    cout << n << ' ' << m << endl;

    return 0;
}

void swap(int &n, int &m) {
    int temp = n;
    n = m;
    m = temp;
}
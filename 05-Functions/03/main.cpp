#include <iomanip>
#include <iostream>

using namespace std;

void setSmallerToZero(int &n, int &m);

int main() {
    int n;
    int m;

    cout << "Enter two integer numbers:" << endl;
    cin >> n >> m;

    cout << setw(9) << "Before:" << setw(11) << n << setw(11) << m << endl;
    setSmallerToZero(n, m);
    cout << setw(9) << "After:" << setw(11) << n << setw(11) << m << endl;

    return 0;
}


void setSmallerToZero(int &n, int &m) {
    if (n != m) {
        (n < m) ? n = 0 : m = 0;
    }
}
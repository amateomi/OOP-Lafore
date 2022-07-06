#include <iostream>

using namespace std;

int main() {
    int number;

    cout << (number = 10) << endl
         << (number *= 2) << endl
         << --number << endl;

    return 0;
}

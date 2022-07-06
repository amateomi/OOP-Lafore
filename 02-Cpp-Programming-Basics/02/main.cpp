#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int date = 1990;

    cout << date++ << setw(10) << 135 << endl
         << date++ << setw(10) << 7290 << endl
         << date++ << setw(10) << 11300 << endl
         << date << setw(10) << 16200 << endl;

    return 0;
}

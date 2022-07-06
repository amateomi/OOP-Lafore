#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter number:";
    cin >> number;

    for (int i = 1; i <= 200; ++i) {
        cout << setw(7) << number * i;
        if (i % 10 == 0)
            cout << endl;
    }

    return 0;
}

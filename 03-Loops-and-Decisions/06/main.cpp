#include <iostream>

using namespace std;

int main() {
    unsigned long factorial;

    cout << "Enter number to calculate its factorial." << endl
         << "Enter 0 to exit:";
    cin >> factorial;

    while (factorial) {
        for (unsigned long i = factorial; i > 1; factorial *= i, --i);
        cout << "Factorial is " << factorial << endl;

        cout << "Enter number to calculate its factorial." << endl
             << "Enter 0 to exit:";
        cin >> factorial;
    }

    return 0;
}

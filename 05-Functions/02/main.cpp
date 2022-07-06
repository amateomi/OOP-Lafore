#include <iostream>

using namespace std;

double computePower(double n, int p = 2);

int main() {
    double number;
    int power;

    cout << "Enter number and power:" << endl;
    cin >> number >> power;

    cout << "Default call is " << computePower(number) << endl
         << number << " in " << power << " is " << computePower(number, power) << endl;

    return 0;
}

double computePower(double n, int p) {
    double res = n;
    while (p-- > 1) {
        res *= n;
    }
    return res;
}
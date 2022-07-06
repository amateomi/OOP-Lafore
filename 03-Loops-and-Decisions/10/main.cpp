#include <iostream>

using namespace std;

int main() {
    float contribution, accountAmount;
    float rate;
    unsigned short year = 0;

    cout << "Enter initial contribution:";
    cin >> contribution;
    cout << "Enter account amount:";
    cin >> accountAmount;
    cout << "Enter interest rate:";
    cin >> rate;
    rate *= 0.01;

    while (accountAmount > contribution) {
        accountAmount /= 1 + rate;
        year++;
    }

    cout << "You need " << year << " years" << endl;

    return 0;
}

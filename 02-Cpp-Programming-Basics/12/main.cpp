#include <iostream>

using namespace std;

int main() {
    int pounds;
    double decimalPenny;
    int shilling, penny;

    cout << "Enter amount of pounds in decimal system:";
    cin >> pounds >> decimalPenny;

    shilling = static_cast<int>(decimalPenny * 20);
    penny = static_cast<int>(((decimalPenny * 20) - shilling) * 12);

    cout << "In old system: J" << pounds << '.' << shilling << '.' << penny << endl;

    return 0;
}

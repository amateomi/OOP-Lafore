#include <iostream>

using namespace std;

int main() {
    unsigned int pound, shilling, penny;

    cout << "Enter amount of pounds:";
    cin >> pound;
    cout << "Enter amount of shillings:";
    cin >> shilling;
    cout << "Enter amount of penny:";
    cin >> penny;

    cout << 'J' << static_cast<double>(pound + (penny / 12.0 + shilling) / 20.0) << endl;

    return 0;
}

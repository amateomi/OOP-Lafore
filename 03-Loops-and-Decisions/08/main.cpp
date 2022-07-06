#include <iostream>

using namespace std;

int main() {
    unsigned int pound1, pound2, pound3;
    unsigned int shilling1, shilling2, shilling3;
    unsigned int penny1, penny2, penny3;
    char ch;

    do {
        cout << "Enter first sum: J";
        cin >> pound1 >> ch >> shilling1 >> ch >> penny1;
        cout << "Enter second sum: J";
        cin >> pound2 >> ch >> shilling2 >> ch >> penny2;

        if ((penny3 = penny1 + penny2) >= 12) {
            penny3 -= 12;
            shilling1++;
        }
        if ((shilling3 = shilling1 + shilling2) >= 20) {
            shilling3 -= 20;
            pound1++;
        }
        pound3 = pound1 + pound2;

        cout << "Sum is J" << pound3 << '.' << shilling3 << '.' << penny3 << endl;

        cout << "Continue (y/n)?:";
        cin >> ch;
    } while (ch != 'n');

    return 0;
}

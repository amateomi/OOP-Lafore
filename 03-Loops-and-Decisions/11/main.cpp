#include <iostream>

using namespace std;

int main() {
    long pound1, pound2, pound3;
    long shilling1, shilling2, shilling3;
    long penny1, penny2, penny3;
    char operation, point, isContinue;
    double multiplicationNumber;

    do {
        cout << "Enter first operand, operation and second operand: J";
        cin >> pound1 >> point >> shilling1 >> point >> penny1 >> operation;

        operation == '*' ? cin >> multiplicationNumber : cin >> pound2 >> point >> shilling2 >> point >> penny2;

        switch (operation) {
            case '+':
                if ((penny3 = penny1 + penny2) >= 12) {
                    penny3 -= 12;
                    shilling1++;
                }
                if ((shilling3 = shilling1 + shilling2) >= 20) {
                    shilling3 -= 20;
                    pound1++;
                }
                pound3 = pound1 + pound2;

                cout << "Sum is J" << pound3 << '.' << shilling3 << '.' << penny3;
                break;

            case '-':
                if ((penny3 = penny1 - penny2) < 0) {
                    penny3 += 12;
                    shilling1--;
                }
                if ((shilling3 = shilling1 - shilling2) < 0) {
                    shilling3 += 20;
                    pound1--;
                }
                pound3 = pound1 - pound2;

                cout << "Difference is J" << pound3 << '.' << shilling3 << '.'
                     << penny3;
                break;

            case '*':
                double d_totalShillings;
                int i_totalShillings;

                d_totalShillings = shilling1;
                d_totalShillings += pound1 * 20.0;
                d_totalShillings += penny1 / 12.0;
                d_totalShillings *= multiplicationNumber;

                i_totalShillings = static_cast<int>(d_totalShillings);

                pound3 = i_totalShillings / 20;
                shilling3 = i_totalShillings % 20;
                penny3 = static_cast<int>((d_totalShillings - i_totalShillings) * 12);

                cout << "Multiplication is J" << pound3 << '.' << shilling3 << '.' << penny3;
                break;

            default:
                cout << "There is no such operation!";
                break;
        }

        cout << endl << "Continue(y/n)?:";
        cin >> isContinue;
    } while (isContinue != 'n');

    return 0;
}

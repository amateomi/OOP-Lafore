#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    signed int a, c;
    unsigned int b, d;
    char operation;
    char slash;
    char isContinue;

    do {
        cout << "Enter first fraction, operation and second fraction:";
        cin >> a >> slash >> b >> operation >> c >> slash >> d;

        switch (operation) {
            case '+':
                cout << "Sum is " << a * d + b * c << '/' << b * d;
                break;

            case '-':
                cout << "Differance is " << static_cast<signed int>(a * d - b * c) << '/' << b * d;
                break;

            case '*':
                cout << "Multiplication is " << a * c << '/' << b * d;
                break;

            case '/':
                cout << "Division is " << a * d << '/' << b * c;
                break;

            default:
                cout << "Unknown operation!";
                break;
        }

        cout << endl << "Continue(y/n)?:";
        cin >> isContinue;
    } while (isContinue != 'n');

    return 0;
}

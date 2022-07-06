#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////
struct Fraction {
    int num;
    int den;
};
/////////////////////////////////////////////////////////////////////

int main() {
    Fraction f1 = {};
    Fraction f2 = {};
    char operation;
    char slash;
    char isContinue;

    do {
        cout << "Enter first fraction, operation and second fraction:" << endl;
        cin >> f1.num >> slash >> f1.den
            >> operation
            >> f2.num >> slash >> f2.den;

        switch (operation) {
            case '+':
                cout << "Sum is " << f1.num * f2.den + f2.num * f1.den << '/' << f1.den * f2.den;
                break;

            case '-':
                cout << "Differance is " << f1.num * f2.den - f2.num * f1.den << '/' << f1.den * f2.den;
                break;

            case '*':
                cout << "Multiplication is " << f1.num * f2.num << '/' << f1.den * f2.den;
                break;

            case '/':
                cout << "Division is " << f1.num * f2.den << '/' << f2.num * f1.den;
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

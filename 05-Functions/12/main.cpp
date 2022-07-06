#include <iostream>

using namespace std;

struct Fraction {
    int num;
    int den;
};

Fraction fAdd(const Fraction &f1, const Fraction &f2);

Fraction fSub(const Fraction &f1, const Fraction &f2);

Fraction fMul(const Fraction &f1, const Fraction &f2);

Fraction fDiv(const Fraction &f1, const Fraction &f2);

int main() {
    Fraction f1 = {};
    Fraction f2 = {};
    Fraction f3 = {};
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
                f3 = fAdd(f1, f2);
                cout << "Sum is " << f3.num << '/' << f3.den;
                break;

            case '-':
                f3 = fSub(f1, f2);
                cout << "Difference is " << f3.num << '/' << f3.den;
                break;

            case '*':
                f3 = fMul(f1, f2);
                cout << "Multiplication is " << f3.num << '/' << f3.den;
                break;

            case '/':
                f3 = fDiv(f1, f2);
                cout << "Division is " << f3.num << '/' << f3.den;
                break;

            default:
                cout << "Unknown operation!";
                break;
        }

        cout << "\nContinue(y/n)?:";
        cin >> isContinue;
    } while (isContinue != 'n');

    return 0;
}

Fraction fAdd(const Fraction &f1, const Fraction &f2) {
    Fraction res = {f1.num * f2.den + f2.num * f1.den,
                    f1.den * f2.den};

    return res;
}

Fraction fSub(const Fraction &f1, const Fraction &f2) {
    Fraction res = {f1.num * f2.den - f2.num * f1.den,
                    f1.den * f2.den};

    return res;
}

Fraction fMul(const Fraction &f1, const Fraction &f2) {
    Fraction res = {f1.num * f2.num,
                    f1.den * f2.den};

    return res;
}

Fraction fDiv(const Fraction &f1, const Fraction &f2) {
    Fraction res = {f1.num * f2.den,
                    f1.den * f2.num};

    return res;
}
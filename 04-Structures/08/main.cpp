#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Fraction {
    int numerator;
    int denominator;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Fraction f1 = {}, f2 = {};
    char slash;

    cout << "Enter first fraction:" << endl;
    cin >> f1.numerator >> slash >> f2.denominator;
    cout << "Enter second fraction:" << endl;
    cin >> f2.numerator >> slash >> f2.denominator;

    Fraction f3 = {f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                   f1.denominator * f2.denominator};

    cout << "f1 + f2 is " << f3.numerator << '/' << f3.denominator << endl;

    return 0;
}

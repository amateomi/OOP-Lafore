#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

class Fraction {
private:
    int numerator;

    int denominator;

    bool checkZeroDenominator() const {
        if (denominator == 0) {
            cerr << "Division by zero attempted!" << endl;
            return true;
        } else {
            return false;
        }
    }

    void lowTerms() {
        int num = abs(numerator);
        int den = abs(denominator);

        checkZeroDenominator();

        while (num != 0) {
            if (num < den) {
                swap(num, den);
            }
            num -= den;
        }

        int gcd = den;
        numerator /= gcd;
        denominator /= gcd;
    }

public:

    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (checkZeroDenominator()) {
            exit(1);
        } else {
            lowTerms();
        }
    }

    friend ostream &operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << '/' << f.denominator;

        return out;
    }

    friend istream &operator>>(istream &in, Fraction &f) {
        char slash;
        while (true) {
            in.unsetf(ios::skipws);
            in >> f.numerator;
            if (in.good()) {
                in.unsetf(ios::skipws);
                in >> slash;
                if (slash == '/') {
                    in.unsetf(ios::skipws);
                    in >> f.denominator;
                    if (in.good()) {
                        if (f.denominator != 0) {
                            in.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        } else {
                            cerr << "Unable to use 0 for denominator!" << endl;
                        }
                    } else {
                        in.clear();
                        cerr << "Incorrect entry of the denominator!" << endl;
                    }
                } else {
                    cerr << "Between numerator and denominator must be slash!"
                         << endl;
                }
            } else {
                in.clear();
                cerr << "Incorrect entry of the numerator!" << endl;
            }

            in.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter fraction again:";
        }

        return in;
    }

    Fraction operator+(const Fraction &f) const {
        return Fraction(numerator * f.denominator + denominator * f.numerator,
                        denominator * f.denominator);
    }

    Fraction operator-(const Fraction &f) const {
        return Fraction(numerator * f.denominator - denominator * f.numerator,
                        denominator * f.denominator);
    }

    Fraction operator*(const Fraction &f) const {
        return Fraction(numerator * f.numerator,
                        denominator * f.denominator);
    }

    Fraction operator/(const Fraction &f) const {
        if (f.numerator == 0) {
            cerr << "Division by zero attempted!" << endl;
            return Fraction(0, 1);
        } else {
            return Fraction(numerator * f.denominator,
                            denominator * f.numerator);
        }
    }
};

int main() {
    Fraction fraction1;
    Fraction fraction2;
    char operation;

    char choice;
    do {
        cout << "Enter first fraction:";
        cin >> fraction1;
        cout << "Enter operation (+, =, *, /):";
        cin >> operation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter second fraction:";
        cin >> fraction2;

        switch (operation) {
            case '+':
                cout << "Sum is " << fraction1 + fraction2 << endl;
                break;

            case '-':
                cout << "Difference is " << fraction1 - fraction2 << endl;
                break;

            case '*':
                cout << "Multiplication is " << fraction1 * fraction2 << endl;
                break;

            case '/':
                cout << "Division is " << fraction1 / fraction2 << endl;
                break;

            default:
                cout << "Unknown operation!";
                break;
        }

        cout << "Continue(y/n)?:";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice == 'y');

    return 0;
}


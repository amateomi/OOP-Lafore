#include <cmath>
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;

    int denominator;

public:

    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) {}

    void init() {
        char c;

        cin >> numerator >> c >> denominator;

        lowTerms();
    }

    void show() const {
        cout << numerator << '/' << denominator;
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

    void checkZeroDenominator() const {
        if (denominator == 0) {
            cout << "Division by zero!" << endl;
            exit(1);
        }
    }

    void add(const Fraction &a, const Fraction &b) {
        numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        denominator = a.denominator * b.denominator;

        lowTerms();
    }

    void sub(const Fraction &a, const Fraction &b) {
        numerator = a.numerator * b.denominator - b.numerator * a.denominator;
        denominator = a.denominator * b.denominator;

        lowTerms();
    }

    void mul(const Fraction &a, const Fraction &b) {
        numerator = a.numerator * b.numerator;
        denominator = a.denominator * b.denominator;

        lowTerms();
    }

    void div(const Fraction &a, const Fraction &b) {
        checkZeroDenominator();

        numerator = a.numerator * b.denominator;
        denominator = a.denominator * b.numerator;

        lowTerms();
    }
};

int main() {
    Fraction fraction1;
    Fraction fraction2;
    Fraction fraction3;
    char operation;
    char isContinue;

    do {
        cout << "Enter first fraction, operation and second fraction:" << endl;
        fraction1.init();
        cin >> operation;
        fraction2.init();

        switch (operation) {
            case '+':
                fraction3.add(fraction1, fraction2);
                cout << "Sum is ";
                fraction3.show();
                break;

            case '-':
                fraction3.sub(fraction1, fraction2);
                cout << "Difference is ";
                fraction3.show();
                break;

            case '*':
                fraction3.mul(fraction1, fraction2);
                cout << "Multiplication is ";
                fraction3.show();
                break;

            case '/':
                fraction3.div(fraction1, fraction2);
                cout << "Division is ";
                fraction3.show();
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

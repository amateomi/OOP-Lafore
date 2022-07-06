#include <cmath>
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;

    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) {
        checkZeroDenominator();
        lowTerms();
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
        f.checkZeroDenominator();

        return Fraction(numerator * f.denominator,
                        denominator * f.numerator);
    }

    void init() {
        char c;

        cin >> numerator >> c >> denominator;

        checkZeroDenominator();
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
};

int main() {
    Fraction firstFraction;
    Fraction secondFraction;
    char operation;
    char isContinue;

    do {
        cout << "Enter first fraction, operation and second fraction:" << endl;
        firstFraction.init();
        cin >> operation;
        secondFraction.init();

        switch (operation) {
            case '+':
                cout << "Sum is ";
                (firstFraction + secondFraction).show();
                break;

            case '-':
                cout << "Difference is ";
                (firstFraction - secondFraction).show();
                break;

            case '*':
                cout << "Multiplication is ";
                (firstFraction * secondFraction).show();
                break;

            case '/':
                cout << "Division is ";
                (firstFraction / secondFraction).show();
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

#include <cmath>
#include <iostream>

using namespace std;

template<class T>
class Fraction {
private:
    T numerator;

    T denominator;

public:

    Fraction() : numerator(0), denominator(1) {}

    Fraction(T n, T d) : numerator(n), denominator(d) {
        checkZeroDenominator();
        lowTerms();
    }

    friend ostream &operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << '/' << f.denominator;
        return out;
    }

    friend istream &operator>>(istream &in, Fraction &f) {
        char c;
        in >> f.numerator >> c >> f.denominator;

        f.checkZeroDenominator();
        f.lowTerms();

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
        f.checkZeroDenominator();

        return Fraction(numerator * f.denominator,
                        denominator * f.numerator);
    }

    void lowTerms() {
        T num = abs(numerator);
        T den = abs(denominator);

        checkZeroDenominator();

        while (num != 0) {
            if (num < den) {
                swap(num, den);
            }
            num -= den;
        }

        T gcd = den;
        numerator /= gcd;
        denominator /= gcd;
    }

    void checkZeroDenominator() const {
        if (denominator == 0) {
            cout << "Division by zero attempted!" << endl;
            exit(1);
        }
    }
};

int main() {
    Fraction<char> fraction1;
    Fraction<char> fraction2;
    char operation;

    char choice;
    do {
        cout << "Enter first fraction, operation and second fraction:" << endl;
        cin >> fraction1 >> operation >> fraction2;

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
    } while (choice == 'y');

    return 0;
}


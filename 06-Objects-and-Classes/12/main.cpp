#include <cstdlib>
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;

    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) : numerator(n), denominator(d) { lowTerms(); }

    void init() {
        char c;

        cin >> numerator >> c >> denominator;

        lowTerms();
    }

    void set(int n, int d) {
        numerator = n;
        denominator = d;

        lowTerms();
    };

    void show() const {
        cout << numerator << '/' << denominator;
    }

    void lowTerms() {
        int num = abs(numerator);
        int den = abs(denominator);

        divisionByZeroCheck();

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

    void divisionByZeroCheck() const {
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
        divisionByZeroCheck();

        numerator = a.numerator * b.denominator;
        denominator = a.denominator * b.numerator;

        lowTerms();
    }
};

int main() {
    Fraction f1;
    Fraction f2;
    Fraction f3;
    int den;

    cout << "Enter denominator:" << endl;
    cin >> den;

    cout << "    ";
    for (int i = 1; i < den; ++i) {
        f1.set(i, den);
        f1.show();
        cout << ' ';
    }
    cout << endl;

    for (int i = 0; i < 80; ++i) {
        cout << '-';
    }
    cout << endl;

    for (int i = 1; i < den; ++i) {
        f1.set(i, den);
        f1.show();
        cout << ' ';
        for (int j = 1; j < den; ++j) {
            f2.set(j, den);
            f3.mul(f1, f2);
            f3.show();
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

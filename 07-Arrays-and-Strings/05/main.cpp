#include <ctime>
#include <cstdlib>
#include <cmath>
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
    const int SIZE = 2;
    Fraction fractions[SIZE];
    Fraction averageFraction;

    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i) {
        fractions[i].set(rand() % 50 + 1, rand() % 50 + 1);
        fractions[i].show();
        cout << ' ';
    }
    cout << endl;

    averageFraction = fractions[0];
    for (int i = 1; i < SIZE; ++i) {
        averageFraction.add(averageFraction, fractions[i]);
    }

    averageFraction.div(averageFraction, Fraction(SIZE, 1));
    cout << "Average fraction is ";
    averageFraction.show();

    return 0;
}

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

        cout << "Enter fraction in format 3/5:" << endl;
        cin >> numerator >> c >> denominator;
    }

    void show() const {
        cout << numerator << '/' << denominator;
    }

    void add(Fraction &a, Fraction &b) {
        numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        denominator = a.denominator * b.denominator;
    }
};

int main() {
    Fraction fraction1, fraction2, fraction3;
    char isContinue;

    do {
        fraction1.init();
        fraction2.init();

        fraction3.add(fraction1, fraction2);

        fraction3.show();

        cout << "\nContinue(y/n)?:" << endl;
        cin >> isContinue;
    } while (isContinue != 'n');
    return 0;
}

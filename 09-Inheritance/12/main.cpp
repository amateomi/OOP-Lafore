#include <cstdlib>
#include <iostream>

using namespace std;

class Sterling {
protected:
    long pounds;

    int shillings;

    int pence;

public:
    Sterling() : pounds(), shillings(), pence() {}

    explicit Sterling(const double &f) {
        pounds = static_cast<int>(f);

        double fractionPart = f - pounds;

        shillings = static_cast<int>(fractionPart * 20.0);
        pence = static_cast<int>((fractionPart * 20.0 - shillings) * 12.0);
    }

    Sterling(const long &po, const int &sh, const int &pe) :
            pounds(po), shillings(sh), pence(pe) {}

    operator double() const {
        return pounds + (pence / 12.0 + shillings) / 20.0;
    }

    Sterling operator+(const Sterling &s) const {
        return Sterling(static_cast<double>(Sterling(pounds, shillings, pence))
                        + static_cast<double>(s));
    }

    Sterling operator-(const Sterling &s) const {
        return Sterling(static_cast<double>(Sterling(pounds, shillings, pence))
                        - static_cast<double>(s));
    }

    double operator/(const Sterling &s) const {
        if (isEmpty(s)) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return Sterling(static_cast<double>(Sterling(pounds, shillings, pence))
                        / static_cast<double>(s));
    }

    Sterling operator*(const double &f) const {
        return Sterling(static_cast<double>(Sterling(pounds, shillings, pence))
                        * f);
    }

    Sterling operator/(const double &f) const {
        if (f == 0.0) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return Sterling(static_cast<double>(Sterling(pounds, shillings, pence))
                        / f);
    }

    void getPound() {
        char point;

        cout << "Enter sum of money in old sterling system:" << endl << 'J';
        cin >> pounds >> point
            >> shillings >> point
            >> pence;
    }

    void putPound() const {
        cout << 'J' << pounds
             << '.' << shillings
             << '.' << pence;
    }

    bool isEmpty() const {
        return pounds == 0
               && shillings == 0
               && pence == 0;
    }

    static bool isEmpty(const Sterling &s) {
        return s.pounds == 0
               && s.shillings == 0
               && s.pence == 0;
    }
};

class Sterfrac : private Sterling {
private:
    int eights;

public:
    Sterfrac() : Sterling(), eights() {}

    Sterfrac(const long &po, const int &sh, const int &pe, const int &ei) :
            Sterling(po, sh, pe), eights(ei) {}

    Sterfrac operator+(const Sterfrac &s) const {
        double a = convertSterlingToPence();
        double b = s.convertSterlingToPence();
        double res = a + b;

        return convertPenceToSterling(res);
    }

    Sterfrac operator-(const Sterfrac &s) const {
        double a = convertSterlingToPence();
        double b = s.convertSterlingToPence();
        double res = a - b;

        return convertPenceToSterling(res);
    }

    double operator/(const Sterfrac &s) const {
        double a = convertSterlingToPence();
        double b = s.convertSterlingToPence();

        if (b == 0) {
            cout << "Division by zero attempted!" << endl;
            exit(1);
        }

        return a / b;
    }

    Sterfrac operator*(const double &f) const {
        double a = convertSterlingToPence();

        return convertPenceToSterling(a * f);
    }

    Sterfrac operator/(const double &f) const {
        double a = convertSterlingToPence();

        if (f == 0) {
            cout << "Division by zero attempted!" << endl;
            exit(1);
        }

        return convertPenceToSterling(a / f);
    }

    void getData() {
        int numerator;
        int denominator;
        char ch;
        cout << "Enter sum of money in old system with farthings:\n"
                "Example: J123.19.11-1/8" << endl << 'J';
        cin >> pounds >> ch >> shillings >> ch >> pence >>
            ch >> numerator >> ch >> denominator;

        eights = numerator * 8 / denominator;
    }

    void putData() const {
        Sterling::putPound();
        cout << '-' << eights << '/' << '8' << endl;
    }

    double convertSterlingToPence() const {
        return (pounds * 20 + shillings) * 12 + pence + static_cast<double>(eights) / 8;
    }

    static Sterfrac convertPenceToSterling(const double &totalPence) {
        long po = static_cast<long>(totalPence / 12 / 20);
        int sh = static_cast<int>(totalPence / 12) - po * 20;
        int pe = static_cast<int>(totalPence - (po * 20 + sh) * 12);
        int ei = static_cast<int>((totalPence - static_cast<int>(totalPence)) * 8);

        return Sterfrac(po, sh, pe, ei);
    }
};

int main() {
    Sterfrac sterfrac;

    sterfrac.getData();
    sterfrac.putData();

    Sterfrac sterfrac1(12, 6, 7, 3);
    sterfrac1.putData();
    Sterfrac sterfrac2 = sterfrac + sterfrac1;
    sterfrac2.putData();

    return 0;
}

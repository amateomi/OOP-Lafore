#include <cstdlib>
#include <iostream>

using namespace std;

class Sterling {
private:
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

    bool isEmpty(const Sterling &s) const {
        return s.pounds == 0
               && s.shillings == 0
               && s.pence == 0;
    }
};

int main() {
    Sterling s1(100.56);
    s1.putPound();
    cout << ' ' << static_cast<double>(s1) << endl;

    Sterling s2(120.30);
    s2.putPound();
    cout << ' ' << static_cast<double>(s2) << endl;

    (s1 + s2).putPound();
    cout << ' ' << static_cast<double>(s1 + s2) << endl;

    return 0;
}

#include <iomanip>
#include <sstream>
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

    Sterling(const double &f) {
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

class Money {
private:
    long double money;

public:
    Money() : money() {}

    Money(const long double m) : money(m) {}

    operator double() const {
        return static_cast<double>(money);
    }

    Money operator+(const Money &m) const {
        return Money(money + m.money);
    }

    Money operator-(const Money &m) const {
        return Money(money - m.money);
    }

    Money operator*(const long double &f) const {
        return Money(money * f);
    }

    long double operator/(const Money &m) const {
        if (m.money == 0.0L) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return money / m.money;
    }

    Money operator/(const long double &f) const {
        if (f == 0.0L) {
            cout << endl << "Division by zero attempted!" << endl;
            exit(1);
        }
        return Money(money / f);
    }

    void init() {
        string str;

        cout << "Enter money in format $1,234,567.89:" << endl;
        cin >> str;

        stringToNumber(str);
    }

    void show() const {
        cout << numberToString();
    }

    string numberToString() const {
        ostringstream ustring;
        ustring << setiosflags(ios::fixed)
                << setiosflags(ios::showpoint)
                << money;

        string str = ustring.str();

        int count = 1;

        for (size_t i = str.find('.') - 1; i > 0; --i) {
            if (count % 3 == 0) {
                str.insert(i, ",");
                count = 0;
            }
            count++;
        }
        str.insert(0, "$");
        str.erase(str.find('.') + 3);

        return str;
    };

    void stringToNumber(const string &str) {
        if (str.find_first_not_of("$0123456789,.") != -1
            || str.at(0) != '$'
            || str.find_first_of('.') != str.find_last_of('.')
            || str.find('.') + 3 != str.length()) {
            cout << endl << "Incompatible string!" << endl;
            return;
        }

        int i;
        long double count = 1.0L;

        for (i = static_cast<int>(str.find('.') - 1); i >= 0; --i) {
            if (isdigit(str.at(i))) {
                money += (str.at(i) - '0') * count;
                count *= 10.0L;
            }
        }

        count = 0.1L;

        for (i = 1; i < 3; ++i) {
            money += (str.at(str.find('.') + i) - '0') * count;
            count *= 0.1L;
        }
    }
};

int main() {
    Money money;
    Sterling sterling;
    char option;

    do {
        cout << "1) Sterling to Money\n"
                "2) Money to Sterling"
             << endl;
        cin >> option;

        switch (option) {
            case '1':
                sterling.getPound();
                money = static_cast<double>(sterling) * 50.0;
                money.show();
                break;

            case '2':
                money.init();
                sterling = static_cast<double>(money) / 50.0;
                sterling.putPound();
                break;

            default:
                cout << "Unknown operation!";
                break;
        }

        cout << "\nContinue(y/n)?";
        cin >> option;
    } while (option != 'n');
    return 0;
}

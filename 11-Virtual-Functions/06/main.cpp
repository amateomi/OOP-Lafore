#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Money {
private:
    long double money;

public:
    Money() : money(0.0L) {}

    Money(long double m) : money(m) {}

    Money operator+(const Money &m) const {
        return Money(money + m.money);
    }

    Money operator-(const Money &m) const {
        return Money(money - m.money);
    }

    friend Money operator*(const Money &m1, const Money &m2) {
        return Money(m1.money * m2.money);
    }

    friend Money operator/(const Money &m1, const Money &m2) {
        if (m2.money == 0.0L) {
            cout << endl << "Division by zero attempt!" << endl;
            exit(1);
        }
        return Money(m1.money / m2.money);
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

        long double count = 1.0L;

        for (int i = static_cast<int>(str.find('.') - 1); i >= 0; --i) {
            if (isdigit(str.at(i))) {
                money += (str.at(i) - '0') * count;
                count *= 10.0L;
            }
        }

        count = 0.1L;

        for (int i = 1; i < 3; ++i) {
            money += (str.at(str.find('.') + i) - '0') * count;
            count *= 0.1L;
        }
    }
};

int main() {
    Money m1(120.50L);
    Money m2(60.25L);

    long double f = 3.0l;

    (m1 + m2).show();
    cout << endl;
    (m1 - m2).show();
    cout << endl;
    (f * m1).show();
    cout << endl;
    (m1 / m2).show();
    cout << endl;
    (m1 / f).show();
    cout << endl;

    return 0;
}


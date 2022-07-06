#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

class Money {
private:
    long double money;

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

    bool stringToNumber(const string &str) {
        if (str.find_first_not_of("$0123456789,.") != -1
            || str.at(0) != '$'
            || str.find_first_of('.') != str.find_last_of('.')
            || str.find('.') + 3 != str.length()) {
            cout << endl << "Incompatible string!" << endl;
            return false;
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

        return true;
    }

public:

    Money() : money() {}

    explicit Money(const long double &m) : money(m) {}

    friend istream &operator>>(istream &in, Money &m) {
        string moneyString;

        while (true) {
            in >> moneyString;
            if (in.good() && m.stringToNumber(moneyString)) {
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cerr << "Incorrect money input!" << endl;
            cout << "Enter again:";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        return in;
    }

    friend ostream &operator<<(ostream &out, const Money &m) {
        out << m.numberToString();

        return out;
    }

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
            cerr << endl << "Division by zero attempt!" << endl;
            exit(1);
        }
        return Money(m1.money / m2.money);
    }
};

int main() {
    Money money;

    cout << "Enter money in format $1,234,567.89:";
    cin >> money;
    cout << "You entered " << money << endl;

    return 0;
}

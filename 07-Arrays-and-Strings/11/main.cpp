#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Money {
private:
    long double money;

public:
    Money() : money(0.0L) {}

    explicit Money(const long double m) : money(m) {}

    void show() const {
        cout << setiosflags(ios::fixed)
             << setiosflags(ios::showpoint)
             << '$' << money;
    }

    void stringToNumber(char *str) {
        char newStr[20];
        int i = 0;

        for (int j = 0; str[j] != '\0'; ++j) {
            if (isdigit(str[j])
                || str[j] == '.') {
                newStr[i++] = str[j];
            }
        }
        newStr[i] = '\0';

        for (i = 0; newStr[i] != '\0'; ++i) {
            if (newStr[i] == '.') {
                i++;
                break;
            }
            money = money * 10 + (newStr[i] - '0');
        }

        long double k = 0.1L;

        for (; newStr[i] != '\0'; ++i) {
            money += (newStr[i] - '0') * k;
            k *= 0.1L;
        }
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
};

int main() {

    cout << Money(1234.0L).numberToString();

    return 0;
}

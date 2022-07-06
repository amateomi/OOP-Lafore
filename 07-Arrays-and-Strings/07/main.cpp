#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

class Money {
private:
    long double money;

public:
    Money() : money(0.0L) {}

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
};

int main() {
    Money money;
    char string[20];

    cout << "Enter sum of money in format $1,234,567.89:" << endl;
    cin >> string;

    money.stringToNumber(string);

    money.show();

    return 0;
}

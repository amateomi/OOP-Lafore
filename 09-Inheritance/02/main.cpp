#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    static const int LIMIT = 80;

    char str[LIMIT];

public:
    String() : str() {}

    String(const char s[]) : str() {
        strcpy(str, s);
    }

    String operator+(String s) {
        String temp;
        if (strlen(str) + strlen(s.str) >= LIMIT) {
            cout << endl << "Buffer overflow!" << endl;
            return String("");
        }

        strcpy(temp.str, str);
        strcat(temp.str, s.str);

        return temp;
    }

    String operator+=(String s) {
        if (strlen(str) + strlen(s.str) >= LIMIT) {
            cout << endl << "Buffer overflow!" << endl;
            return String("");
        }

        strcat(str, s.str);

        return String(str);
    }

    void show() const {
        cout << str;
    }
};

class Pstring : public String {
public:
    Pstring(char s[]) {
        if (strlen(s) >= LIMIT) {
            strncpy(str, s, LIMIT - 1);
        } else {
            strcpy(str, s);
        }
    }
};

int main() {
    Pstring s2 = "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";

    s2.show();

    return 0;
}

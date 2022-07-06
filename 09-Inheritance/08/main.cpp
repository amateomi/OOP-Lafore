#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    static const int LIMIT = 80;

    char str[LIMIT];

public:
    String() : str() {}

    explicit String(const char s[]) : str() {
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

    operator char *() { return str; }

    void show() const {
        cout << str << endl;
    }
};

class Pstring : public String {
public:
    Pstring() : String() {};

    explicit Pstring(char s[]) {
        if (strlen(s) >= LIMIT) {
            strncpy(str, s, LIMIT - 1);
        } else {
            strcpy(str, s);
        }
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {};

    explicit Pstring2(char s[]) : Pstring(s) {}

    Pstring2 &left(char s[], int n) {
        int i;
        for (i = 0; i < n; ++i) {
            str[i] = s[i];
        }
        str[i] = '\0';

        return *this;
    }
};

int main() {
    char c[] = "Hello world!";
    Pstring2 pstring2(c);

    pstring2.show();

    Pstring2 pstring21, pstring22;
    pstring22 = pstring21.left(static_cast<char *>(pstring2), 5);

    pstring2.show();
    pstring21.show();
    pstring22.show();

    return 0;
}

#include <cstring>
#include <iostream>

using namespace std;

class String {
private:
    static const int SIZE = 80;

    char str[SIZE];

public:
    String() : str() {}

    explicit String(const char s[]) : str() {
        strcpy(str, s);
    }

    void show() const {
        cout << str;
    }

    String operator+(String s) {
        String temp;
        if (strlen(str) + strlen(s.str) >= SIZE) {
            cout << endl << "Buffer overflow!" << endl;
            return String("");
        }

        strcpy(temp.str, str);
        strcat(temp.str, s.str);

        return temp;
    }

    String operator+=(String s) {
        if (strlen(str) + strlen(s.str) >= SIZE) {
            cout << endl << "Buffer overflow!" << endl;
            return String("");
        }

        strcat(str, s.str);

        return String(str);
    }
};

int main() {
    String string1("ha");
    String string3 = string1 + string1;
    String string2 = string3 += string1;

    string1.show();
    cout << endl;

    string2.show();
    cout << endl;

    string3.show();
    cout << endl;

    return 0;
}

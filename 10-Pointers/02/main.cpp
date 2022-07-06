#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class String {
private:
    char *str;

public:
    explicit String(char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~String() { delete[] str; }

    void display() { cout << str << endl; }

    void upit() {
        for (int i = 0; i < strlen(str); ++i) {
            str[i] = static_cast<char>(toupper(static_cast<int>(str[i])));
        }
    }
};

int main() {
    String str("Hello world!");

    str.upit();
    str.display();

    return 0;
}

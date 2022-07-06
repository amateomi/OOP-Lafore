#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class String {
private:
    static const int LEN = 6;

    char str[LEN];

public:
    class Ex {
    public:
        string errorMessage;

        explicit Ex(int n) {
            switch (n) {
                case 1:
                    errorMessage = "Constructor with 2 args:\n"
                                   "Argument is bigger than max size of String!";
                    break;

                case 2:
                    errorMessage = "Operator +:\n"
                                   "Unable to concatenate strings,"
                                   " result bigger then max size!";
                    break;

                default:
                    errorMessage = "Unknown error!";
                    break;
            }
        }
    };

    String() : str() {
        str[0] = '\0';
    }

    explicit String(char s[]) : str() {
        if (strlen(s) > LEN) {
            throw Ex(1);
        }
        strcpy(str, s);
    }

    String operator+(const String &s) {
        String temp;

        if (strlen(str) + strlen(s.str) < LEN) {
            strcpy(temp.str, str);
            strcat(temp.str, s.str);
        } else {
            throw Ex(2);
        }

        return temp;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    try {
        String s1("ab");
        String s2("zxc");
        String s3;

        s1.display();
        s2.display();
        s3.display();

        s3 = s1 + s2;

        s3.display();
    } catch (String::Ex er) {
        cerr << endl << er.errorMessage << endl;
    }

    return 0;
}

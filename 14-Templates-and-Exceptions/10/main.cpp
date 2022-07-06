#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void isFeet(string);

class Distance {
private:
    int feet;

    float inches;

public:
    class Exception {
    public:
        string errorType;

        explicit Exception(int n) {
            switch (n) {
                case 1:
                    errorType = "Constructor with 2 args:\n"
                                "Feet must be between -999 and 999!";
                    break;

                case 2:
                    errorType = "Constructor with 2 args:\n"
                                "Inches must be between 0.0 and 11.99!";
                    break;

                case 3:
                    errorType = "Function getDist():\n"
                                "Incorrectly entered feet!";
                    break;

                case 4:
                    errorType = "Function isFeet():\n"
                                "Nothing entered or too many characters entered!";
                    break;

                case 5:
                    errorType = "Function isFeet():\n"
                                "Entered not '-' or a number!";
                    break;

                case 6:
                    errorType = "Function isFeet():\n"
                                "Feet must be between -999 and 999!";
                    break;

                case 7:
                    errorType = "Function getDist():\n"
                                "Incorrectly entered inches!";
                    break;

                case 8:
                    errorType = "Function getDist():\n"
                                "Inches must be between 0.0 and 11.99!";
                    break;

                default:
                    errorType = "Unknown error!";
                    break;
            }
        }
    };

    Distance() : feet(), inches() {}

    Distance(int ft, float in) : feet(ft), inches(in) {
        if (ft < -999 || ft > 999) {
            throw Exception(1);
        }
        if (in < 0.0 || in >= 12) {
            throw Exception(2);
        }
        feet = ft;
        inches = in;
    }

    void showDist() const {
        cout << feet << "'-" << inches << '\"';
    }

    void getDist();
};

void Distance::getDist() {
    do {
        try {
            string instr;
            cout << "Enter feet:";
            cin.unsetf(ios::skipws);
            cin >> instr;

            if (!cin.good()) {
                cin.clear();
                cin.ignore(10, '\n');
                throw Exception(3);
            }

            cin.ignore(10, '\n');
            isFeet(instr);

            feet = atoi(instr.c_str());
            break;
        } catch (Exception error) {
            cerr << endl << error.errorType << endl;
        }
    } while (true);

    do {
        try {
            cout << "Enter inches:";
            cin.unsetf(ios::skipws);
            cin >> inches;
            if (!cin.good()) {
                cin.clear();
                cin.ignore(10, '\n');
                throw Exception(7);
            }

            cin.ignore(10, '\n');
            if (inches >= 12.0 || inches < 0.0) {
                throw Exception(8);
            }

            break;
        } catch (Exception error) {
            cerr << endl << error.errorType << endl;
        }
    } while (true);
}

void isFeet(string str) {
    int len = static_cast<int>(str.size());
    if (len == 0 || len > 5) {
        throw Distance::Exception(4);
    }
    for (int i = 0; i < len; ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            throw Distance::Exception(5);
        }
    }

    double n = atof(str.c_str());
    if (n < -999.0 || n > 999.0) {
        throw Distance::Exception(6);
    }
}

int main() {
    Distance d;

    char ans;
    do {
        d.getDist();
        cout << "Distance = ";
        d.showDist();
        cout << endl << "Continue?(y/n)";
        cin >> ans;
        cin.ignore(10, '\n');
    } while (ans != 'n');

    return 0;
}

#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

class Int {
private:
    int number;

public:
    Int() : number() {}

    Int(int n) : number(n) {}

    operator int() const {
        return number;
    }

    Int operator+(Int &n) const {
        long double res = number + n.number;

        overflowCheck(res);

        return Int(static_cast<int>(res));
    }

    Int operator-(Int &n) const {
        long double res = number - n.number;

        overflowCheck(res);

        return Int(static_cast<int>(res));
    }

    Int operator*(Int &n) const {
        long double res = number * n.number;

        overflowCheck(res);

        return Int(static_cast<int>(res));
    }

    Int operator/(Int &n) const {
        if (n.number == 0) {
            cout << endl << "Division by zero attempt!" << endl;
            exit(1);
        }

        long double res = static_cast<int>(number / n.number);

        overflowCheck(res);

        return Int(static_cast<int>(res));
    }

    static void overflowCheck(long double n) {
        if (n > INT_MAX || n < INT_MIN) {
            cout << endl << "Int overflow!" << endl;
            exit(1);
        }
    }

    void show() const {
        cout << number;
    }

    int getNumber() const {
        return number;
    }
};

int main() {
    Int a = 7;
    Int b = 0;
    Int c = a * b;

    cout << c.getNumber();
    cout << a.getNumber();

    return 0;
}

#include <iostream>

using namespace std;

class Int {
private:
    int number;

public:
    Int() : number(0) {}

    explicit Int(int n) : number(n) {}

    void show() const { cout << number; }

    void add(Int a, Int b) { number = a.number + b.number; }
};

int main() {
    Int a;
    Int b(8);
    Int c;

    c.add(a, b);

    a.show();
    cout << endl;
    b.show();
    cout << endl;
    c.show();
    cout << endl;

    return 0;
}

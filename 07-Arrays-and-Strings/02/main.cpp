#include <string>
#include <iostream>

using namespace std;

class Employee {
private:
    string name;

    long number;

public:
    Employee() : number(0) {}

    void getDate() {
        cout << "Enter name:" << endl;
        getline(cin, name);
        cout << "Enter number:" << endl;
        cin >> number;
    }

    void putDate() const {
        cout << " Name " << name
             << " Number " << number;
    }
};

int main() {
    Employee employees[100];

    for (int i = 0; i < 100; ++i) {
        cout << "\nEmployee No " << i + 1 << endl;
        employees[i].getDate();
        employees[i].putDate();
    }

    return 0;
}

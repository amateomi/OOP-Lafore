#include <iomanip>
#include <iostream>

using namespace std;

class Employee {
private:
    int number;

    float salary;

public:
    Employee() : number(0), salary(0.0f) {}

    void init() {
        cout << "Enter employee number:" << endl;
        cin >> number;
        cout << "Enter employee salary:" << endl;
        cin >> salary;
    }

    void display() const {
        cout << "Employee info:" << endl
             << setw(9) << "Number:" << setw(9) << number
             << setw(9) << "Salary:" << setw(9) << salary
             << endl;
    }
};

int main() {
    Employee e1, e2, e3;

    e1.init(), e2.init(), e3.init();
    e1.display(), e2.display(), e3.display();

    return 0;
}

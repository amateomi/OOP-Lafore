#include <iomanip>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Employee {
    int number;
    float salary;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Employee employee1 = {};
    Employee employee2 = {};
    Employee employee3 = {};

    cout << "Enter employee number and salary for first employee:" << endl;
    cin >> employee1.number >> employee1.salary;
    cout << "Enter employee number and salary for second employee:" << endl;
    cin >> employee2.number >> employee2.salary;
    cout << "Enter employee number and salary for third employee:" << endl;
    cin >> employee3.number >> employee3.salary;

    cout << setw(12) << "Number" << setw(12) << "Salary" << endl
         << setw(12) << employee1.number << setw(12) << employee1.salary << endl
         << setw(12) << employee2.number << setw(12) << employee2.salary << endl
         << setw(12) << employee2.number << setw(12) << employee3.salary << endl;
    return 0;
}

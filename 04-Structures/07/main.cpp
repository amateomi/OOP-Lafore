#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
enum Etype {
    laborer, secretary, manager, accountant, executive, researcher
};
///////////////////////////////////////////////////////////////////////////////
struct Date {
    int month;
    int day;
    int year;
};
///////////////////////////////////////////////////////////////////////////////
struct Employee {
    int number;
    float salary;
    Date date;
    Etype etype;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Employee employee[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Employee " << i + 1 << ':' << endl
             << "Enter number:" << endl;
        cin >> employee[i].number;

        cout << "Enter salary:" << endl;
        cin >> employee[i].salary;

        cout << "Enter date in format 12/31/2003:" << endl;
        cin >> employee[i].date.month >> employee[i].date.day >> employee[i].date.year;

        char c;
        cout << "Enter first letter from tittles list:" << endl
             << "laborer, secretary, manager, accountant, executive, researcher" << endl;
        cin >> c;

        switch (c) {
            case 'l':
                employee[i].etype = laborer;
                break;

            case 's':
                employee[i].etype = secretary;
                break;

            case 'm':
                employee[i].etype = manager;
                break;

            case 'a':
                employee[i].etype = accountant;
                break;

            case 'e':
                employee[i].etype = executive;
                break;

            case 'r':
                employee[i].etype = researcher;
                break;

            default:
                cout << "There is no such title!";
                return 0;
        }
    }

    // I'm to lazy to continue.

    return 0;
}

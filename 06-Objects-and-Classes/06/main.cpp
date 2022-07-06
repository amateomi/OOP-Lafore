#include <iomanip>
#include <iostream>

using namespace std;

class Date {
private:
    int day;

    int month;

    int year;

public:
    Date() : day(0), month(0), year(0) {}

    void get() {
        char slash;

        cout << "Enter date in format 31/12/03:" << endl;
        cin >> day >> slash >> month >> slash >> year;
    }

    void show() const {
        cout << "  ";
        if (day <= 9) {
            cout << '0';
        }
        cout << day << '/';
        if (month <= 9) {
            cout << '0';
        }
        cout << month << '/';
        if (year <= 9) {
            cout << '0';
        }
        cout << year
             << "  ";
    }
};

enum Etype {
    none = -1,
    laborer, secretary, manager, accountant, executive, researcher
};

class Employee {
private:
    int number;

    float salary;

    Date hiringDate;

    Etype status;

public:

    Employee() : number(0), salary(0.0f), status(none) {}

    void get() {
        cout << "Enter employee number:" << endl;
        cin >> number;

        cout << "Enter employee salary:" << endl;
        cin >> salary;

        hiringDate.get();

        char c;
        cout << "Enter first letter of the title" << endl
             << "(laborer, secretary, manager, accountant, executive, researcher):" << endl;
        cin >> c;
        switch (c) {
            case 'l':
                status = laborer;
                break;

            case 's':
                status = secretary;
                break;

            case 'm':
                status = manager;
                break;

            case 'a':
                status = accountant;
                break;

            case 'e':
                status = executive;
                break;

            case 'r':
                status = researcher;
                break;

            default:
                cout << "Unknown status!" << endl;
                break;
        }
    }

    void show() const {
        cout << setw(9) << number
             << setw(9) << salary;

        hiringDate.show();

        cout << setw(12);
        switch (status) {
            case laborer:
                cout << "laborer";
                break;

            case secretary:
                cout << "secretary";
                break;

            case manager:
                cout << "manager";
                break;

            case accountant:
                cout << "accountant";
                break;

            case executive:
                cout << "executive";
                break;

            case researcher:
                cout << "researcher";
                break;

            case none:
                cout << "none";
                break;
        }

        cout << endl;
    }
};

int main() {
    Employee employee;

    employee.get();
    employee.show();

    return 0;
}
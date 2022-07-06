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
        cout << day << '/' << month << '/' << year;
    }
};


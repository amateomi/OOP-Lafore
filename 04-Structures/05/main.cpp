#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Date {
    int month;
    int day;
    int year;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Date date = {};
    char slash;

    cout << "Enter date in format 31/12/2002:" << endl;
    cin >> date.month >> slash >> date.day >> slash >> date.year;

    if (date.month < 9) {
        cout << '0';
    }
    cout << date.month << '/';
    if (date.day < 9) {
        cout << '0';
    }

    cout << date.day << '/' << date.year << endl;

    return 0;
}

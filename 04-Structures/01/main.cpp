#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////////////
struct Phone {
    int area;
    int exchange;
    int number;
};

///////////////////////////////////////////////////////////////////////////////
int main() {

    Phone phone1 = {375, 29, 1234};
    Phone phone2 = {};

    cout << "Enter town code, station number and subscriber number:";
    cin >> phone2.area >> phone2.exchange >> phone2.number;

    cout << "My number: " << '(' << phone1.area << ") " << phone1.exchange << '-' << phone1.number << endl;
    cout << "Your number: " << '(' << phone2.area << ") " << phone2.exchange << '-' << phone2.number << endl;

    return 0;
}

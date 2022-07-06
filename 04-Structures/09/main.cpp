#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Time {
    int hour;
    int minute;
    int second;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Time time = {};

    cout << "Enter time:" << endl;
    cin >> time.hour >> time.minute >> time.second;

    cout << "Total seconds is " << time.hour * 3600 + time.minute * 60 + time.second << endl;

    return 0;
}

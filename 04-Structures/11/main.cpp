#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Time {
    int hours;
    int minutes;
    int seconds;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Time t1 = {};
    Time t2 = {};
    char colon;

    cout << "Enter 2 time value in format 23:59:59:" << endl;
    cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds
        >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;

    int sec1, sec2, sec3;

    sec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    sec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    sec3 = sec1 + sec2;

    Time t3 = {};

    t3.hours = sec3 / 3600;
    t3.minutes = (sec3 - t3.hours * 3600) / 60;
    t3.seconds = (sec3 - t3.hours * 3600 - t3.minutes * 60);

    const int HOUR_CYCLE = 24;
    t3.hours -= t3.hours >= HOUR_CYCLE ? HOUR_CYCLE : 0;

    cout << "Result is " << t3.hours << ':' << t3.minutes << ':' << t3.seconds << endl;

    return 0;
}

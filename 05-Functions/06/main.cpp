#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

long convertTimeToSeconds(Time time);

Time convertSecondsToTime(long sec);

int main() {
    Time t1 = {};
    Time t2 = {};
    char colon;

    cout << "Enter 2 time value in format 23:59:59:" << endl;
    cin >> t1.hours >> colon >> t1.minutes >> colon >> t1.seconds
        >> t2.hours >> colon >> t2.minutes >> colon >> t2.seconds;

    long totalSeconds = convertTimeToSeconds(t1) + convertTimeToSeconds(t2);
    cout << "Total seconds is " << totalSeconds << endl;

    Time t3 = convertSecondsToTime(totalSeconds);
    cout << "Final time is " << t3.hours << ':' << t3.minutes << ':' << t3.seconds << endl;

    return 0;
}

long convertTimeToSeconds(Time time) {
    return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

Time convertSecondsToTime(long sec) {
    Time time = {sec / 3600,
                 (sec - time.hours * 3600) / 60,
                 sec - time.hours * 3600 - time.minutes * 60};

    if (time.hours >= 24) {
        time.hours -= 24;
    }

    return time;
}
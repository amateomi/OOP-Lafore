#include <iostream>

using namespace std;

class Time {
private:
    int hours;

    int minutes;

    int seconds;

public:

    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void show() const { cout << hours << ':' << minutes << ':' << seconds; }

    void add(const Time &a, const Time &b) {
        seconds = a.seconds + b.seconds;
        minutes = a.minutes + b.minutes;
        hours = a.hours + b.hours;

        if (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        if (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        if (hours >= 24) {
            hours -= 24;
        }
    }
};

int main() {
    const Time a(5, 45, 11);
    const Time b(20, 12, 59);
    Time c;

    c.add(a, b);
    c.show();

    return 0;
}

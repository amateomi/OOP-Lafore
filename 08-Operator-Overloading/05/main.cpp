#include <iostream>

using namespace std;

class Time {
private:
    int hours;

    int minutes;

    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) { checkTime(); }

    Time operator+(const Time &b) const {
        int s = seconds + b.seconds;
        int m = minutes + b.minutes;
        int h = hours + b.hours;

        if (s >= 60) {
            s -= 60;
            m++;
        }
        if (m >= 60) {
            m -= 60;
            h++;
        }
        if (h >= 24) {
            h -= 24;
        }

        return Time(h, m, s);
    }

    Time operator++() {
        ++seconds;
        checkTime();

        return Time(hours, minutes, seconds);
    }

    Time operator++(int) {
        seconds++;
        checkTime();

        return Time(hours, minutes, seconds - 1);
    }

    Time operator--() {
        --seconds;
        checkTime();

        return Time(hours, minutes, seconds);
    }

    Time operator--(int) {
        seconds--;
        checkTime();

        return Time(hours, minutes, seconds + 1);
    }

    void show() const { cout << hours << ':' << minutes << ':' << seconds; }

    void checkTime() {
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

        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        if (hours < 0) {
            hours += 24;
        }
    }
};

int main() {
    Time time(12, 59, 59);
    time.show();
    cout << endl;

    (++time).show();
    cout << endl;
    (--time).show();
    cout << endl;
    (time++).show();
    cout << endl;
    time.show();
    cout << endl;
    Time t;
    t = ++time;

    cout << endl;
    t.show();
    cout << endl;

    time.show();

    return 0;
}

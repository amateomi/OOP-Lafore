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

    void show() const { cout << hours << ':' << minutes << ':' << seconds; }

    Time operator+(const Time &t) const {
        return Time(hours + t.hours,
                    minutes + t.minutes,
                    seconds + t.seconds);
    }

    Time operator-(const Time &t) const {
        return Time(hours - t.hours,
                    minutes - t.minutes,
                    seconds - t.seconds);
    }

    Time operator*(double n) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds = static_cast<int>(totalSeconds * n);

        int h = totalSeconds / 3600;
        int m = (totalSeconds - h * 3600) / 60;
        int s = totalSeconds - h * 3600 - m * 60;

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
    Time t1(2, 30, 50);
    Time t2(4, 20, 30);

    (t1 + t2).show();
    cout << endl;
    (t1 - t2).show();
    cout << endl;
    (t2 - t1).show();
    cout << endl;
    (t1 * 2.2).show();
    cout << endl;

    return 0;
}

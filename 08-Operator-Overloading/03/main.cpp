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
};

int main() {
    Time t1(5, 30, 20);
    Time t2(20, 30, 50);

    Time t3 = t1 + t2;
    t3.show();

    return 0;
}

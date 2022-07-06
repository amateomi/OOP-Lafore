#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void swap(Time &a, Time &b);

int main() {
    Time t1 = {1, 2, 3};
    Time t2 = {4, 5, 6};

    cout << t1.hours << ':' << t1.minutes << ':' << t1.seconds << ' '
         << t2.hours << ':' << t2.minutes << ':' << t2.seconds << endl;

    swap(t1, t2);

    cout << t1.hours << ':' << t1.minutes << ':' << t1.seconds << ' '
         << t2.hours << ':' << t2.minutes << ':' << t2.seconds << endl;

    return 0;
}

void swap(Time &a, Time &b) {
    Time temp = a;
    a = b;
    b = temp;
}

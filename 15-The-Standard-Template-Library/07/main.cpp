#include <iostream>
#include <list>
#include <numeric>

using namespace std;

class AirTime {
private:
    int hours;

    int minutes;

public:
    AirTime() : hours(), minutes() {}

    AirTime(int h, int m) : hours(h), minutes(m) {}

    bool operator==(const AirTime &right) const {
        return hours == right.hours && minutes == right.minutes;
    }

    bool operator<(const AirTime &right) const {
        return (hours < right.minutes)
               || (hours == right.hours && minutes < right.minutes);
    }

    bool operator>(const AirTime &right) const {
        return !(*this < right || *this == right);
    }

    bool operator!=(const AirTime &right) const {
        return !(*this == right);
    }

    AirTime operator+(const AirTime &right) const {
        AirTime sum(hours + right.hours, minutes + right.minutes);
        if (sum.minutes > 59) {
            sum.minutes -= 60;
            sum.hours++;
        }
        if (sum.hours > 12) {
            sum.hours -= 12;
        }

        return sum;
    }

    void display() const {
        cout << hours << ':' << minutes << endl;
    }

    void get() {
        char colon;
        cout << "Enter time (format 12:59):";
        cin >> hours >> colon >> minutes;
    }
};

int main() {
    char choice;
    AirTime temp, sum;
    list<AirTime> airList;

    do {
        temp.get();
        airList.push_back(temp);

        cout << "Continue(y/n)?";
        cin >> choice;
    } while (choice != 'n');

    sum = accumulate(airList.begin(), airList.end(), AirTime(0, 0));
    cout << "Sum: ";
    sum.display();

    return 0;
}

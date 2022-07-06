#include <iostream>
#include <limits>

using namespace std;

class Time {
private:
    int hours;

    int minutes;

    int seconds;

    static const int HOURS_LIMIT = 23;

    static const int MINUTES_AND_SECONDS_LIMIT = 59;

public:
    Time() : hours(), minutes(), seconds() {}

    bool isCorrect() const {
        bool isCorrect = true;

        if (hours < 0 || hours > HOURS_LIMIT) {
            cout << "Hours out of range! Hours value must be in 0 - "
                 << HOURS_LIMIT << " interval." << endl;
            isCorrect = false;
        }
        if (minutes < 0 || minutes > MINUTES_AND_SECONDS_LIMIT) {
            cout << "Minutes out of range! Minutes value must be in 0 - "
                 << MINUTES_AND_SECONDS_LIMIT << " interval." << endl;
            isCorrect = false;
        }
        if (seconds < 0 || seconds > MINUTES_AND_SECONDS_LIMIT) {
            cout << "Seconds out of range! Seconds value must be in 0 - "
                 << MINUTES_AND_SECONDS_LIMIT << " interval." << endl;
            isCorrect = false;
        }

        return isCorrect;
    }

    void getTime() {
        while (true) {
            cout << "Enter hours:";
            cin.unsetf(ios::skipws);
            cin >> hours;

            if (cin.good() && isCorrect()) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect number!" << endl;
        }

        while (true) {
            cout << "Enter minutes:";
            cin.unsetf(ios::skipws);
            cin >> minutes;

            if (cin.good() && isCorrect()) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect number!" << endl;
        }

        while (true) {
            cout << "Enter seconds:";
            cin.unsetf(ios::skipws);
            cin >> seconds;

            if (cin.good() && isCorrect()) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect number!" << endl;
        }
    }

    void showTime() const {
        cout << hours << ':' << minutes << ':' << seconds;
    }
};

int main() {
    Time time;
    char choice;

    do {
        time.getTime();

        time.showTime();
        cout << endl;

        cout << "Continue?(y/n)";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice == 'y');

    return 0;
}

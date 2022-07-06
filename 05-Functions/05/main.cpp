#include <iostream>

using namespace std;

long convertTimeToSeconds(int h, int m, int s);

int main() {
    int hours;
    int minutes;
    int seconds;
    char isContinue;

    do {
        cout << "Enter hours, minutes and seconds:" << endl;
        cin >> hours >> minutes >> seconds;

        cout << hours << 'h' << minutes << 'm' << seconds << 's' << " is "
             << convertTimeToSeconds(hours, minutes, seconds) << 's' << endl;

        cout << "Continue(y/n)?" << endl;
        cin >> isContinue;
    } while (isContinue != 'n');

    return 0;
}

long convertTimeToSeconds(int h, int m, int s) {
    return (h * 3600 + m * 60 + s);
}
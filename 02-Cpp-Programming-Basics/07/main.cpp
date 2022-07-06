#include <iostream>

using namespace std;

int main() {
    double celsiusTemperature;

    cout << "Enter celsius temperature:";
    cin >> celsiusTemperature;

    cout << celsiusTemperature << " in Fahrenheit system is "
         << celsiusTemperature / 5 * 9 + 32;

    return 0;
}

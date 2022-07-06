#include <iostream>

using namespace std;

int main() {
    double temperature;
    short scale;

    cout << "Enter 1 to convert from Celsius to Fahrenheit" << endl
         << "Enter 2 to convert from Fahrenheit to Celsius:";
    cin >> scale;

    switch (scale) {
        case 1:
            cout << "Enter temperature in Celsius:";
            cin >> temperature;
            cout << temperature << " in Celsius is " << temperature / 5 * 9 + 32 << " in Fahrenheit";
            break;

        case 2:
            cout << "Enter temperature in Fahrenheit:";
            cin >> temperature;
            cout << temperature << " in Fahrenheit is " << (temperature - 32) / 9 * 5 << " in Celsius";
            break;

        default:
            cout << "Wrong input!";
            break;
    }

    return 0;
}

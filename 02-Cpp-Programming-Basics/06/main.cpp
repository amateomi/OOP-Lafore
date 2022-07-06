#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    // Cost in $
    const double pound = 1.487;
    const double frank = 0.172;
    const double mark = 0.584;
    const double yen = 0.00955;
    double dollar;

    cout << "Enter sum of money:";
    cin >> dollar;

    cout << "pound" << setw(8) << dollar / pound << endl
         << "frank" << setw(8) << dollar / frank << endl
         << "mark" << setw(8) << dollar / mark << endl
         << "yen" << setw(8) << dollar / yen << endl;

    return 0;
}

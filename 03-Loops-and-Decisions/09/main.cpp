#include <iostream>

using namespace std;

int main() {
    unsigned int spot;
    unsigned int guest;
    unsigned int way = 1;

    cout << "Enter amount of guests:";
    cin >> guest;
    cout << "Enter amount of spots:";
    cin >> spot;

    for (int i = 0; i < spot; ++i) {
        way *= guest--;
    }

    cout << "There are " << way << " different ways";

    return 0;
}

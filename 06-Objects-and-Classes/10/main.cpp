#include <iostream>

using namespace std;

class Angle {
private:
    int degree;

    float minutes;

    char direction;

public:
    Angle() : degree(0), minutes(0.0f), direction('\0') {}

    Angle(int de, float mi, char di) : degree(de), minutes(mi), direction(di) {}

    void init() {
        cout << "coordinates:" << endl;
        cin >> degree >> minutes >> direction;
    }

    void show() const {
        cout << degree << '\xf8' << minutes << '\'' << ' ' << direction;
    }
};

class Ship {
private:
    static int totalShips;

    int number;

    Angle longitude;

    Angle latitude;

public:
    Ship() : number(++totalShips) {}

    void init() {
        cout << "longitude ";
        longitude.init();

        cout << "latitude ";
        latitude.init();
    }

    void show() const {
        cout << number
             << ' ';

        longitude.show();
        cout << ' ';

        latitude.show();
        cout << ' ';
    }
};

int Ship::totalShips = 0;

int main() {
    Ship ship1;
    Ship ship2;
    Ship ship3;

    ship1.init();
    ship2.init();
    ship3.init();

    ship1.show();
    cout << endl;
    ship2.show();
    cout << endl;
    ship3.show();
    cout << endl;

    return 0;
}

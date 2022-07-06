#include <iostream>

using namespace std;

class Angle {
private:
    int degree;

    float minutes;

    char direction;

public:

    Angle(int de, float mi, char di) : degree(de), minutes(mi), direction(di) {}

    void get() {
        cout << "Enter coordinate:" << endl;
        cin >> degree >> minutes >> direction;
    }

    void show() const {
        cout << degree << '\xf8' << minutes << '\'' << ' ' << direction;
    }
};

int main() {
    Angle angle(105, 13.7f, 'N');

    angle.show();

    return 0;
}

#include <cmath>
#include <iostream>

using namespace std;

class Polar {
private:
    double radius;

    double angle;

public:
    Polar() : radius(), angle() {}

    Polar(double r, double ang) : radius(r), angle(ang) {}

    Polar operator+(const Polar &p) const {
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);
        double x2 = p.radius * cos(p.angle);
        double y2 = p.radius * sin(p.angle);

        double x3 = x1 + x2;
        double y3 = y1 + y2;

        return Polar(sqrt(pow(x3, 2) + pow(y3, 2)),
                     atan(y3 / x3));
    }

    void show() const {
        cout << "r: " << radius << " ang: " << angle;
    }
};

int main() {

    Polar p1(1, 0.52);
    Polar p2(2, 0.785);

    (p1 + p2).show();

    return 0;
}

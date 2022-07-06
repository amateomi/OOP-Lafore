#include <iostream>

using namespace std;

class Distance {
private:
    int feet;

    float inches;

public:
    Distance() : feet(), inches() {}

    Distance(int f, float i) : feet(f), inches(i) {}

    Distance(float n) {
        feet = static_cast<int>(n);
        inches = (n - static_cast<float>(feet)) * 12;
    }

    friend Distance operator*(Distance d1, Distance d2) {
        float n = static_cast<float>(d1.feet) + d1.inches / 12;
        float m = static_cast<float>(d2.feet) + d2.inches / 12;

        return Distance(n * m);
    }

    void show() const {
        cout << feet << "'-" << inches << "''";
    }
};

int main() {
    Distance d1(13.5f);
    Distance d2(10, 5);

    (d1 * d2).show();
    cout << endl;

    (d1 * 2.5f).show();
    cout << endl;

    (2.5f * d1).show();
    cout << endl;

    return 0;
}

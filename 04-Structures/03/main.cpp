#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
struct Distance {
    int feet;
    float inches;
};
///////////////////////////////////////////////////////////////////////////////
struct Volume {
    Distance length;
    Distance width;
    Distance height;
};
///////////////////////////////////////////////////////////////////////////////

int main() {
    Volume volume = {{3, 5},
                     {5, 7},
                     {7, 3}};

    float l = static_cast<float>(volume.length.feet) + volume.length.inches / 12;
    float w = static_cast<float>(volume.width.feet) + volume.width.inches / 12;
    float h = static_cast<float>(volume.height.feet) + volume.height.inches / 12;

    cout << "Volume is " << l * w * h << endl;

    return 0;
}

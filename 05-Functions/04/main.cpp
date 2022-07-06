#include <iostream>

using namespace std;

struct Distance {
    int feet;
    float inches;
};

Distance maxDistance(Distance d1, Distance d2);

int main() {
    Distance d1 = {12, 3.6};
    Distance d2 = {12, 5.77};

    Distance d3 = maxDistance(d1, d2);
    cout << d3.feet << "'-" << d3.inches << "\"" << endl;

    return 0;
}

Distance maxDistance(Distance d1, Distance d2) {
    return (d1.feet > d2.feet) ? d1 :
           (d1.feet < d2.feet) ? d2 :
           (d1.inches > d2.inches) ? d1 : d2;
}
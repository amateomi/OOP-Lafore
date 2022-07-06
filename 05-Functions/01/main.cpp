#include <iostream>

using namespace std;

float computeCircleArea(float r);

const float PI = 3.14159265359;

int main() {
    float radius;

    cout << "Enter radius:" << endl;
    cin >> radius;

    cout << "Area is " << computeCircleArea(radius);

    return 0;
}

float computeCircleArea(float r) {
    return PI * r * r;
}

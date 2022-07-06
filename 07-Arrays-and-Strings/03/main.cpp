#include <iostream>

using namespace std;

class Distance {
private:
    int feet;

    float inches;

public:
    Distance() : feet(0), inches(0.0f) {}

    void getDist() {
        cout << "Enter feet:" << endl;
        cin >> feet;
        cout << "Enter inches:" << endl;
        cin >> inches;
    }

    void showDist() const {
        cout << feet << '\'' << inches << '\"';
    }

    void addDist(Distance &a, Distance &b) {
        inches = a.inches + b.inches;
        feet = a.feet + b.feet;

        if (inches >= 12) {
            inches -= 12;
            feet++;
        }
    }

    void divDistOnNumber(int n) {
        if (n == 0) {
            cout << "Division by zero!";
            return;
        }

        float totalInches = inches + static_cast<float>(feet * 12);

        totalInches /= static_cast<float>(n);

        feet = static_cast<int>(totalInches / 12);
        inches = totalInches - static_cast<float>(feet * 12);
    }
};

int main() {
    const int MAX = 3;
    Distance distances[MAX];
    Distance averageDistance;

    for (int i = 0; i < MAX; ++i) {
        distances[i].getDist();
        averageDistance.addDist(averageDistance, distances[i]);
    }

    averageDistance.divDistOnNumber(MAX);

    cout << "Average distance is ";
    averageDistance.showDist();

    return 0;
}

#include <iostream>

using namespace std;

class Distance {
private:
    int feet;

    float inches;

public:
    Distance() : feet(0), inches(0.0f) {}

    Distance(int f, float i) : feet(f), inches(i) {}

    Distance operator+(Distance d) const {
        int f = feet + d.feet;
        float i = inches + d.inches;
        if (i >= 12) {
            i -= 12;
            f++;
        }
        return Distance(f, i);
    }

    Distance operator-(Distance d) const {
        int f = feet - d.feet;
        float i = inches - d.inches;
        if (i < 0) {
            i += 12;
            f--;
        }

        return Distance(f, i);
    }

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

    Distance a(120, 11.7f);
    Distance b(121, 3.0f);

    Distance c = a + b;
    c.showDist();
    cout << endl;

    c = b - a;
    c.showDist();
    cout << endl;

    return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

class Distance {
private:
    int feet;

    float inches;

public:
    Distance() : feet(), inches() {}

    Distance(int ft, float in) : feet(ft), inches(in) {}

    void getDist() {
        cout << "Enter feet:";
        cin >> feet;
        cout << "Enter inches:";
        cin >> inches;
    }

    void showDist() const {
        cout << feet << "'-" << inches << "''";
    }
};

int main() {
    char choice;
    Distance distance;
    fstream file;

    file.open("12.1.dat", ios::app | ios::out | ios::in | ios::binary);

    do {
        cout << "Enter data:" << endl;
        distance.getDist();

        file.write(reinterpret_cast<char *>(&distance), sizeof(distance));

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');

    file.seekg(ios::beg);

    cout << endl << "Data form file:";
    file.read(reinterpret_cast<char *>(&distance), sizeof(distance));
    while (!file.eof()) {
        cout << endl << "Distance:" << endl;
        distance.showDist();
        file.read(reinterpret_cast<char *>(&distance), sizeof(distance));
    }

    return 0;
}
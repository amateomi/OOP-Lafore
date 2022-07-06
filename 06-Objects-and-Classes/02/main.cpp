#include <iostream>

using namespace std;

class TollBooth {
private:

    unsigned int count;

    double proceed;

public:

    TollBooth() : count(0), proceed(0.0) {}

    void payingCar() {
        count++;
        proceed += 0.50;
    }

    void noPayCar() {
        count++;
    }

    void display() const {
        cout << "Total passed cars: " << count << endl
             << "Total proceed: " << proceed << endl;
    }
};

int main() {
    TollBooth tollBooth;
    char option;

    cout << "Enter 'q' to exit." << endl;
    do {
        cout << "The car pays?(y/n)?:" << endl;
        cin >> option;

        switch (option) {
            case 'y':
                tollBooth.payingCar();
                break;

            case 'n':
                tollBooth.noPayCar();
                break;

            case 'q':
                tollBooth.display();
                return 0;

            default:
                cout << "Unknown operation!" << endl;
                break;
        }
    } while (true);
}

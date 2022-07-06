#include <iostream>

using namespace std;

class Chain {
private:
    static int totalObjects;

    int number;

public:

    Chain() {
        totalObjects++;
        number = totalObjects;
    }

    void showNumber() const {
        cout << number;
    }
};

int Chain::totalObjects = 0;

int main() {
    Chain chain1, chain2, chain3;

    chain1.showNumber();
    chain2.showNumber();
    chain3.showNumber();

    return 0;
}

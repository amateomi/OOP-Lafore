#include <iostream>

using namespace std;

int main() {
    float contribution;
    unsigned short years;
    float rate;

    cout << "Enter initial contribution:";
    cin >> contribution;
    cout << "Enter the number of years:";
    cin >> years;
    cout << "Enter interest rate:";
    cin >> rate;
    rate *= 0.01F;

    for (int i = 0; i < years; ++i) {
        contribution += contribution * rate;
    }

    cout << "After " << years << " years you will get " << contribution << '$' << endl;

    return 0;
}

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    long pop1 = 8425785, pop2 = 47, pop3 = 9761;

    cout << setfill('.')
         << setw(9) << "City" << setw(12) << "Population" << endl
         << setw(9) << "Moscow" << setw(12) << pop1 << endl
         << setw(9) << "Kirov" << setw(12) << pop2 << endl
         << setw(9) << "Morose" << setw(12) << pop3 << endl;

    return 0;
}

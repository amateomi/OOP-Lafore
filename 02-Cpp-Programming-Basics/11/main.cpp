#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cout << setiosflags(ios::left)
         << setw(11) << "Lastname" << setw(9) << "Name"
         << setw(20) << "Address" << setw(20) << "City" << endl

         << setfill('-') << setw(60) << '-' << setfill(' ') << endl

         << setw(11) << "Petrov" << setw(9) << "Vasiliy" << setw(20)
         << "Klenovaya 16" << setw(20) << "St. Petersburg" << endl

         << setw(11) << "Ivanov" << setw(9) << "Sergey" << setw(20)
         << "Osinovaya 3" << setw(20) << "Nahodka" << endl

         << setw(11) << "Sidorov" << setw(9) << "Ivan" << setw(20)
         << "Beresovaya 21" << setw(20) << "Kaliningrad" << endl;

    return 0;
}

#include <conio.h>

#include <iostream>

using namespace std;

int main() {
    char digit;
    unsigned long number = 0;

    cout << "Enter number:";
    for (int i = 0; i < 6; ++i) {
        digit = static_cast<char>(getch());
        if (digit == '\r') { break; }
        number = number * 10 + (digit - '0');
    }

    cout << "Your entered number: " << number << endl;

    return 0;
}

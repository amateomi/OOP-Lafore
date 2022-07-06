#include <cctype>
#include <iostream>

using namespace std;

int main() {
    char letter;

    cout << "Enter letter:";
    cin >> letter;

    cout << "Result of function islower() is: " << islower(letter);

    return 0;
}

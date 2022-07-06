#include <cstring>
#include <iostream>

using namespace std;

void reverseIt(char str[]) {
    size_t len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char str[50];

    cout << "Enter string:" << endl;
    cin.get(str, 50);

    cout << str << endl;
    reverseIt(str);
    cout << str << endl;

    return 0;
}

#include <iostream>

using namespace std;

int compString(char *str1, char *str2) {
    do {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        } else if (*str1 == '\0') {
            return 0;
        }

        str1++ && str2++;
    } while (true);
}

int main() {
    char *str1 = "";
    char *str2 = "aaa";

    cout << compString(str1, str2);

    return 0;
}

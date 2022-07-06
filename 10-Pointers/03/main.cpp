#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int DAYS = 7;
    char *array[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (int i = 0; i < DAYS - 1; ++i) {
        for (int j = i + 1; j < DAYS; ++j) {
            if (strcmp(array[i], array[j]) > 0) {
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < DAYS; ++i) {
        cout << array[i] << endl;
    }

    return 0;
}

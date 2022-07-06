#include <iostream>

using namespace std;

int main() {
    const short height = 20;

    for (int i = 1; i <= height; ++i) {
        for (int j = 0; j < height; ++j) {
            if (j >= height - i) {
                cout << 'X';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}

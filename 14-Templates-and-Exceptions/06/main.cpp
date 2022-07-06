#include <iostream>
#include <cstdlib>

using namespace std;

const int LIMIT = 100;

template<class T>
class SafeArray {
private:
    T array[LIMIT];

public:
    T &operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "Unable index!" << endl;
            exit(1);
        }

        return array[n];
    }
};

int main() {
    SafeArray<int> arr1;

    for (int i = 0; i < LIMIT; ++i) {
        arr1[i] = i;
        cout << arr1[i] << ' ';
    }

    return 0;
}

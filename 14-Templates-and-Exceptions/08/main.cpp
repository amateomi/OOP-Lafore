#include <iostream>

using namespace std;

const int LIMIT = 100;

template<class T>
class SafeArray {
private:
    T array[LIMIT];

public:
    SafeArray() : array() {}

    class OutOfRange {
    };

    T &operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            throw OutOfRange();
        }

        return array[n];
    }
};

int main() {
    do {
        try {

            SafeArray<int> arr1;
            SafeArray<double> arr2;

            for (int i = 0; i < LIMIT; ++i) {
                arr1[i] = i;
                arr2[i] = i * 0.33;
            }

            for (int i = 0; i < LIMIT + 2; ++i) {
                cout << arr1[i] << ' ' << arr2[i] << endl;
            }
        }
        catch (SafeArray<int>::OutOfRange) {
            cout << "Error: index out  of range!" << endl;
            continue;
        }
        catch (SafeArray<double>::OutOfRange) {
            cout << "Error: index out  of range!" << endl;
            continue;
        }
        break;
    } while (true);

    return 0;
}


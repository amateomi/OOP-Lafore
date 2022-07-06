#include <iostream>

using namespace std;

class ArrayDynamic {
private:
    int *ptr;

    int size;

public:
    explicit ArrayDynamic(const int &s) {
        size = s;
        ptr = new int[size];
    }

    ArrayDynamic(const ArrayDynamic &array) {
        size = array.size;
        ptr = new int[size];

        for (int i = 0; i < size; ++i) {
            *(ptr + i) = *(array.ptr + i);
        }
    }

    ~ArrayDynamic() {
        delete[] ptr;
    }

    int &operator[](const int i) const {
        return *(ptr + i);
    }

    ArrayDynamic &operator=(const ArrayDynamic &array) {
        delete[] ptr;

        size = array.size;
        ptr = new int[size];

        for (int i = 0; i < size; ++i) {
            *(ptr + i) = *(array.ptr + i);
        }

        return *this;
    }
};

int main() {
    const int ARRAY_SIZE = 10;
    ArrayDynamic array(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = i * i;
        cout << array[i] << ' ';
    }
    cout << endl;

    ArrayDynamic arr1(array);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    ArrayDynamic arr2(ARRAY_SIZE * ARRAY_SIZE);
    arr2 = arr1;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    return 0;
}

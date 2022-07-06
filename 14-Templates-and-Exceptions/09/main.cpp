#include <iostream>

using namespace std;

const int LIMIT = 100;

template <class T>
class SafeArray {
private:
    T array[LIMIT];

public:
    SafeArray(): array() {}
    
    class OutOfRange {
    public:
        string origin;
        
        int index;
        
        explicit OutOfRange(const string& o, int i): origin(o), index(i) {}
    };
    
    T& operator[](int i) {
        if (i < 0 || i >= LIMIT) {
            throw OutOfRange("Operator[]", i);
        }
        
        return array[i];
    }
};

int main() {
    
    try {
        
        SafeArray<int> arr1;
        
        for (int i = 0; i < LIMIT; ++i) {
            arr1[i] = i;
        }
        
        for (int i = 0; i < LIMIT + 2; ++i) {
            cout << arr1[i] << ' ';
        }
    }
    catch (SafeArray<int>::OutOfRange ex) {
        cout << endl << "Error: array out of bounds in " << ex.origin << endl
             << "Unable index: " << ex.index << endl;
    }
    
    return 0;
}


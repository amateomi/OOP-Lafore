#include <iostream>

using namespace std;

template<class T>
void swaps(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 3, y = 4;

    swaps(x, y);
    cout << "x = " << x << " , y = " << y << endl;

    return 0;
}

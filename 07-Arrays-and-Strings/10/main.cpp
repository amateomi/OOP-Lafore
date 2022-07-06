#include <iostream>

using namespace std;

class Matrix {
private:
    static const int MAX_STRINGS = 10;

    static const int MAX_COLUMNS = 10;

    int matrix[MAX_STRINGS][MAX_COLUMNS];

    int strings;

    int columns;

public:
    Matrix() : matrix(), strings(MAX_STRINGS), columns(MAX_COLUMNS) {}

    Matrix(const int str, const int col) : matrix() {
        if (str > MAX_STRINGS || col > MAX_COLUMNS) {
            cout << endl << "Incompatible amount of strings or columns" << endl;
            strings = columns = 0;
        } else {
            strings = str;
            columns = col;
        }
    }

    void put(const int i, const int j, const int n) {
        if (i > strings || j > columns) {
            cout << endl << "Incompatible amount of strings or columns" << endl;
            return;
        } else {
            matrix[i][j] = n;
        }
    }

    int get(const int i, const int j) const {
        if (i > strings || j > columns) {
            cout << endl << "Incompatible amount of strings or columns" << endl;
            return 0;
        } else {
            return matrix[i][j];
        }
    }
};

int main() {
    Matrix matrix(3, 4);

    matrix.put(3, 2, 7);

    cout << matrix.get(3, 2) << endl;

    return 0;
}

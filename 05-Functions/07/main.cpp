#include <iostream>

using namespace std;

double power(double n, int p = 2);

double power(float n, int p = 2);

double power(long n, int p = 2);

double power(int n, int p = 2);

double power(char n, int p = 2);

int main() {
    cout << power(12.0) << endl;
    cout << power(12.0F) << endl;
    cout << power(12L) << endl;
    cout << power(12) << endl;
    cout << power('a') << endl;

    return 0;
}

double power(double n, int p) {
    double res = 1.0;

    for (int i = 0; i < p; ++i) {
        res *= n;
    }

    return res;
}

double power(float n, int p) {
    double res = 1.0;

    for (int i = 0; i < p; ++i) {
        res *= n;
    }

    return res;
}

double power(long n, int p) {
    double res = 1.0;

    for (int i = 0; i < p; ++i) {
        res *= n;
    }

    return res;
}

double power(int n, int p) {
    double res = 1.0;

    for (int i = 0; i < p; ++i) {
        res *= n;
    }

    return res;
}

double power(char n, int p) {
    double res = 1.0;

    for (int i = 0; i < p; ++i) {
        res *= n;
    }

    return res;
}
#include <iostream>

using namespace std;

struct Sterling {
    int pounds;
    int shilling;
    int pence;
};

Sterling getSterling();

Sterling sumSterling(Sterling &a, Sterling &b);

void printSterling(const Sterling &sterling);

int main() {
    Sterling s1 = getSterling();
    Sterling s2 = getSterling();

    Sterling s3 = sumSterling(s1, s2);

    printSterling(s1);
    printSterling(s2);
    printSterling(s3);

    return 0;
}

Sterling getSterling() {
    Sterling sterling = {};
    char point;

    cout << "Enter sum of money in old sterling system:" << endl << 'J';
    cin >> sterling.pounds >> point >> sterling.shilling >> point >> sterling.pence;

    return sterling;
}

Sterling sumSterling(Sterling &a, Sterling &b) {
    Sterling res = {a.pounds + b.pounds,
                    a.shilling + b.shilling,
                    a.pence + b.pence};

    if (res.pence >= 12) {
        res.pence -= 12;
        res.shilling++;
    }
    if (res.shilling >= 20) {
        res.shilling -= 20;
        res.pounds++;
    }

    return res;
}

void printSterling(const Sterling &sterling) {
    cout << 'J' << sterling.pounds << '.' << sterling.shilling << '.' << sterling.pence << endl;
}
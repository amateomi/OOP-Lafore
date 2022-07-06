#include <iostream>

using namespace std;

enum etype {
    Laborer, Secretary, Manager, Accountant, Executive, Researcher
};

int main() {
    etype etype;
    char letter;

    cout << "Enter first letter of the title" << endl
         << "(laborer, secretary, manager, accountant, executive, researcher):" << endl;
    cin >> letter;

    switch (letter) {
        case 'l':
            etype = Laborer;
            break;

        case 's':
            etype = Secretary;
            break;

        case 'm':
            etype = Manager;
            break;

        case 'a':
            etype = Accountant;
            break;

        case 'e':
            etype = Executive;
            break;

        case 'r':
            etype = Researcher;
            break;

        default:
            cout << "There is no such title!";
            return 0;
    }

    cout << "Full title is ";
    switch (etype) {
        case Laborer:
            cout << "laborer" << endl;
            break;

        case Secretary:
            cout << "secretary" << endl;
            break;

        case Manager:
            cout << "manager" << endl;
            break;

        case Accountant:
            cout << "accountant" << endl;
            break;

        case Executive:
            cout << "executive" << endl;
            break;

        case Researcher:
            cout << "researcher" << endl;
            break;
    }

    return 0;
}

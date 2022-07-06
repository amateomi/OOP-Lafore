#include <iostream>

using namespace std;

int main() {
    double operand1, operand2;
    char operation;
    char isContinue;

    do {
        cout << "Enter first operand, operation and second operand:";
        cin >> operand1 >> operation >> operand2;

        switch (operation) {
            case '+':
                cout << "Result is " << operand1 + operand2;
                break;

            case '-':
                cout << "Result is " << operand1 - operand2;
                break;

            case '*':
                cout << "Result is " << operand1 * operand2;
                break;

            case '/':
                if (operand2 == 0) {
                    cout << "Division by zero";
                } else {
                    cout << "Result is " << operand1 / operand2;
                }
                break;

            default:
                cout << "Unknown operation";
                break;
        }

        cout << endl << "Continue (y/n)?";
        cin >> isContinue;
    } while (isContinue != 'n');

    return 0;
}

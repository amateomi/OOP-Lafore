#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

bool checkCout() {
    bool isCorrect = true;

    if (cin.get() != '\n') {
        cout << "Incorrect input!" << endl;
        isCorrect = false;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return isCorrect;
}

int main() {
    string name;
    string lastname;
    string patronymic;
    unsigned long number;

    char choice;

    ofstream outputFile("12.4.txt", ios::trunc);
    if (!outputFile) {
        cerr << "Unable to open 12.4.txt!";
        return 1;
    }
    do {
        cout << "Enter name:";
        cin >> name;
        checkCout();
        cout << "Enter lastname:";
        cin >> lastname;
        cout << "Enter patronymic:";
        cin >> patronymic;
        cout << "Enter number:";
        cin >> number;

        outputFile << name << ' ' << lastname << ' ' << patronymic << ' '
                   << number << endl;

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');
    outputFile.close();

    ifstream inputFile("12.4.txt");
    if (!inputFile) {
        cerr << "Unable to open 12.4.txt!";
        return 1;
    }

    cout << endl << "Info from file:" << endl << endl;

    inputFile >> name >> lastname >> patronymic >> number;
    while (inputFile) {
        cout << name << ' ' << lastname << ' ' << patronymic << ' ' << number
             << endl;
        inputFile >> name >> lastname >> patronymic >> number;
    }

    return 0;
}

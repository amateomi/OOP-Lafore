#include <iostream>
#include <fstream>

using namespace std;

class Person {
private:
    string name;

    string lastname;

    string patronymic;

    unsigned long number;

    static string fileName;

    static fstream file;

public:
    Person() : name(), lastname(), patronymic(), number() {}

    friend istream &operator>>(istream &in, Person &data) {
        in >> data.name >> data.lastname >> data.patronymic >> data.number;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Person &data) {
        out << data.name << ' ' << data.lastname << ' '
            << data.patronymic << ' ' << data.number << endl;
        return out;
    }

    static string getFileName() {
        return fileName;
    }

    static void setFileName(const string &newFileName) {
        fileName = newFileName;
    }

    static bool openFile() {
        bool isOK = true;

        file.open(fileName.c_str(), ios::app | ios::in | ios::out);
        if (!file) {
            cerr << "Unable to open " << fileName << endl;
            isOK = false;
        }

        return isOK;
    }

    static void closeFile() {
        file.close();
    }

    static void rewind() {
        file.seekg(0);
    }

    bool writeToFile() const {
        bool isOK = true;

        if (!file.is_open()) {
            cerr << "Open file first!" << endl;
            isOK = false;
        } else {
            file << *this;
        }

        return isOK;
    }

    bool readFromFile(int recordNumber) {
        bool isOK = true;

        if (recordNumber <= 0 || recordNumber > getTotalFileRecords()) {
            cerr << "No such record number in file!" << endl;
            isOK = false;
        } else if (!file.is_open()) {
            cerr << "Open file first!" << endl;
            isOK = false;
        } else {
            rewind();
            for (int count = 1; count <= recordNumber; ++count) {
                file >> *this;
            }
        }

        return isOK;
    }

    static int getTotalFileRecords() {
        if (!file.is_open()) {
            cerr << "Open file first!" << endl;
            return -1;
        }

        Person person;
        int count = 0;

        rewind();
        file >> person;
        while (!file.eof()) {
            file >> person;
            count++;
        }
        file.clear();
        rewind();

        return count;
    }
};

string Person::fileName;
fstream Person::file;

int main() {
    Person person;
    char choice;
    string fileName = "data file.txt";

    Person::setFileName(fileName);
    if (!Person::openFile()) {
        return 1;
    }

    do {
        cout << "Enter name, lastname, patronymic and number:";
        cin >> person;
        person.writeToFile();

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');

    int record;
    int totalRecords = Person::getTotalFileRecords();
    if (totalRecords < 0) {
        return 1;
    }

    do {
        cout << "In file " << totalRecords << " person records." << endl;

        cout << "Enter record number to show data from file:";
        cin >> record;
        if (person.readFromFile(record)) {
            cout << person;
        }

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');
    Person::closeFile();

    return 0;
}


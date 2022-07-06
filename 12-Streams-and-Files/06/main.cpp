#include <iostream>
#include <fstream>

using namespace std;

class Person {
private:
    string name;

    string lastname;

    string patronymic;

    unsigned long number;

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

    bool writeToFile(const char *fileName) const {
        ofstream out(fileName, ios::app);
        if (!out) {
            cerr << "Unable to open " << fileName << endl;
            out.close();
            return false;
        }
        out << *this;
        out.close();
        return true;
    }

    bool readFromFile(const char *fileName, int recordNumber) {
        if (recordNumber <= 0
            || recordNumber > getTotalRecordNumberInFile(fileName)) {
            cerr << "No such record number number in file!" << endl;
            return false;
        }
        ifstream in(fileName);
        if (!in) {
            cerr << "Unable to open " << fileName << endl;
            in.close();
            return false;
        }

        for (int count = 1; count <= recordNumber; ++count) {
            in >> *this;
        }

        in.close();
        return true;
    }

    static int getTotalRecordNumberInFile(const char *fileName) {
        ifstream in(fileName);
        if (!in) {
            cerr << "Unable to open " << fileName << endl;
            in.close();
            return -1;
        }

        Person person;
        int count = 0;
        in >> person;
        while (!in.eof()) {
            in >> person;
            count++;
        }

        return count;
    }
};

int main() {
    Person person;
    char choice;
    char fileName[] = "data file.txt";

    do {
        cout << "Enter name, lastname, patronymic and number:";
        cin >> person;
        person.writeToFile(fileName);

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');

    int recordNumber;
    do {
        cout << "In file " << Person::getTotalRecordNumberInFile(fileName)
             << " person records." << endl;

        cout << "Enter record number to show data from file:";
        cin >> recordNumber;
        if (person.readFromFile(fileName, recordNumber)) {
            cout << person;
        }

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}

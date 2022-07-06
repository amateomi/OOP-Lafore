#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdlib>

using namespace std;

const int LEN = 32;

const int MAX_EMPLOYEE = 100;

enum EmployeeType {
    manager, scientist, laborer
};

class Employee {
private:
    char name[LEN];

    unsigned long number;

    static int n;

    static Employee *array[];

public:
    virtual void getData() {
        cin.ignore(10, '\n');
        cout << "Enter lastname:";
        cin >> name;
        cout << "Enter number:";
        cin >> number;
    }

    virtual void putData() const {
        cout << "Lastname: " << name << endl;
        cout << "Number: " << number << endl;
    }

    virtual EmployeeType getType();

    static void add();

    static void display();

    static void read();

    static void write();

    static void find();
};

int Employee::n;
Employee *Employee::array[MAX_EMPLOYEE];

class Manager : public Employee {
private:
    char title[LEN];

    double dues;

public:
    void getData() {
        Employee::getData();
        cin.ignore(10, '\n');
        cout << "Enter title:";
        cin >> title;
        cout << "Enter dues:";
        cin >> dues;
    }

    void putData() const {
        Employee::putData();
        cout << "Title: " << title << endl;
        cout << "Dues: " << dues << endl;
    }
};

class Scientist : public Employee {
private:
    int pubs;

public:
    void getData() {
        Employee::getData();
        cin.ignore(10, '\n');
        cout << "Enter pubs:";
        cin >> pubs;
    }

    void putData() const {
        Employee::putData();
        cout << "Pubs: " << pubs << endl;
    }
};

class Laborer : public Employee {
};

void Employee::add() {
    char choice;

    cout << "'m' - manager" << endl
         << "'s' - scientist" << endl
         << "'l' - laborer" << endl
         << "Your choice:";
    cin >> choice;

    switch (choice) {
        case 'm':
            array[n] = new Manager;
            break;

        case 's':
            array[n] = new Scientist;
            break;

        case 'l':
            array[n] = new Laborer;
            break;

        default:
            cout << "Unknown employee type!" << endl;
            return;
    }

    array[n++]->getData();
}

void Employee::display() {
    for (int i = 0; i < n; ++i) {
        cout << "No " << i + 1;
        switch (array[i]->getType()) {
            case manager:
                cout << " Type: Manager:" << endl;
                break;

            case scientist:
                cout << " Type: Scientist:" << endl;
                break;

            case laborer:
                cout << " Type: Laborer:" << endl;
                break;

            default:
                cout << "Unknown type!" << endl;
        }
        array[i]->putData();
        cout << endl;
    }
}

EmployeeType Employee::getType() {
    if (typeid(*this) == typeid(Manager)) {
        return manager;
    } else if (typeid(*this) == typeid(Scientist)) {
        return scientist;
    } else if (typeid(*this) == typeid(Laborer)) {
        return laborer;
    } else {
        cerr << "Wrong employee type!" << endl;
        exit(1);
    }
}

void Employee::write() {
    int size;
    EmployeeType type;

    ofstream out("Employee.dat", ios::trunc | ios::binary);
    if (!out) {
        cerr << "Unable to open file!" << endl;
        return;
    }

    cout << "Writing " << n << "employees." << endl;
    for (int i = 0; i < n; ++i) {
        type = array[i]->getType();
        out.write(reinterpret_cast<char *>(&type), sizeof(type));
        switch (type) {
            case manager:
                size = sizeof(Manager);
                break;

            case scientist:
                size = sizeof(Scientist);
                break;

            case laborer:
                size = sizeof(Laborer);
                break;
        }

        out.write(reinterpret_cast<char *>(array[i]), size);
        if (!out) {
            cerr << "Unable to write into file!" << endl;
            return;
        }
    }
}

void Employee::read() {
    int size;
    EmployeeType type;

    ifstream in("Employee.dat", ios::binary);
    if (!in) {
        cerr << "Unable to open file!";
        return;
    }

    n = 0;
    while (true) {
        in.read(reinterpret_cast<char *>(&type), sizeof(type));
        if (in.eof()) {
            break;
        }
        if (!in) {
            cerr << "Unable to read type!" << endl;
            return;
        }

        switch (type) {
            case manager:
                array[n] = new Manager;
                size = sizeof(Manager);
                break;

            case scientist:
                array[n] = new Scientist;
                size = sizeof(Scientist);
                break;

            case laborer:
                array[n] = new Laborer;
                size = sizeof(Laborer);
                break;

            default:
                cerr << "Unknown type in file!" << endl;
                return;
        }

        in.read(reinterpret_cast<char *>(array[n]), size);
        if (!in) {
            cerr << "Unable to read form file" << endl;
            return;
        }

        n++;
    }
    cout << "Read " << n << " employees." << endl;
}

void Employee::find() {
    ifstream in("Employee.dat", ios::binary);
    if (!in) {
        cerr << "Unable to open file!" << endl;
        return;
    }

    Employee *employee;
    EmployeeType type;
    int size;

    int number;
    int count = 1;
    cout << "Enter No:";
    cin >> number;
    if (number <= 0) {
        cout << "No must be positive!" << endl;
        return;
    }

    while (true) {
        in.read(reinterpret_cast<char *>(&type), sizeof(type));
        if (in.eof()) {
            cout << "No such No in file!" << endl;
            break;
        }
        if (!in) {
            cerr << "Unable to read type!" << endl;
            return;
        }

        switch (type) {
            case manager:
                employee = new Manager;
                size = sizeof(Manager);
                break;

            case scientist:
                employee = new Scientist;
                size = sizeof(Scientist);
                break;

            case laborer:
                employee = new Laborer;
                size = sizeof(Laborer);
                break;

            default:
                cerr << "Unknown type in file!" << endl;
                return;
        }

        in.read(reinterpret_cast<char *>(employee), size);

        if (count == number) {
            switch (type) {
                case manager:
                    cout << " Type: Manager:" << endl;
                    break;

                case scientist:
                    cout << " Type: Scientist:" << endl;
                    break;

                case laborer:
                    cout << " Type: Laborer:" << endl;
                    break;

                default:
                    cout << "Unknown type!" << endl;
            }
            employee->putData();
            cout << endl;

            delete employee;
            return;
        }

        count++;
    }
}

int main() {
    char choice;

    while (true) {
        cout << "'a' - add employee" << endl
             << "'d' - display employees" << endl
             << "'w' - write in file" << endl
             << "'r' - read from file" << endl
             << "'f' - find in file" << endl
             << "'q' - quite program" << endl
             << "Your choice:";
        cin >> choice;
        switch (choice) {
            case 'a':
                Employee::add();
                break;

            case 'd':
                Employee::display();
                break;

            case 'w':
                Employee::write();
                break;

            case 'r':
                Employee::read();
                break;

            case 'f':
                Employee::find();
                break;

            case 'q':
                exit(0);

            default:
                cout << "Unknown command!" << endl;
        }
    }
}

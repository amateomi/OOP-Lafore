#include <iostream>

using namespace std;

const int LEN = 30;

class Employee {
private:
    char name[LEN];

    unsigned long number;

public:
    void getData() {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter number:";
        cin >> number;
    }

    void putData() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class Manager : private Employee {
private:
    char title[LEN];

    double dues;

public:
    void getData() {
        Employee::getData();
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

class Scientist : private Employee {
private:
    int pubs;

public:
    void getData() {
        Employee::getData();
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

class Compensation {
private:
    double compensation;

    enum {
        none, hourly, weakly, monthly
    }
            period;

public:
    void getData() {
        cout << "Enter compensation:";
        cin >> compensation;
        char letter;
        cout << "Enter first letter form periods list:\n"
                "(hourly, weakly, monthly)" << endl;
        cin >> letter;
        switch (letter) {
            case 'h':
                period = hourly;
                break;

            case 'w':
                period = weakly;
                break;

            case 'm':
                period = monthly;
                break;

            default:
                cout << "Unknown period!";
                period = none;
        }
        cout << endl;
    }

    void putData() const {
        cout << "Compensation: " << compensation << endl;
        cout << "Period: ";
        switch (period) {
            case hourly:
                cout << "hourly";
                break;

            case weakly:
                cout << "weakly";
                break;

            case monthly:
                cout << "monthly";
                break;

            default:
                cout << "none";
                break;
        }
        cout << endl;
    }
};

class Manager2 : private Manager, private Compensation {
public:
    void getData() {
        Manager::getData();
        Compensation::getData();
    }

    void putData() const {
        Manager::putData();
        Compensation::putData();
    }
};

class Scientist2 : private Scientist, private Compensation {
public:
    void getData() {
        Scientist::getData();
        Compensation::getData();
    }

    void putData() const {
        Scientist::putData();
        Compensation::putData();
    }
};

class Laborer2 : private Laborer, private Compensation {
public:
    void getData() {
        Laborer::getData();
        Compensation::getData();
    }

    void putData() const {
        Laborer::putData();
        Compensation::putData();
    }
};
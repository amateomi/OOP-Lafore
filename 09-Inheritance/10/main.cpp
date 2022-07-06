#include <iostream>

using namespace std;

const int LEN = 30;

class Student {
private:
    char school[LEN];

    char degree[LEN];

public:
    void getEdu() {
        cout << "Enter school:";
        cin >> school;
        cout << "Enter degree:";
        cin >> degree;
    }

    void putEdu() const {
        cout << "School: " << school << endl;
        cout << "Degree: " << degree << endl;
    }
};

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

class Manager : private Employee, private Student {
private:
    char title[LEN];

    double dues;

public:
    void getData() {
        Employee::getData();
        Student::getEdu();
        cout << "Enter title:";
        cin >> title;
        cout << "Enter dues:";
        cin >> dues;
    }

    void putData() const {
        Employee::putData();
        Student::putEdu();
        cout << "Title: " << title << endl;
        cout << "Dues: " << dues << endl;
    }
};

class Scientist : private Employee, private Student {
private:
    int pubs;

public:
    void getData() {
        Employee::getData();
        Student::getEdu();
        cout << "Enter pubs:";
        cin >> pubs;
    }

    void putData() const {
        Employee::putData();
        Student::putEdu();
        cout << "Pubs: " << pubs << endl;
    }
};

class Laborer : public Employee {
};

class Executive : private Manager {
private:
    double premium;

    int shares;

public:
    void getData() {
        Manager::getData();
        cout << "Enter premium:";
        cin >> premium;
        cout << "Enter shares:";
        cin >> shares;
    }

    void putData() const {
        Manager::putData();
        cout << "Premium: " << premium << endl;
        cout << "Shares: " << shares << endl;
    }
};
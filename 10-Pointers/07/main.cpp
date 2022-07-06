#include <iostream>

using namespace std;

class Person {
protected:
    string name;

    float salary;

public:
    Person() : salary() {}

    void setData() {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter salary:";
        cin >> salary;
    }

    void printData() const {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    string getName() const {
        return name;
    }

    float getSalary() const {
        return salary;
    }
};

void salarySort(Person *pPerson[], int n) {
    for (int i = 0; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((*(pPerson + i))->getSalary() > (*(pPerson + j))->getSalary()) {
                Person *temp = *(pPerson + i);
                *(pPerson + i) = *(pPerson + j);
                *(pPerson + j) = temp;
            }
        }
    }
}

int main() {
    Person *persons[100];
    int n = 0;
    char choice;

    do {
        persons[n] = new Person;
        persons[n]->setData();
        n++;

        cout << "Continue(y/n)?";
        cin >> choice;
    } while (choice == 'y');

    cout << "Unsorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ':' << endl;
        persons[i]->printData();
    }

    salarySort(persons, n);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ':' << endl;
        persons[i]->printData();
    }

    return 0;
}

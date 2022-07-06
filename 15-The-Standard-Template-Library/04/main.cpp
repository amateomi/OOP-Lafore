#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Person {
private:
    string lastName;

    string firstName;

    long phoneNumber;

public:
    Person() : lastName("empty"), firstName("empty"), phoneNumber(0L) {}

    Person(const string &la, const string &fi, long ph) :
            lastName(la), firstName(fi), phoneNumber(ph) {}

    ~Person() {
        cout << "Destructing ";
        display();
    }

    friend bool operator<(const Person &p1, const Person &p2) {
        if (p1.lastName == p2.lastName) {
            return p1.firstName < p2.firstName;
        }
        return p1.lastName < p2.lastName;
    }

    void display() const {
        cout << lastName << '\t' << firstName << '\t' << phoneNumber << endl;
    }
};

class ComparePersons {
public:
    bool operator()(const Person *p1, const Person *p2) const {
        return *p1 < *p2;
    }
};

void Display(const Person *person) {
    person->display();
}

int main() {
    multiset<Person *, ComparePersons> personSet;
    multiset<Person *, ComparePersons>::iterator iter;

    Person *p1 = new Person("a", "a", 1);
    Person *p2 = new Person("b", "b", 2);
    Person *p3 = new Person("a", "a", 3);
    Person *p4 = new Person("a", "b", 4);
    Person *p5 = new Person("zxc", "qwe", 5);
    Person *p6 = new Person("qwe", "zxc", 6);

    personSet.insert(p1);
    personSet.insert(p2);
    personSet.insert(p3);
    personSet.insert(p4);
    personSet.insert(p5);
    personSet.insert(p6);

    cout << "In multiset " << personSet.size() << " persons:" << endl;
    for_each(personSet.begin(), personSet.end(), Display);

    for (iter = personSet.begin(); iter != personSet.end(); ++iter) {
        delete *iter;
    }

    return 0;
}

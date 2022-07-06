#include <iostream>

using namespace std;

class Date {
private:
    int day;

    int month;

    int year;

public:
    Date() : day(), month(), year() {}

    void getData() {
        char slash;

        cout << "Enter date in format 31/12/03:";
        cin >> day >> slash >> month >> slash >> year;
    }

    void putData() const {
        cout << day << '/' << month << '/' << year;
    }
};

class Publication {
private:
    string title;

    float price;

public:
    Publication() : title(), price() {}

    void getData() {
        cout << "Enter name:";
        cin >> title;
        cout << "Enter price:";
        cin >> price;
    }

    void putData() const {
        cout << "Name: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Publication2 : private Publication {
private:
    Date date;

public:
    Publication2() : Publication(), date() {}

    void getData() {
        Publication::getData();
        date.getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Date:";
        date.putData();
        cout << endl;
    }
};

class Book : private Publication2 {
private:
    int pages;

public:
    Book() : Publication2(), pages() {}

    void getData() {
        Publication2::getData();
        cout << "Enter pages:";
        cin >> pages;
    }

    void putData() const {
        Publication2::putData();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : private Publication2 {
private:
    float time;

public:
    Tape() : Publication2(), time() {}

    void getData() {
        Publication2::getData();
        cout << "Enter time:";
        cin >> time;
    };

    void putData() const {
        Publication2::putData();
        cout << "Time: " << time << endl;
    }
};

int main() {
    Book book;
    Tape type;

    book.getData();
    type.getData();

    book.putData();
    type.putData();

    return 0;
}

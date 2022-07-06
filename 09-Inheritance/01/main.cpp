#include <iostream>

using namespace std;

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

class Book : private Publication {
private:
    int pages;

public:
    Book() : Publication(), pages() {}

    void getData() {
        Publication::getData();
        cout << "Enter pages:";
        cin >> pages;
    }

    void putData() const {
        Publication::putData();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : private Publication {
private:
    float time;

public:
    Tape() : Publication(), time() {}

    void getData() {
        Publication::getData();
        cout << "Enter record time:";
        cin >> time;
    };

    void putData() const {
        Publication::putData();
        cout << "Record time: " << time << endl;
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

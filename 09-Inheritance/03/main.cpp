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

class Sales {
private:
    static const int MONTHS = 3;

    float incomes[MONTHS];

public:
    Sales() : incomes() {}

    void getData() {
        cout << "Enter income for last " << MONTHS << " months:" << endl;
        for (int i = 0; i < MONTHS; ++i) {
            cout << "Month " << i + 1 << ':';
            cin >> incomes[i];
        }
    }

    void putData() const {
        cout << "Incomes for last 3 months:" << endl;
        for (int i = 0; i < MONTHS; ++i) {
            cout << "Month " << i + 1 << ": " << incomes[i] << endl;
        }
    }
};

class Book : private Publication, private Sales {
private:
    int pages;

public:
    Book() : Publication(), Sales(), pages() {}

    void getData() {
        Publication::getData();
        cout << "Enter pages:";
        cin >> pages;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Pages: " << pages << endl;
        Sales::putData();
    }
};

class Tape : private Publication, private Sales {
private:
    float time;

public:
    Tape() : Publication(), Sales(), time() {}

    void getData() {
        Publication::getData();
        cout << "Enter record time:";
        cin >> time;
        Sales::getData();
    };

    void putData() const {
        Publication::putData();
        cout << "Record time: " << time << endl;
        Sales::putData();
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter book information:" << endl << endl;
    book.getData();

    cout << "Enter tape information:" << endl << endl;
    tape.getData();

    cout << "Book:" << endl;
    book.putData();

    cout << "Tape:" << endl;
    book.putData();

    return 0;
}

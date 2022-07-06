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

class Disk : private Publication, private Sales {
private:
    enum {
        none, CD, DVD
    } type;

public:
    Disk() : Publication(), Sales(), type() {}

    void getData() {
        Publication::getData();
        cout << "Choose disk type, enter first letter from list (CD, DVD):";
        char temp;
        cin >> temp;
        switch (temp) {
            case 'C':
                type = CD;
                break;

            case 'D':
                type = DVD;
                break;

            default:
                cout << "Unknown type!";
                break;
        }
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Type: ";
        switch (type) {
            case CD:
                cout << "CD";
                break;

            case DVD:
                cout << "DVD";
                break;

            default:
                cout << "none";
                break;
        }
        cout << endl;
        Sales::putData();
    }
};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter book information:" << endl << endl;
    book.getData();

    cout << "Enter tape information:" << endl << endl;
    tape.getData();

    cout << "Enter disk information:" << endl << endl;
    disk.getData();

    cout << "Book:" << endl;
    book.putData();

    cout << "Tape:" << endl;
    book.putData();

    cout << "Disk:" << endl;
    disk.putData();

    return 0;
}


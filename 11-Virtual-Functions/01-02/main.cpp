#include <iostream>
#include <typeinfo>

using namespace std;

class Publication {
private:
    string title;

    float price;

public:
    Publication() : title(), price() {}

    virtual void getData() {
        cout << "Enter name:";
        cin >> title;
        cout << "Enter price:";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Name: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
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

class Tape : public Publication {
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
    Publication *publications[100];
    int n = 0;
    char choice;

    do {
        cout << "Book or Tape?(b/t)";
        cin >> choice;

        switch (choice) {
            case 'b':
                publications[n] = new Book;
                break;

            case 't':
                publications[n] = new Tape;
                break;

            default:
                cout << "Unknown choice! Try again!" << endl;
                choice = 'y';
                continue;
        }

        publications[n++]->getData();

        cout << "Continue?(y/n)";
        cin >> choice;
    } while (choice == 'y');

    for (int i = 0; i < n; ++i) {
        cout << typeid(publications[i]).name() << " No. " << i + 1 << endl;
        publications[i]->putData();
    }

    return 0;
}

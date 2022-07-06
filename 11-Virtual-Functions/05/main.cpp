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

    virtual bool isOversize() const { return false; }
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

    bool isOversize() const {
        const int PAGES_LIMIT = 800;

        if (pages > PAGES_LIMIT) {
            cout << "Too many pages!" << endl;
            return true;
        }

        return false;
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

    bool isOversize() const {
        const int TIME_LIMIT = 90;

        if (time > TIME_LIMIT) {
            cout << "Too many minutes!" << endl;
            return true;
        }

        return false;
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
        cout << typeid(*publications[i]).name() << " No. " << i + 1 << endl;
        publications[i]->putData();
        publications[i]->isOversize();
    }

    return 0;
}

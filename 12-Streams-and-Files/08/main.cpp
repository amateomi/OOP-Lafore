#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Linklist {
private:
    Node *first;

public:
    Linklist() : first() {}

    void addItem(int d);

    void display() const;

    void write(const string &fileName) const;

    void read(const string &fileName);
};

int main() {
    Linklist linklist;
    char choice;
    string fileName = "data.txt";

    do {
        cout << "Choose option:" << endl
             << "1) Add item to list" << endl
             << "2) Display list" << endl
             << "3) Write in file" << endl
             << "4) Read form file" << endl
             << "0) Quite program" << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                int number;
                cout << "Enter number:";
                cin >> number;
                linklist.addItem(number);
                break;

            case '2':
                cout << "List:" << endl;
                linklist.display();
                break;

            case '3':
                linklist.write(fileName);
                break;

            case '4':
                linklist.read(fileName);
                break;

            case '0':
                return 0;

            default:
                cout << "Unknown operation!" << endl;
                break;
        }
    } while (true);
    return 0;
}

void Linklist::addItem(int d) {
    Node *newNode = new Node;
    newNode->data = d;
    newNode->next = first;
    first = newNode;
}

void Linklist::display() const {
    Node *current = first;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

void Linklist::write(const string &fileName) const {
    ofstream file(fileName.c_str(), ios::trunc);
    if (!file) {
        cerr << "Unable to open " << fileName << endl;
        exit(1);
    }

    Node *current = first;
    while (current) {
        file << current->data << ' ';
        current = current->next;
    }

    file.close();
}

void Linklist::read(const string &fileName) {
    ifstream file(fileName.c_str());
    if (!file) {
        cerr << "Unable to open " << fileName << endl;
        exit(1);
    }

    int data;
    file >> data;
    while (!file.eof()) {
        addItem(data);
        file >> data;
    }

    file.close();
}
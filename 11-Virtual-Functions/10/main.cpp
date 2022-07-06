#include <iostream>

using namespace std;

class ListNode {
public:
    int data;

    ListNode *next;
};

class List {
private:
    ListNode *head;

public:
    List() : head() {}

    List(const List &l) : head() {
        ListNode *temp = l.head;
        while (temp) {
            this->add(temp->data);
            temp = temp->next;
        }
    }

    ~List() {
        clear();
    }

    List &operator=(const List &l) {
        if (head != l.head) {
            clear();

            ListNode *temp = l.head;
            while (temp) {
                this->add(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    void add(int d) {
        ListNode *temp = new ListNode;
        temp->data = d;
        temp->next = head;
        head = temp;
    }

    void show() {
        ListNode *temp = head;
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    void clear() {
        while (head) {
            cout << "Deleting " << head->data << endl;

            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    list.show();

    List list1(list);
    list1.show();
    cout << endl;

    List l1;
    l1.add(7);
    l1.add(8);
    l1.add(9);
    l1.show();

    cout << endl;
    l1 = l1;
    l1.show();

    return 0;
}

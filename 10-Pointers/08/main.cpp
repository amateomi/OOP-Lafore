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
    List() : head(NULL) {}

    ~List() {
        while (head) {
            cout << "Deleting " << head->data << endl;

            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int d) {
        ListNode *newElement = new ListNode;
        newElement->data = d;
        newElement->next = NULL;

        if (head == NULL) {
            head = newElement;
        } else {
            ListNode *temp = head;
            while (temp->next) {
                temp = temp->next;
            }

            temp->next = newElement;
        }
    }

    void show() {
        ListNode *temp = head;
        while (temp) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
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

    return 0;
}

#include <iostream>

using namespace std;

class Queue {
private:
    static const int MAX_ELEMENTS = 5;

    int amountOfElements;

    int queue[MAX_ELEMENTS];

    int head;

    int tail;

public:
    Queue() : amountOfElements(), queue(), head(), tail() {}

    void put(int n) {
        if (amountOfElements == MAX_ELEMENTS) {
            cout << endl << "Queue is full!" << endl;
            return;
        }

        queue[tail++] = n;
        amountOfElements++;

        if (tail == MAX_ELEMENTS) {
            tail = 0;
        }
    }

    int get() {
        if (amountOfElements == 0) {
            cout << endl << "Queue is empty!" << endl;
            return 0;
        }

        int n = queue[head++];
        amountOfElements--;

        if (head == MAX_ELEMENTS) {
            head = 0;
        }

        return n;
    }
};

int main() {

    Queue queue;

    queue.put(1);
    queue.put(2);
    queue.put(3);
    queue.put(4);
    queue.put(5);
    queue.put(6);

    cout << queue.get() << ' '
         << queue.get() << ' '
         << queue.get() << ' '
         << queue.get() << ' '
         << queue.get() << ' '
         << queue.get();

    return 0;
}

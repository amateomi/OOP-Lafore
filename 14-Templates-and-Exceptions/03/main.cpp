#include <iostream>

using namespace std;

const int size = 3;

template<class T>
class Queue {
private:

    int head;

    int tail;

    T queue[size];

    int count;

public:
    class Full {
    };

    class Empty {
    };

    Queue() : queue(), head(), tail(), count() {}

    void push(const T &data) {
        if (count == size) {
            throw Full();
        }
        queue[tail++] = data;
        count++;

        if (tail == size) {
            tail = 0;
        }
    }

    T pop() {
        if (count == 0) {
            throw Empty();
        }
        T temp = queue[head++];
        queue[head - 1] = 0;
        count--;

        if (head == size) {
            head = 0;
        }

        return temp;
    }

    void show() const {
        for (int i = 0; i < size; ++i) {
            cout << queue[i] << ' ';
        }
        cout << endl;
    };
};

int main() {
    Queue<int> queue;
    int choice;
    int number;

    do {
        queue.show();

        cout << "1) - push" << endl
             << "2) - pop" << endl
             << "0) - quite" << endl
             << '>';
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter number:";
                    cin >> number;

                    queue.push(number);
                    break;

                case 2:
                    cout << "pop: " << queue.pop() << endl;
                    break;

                case 0:
                    return 0;

                default:
                    cout << "Unknown operation!" << endl;
                    break;
            }
        } catch (Queue<int>::Empty) {
            cout << "Error: queue is empty!" << endl;
        } catch (Queue<int>::Full) {
            cout << "Error: queue is full!" << endl;
        }
    } while (true);
}

#include <iostream>

using namespace std;

template<class T>
class Queue {
private:
    static const int size = 10;

    int head;

    int tail;

    T queue[size];

public:
    Queue() : head(), tail() {}

    void push(const T &data) {
        queue[tail++] = data;
    }

    T pop() {
        return queue[head++];
    }
};

int main() {
    Queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;

    return 0;
}

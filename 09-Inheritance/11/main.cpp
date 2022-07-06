#include <iostream>
#include <cstdlib>

using namespace std;

class Stack {
protected:
    static const int MAX = 8;

    int st[MAX];

    int top;

public:
    Stack() : st(), top(-1) {}

    void push(int var) { st[++top] = var; }

    int pop() { return st[top--]; }
};

class Stack2 : public Stack {
public:
    void push(int var) {
        if (top >= MAX - 1) {
            cout << "Stack is full!" << endl;
            exit(1);
        }

        Stack::push(var);
    }

    int pop() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            exit(1);
        }

        return Stack::pop();
    }
};

struct Pair {
    int x;
    int y;
};

class PairStack : Stack2 {
public:
    void push(Pair var) {
        Stack2::push(var.x);
        Stack2::push(var.y);
    }

    Pair pop() {
        Pair var;

        var.y = Stack2::pop();
        var.x = Stack2::pop();

        return var;
    }
};

int main() {
    Pair var = {1, 2};
    PairStack pairStack;

    pairStack.push(var);
    pairStack.push(var);
    pairStack.push(var);

    Pair res;
    res = pairStack.pop();
    cout << res.x << ' ' << res.y << endl;

    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int LEN = 80;
const int MAX = 40;

class Token {
public:
    virtual bool operator==(char c) const = 0;

    virtual float getNumber() const = 0;

    virtual char getOperation() const = 0;
};

class Operation : public Token {
private:
    float getNumber() const { return -1.0F; }

    char operation;

public:
    explicit Operation(char c) : operation(c) {}

    bool operator==(char c) const {
        return operation == c;
    }

    char getOperation() const { return operation; }
};

class Number : public Token {
private:
    char getOperation() const { return -1; }

    bool operator==(char c) const { return false; }

    float number;

public:
    explicit Number(float n) : number(n) {}

    float getNumber() const { return number; }
};

class Stack {
private:
    Token *atoken[MAX];

    int top;

public:
    Stack() : atoken() {
        top = 0;
    }

    void push(Token *token) {
        atoken[++top] = token;
    }

    Token *pop() {
        return atoken[top--];
    }

    int getTop() const {
        return top;
    }
};

class Express {
private:
    Stack stack;

    char *str;

    size_t len;

public:
    explicit Express(char *ptr) {
        str = ptr;
        len = strlen(str);
    }

    void parse();

    Number *solve();
};

inline bool isSign(char ch) {
    return ch == '+' || ch == '-' || ch == '/' || ch == '*';
}

void Express::parse() {
    Token *token;
    Number *lastVal;
    Operation *lastOp;

    for (int i = 0; i < len; ++i) {
        if (isSign(str[i])) {
            token = new Operation(str[i]);
        } else {
            char strNumber[20];
            int indexStrNumber = 0;

            do {
                if (isdigit(str[i]) || str[i] == '.') {
                    strNumber[indexStrNumber++] = str[i];
                }
            } while (++i < len && !isSign(str[i]));
            i--;
            strNumber[indexStrNumber] = '\0';

            float number = static_cast<float>(atof(strNumber));
            token = new Number(number);
        }

        Number *pNumber;
        Operation *pOperation;

        if ((pNumber = dynamic_cast<Number *>(token))) {
            stack.push(token);
        } else if ((pOperation = dynamic_cast<Operation *>(token))) {
            if (stack.getTop() == 1) {
                stack.push(token);
            } else {
                lastVal = dynamic_cast<Number *>(stack.pop());
                lastOp = dynamic_cast<Operation *>(stack.pop());
                if (((*token == '*') || (*token == '/')) && ((*lastOp == '+') || (*lastOp == '-'))) {
                    stack.push(lastOp);
                    stack.push(lastVal);
                } else {
                    switch (lastOp->getOperation()) {
                        case '+':
                            stack.push(new Number(stack.pop()->getNumber() + lastVal->getNumber()));
                            break;

                        case '-':
                            stack.push(new Number(stack.pop()->getNumber() - lastVal->getNumber()));
                            break;

                        case '*':
                            stack.push(new Number(stack.pop()->getNumber() * lastVal->getNumber()));
                            break;

                        case '/':
                            if (lastVal->getNumber() == 0.0F) {
                                cout << "Division by zero attempted!" << endl;
                                exit(1);
                            }
                            stack.push(new Number(stack.pop()->getNumber() / lastVal->getNumber()));
                            break;

                        default:
                            cout << "Unknown operator!" << endl;
                            exit(1);
                    }
                }
                stack.push(token);
            }
        } else {
            cout << "Unknown character!" << endl;
            exit(1);
        }
    }
}

Number *Express::solve() {
    Number *lastVal;

    while (stack.getTop() > 1) {
        lastVal = dynamic_cast<Number *>(stack.pop());
        switch (stack.pop()->getOperation()) {
            case '+':
                stack.push(new Number(stack.pop()->getNumber() + lastVal->getNumber()));
                break;

            case '-':
                stack.push(new Number(stack.pop()->getNumber() - lastVal->getNumber()));
                break;

            case '*':
                stack.push(new Number(stack.pop()->getNumber() * lastVal->getNumber()));
                break;

            case '/':
                if (lastVal->getNumber() == 0.0F) {
                    cout << "Division by zero attempted!" << endl;
                    exit(1);
                }
                stack.push(new Number(stack.pop()->getNumber() / lastVal->getNumber()));
                break;

            default:
                cout << "Unknown operator!" << endl;
                exit(1);
        }
    }

    return dynamic_cast<Number *>(stack.pop());
}

int main() {
    char ans;
    char string[LEN];

    do {
        cout << "Enter expression:";
        cin >> string;

        Express *expression = new Express(string);
        expression->parse();
        cout << "Result: " << expression->solve()->getNumber() << endl;
        delete expression;

        cout << "Continue?(y/n)";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

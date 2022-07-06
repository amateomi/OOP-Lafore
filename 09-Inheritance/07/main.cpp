#include <iostream>

using namespace std;

class Counter {
protected:
    unsigned int count;

public:
    Counter() : count() {}

    explicit Counter(unsigned int c) : count(c) {}

    Counter operator++() { return Counter(++count); }

    Counter operator--() { return Counter(--count); }

    unsigned int getCount() const { return count; }
};

class Count : public Counter {
public:
    Count() : Counter() {}

    explicit Count(unsigned int c) : Counter(c) {}

    Count operator++(int) {
        count++;
        return Count(count - 1);
    }

    Count operator--(int) {
        count--;
        return Count(count + 1);
    }
};

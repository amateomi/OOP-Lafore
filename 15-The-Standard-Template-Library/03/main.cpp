#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> lists;
    for (int i = 0; i < 2; ++i) {
        lists.push_back(i);
        cout << lists.back() << ' ';
    }
    cout << endl;

    list<int>::iterator begin = lists.begin();
    list<int>::iterator end = lists.end();

    while (begin != end) {
        end--;
        if (begin == end) {
            break;
        }
        swap(*begin, *end);
        begin++;
    }

    list<int>::iterator i;
    for (i = lists.begin(); i != lists.end(); ++i) {
        cout << *i << ' ';
    }

    return 0;
}

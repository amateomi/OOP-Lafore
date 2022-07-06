#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile("data.txt", ios::trunc);

    for (int i = 0; i < 20; ++i) {
        outFile << i << ' ';
    }
    outFile.close();

    ifstream source("data.txt");
    ofstream target("result.txt", ios::trunc);

    istream_iterator<int> s(source);
    istream_iterator<int> endOfStream;
    ostream_iterator<int> t(target, " ");

    while (s != endOfStream) {
        *t++ = *s++;
    }

    source.close();
    target.close();

    return 0;
}

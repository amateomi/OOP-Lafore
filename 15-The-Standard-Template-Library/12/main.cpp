#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ifstream source("text.txt");

    istream_iterator<string> iter(source);
    istream_iterator<string> end;

    map<string, int> table;

    string word;
    while (iter != end) {
        word = *iter++;
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (table.find(word) == table.end()) {
            table[word] = 1;
        } else {
            table[word]++;
        }
    }
    source.close();

    for (map<string, int>::iterator i = table.begin(); i != table.end(); i++) {
        cout << setw(30) << (*i).first << setw(10) << (*i).second << endl;
    }

    return 0;
}

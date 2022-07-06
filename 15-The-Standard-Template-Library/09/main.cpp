#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> strList;
    string searchList;

    strList.push_back("a");
    strList.push_back("b");
    strList.push_back("c");
    strList.push_back("d");
    strList.push_back("e");
    strList.push_back("f");

    vector<string>::iterator i;
    i = find_if(strList.begin(), strList.end(), bind2nd(equal_to<string>(), "c"));

    cout << "pos = " << i - strList.begin() << endl;

    return 0;
}

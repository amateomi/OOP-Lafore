#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Must be 1 argument (file name)!";
        return 1;
    }

    ifstream file(argv[1], ios::binary);
    if (!file) {
        cerr << "Unable to open " << argv[1] << " file!";
        return 1;
    }

    file.seekg(0, ios::end);

    cout << "Size of the " << argv[1] << " is " << file.tellg() << " byte";

    return 0;
}

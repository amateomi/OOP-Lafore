#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Must be 2 parameters!";
        return 1;
    }

    ofstream targetFile(argv[1], ios::trunc | ios::binary);
    if (!targetFile) {
        cerr << "Unable to open/create " << argv[1] << " file!";
        return 1;
    }
    ifstream sourceFile(argv[2], ios::binary);
    if (!sourceFile) {
        cerr << "Unable to open " << argv[2] << " file!";
        return 1;
    }

    char buffer;
    sourceFile.get(buffer);
    while (sourceFile) {
        targetFile.put(buffer);
        sourceFile.get(buffer);
    }
    cout << "Success copying!";

    return 0;
}

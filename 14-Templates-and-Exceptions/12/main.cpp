#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX = 1000;
int buff[MAX];

class DoFile {
private:
    fstream file;

public:
    class FileEx : exception {
    public:
        int num;

        explicit FileEx(int n) : num(n) {}
    };

    explicit DoFile(const char *fileName) {
        file.open(fileName, ios::trunc | ios::out | ios::in | ios::binary);
        if (!file) {
            throw FileEx(1);
        }
    }

    ~DoFile() {
        file.close();
    }

    void write(int *data, int size) {
        file.write(reinterpret_cast<char *>(data), size * (int) sizeof(int));
        if (!file) {
            throw FileEx(2);
        }
    }

    void read(int *data, int size) {
        file.read(reinterpret_cast<char *>(data), size * (int) sizeof(int));
        if (!file) {
            throw FileEx(3);
        }
    }

    void rewind() {
        file.seekg(0);
    }
};

int main() {
    for (int i = 0; i < MAX; ++i) {
        buff[i] = i;
    }
    try {
        DoFile file("data.dat");

        cout << "Writing..." << endl;
        file.write(buff, MAX);

        for (int i = 0; i < MAX; ++i) {
            buff[i] = 0;
        }

        file.rewind();

        cout << "Reading..." << endl;
        file.read(buff, MAX);
    } catch (DoFile::FileEx err) {
        switch (err.num) {
            case 1:
                cerr << "Unable to open file!" << endl;
                break;

            case 2:
                cerr << "Unable to write into file!" << endl;
                break;

            case 3:
                cerr << "Unable to read from file!" << endl;
                break;

            default:
                cerr << "Unknown error!" << endl;
                break;
        }

        exit(1);
    }
    for (int i = 0; i < MAX; ++i) {
        if (buff[i] != i) {
            cerr << endl << "Incorrect data!" << endl;
            exit(1);
        }
    }
    cout << "Data is fine!";

    return 0;
}

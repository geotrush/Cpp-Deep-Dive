#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ios;
using std::string;
using std::ifstream;
using std::ofstream;

void ReadAll(const string& file_path) {
    ifstream input(file_path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "No such file" << endl;
    }
}

int main() {
    // Read from file
    ifstream read("7_timeless_way.txt");
    if (read) {
        string quote;
        string author;
        getline(read, quote, '-');
        getline(read, author);
        cout << quote << author << endl;
    }
    else {
        cout << "No such file" << endl;
    }

    // Write (append) to file
    ReadAll("7_notebooks.txt");
    ofstream write("7_notebooks.txt", ios::app);
    write << "-- Samuel Taylor Coleridge\n";

    return 0;
}

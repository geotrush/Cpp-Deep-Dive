/*
Task
You should write a program that:
1) Reads from "input.txt" and outputs the result;
2) Writes to "output.txt".
*/
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
    ifstream input("input.txt");
    string line;
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }

    ifstream input2("input.txt");
    ofstream output("output.txt");
    if (input2) {
        while (getline(input2, line)) {
            output << line << endl;
        }
    }

    return 0;
}

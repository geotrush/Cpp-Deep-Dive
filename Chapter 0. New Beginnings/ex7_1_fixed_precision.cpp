/*
Task
You should write a program that:
1) Reads real numbers from "input.txt";
2) Outputs them with three decimal points.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using std::cout;
using std::fixed;
using std::setprecision;
using std::endl;
using std::string;
using std::ifstream;

int main() {
    ifstream input("input.txt");
    double n;
    cout << fixed << setprecision(3);
    while (input >> n) {
        cout << n << endl;
    }

    return 0;
}

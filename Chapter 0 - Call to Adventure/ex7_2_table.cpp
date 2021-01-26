/*
Task
You should write a program that:
1) Reads the two integers n and m from the first line of "input.txt";
2) Reads from each of the next n lines m integers separated by commas;
3) Outputs the table of n rows and m columns taking into account that:
    a) Cell size equals 10;
    b) Neighbouring cells are separated by a space;
    c) Last cell of the row doesn't end on a space;
    d) Last row doesn't end with a new line.
*/
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::setw;
using std::endl;
using std::string;
using std::ifstream;

int main() {
	ifstream input("input.txt");
	int n, m;
	if (input) {
		input >> n >> m;
		input.ignore(1);

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= (m * 2 - 1); ++j) {
				int number;
				cout << setw(10);
				if (j % 2 == 0 && j < (m * 2 - 2)) {
					input >> number;
					cout << number << ' ';
				}
				else if (j % 2 == 0 && j == (m * 2 - 2)) {
					input >> number;
					cout << number;
				}
				else {
					input.ignore(1);
				}
			}
			if (i != n) {
				cout << endl;
			}
		}
	}
    
	return 0;
}

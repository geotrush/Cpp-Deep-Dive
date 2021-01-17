/* 
Input
The input stream contains a single string: s.

Output
You should output the index of the second instance of sign '#'.
If the sign appears only once, output "-1".
If the sign doesn't appear, output "-2".
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	string str;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '#') {
			++count;
			if (count == 2) {
				cout << i;
				break;
			}
		}
	}

	if (count == 1)	{
		cout << -1;
    }
	else if (count == 0) {
		cout << -2;
	}

	return 0;
}

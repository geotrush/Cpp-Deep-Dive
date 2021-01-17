/*
Input
The input stream contains an integer n (number of elements)
as well as a sequence of n strings separated by spaces.

Output
You should output the sorted strings ignoring letter case.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
	int n;
	cin >> n;
	
	vector<string> strings(n);
	for (string& s : strings) {
		cin >> s;
	}

	auto compare_char = [](const char& left, const char& right) {
		return tolower(left) < tolower(right);
	};

	sort(strings.begin(), strings.end(), [compare_char](const string& left, const string& right) {
		return lexicographical_compare(begin(left), end(left), begin(right), end(right), compare_char);
	});
	
    for (const string& s : strings) {
        cout << s << ' ';
    }

	return 0;
}

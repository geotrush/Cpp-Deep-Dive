/*
Input
The input stream contains a positive integer n (number of strings)
as well as n strings on separate lines.
Note: all strings contain only latin letters, digits and underscores.

Output
You should output the number of unique strings.
*/
#include <iostream>
#include <string>
#include <set>

using std::cin;
using std::cout;
using std::string;
using std::set;

int main() {
    int n;
    cin >> n;

    set<string> unique_strings;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        unique_strings.insert(s);
    }

    cout << unique_strings.size();

    return 0;
}

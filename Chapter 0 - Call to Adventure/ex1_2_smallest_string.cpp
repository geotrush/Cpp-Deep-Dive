/* 
Input
The input stream contains three strings of lower-case latin letters: a, b, c.

Output
You should output the smallest one (lexicographically).
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
    string a, b, c;
    cin >> a >> b >> c;
    vector<string> V = {a, b ,c};
    sort(begin(V), end(V));
    cout << V[0];

    return 0;
}

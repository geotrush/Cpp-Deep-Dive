/* 
Input
The input stream contains two integer numbers: a, b.

Output
You should output every even integer between a and b (inclusive).
Integers should be in ascending order, separated by a single space.
*/
#include <iostream>

using std::cin;
using std::cout;

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            cout << i << ' ';
        }
    }

    return 0;
}

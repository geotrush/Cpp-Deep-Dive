/* 
Input
The input stream contains two integers: a, b.

Output
You should output their greatest common divisor.
*/
#include <iostream>

using std::cin;
using std::cout;
using std::swap;

int main() {
	int a, b;
    cin >> a >> b;

	while (b) {
        swap(a %= b, b);
    }
	cout << a;

	return 0;
}

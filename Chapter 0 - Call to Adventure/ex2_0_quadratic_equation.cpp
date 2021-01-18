/* 
Input
The input stream contains three integers: a, b, c.

Output
You should output the roots (in any order) of the quadratic equation:
ax² + bx + c = 0, which is guaranteed to have at least one root.
*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main() {
	double a, b, c;
    cin >> a >> b >> c;
	double D = pow(b, 2) - 4 * a * c;

	if (a == 0) {
		if (b != 0) {
			cout << -c / b;
		}
	}
	else if (D == 0) {
		cout << -b / (2 * a);
	}
	else if (D > 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << ' ' << x2;
	}

	return 0;
}

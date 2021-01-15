/* 
Input
The input stream contains two integer numbers: a, b.

Output
You should output the integer part of the division a / b.
If b is equal to zero, output "Impossible".
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << a / b << endl;
    }

    return 0;
}

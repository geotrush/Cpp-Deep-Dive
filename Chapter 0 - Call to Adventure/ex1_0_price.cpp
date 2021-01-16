/* 
Input
The input stream contains five integer numbers: p, a, b, x, y.

Output
If price (p) is bigger than a, the discount is x %.
If price (p) is bigger than b, the discount is y %.
Output the final price.
*/
#include <iostream>

using std::cin;
using std::cout;

int main() {
    double p, a, b, x, y;
    cin >> p >> a >> b >> x >> y;

    if (p > b) {
        p *= (1 - y / 100);
    } else if (p > a) {
        p *= (1 - x / 100);
    }
    
    cout << p;

    return 0;
}

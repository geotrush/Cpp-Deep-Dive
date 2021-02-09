/* 
Input
The input stream contains two positive integers: n (total amount), r (density)
as well as positive integer triples w, h, d on each of the next n lines
denoting width, height and depth of rectangular blocks.

Output
You should output the total mass of all blocks (mass = r * w * h * d).
Notes: it is guaranteed that n doesn't exceed 10^5, r - 10^2 and
w, h, d - 10^4.
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;


int main() {
    size_t n;
    uint16_t r;
    cin >> n >> r;
    vector<int> blocks(n);

    uint64_t total_mass = 0;
    for (size_t i = 0; i < n; ++i) {
        uint32_t w, h, d;
        cin >> w >> h >> d;
        total_mass += w * h * d;
    }
    total_mass *= r;
    cout << total_mass;

    return 0;
}

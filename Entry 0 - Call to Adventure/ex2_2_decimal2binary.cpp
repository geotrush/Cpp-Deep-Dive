/* 
Input
The input stream contains a positive integer: n.

Output
You should convert the integer to binary and output without leading zeros.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::reverse;

int main() {
    int n;
    cin >> n;

    vector<int> bin;
    while (n > 0) {
        bin.push_back(n % 2);
        n /= 2;
    }

    reverse(bin.begin(), bin.end());

    for (const auto& i : bin) {
        cout << i;
    }

    return 0;
}

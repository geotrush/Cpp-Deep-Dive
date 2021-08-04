/* 
Input
The input stream contains a single integer: n.

Output
You should output all permutations of integers from 1 to n
in reverse lexicographical order.
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
    int n;
    cin >> n;
    vector<int> permutation(n);
    iota(permutation.rbegin(), permutation.rend(), 1);

    do {
        for (int num : permutation) {
            cout << num << ' ';
        }
        cout << endl;
    } while (prev_permutation(permutation.begin(), permutation.end()));

    return 0;
}

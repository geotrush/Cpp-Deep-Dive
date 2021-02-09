/* 
Input
The input stream contains integers: n
as well as a sequence of n non-negative values
denoting temperatures in consecutive days (from 0-th day).

Output
You should output the number of days (integer k)
when the temperature was higher than the mean (integer)
as well as the indices of those days (on the next line).
Notes: it is guaranteed that n doesn't exceed 10^6 and
temperature values are from −10^8 to 10^8.
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
    size_t n;
    cin >> n;
    vector<int> temperatures(n);

    int32_t sum = 0;
    for (int& t : temperatures) {
        cin >> t;
        sum += t;
    }

    int32_t mean = sum / static_cast<int32_t>(n);
    vector<size_t> result_indices;
    for (size_t i = 0; i < n; ++i) {
        if (temperatures[i] > mean) {
            result_indices.push_back(i);
        }
    }

    cout << result_indices.size() << endl;
    for (const size_t& i : result_indices) {
        cout << i << ' ';
    }

    return 0;
}

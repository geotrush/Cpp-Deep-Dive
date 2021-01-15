/* 
Input
The input stream contains integers: n
as well as a sequence of n non-negative values
denoting temperatures in consecutive days (from 0-th day).

Output
You should output the number of days (integer k)
when the temperature was higher than the mean (integer)
as well as the indices of those days (on the next line).
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> temperatures(n);

    int sum = 0;
    for (int& t : temperatures) {
        cin >> t;
        sum += t;
    }

    int mean = sum / n;
    vector<int> result_indices;
    for (int i = 0; i < n; ++i) {
        if (temperatures[i] > mean) {
            result_indices.push_back(i);
        }
    }

    cout << result_indices.size() << endl;
    for (const int& i : result_indices) {
        cout << i << ' ';
    }

    return 0;
}

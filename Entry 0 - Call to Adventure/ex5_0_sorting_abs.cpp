/*
Input
The input stream contains an integer n (number of elements)
as well as a sequence of n integers separated by spaces.

Output
You should output the integers sorted by absolute value.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int& num : numbers) {
        cin >> num;
    }

    sort(numbers.begin(), numbers.end(), [](const int& left, const int& right) {
        return abs(left) < abs(right);
        });
        
    for (const int& num : numbers) {
        cout << num << ' ';
    }

    return 0;
}

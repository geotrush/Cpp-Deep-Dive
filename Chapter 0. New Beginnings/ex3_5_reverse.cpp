/* 
Input
The function call contains a vector of integers: input.

Output
You should write a function that reverses the order of elements.
*/
#include <algorithm>
#include <vector>

using std::vector;

void Reverse(vector<int>& input) {
    reverse(input.begin(), input.end());
}

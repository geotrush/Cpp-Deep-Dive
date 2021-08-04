/* 
Input
The function call contains a vector of integers: input.

Output
You should write a function that returns a copy of the
input with reversed order of elements.
*/
#include <vector>

using std::vector;

vector<int> Reversed(const vector<int>& input) {
    vector<int> result;
    for (auto iter = input.rbegin(); iter != input.rend(); ++iter) {
        result.push_back(*iter);
    }
    return result;
}

/* 
Task
You should write a function that outputs all integers
before the first negative integer in a vector of integers
in reverse order.
Note: output all integers in reverse order, if there're no negative ones.
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


void PrintVectorPart(const vector<int>& numbers) {
    auto negative_border = find_if(begin(numbers), end(numbers), [](const int& number) {
        return number < 0;
    });
    for (auto iter = negative_border; iter != numbers.begin(); ) {
        cout << *(--iter) << ' ';
    }
}

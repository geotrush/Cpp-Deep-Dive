/* 
Task
You should write a template function that
removes duplicates from a vector containing any type of elements.
*/
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;


template <typename Type>
void RemoveDuplicates(vector<Type>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(unique(begin(elements), end(elements)), end(elements));
}

/* 
Task
You should write a template function that returns
a vector of elements greater than border in a set of elements.
*/
#include <algorithm>
#include <vector>
#include <set>

using std::set;
using std::vector;


template<typename Type>
vector<Type> FindGreaterElements(const set<Type>& elements, const Type& border) {
    auto gt_border_iter = find_if(elements.begin(), elements.end(), [border](const Type& element) {
        return element > border;
    });
    vector<Type> gt_border;
    for (auto iter = gt_border_iter; iter != elements.end(); ++iter) {
        gt_border.push_back(*iter);
    }
    return gt_border;
}

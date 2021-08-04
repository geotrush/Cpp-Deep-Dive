/* 
Task
You should write a function that accepts a set of integers and an integer,
and returns iterator to a set element, which is the nearest to a given integer.
Note: If there're several nearest elements, return iterator to the smaller one.
*/
#include <iterator>
#include <set>

using std::set;


set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    const auto first_not_less = numbers.lower_bound(border);
    if (first_not_less == numbers.begin()) {
        return first_not_less;
    }
    const auto last_less = prev(first_not_less);
    if (first_not_less == numbers.end()) {
        return last_less;
    }
    const bool is_left = (border - *last_less <= *first_not_less - border);
    return is_left ? last_less : first_not_less;
}

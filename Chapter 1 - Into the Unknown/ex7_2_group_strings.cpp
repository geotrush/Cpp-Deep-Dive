/* 
Task
You should write two functions that implement searching for a sorted range of strings that start with the prefix:
1) "FindStartsWithChar(begin, end)": accepts begin & end iterators and a prefix character,
and returns begin & end iterators defining a range of strings that start with that prefix character;
2) "FindStartsWithString(begin, end)": accepts begin & end iterators and a prefix string,
and returns begin & end iterators defining a range of strings that start with that prefix string.
Notes: It is guaranteed that input strings consist only of lowercase latin letters,
if the resulting range is empty, it should point to a position that could hold a string with that prefix.
*/
#include <algorithm>
#include <string>

using std::pair;
using std::string;
using std::make_pair;
using std::equal_range;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWithChar(RandomIt begin, RandomIt end, char prefix) {
    auto iter = equal_range(begin, end, string(1, prefix), [](const string& x, const string& y) { 
        return x[0] < y[0];
    });
    return make_pair(iter.first, iter.second);
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWithString(RandomIt begin, RandomIt end, const string& prefix) {
    auto iter = equal_range(begin, end, prefix, [&prefix](const string& x, const string& y) {
        return x.compare(0, prefix.length(), y.substr(0, prefix.length())) < 0;;
    });
    return make_pair(iter.first, iter.second);
}

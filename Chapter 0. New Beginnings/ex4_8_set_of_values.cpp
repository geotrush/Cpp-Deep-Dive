/*
Input
The function call contains a map of integers to strings: m.

Output
You should write a function that returns a set of its values.
*/
#include <string>
#include <map>
#include <set>

using std::string;
using std::map;
using std::set;

set<string> BuildMapValuesSet (const map<int, string>& m) {
    set<string> values;
	for (auto& value : m) {
		values.insert(value.second);
	}
	return values;
}

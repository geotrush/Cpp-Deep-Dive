/*
Task
You should write the function EnsureEqual(left, right),
which throws "runtime_error" if the two strings are unequal.
*/
#include <iostream>

using std::string;
using std::runtime_error;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		throw runtime_error(left + " != " + right);
	}
}

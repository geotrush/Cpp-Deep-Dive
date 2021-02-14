/*
Task
You should write tests for the previous Chapter's class in ex3_1_palindrome.cpp
using the unit-testing framework from 4+5_unit_test_framework.cpp.
*/
#include "4+5_unit_test_framework.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>

using std::cerr;
using std::endl;
using std::showpos;
using std::map;
using std::set;
using std::string;
using std::ostream;
using std::ostringstream;
using std::runtime_error;
using std::invalid_argument;


bool IsPalindrome(const std::string& str) {
    return equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}

// Unit tests
void TestIsPalindrome() {
    Assert(IsPalindrome(""), "empty string is a palindrome");
    Assert(IsPalindrome("C"), "single-character string is a palindrome");
    Assert(IsPalindrome("++C++"), "odd-character symmetric string is a palindrome");
    Assert(IsPalindrome("tenet"), "«Tenet» is a palindrome");
    Assert(IsPalindrome("dammitimmad"), "«Dammit, I’m mad!» is a palindrome");
    Assert(IsPalindrome("drawocoward"), "«Draw, O coward!» is a palindrome");
    Assert(IsPalindrome("redrumsirismurder"), "«Red rum, sir, is murder.» is a palindrome");
}


int main() {
    TestRunner runner;
    runner.RunTest(TestIsPalindrome, "TestIsPalindrome");

    return 0;
}

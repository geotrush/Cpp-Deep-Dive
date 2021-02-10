// Pre-processor directive to
// include this header file only once
#pragma once

// To ensure One Definition Rule
// and enable faster compilation
// it is recommended to place only
// declarations and template definitions
// into header files, while putting all other
// function and class definitions into cpp files
#include <exception>
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <map>
#include <set>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::set;
using std::ostream;
using std::ostringstream;
using std::runtime_error;


template <class Type>
ostream& operator << (ostream& os, const set<Type>& s) {
    os << '{';
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << '}';
}

template <class Key, class Value>
ostream& operator << (ostream& os, const map<Key, Value>& m) {
    os << '{';
    bool first = true;
    for (const auto& item : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << item.first << ": " << item.second;
    }
    return os << '}';
}

template<class Type1, class Type2>
void AssertEqual(const Type1& a, const Type2& b, const string& hint) {
    if (a != b) {
        ostringstream os;
        os << "Assertion failed: " << a << " != " << b << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
private:
    int fail_count = 0;
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& e) {
            ++fail_count;
        cerr << test_name << " -> " << e.what() << endl;
        }
    }
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminating..." << endl;
            exit(1);
        }
    }
};

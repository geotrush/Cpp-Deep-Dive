#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::max;
using std::ostream;
using std::stringstream;
using std::make_pair;
using std::string;
using std::vector;
using std::pair;
using std::map;


// Multiplication operator template for pairs
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return {f, s};
}

// Function template
template <typename Type>
Type Square(Type x) {
    return x * x;
}

// Pair output stream template
template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ',' << p.second << ')';
}

// Container output stream templates
template <typename Container>
string Join(const Container& c, char d) {
    stringstream ss;
    bool first = true;
    for (const auto& element : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << element;
    }
    return ss.str();
}

// Vector output stream template
template <typename Type>
ostream& operator << (ostream& out, const vector<Type>& v) {
    return out << '[' << Join(v, ',') << ']';
}

// Map output stream template
template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ',') << '}';
}


int main() {
    // Function template
    auto p = make_pair(22, 22);
    auto result = Square(p);
    cout << result.first << ' ' << result.second << endl;

    // Container output stream templates
    vector<vector<int>> v = {{13}, {31}};
    cout << v << endl;

    // Function parameter type template
    cout << max<double>(989, 979.9) << endl;

    return 0;
}

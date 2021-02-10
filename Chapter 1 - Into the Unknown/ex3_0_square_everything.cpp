/*
Task
You should write a function that squares containers the following way:
1) For vectors, elements are squared;
2) For maps, only values are squared;
3) For pairs, both elements are squared.
*/
#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::map;


// Declare templates beforehand
template<typename Type>
Type Square(Type x);
template<typename Type>
vector<Type> Square(const vector<Type>& v);
template<typename Key, typename Value>
map<Key, Value> Square(const map<Key, Value>& m);
template<typename First, typename Second>
pair<First, Second> Square(const pair<First, Second>& p);


template<typename Type>
Type Square(Type x) {
    return x * x;
}

template<typename Type>
vector<Type> Square(const vector<Type>& v) {
    vector<Type> new_v;
    for (const Type& item : v) {
        new_v.push_back(Square(item));
    }
    return new_v;
}

template<typename Key, typename Value>
map<Key, Value> Square(const map<Key, Value>& m) {
    map<Key, Value> new_m;
    for (auto &item : m) {
        new_m[item.first] = Square(item.second);
    }
    return new_m;
}

template<typename First, typename Second>
pair<First, Second> Square(const pair<First, Second>& p) {
    return {Square(p.First), Square(p.Second)};
}

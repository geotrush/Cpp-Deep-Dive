/*
Task
You should write a function that accepts a map and a key and
returns the corresponding value, but if there's no such key -
it throws a runtime error.
*/
#include <map>

using std::map;


template<typename Key, typename Type>
Type& GetRefStrict(map<Key, Type>& m, Key k) {
    if (m.count(k) == 0) {
        throw runtime_error("There is no value at this key");
    }
    return m[k];
}

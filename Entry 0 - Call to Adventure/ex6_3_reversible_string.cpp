/*
Task
You should define a class with the two public methods:
1) "Reverse()": reverses the string;
2) "ToString()": returns the string.
*/
#include <algorithm>
#include <string>

using std::string;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& new_str) {
        str = new_str;
    }
    void Reverse() {
        reverse(begin(str), end(str));
    }
    string ToString() const {
        return str;
    }
private:
    string str;
};

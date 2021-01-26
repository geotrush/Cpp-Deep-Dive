/*
Task
You should define a class with the two public methods:
1) "AddString(str)": adds a string;
2) "GetSortedStrings()": returns a sorted vector of strings.
*/
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class SortedStrings {
    public:
        void AddString(const string& str) {
            v.push_back(str);
        }
        vector<string> GetSortedStrings() {
            sort(v.begin(), v.end());
            return v;
        }
    private:
        vector<string> v;
};

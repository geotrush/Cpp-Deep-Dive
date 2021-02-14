/*
Task
You should refactor the class from the previous Chapter's exercise: ex6_1_names_1.cpp,
in such a way that it uses binary searching.
*/
#include <string>
#include <map>

using std::map;
using std::string;


class Person {
private:
    map<int, string> first_names;
    map<int, string> last_names;
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string FindNameByYear(const map<int, string>& names, int year) {
        string name;
        auto iter_after = names.upper_bound(year);
        if (iter_after != names.begin()) {
            name = (--iter_after)->second;
        }
        return name;
    }
    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + ' ' + last_name;
        }
    }
};

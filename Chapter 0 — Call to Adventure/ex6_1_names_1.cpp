/*
Task
You should define a class with the three public methods:
1) "ChangeFirstName(year, first_name)": records first name change in the year;
2) "ChangeLastName(year, last_name)": records last name change in the year;
3) "GetFullName(year)": returns the full name for the year separated by a space, however:
    a) If there've been no name changes, returns "Incognito";
    b) If only the first name's been changed, returns "first_name with unknown last name";
    c) If only the last name's been changed, returns "last_name with unknown first name".
Note: there can only be one first name change and one last name change per year.
*/
#include <string>
#include <map>

using std::string;
using std::map;

class Person {
public:
    void ChangeFirstName(const int& year, const string& first_name) {
        first_names[year] = first_name;
    }        
    void ChangeLastName(const int& year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(const int& year) const {
        const string first_name = GetName(year, first_names);
        const string last_name = GetName(year, last_names);
        if (first_name.size() == 0 && last_name.size() == 0) {
            return "Incognito";
        }
        else if (first_name.size() == 0) {
            return last_name + " with unknown first name";
        }
        else if (last_name.size() == 0) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;;
    }
private:
    string GetName(const int& year, const map<int, string>& names) const {
        string name;
        for (const auto& item : names) {
            if (item.first <= year) {
                name = item.second;
            }
            else {
                break;
            }
        }
        return name;
    }

    map<int, string> first_names;
    map<int, string> last_names;
};

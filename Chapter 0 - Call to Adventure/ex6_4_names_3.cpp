/*
Task
You should define a class with the custom contructor and four public methods:
0) "Person(first_name, last_name, birth_year)":
    a) If the year is less than birth_year, GetFullName() & GetFullNameWithHistory() return "No person";
    b) If the year is less than birth_year, ChangeFirstName() & ChangeLastName() ignore the query;
1) "ChangeFirstName(year, first_name)": records first name change in the year;
2) "ChangeLastName(year, last_name)": records last name change in the year;
3) "GetFullName(year)": returns the full name for the year separated by a space, however:
    a) If only the first name's been changed, returns "first_name with unknown last name";
    b) If only the last name's been changed, returns "last_name with unknown first name";
4) "GetFullNameWithHistory(year)": returns the full reversed chronology of name changes for the year.
Notes: there can only be one first name change and one last name change per year,
ignore the identical consecutive name changes.
*/
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Person {
public:
    Person(const string& first_name, const string& last_name, const int& birth) {
		birth_year = birth;
        first_names[birth] = first_name;
		last_names[birth] = last_name;
	}
    void ChangeFirstName(const int& year, const string& first_name) {
        if (year >= birth_year) {
            first_names[year] = first_name;
        }
    }        
    void ChangeLastName(const int& year, const string& last_name) {
        if (year >= birth_year) {
            last_names[year] = last_name;
        }
    }
    string GetFullName(const int& year) const {
        if (year < birth_year) {
            return "No person";
        }
        const string first_name = GetName(year, first_names);
        const string last_name = GetName(year, last_names);
        if (first_name.size() == 0) {
            return last_name + " with unknown first name";
        }
        else if (last_name.size() == 0) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;;
    }
    string GetFullNameWithHistory(const int& year) const {
        if (year < birth_year) {
            return "No person";
        }
        const string first_name = GetName(year, first_names);
        const string last_name = GetName(year, last_names);
        const string history_first_name = GetHistory(year, first_names);
        const string history_last_name = GetHistory(year, last_names);
        if (first_name.size() == 0) {
            if (history_last_name.size() == 0) {
                return last_name + " with unknown first name";
            }
            else {
                return last_name + " (" + history_last_name + ") " + "with unknown first name";
            }
        }
        else if (last_name.size() == 0) {
            if (history_first_name.size() == 0) {
                return first_name + " with unknown last name";
            }
            else {
                return first_name + " (" + history_first_name + ") " + "with unknown last name";
            }
        }
        else if (history_first_name.size() == 0 && history_last_name.size() == 0) {
            return first_name + ' ' + last_name;
        }
        else if (history_first_name.size() == 0) {
            return first_name + ' ' + last_name + " (" + history_last_name + ')';
        }
        else if (history_last_name.size() == 0) {
            return first_name + " (" + history_first_name + ") " + last_name;
        }
        return first_name + " (" + history_first_name + ") " + last_name + " (" + history_last_name + ')';
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
    string GetHistory(const int& year, const map<int, string>& names) const {
        string current_name = "";
        vector<string> history;
        for (const auto& item : names) {
            if (item.first <= year) {
                if (item.second != current_name) {
                    history.push_back(item.second);
                    current_name = item.second;
                }
            }
            else {
                break;
            }
        }
        string reverse_history = "";
        for (int i = history.size() - 2; i >= 0; --i) {
            if (reverse_history.size() == 0) {
                reverse_history += history[i];
            }
            else {
                reverse_history += ", " + history[i];
            }
        }
        return reverse_history;
    }
    
    map<int, string> first_names;
    map<int, string> last_names;
    int birth_year;
};

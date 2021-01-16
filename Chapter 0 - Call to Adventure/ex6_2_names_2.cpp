/*
Task
You should define a class with the four public methods:
1) "ChangeFirstName(year, first_name)": records first name change in the year;
2) "ChangeLastName(year, last_name)": records last name change in the year;
3) "GetFullName(year)": returns the full name for the year separated by a space, however:
    a) If there've been no name changes, returns "Incognito";
    b) If only the first name's been changed, returns "first_name with unknown last name";
    c) If only the last name's been changed, returns "last_name with unknown first name";
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
    string GetFullNameWithHistory(const int& year) const {
        const string first_name = GetName(year, first_names);
        const string last_name = GetName(year, last_names);
        const string history_first_name = GetHistory(year, first_names);
        const string history_last_name = GetHistory(year, last_names);
        if (first_name.size() == 0 && last_name.size() == 0) {
            return "Incognito";
        }
        else if (first_name.size() == 0) {
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
};

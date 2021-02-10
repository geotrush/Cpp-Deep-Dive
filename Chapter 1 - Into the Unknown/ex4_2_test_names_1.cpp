/*
Task
You should write tests for the previous Chapter's class in ex6_1_names_1.cpp
using the unit-testing framework from 4_unit_test_framework.cpp.
*/
#include "4+5_unit_test_framework.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::pow;
using std::cout;
using std::cerr;
using std::endl;
using std::showpos;
using std::map;
using std::set;
using std::string;
using std::vector;
using std::mt19937;
using std::ostream;
using std::stringstream;
using std::ostringstream;
using std::runtime_error;
using std::uniform_real_distribution;


class Person {
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
        return first_name + ' ' + last_name;
    }
};

// Unit tests
void TestPredefinedLastNameFirst() {
    Person person;
    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");
    AssertEqual(person.GetFullName(1964), "Incognito", "");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name", "");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "");
}
void TestPredefined() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    AssertEqual(person.GetFullName(1964), "Incognito", "");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name", "");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "");
    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva", "");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva", "");
    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva", "");
    AssertEqual(person.GetFullName(1968), "Polina Volkova", "");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova", "");
}


int main() {
    TestRunner runner;
    runner.RunTest(TestPredefined, "TestPredefined");
    runner.RunTest(TestPredefinedLastNameFirst, "TestPredefinedLastNameFirst");

    return 0;
}

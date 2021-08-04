/* 
Task
You should write a function that accepts a vector of people and
outputs median age for the following groups of people:
1) All people;
2) Females;
3) Males;
4) Employed females;
5) Unemployed females;
6) Employed males;
7) Unemployed males;
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::partition;
using std::vector;


enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;
    Gender gender;
    bool is_employed;
};

template <typename InputIt>
int ComputeMedianAge(InputIt begin, InputIt end) {
    if (begin == end) {
        return 0;
    }
    vector<typename InputIt::value_type> copy(begin, end);
    auto middle = begin(copy) + copy.size() / 2;
    nth_element(begin(copy), middle, end(copy), [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
    });
    return middle->age;
}

void PrintStats(vector<Person> persons) {
    auto females_end = partition(begin(persons), end(persons), [](const Person& p) {
        return p.gender == Gender::FEMALE;
    });
    auto employed_females_end = partition(begin(persons), females_end, [](const Person& p) {
        return p.is_employed;
    });
    auto employed_males_end = partition(females_end, end(persons), [](const Person& p) {
        return p.is_employed;
    });
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), females_end) << endl;
    cout << "Median age for males = " << ComputeMedianAge(females_end, end(persons)) << endl;
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), employed_females_end) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(employed_females_end, females_end) << endl;
    cout << "Median age for employed males = " << ComputeMedianAge(females_end, employed_males_end) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(employed_males_end, end(persons)) << endl;
}

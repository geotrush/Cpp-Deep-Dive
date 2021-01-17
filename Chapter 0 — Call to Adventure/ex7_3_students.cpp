/*
Input
The input stream contains an integer n (number of students) and n rows
containing name, surname, day, month & year of birth separated by spaces,
also the input stream contains an integer q (number of queries) and q rows
containing a query string and an integer k (student number starting from 1).

Output
You should output the following, based on the query:
- "name k": output the student's name and surname separated by a space;
- "date k": output the student's day, month & birth year separated by dots;
- for any other requests: output "bad request".
Note: output one request per line.
*/
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;
    string name, surname;
    int day, month, year;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        cin >> name >> surname >> day >> month >> year;
        students.push_back(Student{name, surname, day, month, year});
    }

    int q;
    cin >> q;
    string query;
    int k;
    
    for (int i = 0; i < q; ++i) {
        cin >> query >> k;
        --k;

        if (query == "name" && k >= 0 && k < n) {
            cout << students[k].name << ' '
                 << students[k].surname << endl;
        } else if (query == "date" && k >= 0 && k < n) {
            cout << students[k].day << '.'
                 << students[k].month << '.'
                 << students[k].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}

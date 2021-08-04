/*
Task
You should define a struct with the three other structs as attributes:
1) "Specialization(name)";
2) "Course(name)";
3) "Week(order)".
It should only be possible to initialize the main struct as:
LectureTitle title(Specialization("C++"), Course("White belt"), Week("4th"));
Absence of substruct specification or rearrangement of attributes are not allowed.
*/
#include <string>

using std::string;

struct Specialization {
    string name;
    explicit Specialization(const string& new_name) {
        name = new_name;
    }
};

struct Course {
    string name;
    explicit Course(const string& new_name) {
        name = new_name;
    }
};

struct Week {
    string order;
    explicit Week(const string& new_order) {
        order = new_order;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_spec, const Course& new_course, const Week& new_week) {
        specialization = new_spec.name;
        course = new_course.name;
        week = new_week.order;
    }
};

/* 
Task
You should refactor the given code so that it is:
1) More efficient;
2) Less complex;
3) Easier to add new abstractions to.
*/
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


class Person {
private:
    string Name;
    string Occupation;
public:
    Person(const string& name, const string& occupation) : Name(name), Occupation(occupation) {}
    string GetName() const {
        return Name;
    }
    string GetOccupation() const {
        return Occupation;
    }
    virtual void Walk(const string& destination) const = 0;
};

class Student : public Person {
private:
    string FavouriteSong;
public:
    Student(const string& name, const string& favourite_song) : Person(name, "Student"), FavouriteSong(favourite_song) {}
    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }
    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }
    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }
};

class Teacher : public Person {
private:
    string Subject;
public:
    Teacher(string name, string subject) : Person(name, "Teacher"), Subject(subject) {}
    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }
    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }
};

class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}
    void Check(const Person& p) const {
        cout << "Policeman: " << GetName() << " checks " << p.GetOccupation() << ". "
             << p.GetOccupation() << "'s name is: " << p.GetName() << endl;
    }
    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(const Person& persons, const vector<string>& places) {
    for (const auto& place : places) {
        persons.Walk(place);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });

    return 0;
}

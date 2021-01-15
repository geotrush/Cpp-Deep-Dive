#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Day {
    int value;
    // Force only an explicit constructor call
    explicit Day(const int& new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(const int& new_value) {
        value = new_value;
    }
};

struct Year {
    int value;
    explicit Year(const int& new_value) {
        value = new_value;
    }
};

struct Date {
    int day;
    int month;
    int year;
    Date(const Day& new_day, const Month& new_month, const Year& new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate (const Date& date) {
    cout << "Date: " << date.day << '.' << date.month << '.' << date.year << endl;
}

class DimensionlessConstant {
public:
    // Default construstor
    DimensionlessConstant() {}
    // Custom construstor
    DimensionlessConstant(const string& new_name, const string& new_description, const double& new_value) {
        name = new_name;
        description = new_description;
        value = new_value;
    }
    // Destructor
    ~DimensionlessConstant() {
        for (const string& constant : constants_history) {
            cout << constant << endl;
        }
    }
    string GetName() const { return name; }
    string GetDescription() const { return description; }
    double GetValue() const { return value; }
    void SetName(const string& new_name) { name = new_name; constants_history.push_back(name); }
    void SetDescription(const string& new_description) { description = new_description; }
    void SetValue(const double& new_value) { value = new_value; }
private:
    string name;
    string description;
    double value;
    vector<string> constants_history = {name};
};

void PrintConstant (const DimensionlessConstant& dc) {
    cout << dc.GetName() << " is about " << dc.GetValue();
}

int main() {
    PrintDate({Day(1), Month(1), Year(1970)});
    PrintConstant({"Fine-structure constant, or Sommerfeld's constant, or electromagnetic coupling constant",
                   "Quantifies the strength of the electromagnetic interaction between elementary charged particles",
                   1.0 / 137.0});

    return 0;
}

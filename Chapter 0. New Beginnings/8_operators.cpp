#include <algorithm>
#include <exception>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::setfill;
using std::setw;
using std::endl;
using std::istream;
using std::ostream;
using std::stringstream;
using std::exception;
using std::runtime_error;
using std::string;
using std::vector;

struct Time {
    int hour;
    int minute;
    Time(const int& new_hour = 0, const int& new_minute = 0) {
        int time = new_hour * 60 + new_minute;
        hour = time / 60;
        minute = time % 60;
    }
};

// Input operator
istream& operator >> (istream& input, const Time& duration) {
    input >> duration.hour;
    input.ignore(1);
    input >> duration.minute;
    return input;
}

// Output operator
ostream& operator << (ostream& output, const Time& duration) {
    output << setfill('0');
    output << setw(2) << duration.hour << ':'
           << setw(2) << duration.minute;
    return output;
}

// Addition operator
Time operator + (const Time& left, const Time& right) {
    return Time(left.hour + right.hour, left.minute + right.minute);
}

// Less-than operator
bool operator < (const Time& left, const Time& right) {
    if (left.hour != right.hour) {
        return left.hour < right.hour;
    }
    else {
        return left.minute < right.minute;
    }
}

void PrintVector(const vector<Time>& clock) {
    for (const auto& time : clock) {
        cout << time << ' ';
    }
    cout << endl;
}

int main() {
    Time high_noon, midnight;
    string duration = "12:00";
    stringstream input(duration);
    // Exception
    try {
        if (input.peek() != ':') {
            stringstream message;
            message << "Expected ':', but got: '" << char(input.peek()) << '\'';
            throw runtime_error(message.str());
        }
        input >> high_noon;
        Time next_day = high_noon + midnight;
        vector<Time> clock {high_noon, midnight, next_day};
        PrintVector(clock);
        sort(begin(clock), end(clock));
        PrintVector(clock);
    }
    catch (exception& exception) {
        cout << "Raised exception: " << exception.what();
    }
    
    return 0;
}

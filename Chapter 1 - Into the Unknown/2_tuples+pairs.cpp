#include <iostream>
#include <utility>
#include <string>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::tie;
using std::get;
using std::make_pair;
using std::make_tuple;
using std::pair;
using std::tuple;
using std::string;


struct Date {
public:
    Date(const int& year, const int& month, const int& day) {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }
    auto GetRank() const {
        return tie(year, month, day);
    }
private:
    int year;
    int month;
    int day;
};


const bool operator < (const Date& lhs, const Date& rhs) {
    return lhs.GetRank() < rhs.GetRank();
}


int main() {
    Date start(1970, 1, 1);
    Date end(2038, 1, 19);
    cout << (start < end);

    // Create and access tuple
    auto t = make_tuple(0, 'a', true);
    cout << get<1>(t) << endl;

    tuple new_t(-1, 'x', false); // Only since c++17
    cout << get<1>(t) << endl;

    // Create and access pair
    auto p = make_pair("C++", 13);
    pair new_p("C++", 17); // Only since c++17
    cout << new_p.first << ' ' << new_p.second << endl;

    return 0;
}

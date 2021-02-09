/*
Task
Write a function accepts a regional database and
returns the maximal number of region repetitions.
*/
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using std::max;
using std::map;
using std::tuple;
using std::string;
using std::vector;


enum class Lang {
    DE, FR, IT
};


struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};


bool operator < (const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}


int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetition_count;
    for (const Region& region : regions) {
        result = max(result, ++repetition_count[region]);
    }
    return result;
}

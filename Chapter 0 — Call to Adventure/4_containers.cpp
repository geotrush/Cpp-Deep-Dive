#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;

void PrintVector (const vector<string>& v) {
    cout << "Vector Size:" << v.size() << endl;
    for (const string& element : v) {
        cout << element << ' ';
    }
    cout << endl;
}

void PrintMap (const map<int, string>& m) {
    cout << "Map Size:" << m.size() << endl;
    for (const auto& item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}

void PrintReversedMap (const map<int, string>& m) {
    map<string, int> reversed;
    for (const auto& item : m) {
        reversed[item.second] = item.first;
    }
    for (const auto& item : reversed) {
        cout << item.first << ": " << item.second << endl;
    }
}

void PrintSet(const set<string>& s) {
    cout << "Set Size: " << s.size() << endl;
    for (const string& member : s) {
        cout << member << ' ';
    }
    cout << endl;
}

int main() {
    // Vector (stores elements in the order of insertion)
    vector<string> v(2, "nothing here");
    PrintVector(v);
    v.resize(3); // Resize without rewriting
    v.assign(3, "empty"); // Resize with rewriting
    v.clear(); // Empty out the vector

    // Map (stores key-value pairs sorted by keys)
    map<int, string> dates;
    dates[1941] = "Dennis Ritchie's Birthday!";
    dates[1943] = "Kenneth Thompson's Birthday!";
    dates[1950] = "Bjarne Stroustrup's Birthday!";
    dates[1970] = "UNIX Epoch Start...";
    PrintMap(dates);
    dates.erase(1970); // Removes key-value pair
    PrintReversedMap(dates);

    // Make counters (map & vector)
    map<string, int> counters;
    vector<string> revolutions = {"Agent Smith", "Neo", "Agent Smith"};
    cout << "Counters:\n";
    for (const string& program : revolutions) {
        ++counters[program];
    }
    for (const auto& [key, value] : counters) { // Only with c++17
        cout << key << ": " << value << endl;
    };

    // Set (stores unique members in sorted order)
    set<string> legends;
    legends.insert("Homer");
    legends.insert("Ritchie");
    legends.insert("Thompson");
    legends.insert("Stroustrup");
    legends.erase("Homer"); // Removes member
    PrintSet(legends);
    set<string> reloaded(begin(revolutions), end(revolutions));
    PrintSet(reloaded);

    return 0;
}

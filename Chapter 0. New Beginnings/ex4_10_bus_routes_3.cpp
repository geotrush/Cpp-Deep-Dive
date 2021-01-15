/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following queries (guaranteed to be valid):
- All queries contain: a positive integer n (number of stops),
followed by a sequence of n strings (stop names) separated by spaces.
Note: all strings contain only latin letters and underscores.

Output
You should output the following, based on the current state:
- "Already exists for i": if this bus route already exists;
- "New bus i": if this bus route doesn't exist, assign it a unique positive integer.
Note: Bus routes that share the same set of stops are assumed to be the same route.
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::set;

int main() {
	int q;
	cin >> q;

	map<set<string>, int> buses;

	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;

		set<string> stops;
		for (int j = 0; j < n; ++j) {
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		if (buses.count(stops) == 0) {
			const int new_number = buses.size() + 1;
			buses[stops] = new_number;
			cout << "New bus " << new_number << endl;
		}
		else {
			cout << "Already exists for " << buses[stops] << endl;
		}
	}

	return 0;
}

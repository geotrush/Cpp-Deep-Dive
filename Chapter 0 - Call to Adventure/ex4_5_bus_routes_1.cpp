/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following queries (guaranteed to be valid):
- "NEW_BUS bus stop_count stop1 stop2 ...": add a bus route with stop_count number of stop names;
- "BUSES_FOR_STOP stop": check all of the bus routes that pass through the stop;
- "STOPS_FOR_BUS bus": check all of the bus route's stops with the available bus changes;
- "ALL_BUSES": check all bus routes with all of their stops.
Note: all strings contain only latin letters, digits and underscores.

Output
You should output the following, based on the query and current state:
- "BUSES_FOR_STOP stop":
    a) Chronological list of buses passing through the stop, separated by spaces;
    b) If the stop doesn't exist: "No stop";
- "STOPS_FOR_BUS bus":
    a) Chronological list of stops for the bus: "Stop stop: bus1 bus2 ..." without the queried bus;
    b) If no other bus passes through the stop:"no interchange";
    c) If the bus doesn't exist:"No bus";
- "ALL_BUSES":
    a) All bus routes in alphabetical order with their chronology of stops: "Bus bus: stop1 stop2 ...";
    b) If no buses exist: "No buses".
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> buses2stops;
    map<string, vector<string>> stops2buses;

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;

        if (query == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;

            vector<string>& stops = buses2stops[bus];
            stops.resize(stop_count);

            for (string& stop : stops) {
                cin >> stop;
                stops2buses[stop].push_back(bus);
            }
        }
        else if (query == "BUSES_FOR_STOP") {
            string stop_name;
            cin >> stop_name;

            if (stops2buses.count(stop_name) == 0) {
                cout << "No stop\n";
            }
            else {
                for (const string& bus : stops2buses[stop_name]) {
                    cout << bus << ' ';
                }
                cout << endl;
            }
        }
        else if (query == "STOPS_FOR_BUS") {
            string bus_name;
            cin >> bus_name;

            if (buses2stops.count(bus_name) == 0) {
                cout << "No bus\n";
            }
            else {
                for (const string& stop : buses2stops[bus_name]) {
                    cout << "Stop " << stop << ": ";

                    if (stops2buses[stop].size() == 1) {
                        cout << "no interchange\n";
                    }
                    else {
                        for (const string& another_bus : stops2buses[stop]) {
                            if (bus_name != another_bus) {
                                cout << another_bus << ' ';
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
        else if (query == "ALL_BUSES") {
            if (buses2stops.empty()) {
                cout << "No buses\n";
            }
            else {
                for (const auto& [bus, stops] : buses2stops) {
                    cout << "Bus " << bus << ": ";

                    for (const string& stop : stops) {
                        cout << stop << ' ';
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}

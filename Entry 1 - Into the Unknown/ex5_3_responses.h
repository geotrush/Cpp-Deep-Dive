#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::pair;
using std::string;
using std::vector;
using std::ostream;


struct BusesForStopResponse {
    vector<string> buses_to_stop;
};
ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_for_buses;
};
ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};
ostream& operator << (ostream& os, const AllBusesResponse& r);

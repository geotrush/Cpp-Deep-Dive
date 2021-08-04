#pragma once

#include <string>
#include <vector>
#include <map>

#include "ex5_3_responses.h"

using std::string;
using std::vector;
using std::map;


class BusManager {
private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
public:
    void AddBus(const string& bus, const vector<string>& stops);
    BusesForStopResponse GetBusesForStop(const string& stop) const;
    StopsForBusResponse GetStopsForBus(const string& bus) const;
    AllBusesResponse GetAllBuses() const;
};

#pragma once

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::istream;


enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q);

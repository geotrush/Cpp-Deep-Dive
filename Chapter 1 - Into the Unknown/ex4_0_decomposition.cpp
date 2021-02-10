/*
Task
You should decompose the functions and classes from
the previous Chapter's exercise: ex4_5_bus_routes_1.cpp.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::tuple;
using std::string;
using std::vector;
using std::istream;
using std::ostream;


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

istream& operator >> (istream& in, Query& q) {
    string operation_code;
    in >> operation_code;
    if (operation_code == "NEW_BUS") {
        size_t stop_count;
        q.type = QueryType::NewBus;
        in >> q.bus >> stop_count;
        q.stops.resize(stop_count);
        for (auto& item : q.stops) {
            in >> item;
        }
    }
    else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        in >> q.stop;
    }
    else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        in >> q.bus;
    }
    else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return in;
}

struct BusesForStopResponse {
    vector<string> buses_to_stop;
};

ostream& operator << (ostream& out, const BusesForStopResponse& r) {
    if (r.buses_to_stop.empty()) {
        out << "No stop" << endl;
    }
    else {
        for (const string& bus : r.buses_to_stop) {
            out << bus << ' ';
        }
        out << endl;
    }
    return out;
}

struct StopsForBusResponse {
    string bus;
    vector<pair<string, vector<string>>> stops_for_buses;
};

ostream& operator << (ostream& out, const StopsForBusResponse& r) {
    if (r.stops_for_buses.empty()) {
        out << "No bus" << endl;
    }
    else {
        for (const auto& stop : r.stops_for_buses) {
            out << "Stop " << stop.first << ": ";
            if (stop.second.size() == 1) {
                out << "no interchange";
            }
            else {
                for (const auto& other_bus : stop.second) {
                    if (other_bus != r.bus) {
                        out << other_bus << ' ';
                    }
                }
            }
            out << endl;
        }
    }
    return out;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& out, const AllBusesResponse& r) {
    if (r.buses_to_stops.empty()) {
        out << "No buses" << endl;
    }
    else {
        for (const auto& bus_item : r.buses_to_stops) {
            out << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                out << stop << ' ';
            }
            out << endl;
        }
    }
    return out;
}

class BusManager {
private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for (const auto& stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }
    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if (stops_to_buses.count(stop) == 0) {
            return BusesForStopResponse{ vector<string>() };
        }
        else {
            return BusesForStopResponse{ stops_to_buses.at(stop) };
        }
    }
    StopsForBusResponse GetStopsForBus(const string& bus) const {
        vector<pair<string, vector<string>>> result;
        if (buses_to_stops.count(bus) > 0) {
            for (const auto& stop : buses_to_stops.at(bus)) {
                result.push_back(make_pair(stop, stops_to_buses.at(stop)));
            }
        }
        return StopsForBusResponse{ bus, result };
    }
    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse{ buses_to_stops };
    }
};

int main() {
    Query q;
    int query_count;
    cin >> query_count;

    BusManager bd;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bd.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bd.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bd.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bd.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}

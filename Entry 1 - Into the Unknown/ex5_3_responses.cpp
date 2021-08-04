#include "ex5_3_responses.h"

using std::endl;


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

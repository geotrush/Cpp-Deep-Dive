#include "ex5_3_query.h"


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

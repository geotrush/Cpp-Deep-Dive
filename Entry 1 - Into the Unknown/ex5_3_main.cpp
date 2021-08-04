/*
Task
You should decompose the functions and classes from the
previous Chapter's exercise: ex4_5_bus_routes_1.cpp
into separate header and source files.
*/
#include "ex5_3_query.h"
#include "ex5_3_bus_manager.h"

using std::cin;
using std::cout;
using std::endl;


int main() {
    Query q;
    int query_count;
    cin >> query_count;
    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }
}

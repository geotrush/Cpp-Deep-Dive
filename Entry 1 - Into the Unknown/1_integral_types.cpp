#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;


enum class RequestType {
    // Default integers are indices
    ADD = 0,
    NEGATE = 1,
    REMOVE = 42
};

void ProcessRequest(set<int>& numbers, RequestType request_type, int request_data) {
    switch (request_type) {
    case RequestType::ADD:
        numbers.insert(request_data);
        break;
    case RequestType::NEGATE: {  // curly braces because of variable definition
        bool contains = numbers.count(request_data) == 1; // <--
        if (contains) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
        break;
    }
    case RequestType::REMOVE:
        numbers.erase(request_data);
        break;
    default:
        cout << "Unknown request" << endl;
    }
}


int main() {
    int i; // Signed 32-bit integer (size depends on architecture)
    // As container size & in loops
    size_t n; // Unsigned 32-bit integer
    vector<int> blocks(n);

    // C library <cstdint>
    int64_t a; // from -2^31 to 2^31 - 1
    uint16_t b; // from 0 to 2^16 - 1

    // Enumerated types
    // Define specific values as symbolic constants
    auto request_type = static_cast<RequestType>(42); // RequestType::REMOVE

    return 0;
}

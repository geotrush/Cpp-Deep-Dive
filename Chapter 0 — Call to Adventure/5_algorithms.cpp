#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::max;

void PrintVector(const vector<int>& v, const string& title) {
    cout << title << ": ";
    for (auto& i : v) {
        cout << i;
    }
    cout << endl;
}

bool Gt137 (const int& n) {
    if (n > 137) {
        return true;
    }
    return false;
}

int main() {
    // Min & Max
    cout << min(0, 1) << endl;
    cout << max(0, 1) << endl;
    
    // Sorting
    vector<int> numbers = {1, 7, 3};
    PrintVector(numbers, "Initial Number");
    sort(begin(numbers), end(numbers));
    PrintVector(numbers, "Sorted Number");

    // Counting
    cout << count(begin(numbers), end(numbers), 3) << endl;

    // Custom comparison counting
    cout << count_if(begin(numbers), end(numbers), Gt137) << endl;

    // Custom comparison counting with lambda functions
    int thr = 137;
    cout << count_if(begin(numbers), end(numbers), [thr](const int& n) {
        if (n > thr) {
            return true;
        }
        return false;
    });
    cout << endl;

    // Range-based for loop
    for (auto& n : numbers) {
        ++n; // allows modification 
    }
    for (const auto& n : numbers) {
        cout << n; // doesn't allow modification
    }

    return 0;
}

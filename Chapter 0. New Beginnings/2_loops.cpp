#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    // Loop through containers 
    vector<char> cpp = {'C', '+', '+'};
    cout << "Currently writing in ";
    for (auto& c : cpp) {
        cout << c;
    }
    cout << ", not in ";
    for (auto& c : cpp) {
        if (c != '+') cout << c;
    }

    // Use <algorithm> library
    sort(begin(cpp), end(cpp));
    cout << "\nFirst element after sorting: " << cpp[0] << endl;
    int pluses = count(begin(cpp), end(cpp), '+');
    cout << "The difference between C and C++ is in... " << pluses << " pluses!\n";
    
    // Ternary relational operator
    string parity = (pluses % 2 == 0) ? "even" : "odd";
    cout << "The number of pluses has " << parity << " parity";

    return 0;
}

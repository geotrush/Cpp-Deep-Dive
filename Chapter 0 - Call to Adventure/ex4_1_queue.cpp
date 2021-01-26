/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following querys (guaranteed to be valid):
- "WORRY i": mark the i-th person (indexed from '0') as "worried";
- "QUIET i": mark the i-th person (indexed from '0') as "relaxed";
- "COME k": add k "relaxed" people to the end of the queue;
- "COME -k": remove k people from the end of the queue;
- "WORRY_COUNT": check the number of "worried" people.

Output
You should output the number of "worried" people
at every "WORRY_COUNT" query (on a new line).
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    int q;
    cin >> q;

    vector<bool> queue;
    for (int n = 0; n < q; ++n) {
        string query;
        cin >> query;
        if (query == "COME") {
            int k;
            cin >> k;
            queue.resize(queue.size() + k, false);
        }
        else if (query == "WORRY" || query == "QUIET") {
            int i;
            cin >> i;
            queue[i] = (query == "WORRY");
        }
        else if (query == "WORRY_COUNT") {
            cout << count(begin(queue), end(queue), true) << endl;
        }
    }

    return 0;
}

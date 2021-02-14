#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::find;
using std::equal_range;
using std::map;
using std::set;
using std::stack;
using std::queue;
using std::deque;
using std::string;
using std::vector;


int main() {
    // Stack is for pushing to back and poping at back (LIFO)
    stack<int> stack;
    stack.push(1337);
    stack.pop();
    cout << "Stack is empty!" << endl;

    // Queue is for pushing to back and poping at front (FIFO)
    queue<int> queue;
    queue.push(26);
    queue.pop();
    cout << "Queue is empty!" << endl;

    // Double end of queue allows constant time inserting
    // but it's not as efficient as stack or queue
    deque<int> deque(100000);
    while (!deque.empty()) {
        deque.erase(begin(deque));
    }
    cout << "Deque is empty!" << endl;

    // Searching algorithms
    // Strings & vectors (unsorted case) - use functions
    string s = "naysayer88";
    for (auto iter = find(begin(s), end(s), '8'); iter != end(s); iter = find(next(iter), end(s), '8')) {
        cout << iter - begin(s) << ' ';
    }
    cout << endl;
    vector<string> v = {"If on a winter's night a traveler", "Invisible Cities", "If on a winter's night a traveler"};
    auto cnt = count(begin(v), end(v), "If on a winter's night a traveler");
    cout << cnt << endl;

    // Sets & maps (sorted case) - use methods
    set<int> set = {98, 3, 26};
    auto r = set.equal_range(8);
    (r.first == r.second)?(cout << "Not found."):(cout << "Found!");

    return 0;
}

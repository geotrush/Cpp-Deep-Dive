/* 
Input
The input stream contains a single integer x on the first line,
non-negative integer n and a sequence of n one-per-line arithmetic operations, namely:
1) "+ a": add a number;
2) "- b": subtract a number;
3) "* c": multiply by a number;
4) "/ d": divide by a number.

Output
You should output the arithmetic expression resulting from applying operations to x.
Notes: every operation should be enclosed in brackets and
every operation sigh should have spaces on each side.
*/
#include <iostream>
#include <string>
#include <deque>

using std::cin;
using std::cout;
using std::to_string;
using std::string;
using std::deque;


int main() {
    int number;
    size_t size;
    cin >> number >> size;

    deque<string> expr(size);
    expr.push_back(to_string(number));
    for (size_t i = 0; i < size; ++i) {
        int value;
        char operation;
        cin >> operation >> value;
        expr.push_front("(");
        expr.push_back(") ");
        expr.push_back(string(1, operation));
        expr.push_back(" ");
        expr.push_back(to_string(value));
    }
    
    for (auto& item : expr) {
        cout << item;
    }

    return 0;
}

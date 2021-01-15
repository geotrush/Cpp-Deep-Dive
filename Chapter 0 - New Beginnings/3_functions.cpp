#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void Sort(vector<string>& v) {
    sort(begin(v), end(v));
}

// "Const" modifier doesn't allow any type/container changes
void PrintElements(const vector<string>& v) {
    for (const string& s : v) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    vector<string> elements = {"air", "fire", "water", "earth"}; 
    PrintElements(elements);
    Sort(elements);
    PrintElements(elements);
    return 0;
}

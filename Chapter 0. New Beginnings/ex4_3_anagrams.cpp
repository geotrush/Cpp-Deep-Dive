/*
Input
The input stream contains an integer n (number of word pairs)
as well as the strings of word pairs on the next n lines.
Note: all strings contain only latin lower-case letters.

Output
You should output n lines with the word "YES"/"NO"
based on whether the words are anagrams of each other.
*/
#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::string;
using std::map;

map<char, int> BuildCharCounters (const string& s) {
    map<char, int> counters;
    for (const char& c : s) {
        ++counters[c];
    }
    return counters;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word1, word2;
        cin >> word1 >> word2;

        if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
Input
The input stream contains an integer q (number of queries)
as well as some sequence of the following queries (guaranteed to be valid):
- "ADD word1 word2": add a synonym pair;
- "COUNT word": check the word's number of synonyms;
- "CHECK word1 word2": check whether word1 and word2 are synonyms.
Notes: the two words become synonyms only after queries of "ADD word1 word2" or "ADD word1 word2",
all strings contain only latin letters, digits and underscores.

Output
You should output the number of planned tasks for the i-th day as well as their names
in any order, separated by spaces at every "DUMP i" query (on a new line).
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::set;

int main() {
    int q;
    cin >> q;

    map<string, set<string>> words;

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;

        if (query == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            words[word1].insert(word2);
            words[word2].insert(word1);
        }
        else if (query == "COUNT") {
            string word;
            cin >> word;
            cout << words[word].size() << endl;
        }
        else if (query == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            if (words[word1].count(word2) > 0) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

/* 
Task
You should write a function that
splits a string by spaces and returns a vector of words.
*/
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::istringstream;


vector<string> SplitIntoWords_2(const string& s) {
    string word;
    istringstream is(s);
    vector<string> words;
    while (is >> word) {
        words.push_back(word);
    }
    return words;
}

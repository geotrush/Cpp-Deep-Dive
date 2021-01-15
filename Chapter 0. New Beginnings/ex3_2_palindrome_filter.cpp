/* 
Input
The function call contains a vector of strings and integer: words, minLength.

Output
You should write a function that returns vector<string>
with palindromes that are not shorter than minLength.
*/
#include <string>
#include <vector>

using std::string;
using std::vector;

bool IsPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromeFilter(vector<string> words, int minLength) {
    vector<string> result;
    for (const auto& w : words) {
        if (IsPalindrome(w) && w.size() >= minLength) {
            result.push_back(w);
        }
    }
    return result;
}

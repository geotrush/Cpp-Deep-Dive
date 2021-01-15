/* 
Input
The function call contains a string: s.

Output
You should write a function that checks 's' on being a palindrome
and returns a boolean value. Consider empty strings as palindromes.
*/
#include <string>

using std::string;

bool IsPalindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

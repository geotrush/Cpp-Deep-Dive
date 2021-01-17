/* 
Input
The function call contains two vectors of strings: source, endpoint.

Output
You should write a function that transfers all strings
from source to endpoint leaving the former empty.
*/
#include <string>
#include <vector>

using std::string;
using std::vector;

void MoveStrings(vector<string>& source, vector<string>& endpoint) {
    	endpoint.insert(endpoint.end(), source.begin(), source.end());
}

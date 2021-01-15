// Include header files
#include <iostream>
#include <string>

// Import necessary identifiers from the standard namespace
using std::cin;
using std::cout;
using std::string;

int main() {
    string hello, world;
    cin >> hello >> world;
    string helloWorld = hello + ' ' + world;
    cout << helloWorld;
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

// Custom type (structure)
struct MajorArcana {
    int number;
    string name;
};

int main() {
    // Fundamental types
    int zork; // Declaration + Definition with a garbage value
    zork = 69105; // Assignment (assigning a value to a defined variable)
    double tau = 6.28; // Definition or Initialization (declaring and assigning a variable)
    int sameAsZork = zork--; // In-place decrement (returns a copy of the old value)
    int beyondZork = ++zork; // In-place increment (returns a new value)
    cout << "Found Easter Egg " << zork << "!\n";
    bool isAmateur = true;
    char letter = '#';
    
    // Custom type
    vector<MajorArcana> deck;
    deck.push_back({0, "The Fool"});
    deck.push_back({1, "The Magician"});
    cout << "Number " << deck[0].number << " is " << deck[0].name << endl;

    // Containers
    string handle = "tensorush";
    vector<int> magicSquare = {15, 34, 65, 111};
    cout << "Magic Square Size is " << magicSquare.size() << endl;
    map<int, string> num2string;
    num2string[0] = "Zero";
    num2string[1] = "One";
    cout << "Neo is The " << num2string[1];

    return 0;
}

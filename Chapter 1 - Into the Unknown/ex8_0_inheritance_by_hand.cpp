/* 
Task
You should write the following two classes:
1) "Animal": base class that has the name field;
2) "Dog": derived class that implements Bark method and
initializes the name field of the parent class.
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Animal {
public:
    const string name_;
    Animal(const string& name = "animal") : name_(name) {}
};

class Dog : public Animal {
public:
    Dog(const string& name = "dog") : Animal(name) {}
    void Bark() {
       cout << name_ << " barks: woof!" << endl;
    }
};

/* 
Task
You should write the following four classes and a function:
1) "Shape": abstract base class that implements the pure virtual methods Name(), Perimeter(), Area();
2) "Triangle": derived class that overrides the pure virtual methods accordingly;
3) "Rectangle": derived class that overrides the pure virtual methods accordingly;
4) "Circle": derived class that overrides the pure virtual methods accordingly;
5) "CreateShape": function that creates shared_ptr for the objects that comprise the input stream.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::make_shared;
using std::setprecision;
using std::string;
using std::vector;
using std::shared_ptr;
using std::istringstream;


class Shape {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Shape {
private:
    double A;
    double B;
    double C;
public:
    Triangle(const double& a, const double& b, const double& c) : A(a), B(b), C(c) {}
    string Name() const override {
        return "TRIANGLE";
    }
    double Perimeter() const override {
        return A + B + C;
    }
    double Area() const override {
        double p_div_2 = Perimeter() / 2;
        return sqrt(p_div_2 * (p_div_2 - A) * (p_div_2 - B) * (p_div_2 - C));
    }
};

class Rectangle : public Shape {
private:
    double Width;
    double Height;
public:
    Rectangle(const double& width, const double& height) : Width(width), Height(height) {}
    string Name() const override {
        return "RECT";
    }
    double Perimeter() const override {
        return (Width + Height) * 2;
    }
    double Area() const override {
        return Width * Height;
    }
};

class Circle : public Shape {
private:
    double Radius;
public:
    Circle(const double& radius) : Radius(radius) {}
    string Name() const override {
        return "CIRCLE";
    }
    double Perimeter() const override {
        return (2 * 3.14) * Radius;
    }
    double Area() const override {
        return 3.14 * Radius * Radius;
    }
};

shared_ptr<Shape> CreateShape(istringstream& is) {
    string type;
    is >> type;
    if (type == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (type == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rectangle>(width, height);
    }
	else {
		double radius;
		is >> radius;
		return make_shared<Circle>(radius);
	}
}


int main() {
    vector<shared_ptr<Shape>> shapes;
    for (string line; getline(cin, line); ) {
        istringstream is(line);
        string command;
        is >> command;
        if (command == "ADD") {
            shapes.push_back(CreateShape(is));
        }
        else if (command == "PRINT") {
            for (const auto& shape : shapes) {
                cout << fixed << setprecision(3)
                     << shape->Name() << ' '
                     << shape->Perimeter() << ' '
                     << shape->Area() << endl;
            }
        }
    }

    return 0;
}

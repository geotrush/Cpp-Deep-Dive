#include "ex5_2_rectangle.h"


class Rectangle {
private:
    int width, height;
public:
    Rectangle(int width, int height) {
        this -> width = width;
        this -> height = height;
    }
    int GetArea() const {
        return width * height;
    }
    int GetPerimeter() const {
        return 2 * (width + height);
    }
    int GetWidth() const {
        return width;
    }
    int GetHeight() const {
        return height;
    }
};

/*
Task
You should declare class methods that will be defined in the source file ex5_2_rectangle.cpp
*/
#pragma once


class Rectangle {
private:
    int width; 
    int height;
public:
    Rectangle(int width, int height);
    int GetArea() const;
    int GetPerimeter() const;
    int GetWidth() const;
    int GetHeight() const;
};

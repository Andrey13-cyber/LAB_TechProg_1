#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{
public:
    Rectangle();
    ~Rectangle();
    Rectangle(const Rectangle&);
    Rectangle(string type, double size, double square);
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    double getSquare();
};


#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{

private:
    double lenght;
    double width;
    double square;

public:
    Rectangle();
    ~Rectangle();
    Rectangle(const Rectangle&);
    Rectangle(string type, double lenght, double width, double square);
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    double getSquare();
};


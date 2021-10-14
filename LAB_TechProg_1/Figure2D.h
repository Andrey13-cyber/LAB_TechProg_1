#pragma once
#include "Figure.h"
class Figure2D :
    public Figure
{
private:
    string type;
    double size;
    double square;

public:
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    void setSquare(double square);
    double getSquare();
};


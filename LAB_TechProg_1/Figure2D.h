#pragma once
#include "Figure.h"
class Figure2D :
    public Figure
{

private:
    double size;
    double lenght;
    double width;
    double square;

public:
    Figure2D(string type);
    ~Figure2D() {
        cout << "Вызван деструктор" << endl;
    };
    Figure2D(const Figure2D&);
    Figure2D(string type, double lenght, double width, double square);
    void setSize(double size);
    double getSize();
    double getSquareOrVolume();
};


#pragma once
#include "Figure.h"
class Figure3D :
    public Figure
{

private: 
    double volume;
    double size;
    double radius;

public:
    Figure3D(string type);
    ~Figure3D() {
        cout << "Вызван деструктор" << endl;
    };
    Figure3D(const Figure3D&);
    Figure3D(string type, double radius, double volume);
    void setSize(double size);
    double getSize();
    double getSquareOrVolume();
};


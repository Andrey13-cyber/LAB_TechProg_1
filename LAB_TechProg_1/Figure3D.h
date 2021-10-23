#pragma once
#include "Figure.h"
class Sphere :
    public Figure
{
public:
    Sphere();
    ~Sphere();
    Sphere(const Sphere&);
    Sphere(string type, double size, double volume);
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    double getVolume();
};


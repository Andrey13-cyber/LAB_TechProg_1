#pragma once
#include "Figure.h"
class Sphere :
    public Figure
{

private: 
    double volume;
    double radius;

public:
    Sphere();
    ~Sphere();
    Sphere(const Sphere&);
    Sphere(string type, double radius, double volume);
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    double getVolume();
};


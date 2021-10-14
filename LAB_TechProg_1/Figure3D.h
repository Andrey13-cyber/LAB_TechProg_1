#pragma once
#include "Figure.h"
class Figure3D :
    public Figure
{
private:
    string type;
    double size;
    double volume;

public:
    void setType(string type);
    string getType();
    void setSize(double size);
    double getSize();
    void setVolume(double volume);
    double getVolume();
};


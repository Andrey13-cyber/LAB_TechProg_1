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
    ~Sphere() {
        cout << "Вызван деструктор объемной фигуры" << endl;
    };
    Sphere(const Sphere&);
    Sphere(double radius);
    double getSquareOrVolume();
    virtual void changeObject();
    virtual void printToConsole();
    virtual void inputFromConsole();
    void setRadius(double radius);
    double getRadius();
    void calcVolume();
    virtual void printToFile(ostream& out);
    virtual void inputFromFile(ifstream& file, string& fig);
};
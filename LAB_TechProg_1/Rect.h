#pragma once
#include "Figure.h"
class Rect :
    public Figure
{
private:
    double lenght;
    double width;
    double square;

    

public:
    Rect();
    ~Rect() {
        cout << "Вызван деструктор" << endl;
    };
    Rect(const Rect&);
    Rect(double lenght, double width);
    double getSquareOrVolume();
    virtual void changeObject();
    virtual void printToConsole();
    virtual void inputFromConsole();
    void calcSquare();
    void setWidth(double width);
    void setLenght(double lenght);
    double getWidth();
    double getRectLenght();
};


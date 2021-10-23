#pragma once
#include<string>
#include<iostream>
using namespace std;

class Figure
{
private:
    string type;
    double size;
    double square;
    double volume;

public:
    virtual double getSquare() = 0;
    virtual double getVolume() = 0; 
};


#pragma once
#include<string>
#include<iostream>
using namespace std;

class Figure
{
private:
    string type;
    

public:
    Figure(string _type);
    Figure(const Figure& figure);
    ~Figure();
    virtual double getSquare() = 0;
    virtual double getVolume() = 0; 
    virtual void print();
};


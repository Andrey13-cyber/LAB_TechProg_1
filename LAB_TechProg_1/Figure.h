#pragma once
#include<string>
#include<iostream>
#include <cmath>
#include "Keeper.h"
using namespace std;

class Figure
{
private:
    string type;
    

public:
    Figure(string type);
    Figure(const Figure& figure);
    ~Figure() {
        cout << "Вызван деструктор" << endl;
    }
    virtual double getSquareOrVolume() = 0;
    virtual void changeObject() = 0;
    virtual void print(string type, int objNumber);
};


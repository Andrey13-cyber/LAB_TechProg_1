#pragma once
#include<string>
#include<iostream>
#include<cmath>
#include "strToDouble.h"
#include "Keeper.h"
#include "graphics.h"
#include<fstream>
using namespace std;

class Figure
{
private:
    string type;


public:
    Figure(string type);
    Figure(const Figure& figure);
    ~Figure() {
        cout << "Вызван деструктор Figure" << endl;
    }
    virtual double getSquareOrVolume() = 0;
    virtual void changeObject() = 0;
    virtual void printToConsole();
    virtual void inputFromConsole();
    virtual void printToFile(ostream& out);
    virtual void inputFromFile(ifstream& file, string& fig) = 0;
};


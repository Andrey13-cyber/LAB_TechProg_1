#include "Rect.h"

double Rect::getSquareOrVolume() {
	return square;

}

Rect::Rect() : Figure("Прямоугольник") {
	cout << " " << endl;

}



Rect::Rect(const Rect& figure2d) : Figure(figure2d),lenght(figure2d.lenght), width(figure2d.width), square(figure2d.square) {
	cout << "Вызван конструктор копирования плоской фигуры";

}

Rect::Rect(double lenght, double width) : Figure("Прямоугольник"),  lenght(lenght), width(width) {
	calcSquare();
	cout << "Вызван конструктор объекта плоской фигуры";

}

void Rect::changeObject() {
	cout << "Введите новую длину: ";
	cin >> lenght;
	cout << "Введите новую ширину: ";
	cin >> width;
}

void Rect::printToConsole() {
	Figure::printToConsole();
	cout << "Длина: " << lenght << endl;
	cout << "Ширина: " << width << endl;
	cout << "Площадь: " << square << endl;

}

void Rect::inputFromConsole()
{
	cout << "Введите длину: ";
	cin >> lenght;
	cout << "Введите ширину: ";
	cin >> width;
	
}

void Rect::setWidth(double width) {
	this->width = width;
	calcSquare();
}

double Rect::getWidth() {
	return width;
}


void Rect::setLenght(double lenght) {
	this->lenght = lenght;
	calcSquare();
}

double Rect::getRectLenght() {
	return lenght;
}

void Rect::calcSquare()
{
	square = lenght * width;
}


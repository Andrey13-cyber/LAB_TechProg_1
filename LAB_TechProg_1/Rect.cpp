#include "Rect.h"

void Rect::calcSquare()
{
	square = lenght * width;
}

Rect::Rect() : Figure("Прямоугольник"), width(0), lenght(0), square(0) {
	cout << "Вызван конструктор плоской фигуры" << endl;

}



Rect::Rect(const Rect& figure2d) : Figure(figure2d), lenght(figure2d.lenght), width(figure2d.width), square(figure2d.square) {
	cout << "Вызван конструктор копирования плоской фигуры";

}

Rect::Rect(double lenght, double width) : Figure("Прямоугольник"), lenght(lenght), width(width) {
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
	cleardevice();
	rectangle(100, 100, 100 + lenght, 100 + width);
}

void Rect::inputFromConsole()
{
	cout << "Введите длину: ";
	cin >> lenght;
	cout << "Введите ширину: ";
	cin >> width;
	calcSquare();
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

double Rect::getSquareOrVolume() {
	return square;

}

void Rect::printToFile(ostream& out)
{
	Figure::printToFile(out);
	out << lenght << endl;
	out << width << endl;
}

void Rect::inputFromFile(ifstream& file, string& fig)
{
	Figure::inputFromFile(file, fig);
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, fig))
		throw err;
	width = (checkStringToDouble(fig) ? stod(fig) : 0);
	if (!getline(file, fig))
		throw err;
	lenght = (checkStringToDouble(fig) ? stod(fig) : 0);
	calcSquare();

}






#include "Rect.h"

double Rect::getSquareOrVolume() {
	return square;

}

Rect::Rect() : Figure("�������������") {
	cout << " " << endl;

}



Rect::Rect(const Rect& figure2d) : Figure(figure2d),lenght(figure2d.lenght), width(figure2d.width), square(figure2d.square) {
	cout << "������ ����������� ����������� ������� ������";

}

Rect::Rect(double lenght, double width) : Figure("�������������"),  lenght(lenght), width(width) {
	calcSquare();
	cout << "������ ����������� ������� ������� ������";

}

void Rect::changeObject() {
	cout << "������� ����� �����: ";
	cin >> lenght;
	cout << "������� ����� ������: ";
	cin >> width;
}

void Rect::printToConsole() {
	Figure::printToConsole();
	cout << "�����: " << lenght << endl;
	cout << "������: " << width << endl;
	cout << "�������: " << square << endl;

}

void Rect::inputFromConsole()
{
	cout << "������� �����: ";
	cin >> lenght;
	cout << "������� ������: ";
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


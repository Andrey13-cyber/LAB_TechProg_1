#include "Sphere.h"

double Sphere::getSquareOrVolume() {
	return volume;

}

void Sphere::calcVolume() {
	volume = (4.0 / 3.0) * 3.14 * pow(radius, 3.0);
}

Sphere::Sphere() : Figure("Шар"), radius(0), volume(0)
{
	cout << "Вызван конструктор объемной фигуры" << endl;
}


//void Sphere::setSize(double size) {
//	this->size = size;
//}
//
//double Sphere::getSize() {
//	return size;
//}

Sphere::Sphere(const Sphere& figure3d) : Figure(figure3d), radius(figure3d.radius), volume(figure3d.volume) {
	cout << "Вызван конструктор копирования объемной фигуры";

}

Sphere::Sphere(double radius) : Figure("Шар"), radius(radius) {
	calcVolume();
	cout << "Вызван конструктор объекта объемной фигуры";
}

void Sphere::changeObject() {
	cout << "Введите новый радиус: ";
	cin >> radius;

}

void Sphere::printToConsole() {
	Figure::printToConsole();
	cout << "Радиус: " << radius << endl;
	cout << "Объём: " << volume << endl;
	cleardevice();
	circle(200, 200, radius);
}

void Sphere::inputFromConsole()
{

	cout << "Введите радиус шара: ";
	cin >> radius;
	calcVolume();
}

void Sphere::setRadius(double radius) {
	this->radius = radius;
	calcVolume();
}

double Sphere::getRadius() {
	return radius;
}

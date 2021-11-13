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

void Sphere::printToFile(ostream& out)
{
	Figure::printToFile(out);
	out << radius << endl;

}

void Sphere::inputFromFile(ifstream& file, string& fig)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, fig))
		throw err;
	radius = (checkStringToDouble(fig) ? stod(fig) : 0);
	calcVolume();
}

#include "Sphere.h"

double Sphere::getSquareOrVolume() {
	return volume;

}

void Sphere::calcVolume() {
	volume = (4.0 / 3.0) * 3.14 * pow(radius, 3.0);
}

Sphere::Sphere() : Figure("���"), radius(0), volume(0)
{
	cout << "������ ����������� �������� ������" << endl;
}


//void Sphere::setSize(double size) {
//	this->size = size;
//}
//
//double Sphere::getSize() {
//	return size;
//}

Sphere::Sphere(const Sphere& figure3d) : Figure(figure3d), radius(figure3d.radius), volume(figure3d.volume) {
	cout << "������ ����������� ����������� �������� ������";

}

Sphere::Sphere(double radius) : Figure("���"), radius(radius) {
	calcVolume();
	cout << "������ ����������� ������� �������� ������";
}

void Sphere::changeObject() {
	cout << "������� ����� ������: ";
	cin >> radius;

}

void Sphere::printToConsole() {
	Figure::printToConsole();
	cout << "������: " << radius << endl;
	cout << "�����: " << volume << endl;
	cleardevice();
	circle(200, 200, radius);
}

void Sphere::inputFromConsole()
{

	cout << "������� ������ ����: ";
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

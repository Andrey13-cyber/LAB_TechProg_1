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

void Sphere::printToFile(ostream& out)
{
	Figure::printToFile(out);
	out << radius << endl;

}

void Sphere::inputFromFile(ifstream& file, string& fig)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, fig))
		throw err;
	radius = (checkStringToDouble(fig) ? stod(fig) : 0);
	calcVolume();
}

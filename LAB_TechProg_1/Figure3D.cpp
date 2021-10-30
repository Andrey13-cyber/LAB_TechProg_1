#include "Figure3D.h"

double Figure3D::getSquareOrVolume() {

	size = (4.0 / 3.0) * 3.14 * pow(radius, 3);
	double volume = size;
	return volume;

}

Figure3D::Figure3D(string type) : Figure(type) {
	cout << "������ ����������� ���� ������� �������� ������";

}


void Figure3D::setSize(double size) {
	this->size = size;
}

double Figure3D::getSize() {
	return size;
}

Figure3D::Figure3D(const Figure3D& figure3d) : Figure(figure3d), size(figure3d.size), radius(figure3d.radius), volume(figure3d.volume) {
	cout << "������ ����������� ����������� �������� ������";

}

Figure3D::Figure3D(string type, double radius, double volume) : Figure(type), size(size), radius(radius), volume(volume) {
	cout << "������ ����������� ������� �������� ������";
}

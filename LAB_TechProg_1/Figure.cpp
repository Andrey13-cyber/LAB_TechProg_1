#include "Figure.h"

Figure::Figure(string type) : type(type) {
	cout << "������ ����������� ���� �������";
}

Figure::Figure(const Figure& figure) : type(figure.type) {
	cout << "������ ����������� �������";
}

void Figure::print(string type, int objNumber) {
	cout << type << " " << objNumber << ":" << endl;
}

#include "Figure.h"

Figure::Figure(string type) : type(type) {
	cout << "������ ����������� Figure" << endl;
}

Figure::Figure(const Figure& figure) : type(figure.type) {
	cout << "������ ����������� ����������� Figure" << endl;
}

void Figure::printToConsole()
{
	cout << type << endl;
}

void Figure::changeObject() {
	cout << "������� ����� ������: ";
	cin >> type;
}

void Figure::inputFromConsole()
{
	cout << "������� ���: ";
	cin >> type;
}

void Figure::printToFile(ostream& out)
{
	out << type << endl;
}

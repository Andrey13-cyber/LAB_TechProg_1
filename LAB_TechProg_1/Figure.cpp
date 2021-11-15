#include "Figure.h"

Figure::Figure(string type) : type(type) {
	cout << "Вызван конструктор Figure" << endl;
}

Figure::Figure(const Figure& figure) : type(figure.type) {
	cout << "Вызван конструктор копирования Figure" << endl;
}

void Figure::printToConsole()
{
	cout << type << endl;
}

void Figure::changeObject() {
	cout << "Введите новый объект: ";
	cin >> type;
}

void Figure::inputFromConsole()
{
	cout << "Введите тип: ";
	cin >> type;
}

void Figure::printToFile(ostream& out)
{
	out << type << endl;
}

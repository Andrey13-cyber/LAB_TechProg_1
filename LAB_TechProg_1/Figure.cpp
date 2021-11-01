#include "Figure.h"

Figure::Figure(string type) : type(type) {
	cout << "Вызван конструктор Figure";
}

Figure::Figure(const Figure& figure) : type(figure.type) {
	cout << "Вызван конструктор копирования Figure";
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

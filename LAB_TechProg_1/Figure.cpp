#include "Figure.h"

Figure::Figure(string type) : type(type) {
	cout << "Вызван конструктор типа объекта";
}

Figure::Figure(const Figure& figure) : type(figure.type) {
	cout << "Вызван конструктор объекта";
}

void Figure::print(string type, int objNumber) {
	cout << type << " " << objNumber << ":" << endl;
}

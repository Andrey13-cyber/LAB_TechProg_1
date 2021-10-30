#include "Figure2D.h"

double Figure2D::getSquareOrVolume() {

	size = width * lenght;
	double square = size;
	return square;

}

Figure2D::Figure2D(string type) : Figure(type) {
	cout << "Вызван конструктор типа объекта плоской фигуры";

}


void Figure2D::setSize(double size) {
	this->size = size;
}

double Figure2D::getSize() {
	return size;
}

Figure2D::Figure2D(const Figure2D& figure2d) : Figure(figure2d), size(figure2d.size), lenght(figure2d.lenght), width(figure2d.width), square(figure2d.square) {
	cout << "Вызван конструктор копирования плоской фигуры";

}

Figure2D::Figure2D(string type, double lenght, double width, double square): Figure(type), size(size),lenght(lenght), width(width),square(square)  {
	cout << "Вызван конструктор объекта плоской фигуры";

}

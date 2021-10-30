#include "Keeper.h"
#include "Figure.h"
#include "Figure2D.h"
#include "Figure3D.h"
#include <iostream>
#include<windows.h>

using namespace std;
void menu();
int errorProc(int minValue, int maxValue);



void menu() {
        cout << endl << "----------------------------" << endl;
        cout << endl << "      Главное меню   " << endl;
        cout << endl << "----------------------------" << endl;

        cout << "1. Выберите фигуру для работы " << endl;
        cout << "2. Ввести размеры фигуры" << endl;
        cout << "3. Посчитать площадь для плоской фигуры, объем для объемной фигуры" << endl;
        cout << "4. Показать информацию о фигуре" << endl;
        cout << "5. " << endl;
        cout << "0.Выход" << endl;
}

int errorProc(int minValue, int maxValue) {
    int place;
    while (1) {
        cin >> place;
        if (place < minValue || place > maxValue) {
            cout << "Некорректный ввод, введите еще раз -> ";
        }
        else
            return place;
    }

}

 void chooseFigure() {
    cout << "1. Прямоугольник" << endl;
    cout << "2. Шар(сфера)" << endl;
    cout << "0. Отмена" << endl;
}


int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
    cout << endl;

    menu();

    int step = 0;
    int selection;

    while (!step) {
        cout << endl;
        cout << "Введите пункт меню-> ";
        selection = errorProc(0, 4);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "Выход из программы. До свидания,пользователь :)";
            break;

        case 1:
            chooseFigure();
           
            break;

        case 2:
            
            break;

        case 3:
            
            break;

        case 4:
            
            break;
        }
    }
}
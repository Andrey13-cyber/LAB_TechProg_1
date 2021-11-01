#include "Keeper.h"
#include "Figure.h"
#include "Rect.h"
#include "Sphere.h"
#include <iostream>
#include<windows.h>

using namespace std;
void menu();
int errorProc(int minValue, int maxValue);
void addObject(Keeper<Figure*>& keeper);
void changeObject(Keeper<Figure*>& keeper);
void deleteObject(Keeper<Figure*>& keeper);
Figure* createObj(string name);
void printToConsole(Keeper<Figure*>& keeper);

void menu() {
        cout << endl << "----------------------------" << endl;
        cout << endl << "      Главное меню   " << endl;
        cout << endl << "----------------------------" << endl;

        /*cout << "1. Выберите фигуру для работы " << endl;
        cout << "2. Ввести размеры фигуры" << endl;
        cout << "3. Посчитать площадь для плоской фигуры, объем для объемной фигуры" << endl;
        cout << "4. Показать информацию о фигуре" << endl;
        cout << "5. " << endl;
        cout << "0.Выход" << endl;*/

        cout << "1. Добавить объект" << endl;
        cout << "2. Изменить объект" << endl;
        cout << "3. Удалить объект" << endl;
        cout << "4. Вывести данные на экран" << endl;
        cout << "5. Сохранить в файл" << endl;
        cout << "0. Выход" << endl;
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

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Keeper<Figure*> keeper;
    

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
            addObject(keeper);
            break;

        case 2:
            changeObject(keeper);
            break;

        case 3:
            deleteObject(keeper);
            break;

        case 4:
            printToConsole(keeper);
            
            break;
        }
    }
}


void addObject(Keeper<Figure*>& keeper)
{
    cout << "Выберете объект для добавления" << endl;
    cout << "1. Прямоугольник" << endl;
    cout << "2. Шар(сфера)" << endl;
    
    int typeObj = errorProc(1, 2);
    string typeFigure;
    if (typeObj == 1)
        typeFigure = "Прямоугольник";
    if (typeObj == 2)
        typeFigure = "Шар";
    Figure* object = createObj(typeFigure);
    object->inputFromConsole();
    keeper.pushback(object);
}

void changeObject(Keeper<Figure*>& keeper)
{
    if (keeper.getLenght() == 0)
        cout << "Контейнер пуст. Нечего изменять" << endl;
    else
    {
        printToConsole(keeper);
        cout << endl;
        cout << "Выберете номер объекта для изменения: ";
        int number = errorProc(1, keeper.getLenght());
        keeper[number - 1]->changeObject();
    }
}

void deleteObject(Keeper<Figure*>& keeper)
{
    if (keeper.getLenght() == 0)
        cout << "Контейнер пуст. Нечего удалять" << endl;
    else
    {
        printToConsole(keeper);
        cout << "Выберете номер объекта для удаления: ";
        int number = errorProc(1, keeper.getLenght());
        keeper.popindex(number - 1);
    }
}

Figure* createObj(string name)
{
    if (name == "Прямоугольник")
        return new Rect();
    if (name == "Шар")
        return new Sphere();
    string err = "Тип объекта не распознан";
    throw err;
}


void printToConsole(Keeper<Figure*>& keeper) {
    if (keeper.getLenght() == 0)
        cout << "Контейнер пуст" << endl;
    else
    {
        cout << "Содержимое контейнера: " << endl;
        for (int i = 0; i < keeper.getLenght() ; i++)
        {
            cout << endl;
            cout << i + 1 << ". ";
            keeper[i]->printToConsole();
        }
    }
}
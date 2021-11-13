#include "Keeper.h"
#include "Figure.h"
#include "Rect.h"
#include "Sphere.h"
#include <stdlib.h>
#include <iostream>

//#include <windows.h>

using namespace std;
void menu();
int errorProc(int minValue, int maxValue);
void addObject(Keeper<Figure*>& keeper);
void changeObject(Keeper<Figure*>& keeper);
void deleteObject(Keeper<Figure*>& keeper);
Figure* createObj(string name);
void printToConsole(Keeper<Figure*>& keeper);
void printToFile(Keeper<Figure*>& keeper);
void inputFromFile(Keeper<Figure*>& keeper);


void menu() {
    cout << endl << "----------------------------" << endl;
    cout << endl << "      Главное меню   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. Добавить объект" << endl;
    cout << "2. Изменить объект" << endl;
    cout << "3. Удалить объект" << endl;
    cout << "4. Вывести данные на экран" << endl;
    cout << "5. Сохранить данные в файл" << endl;
    cout << "6. Вывести данные из файла" << endl;
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
    int gm, gd = DETECT; //Переменные для инициализации графики
    char a[2] = " ";
    initgraph(&gd, &gm, a); //Поиск нужного графического драйвера


    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
    cout << endl;

    int step = 0;
    int selection;

    while (!step) {
        menu();
        cout << endl;
        cout << "Введите пункт меню-> ";
        selection = errorProc(0, 6);
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

        case 5:
            printToFile(keeper);
            break;
        case 6:
            try {
                inputFromFile(keeper);
            }
            catch (string err) {
                cout << err << endl;
            }
            break;
        }
    }
    closegraph();
}


void addObject(Keeper<Figure*>& keeper)
{
    cout << "Выберете объект для добавления: " << endl;
    cout << "1. Прямоугольник" << endl;
    cout << "2. Шар(сфера)" << endl;
    cout << "-> ";

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
        for (int i = 0; i < keeper.getLenght(); i++)
        {
            cout << endl;
            cout << i + 1 << ". ";
            keeper[i]->printToConsole();
        }
    }
}

void printToFile(Keeper<Figure*>& keeper)
{
    ofstream output("keeper.txt");
    output << keeper.getLenght() << endl;
    for (int i = 0; i < keeper.getLenght(); i++)
        keeper[i]->printToFile(output);
    output.close();
}


void inputFromFile(Keeper<Figure*>& keeper) {


    ifstream input("keeper.txt");
    if (input.is_open())
    {
        string fig;
        int countRecord;
        if (!getline(input, fig))
        {
            input.close();
            string err = "Файл не может быть прочитан";
            throw err;
        }
        countRecord = (checkStringToDouble(fig) ? stod(fig) : 0);
        try
        {
            for (int i = 0; i < countRecord; i++)
            {
                string err = "Файл не может быть корректно прочитан";
                if (!getline(input, fig))
                    throw err;
                Figure* object = createObj(fig);
                object->inputFromFile(input, fig);
                keeper.pushback(object);
            }
        }
        catch (string err)
        {
            input.close();
            throw err;
        }
        input.close();
    }
    else
    {
        string err = "Файл keeper.txt не найден";
        throw err;
    }
}
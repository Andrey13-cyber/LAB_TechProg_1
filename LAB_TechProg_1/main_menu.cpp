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
    cout << endl << "      ������� ����   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. �������� ������" << endl;
    cout << "2. �������� ������" << endl;
    cout << "3. ������� ������" << endl;
    cout << "4. ������� ������ �� �����" << endl;
    cout << "5. ��������� ������ � ����" << endl;
    cout << "6. ������� ������ �� �����" << endl;
    cout << "0. �����" << endl;
}

int errorProc(int minValue, int maxValue) {
    int place;
    while (1) {
        cin >> place;
        if (place < minValue || place > maxValue) {
            cout << "������������ ����, ������� ��� ��� -> ";
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
    int gm, gd = DETECT; //���������� ��� ������������� �������
    char a[2] = " ";
    initgraph(&gd, &gm, a); //����� ������� ������������ ��������


    cout << "����������,������������. �������� ������." << endl;
    cout << endl;

    int step = 0;
    int selection;

    while (!step) {
        menu();
        cout << endl;
        cout << "������� ����� ����-> ";
        selection = errorProc(0, 6);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "����� �� ���������. �� ��������,������������ :)";
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
    cout << "�������� ������ ��� ����������: " << endl;
    cout << "1. �������������" << endl;
    cout << "2. ���(�����)" << endl;
    cout << "-> ";

    int typeObj = errorProc(1, 2);
    string typeFigure;
    if (typeObj == 1)
        typeFigure = "�������������";
    if (typeObj == 2)
        typeFigure = "���";
    Figure* object = createObj(typeFigure);
    object->inputFromConsole();
    keeper.pushback(object);
}

void changeObject(Keeper<Figure*>& keeper)
{
    if (keeper.getLenght() == 0)
        cout << "��������� ����. ������ ��������" << endl;
    else
    {
        printToConsole(keeper);
        cout << endl;
        cout << "�������� ����� ������� ��� ���������: ";
        int number = errorProc(1, keeper.getLenght());
        keeper[number - 1]->changeObject();
    }
}

void deleteObject(Keeper<Figure*>& keeper)
{
    if (keeper.getLenght() == 0)
        cout << "��������� ����. ������ �������" << endl;
    else
    {
        printToConsole(keeper);
        cout << "�������� ����� ������� ��� ��������: ";
        int number = errorProc(1, keeper.getLenght());
        keeper.popindex(number - 1);
    }
}

Figure* createObj(string name)
{
    if (name == "�������������")
        return new Rect();
    if (name == "���")
        return new Sphere();
    string err = "��� ������� �� ���������";
    throw err;
}


void printToConsole(Keeper<Figure*>& keeper) {
    if (keeper.getLenght() == 0)
        cout << "��������� ����" << endl;
    else
    {
        cout << "���������� ����������: " << endl;
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
            string err = "���� �� ����� ���� ��������";
            throw err;
        }
        countRecord = (checkStringToDouble(fig) ? stod(fig) : 0);
        try
        {
            for (int i = 0; i < countRecord; i++)
            {
                string err = "���� �� ����� ���� ��������� ��������";
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
        string err = "���� keeper.txt �� ������";
        throw err;
    }
}
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
        cout << endl << "      ������� ����   " << endl;
        cout << endl << "----------------------------" << endl;

        cout << "1. �������� ������ ��� ������ " << endl;
        cout << "2. ������ ������� ������" << endl;
        cout << "3. ��������� ������� ��� ������� ������, ����� ��� �������� ������" << endl;
        cout << "4. �������� ���������� � ������" << endl;
        cout << "5. " << endl;
        cout << "0.�����" << endl;
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

 void chooseFigure() {
    cout << "1. �������������" << endl;
    cout << "2. ���(�����)" << endl;
    cout << "0. ������" << endl;
}


int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "����������,������������. �������� ������." << endl;
    cout << endl;

    menu();

    int step = 0;
    int selection;

    while (!step) {
        cout << endl;
        cout << "������� ����� ����-> ";
        selection = errorProc(0, 4);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "����� �� ���������. �� ��������,������������ :)";
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
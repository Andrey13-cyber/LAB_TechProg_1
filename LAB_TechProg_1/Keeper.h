#pragma once
#include <cassert>
#include<iostream>
using namespace std;

class Keeper
{
private:
	int mass_lenght;
	int* data;

public:
	Keeper() : mass_lenght(0), data(nullptr) {

	}

	Keeper(int lenght) : mass_lenght(lenght) {
		assert(lenght >= 0);

		if (lenght > 0)
			data = new int[lenght];
		else
			data = nullptr;
	}

	~Keeper() {
		delete[] data;
	}

	void cleanMass() {
		delete[] data;
		data = nullptr;
		mass_lenght = 0;
	}

	int& operator[](int index) {
		assert(index >= 0 && index < mass_lenght);
		return data[index];
	}

	int getLenght() {
		return mass_lenght;
	}

	
};


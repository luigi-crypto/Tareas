#pragma once
#include <iostream>
using namespace std;
template<typename Ti>
class MiDinamicArray
{
private:
	Ti* elementos;
	int capacidad;
	int count;
public:
	static const int maxCapacity = 1024;
	MiDinamicArray(int lol)
	{
		capacidad = lol;
		if (capacidad > 0)
			elementos = new Ti[capacidad];
		else
			elementos = nullptr;

		count = 0;
	}

	~MiDinamicArray()
	{
		if (capacidad > 0)
			delete[] elementos;
	}

	int& operator[](int i)
	{
		return elementos[i];
	}

	void push_back(Ti v)
	{
		if (count == capacidad)
		{
			int capacidadant = capacidad;
			if (capacidad == 0)
				capacidad = 1;
			else if (capacidad * 2 < maxCapacity)
				capacidad *= 2;
			else
			{
				cout << "ERROR: se excedió el tamaño máximo del dynamic array" << endl;
				return;
			}
			Ti* arrayConMasMemoria = new Ti[capacidad];
			for (int i = 0; i < capacidadant; i++)
			{
				arrayConMasMemoria[i] = elementos[i];
			}
			delete[] elementos;
			elementos = arrayConMasMemoria;
		}
		elementos[count] = v;
		count++;
	}
	void pop_back()
	{
		if (count > 0)
			count--;
		else
			cout << "ERROR: el array está vacío, no se puede quitar más elementos" << endl;
	}

	void shrink_to_fit()
	{

	}
	int i() { return count; }
};

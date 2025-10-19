#pragma once
#include <iostream>
using namespace std;

template<typename T>/*Creamos un template*/
void Printarray(T arr[], int tamano)/*Le decimos que va a tener una array y un tamaño*/
{
	for (int i = 0; i < tamano; i++)//un bucle for para recorrer el array
	{
		cout << arr[i] << " ";//e imprimirlo
	}
};
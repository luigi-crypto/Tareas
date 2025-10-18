#pragma once
#include <iostream>
using namespace std;

template<typename T>
void Printarray(T arr[], int tamano)
{
	for (int i = 0; i < tamano; i++)
	{
		cout << arr[i] << " ";
	}
};
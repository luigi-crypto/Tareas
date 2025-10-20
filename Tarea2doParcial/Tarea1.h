#pragma once
#include <iostream>
using namespace std;
template<typename Ti>/*Creamos una template class que como nuestra primer tarea solo que aqui es una clase*/
class MiDinamicArray
{
private:/*Atributos privados por cuestion de seguridad o algo asi dijo el profe*/
	Ti* elementos;//Nuestro puntero
	int capacidad;
	int count;
public:
	static const int maxCapacity = 1024;/*Esto lo vi en el .h del profe y despues vi para que era y es para ponerle un limite a nuestra array*/
	MiDinamicArray(int lol)/*lol como variable temporal*/
	{
		capacidad = lol;/*Aquí lol toma el tamaño de capacidad*/
		if (capacidad > 0)/*Si capacidad es mayor a cero*/
			elementos = new Ti[capacidad];/*Pedimos más memoria y nos da la direccion de memoria del primer elemento*/
		else
			elementos = nullptr;/*Si no nuestros elementos no apunta a nada*/

		count = 0;
	}

	~MiDinamicArray()/*Destructor para liberar memoria*/
	{
		if (capacidad > 0)
			delete[] elementos;
	}

	int& operator[](int i)/*Sobre carga de operador [] para poder modificar el array facilmente*/
	{
		return elementos[i];
	}

	void push_back(Ti v)//Añadir un elemento al final del array
	{
		if (count == capacidad)//Si el conteo es igual a la capacidad
		{
			int capacidadant = capacidad;//Guardamos la capacidad anterior
			if (capacidad == 0)//Si la capacidad es igual a cero
				capacidad = 1;//La capacidad sera igual a 1
			else if (capacidad * 2 < maxCapacity)//Si la capacidad por 2 es menor al maximo de capacidad
				capacidad *= 2;//La capacidad se multiplica por 2
			else
			{
				cout << "ERROR: se excedió el tamaño máximo del dynamic array" << endl;
				return;
			}
			Ti* arrayConMasMemoria = new Ti[capacidad];//Pedimos más memoria
			for (int i = 0; i < capacidadant; i++)//Copiamos los elementos al nuevo array
			{
				arrayConMasMemoria[i] = elementos[i];//Copiamos los elementos
			}
			delete[] elementos;//Liberamos la memoria del array viejo
			elementos = arrayConMasMemoria;//Asignamos el nuevo array al puntero de elementos
		}
		elementos[count] = v;//Asignamos el valor al final del array
		count++;//Incrementamos el conteo
	}
	void pop_back()//Quitar el ultimo elemento del array
	{
		if (count > 0)//Si el conteo es mayor a cero
			count--;//Decrementamos el conteo
		else
			cout << "ERROR: el array está vacío, no se puede quitar más elementos" << endl;
	}

	void shrink_to_fit()
	{
		if (capacidad > count)  // solo si hay espacio de sobra
		{
			capacidad = count;                // la capacidad ahora será igual al número de elementos
			Ti* nuevo = new Ti[capacidad];    // reservamos un nuevo bloque de memoria exacto

			for (int i = 0; i < count; i++)   // copiamos los datos
			{
				nuevo[i] = elementos[i];
			}

			delete[] elementos;   // liberamos la memoria vieja
			elementos = nuevo;    // apuntamos al nuevo bloque
		}
	}
	int i() { return count; }
};

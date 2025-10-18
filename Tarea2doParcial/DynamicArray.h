#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Un array que incrementa su tamaño automáticamente cuando se intenta insertar un elemento en él,
/// pero ya está lleno.
/// </summary>
class DynamicArray
{
public:
	static const int maxCapacity = 1024;

	DynamicArray(int capacity = 0);

	~DynamicArray();

	//Append(x) añadir el valor x en la posición última que se ha ocupado del array.
	// si ya está lleno el arreglo, manda a incrementar su tamaño automáticamente.
	void Append(const int value) 
	{
		if (count == capacity)
		{
			int oldCapacity = capacity;
			if (capacity == 0)
				capacity = 1;
			else if (capacity * 2 < maxCapacity)
				capacity *= 2;
			else
			{
				cout << "ERROR: se excedió el tamaño máximo del dynamic array" << endl;
				return;
			}
			// capacity = capacity == 0 ? 1 : capacity * 2; // este sería el if de una línea que equivale al if-else de arriba
			
			// entonces está lleno y hay que pedir más memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			int *arrayConMasMemoria = new int[capacity]; // trae el doble de memoria
			for (int i = 0; i < oldCapacity; i++)
			{
				arrayConMasMemoria[i] = elements[i];
			}
			delete[] elements;

			// reasignamos nuestra variable interna de elements, a que apunte a la dirección del arreglo nuevo con más memoria.
			elements = arrayConMasMemoria;

			// En otras palabras, mandar a llamar la función Resize()
		}
		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos más.
	}

	bool InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
	{
		// un for para buscar el índice del valor a encontrar
		for (int i = 0; i < count; i++)
		{
			if (valorAEncontrar == elements[i])
			{
				// además, tenemos que checar si se necesita hacer el resize. 
				// si sí se necesita pues lo haces.
				if (count == capacity)
				{
					int oldCapacity = capacity;
					if (capacity == 0)
						capacity = 1;
					else if (capacity * 2 < maxCapacity)
						capacity *= 2;
					else
					{
						cout << "ERROR: se excedió el tamaño máximo del dynamic array" << endl;
						return false;
					}
					// capacity = capacity == 0 ? 1 : capacity * 2; // este sería el if de una línea que equivale al if-else de arriba

					// entonces está lleno y hay que pedir más memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
					int* arrayConMasMemoria = new int[capacity]; // trae el doble de memoria
					for (int i = 0; i < oldCapacity; i++)
					{
						arrayConMasMemoria[i] = elements[i];
					}
					delete[] elements;

					// reasignamos nuestra variable interna de elements, a que apunte a la dirección del arreglo nuevo con más memoria.
					elements = arrayConMasMemoria;

					// En otras palabras, mandar a llamar la función Resize()
				}

				// entonces ya lo encontramos y hay que poner que i+1 es igual a valorAInsertar
				// pero para no perder los valores que ya estaban hay que recorrer todos los 
				// demás elementos una posición a la derecha, empezando desde el final
				for (int j = count; j > i; j--)
				{
					elements[j] = elements[j - 1];
				}
				// finalmente ponemos el valor a insertar en la posición i+1
				elements[i + 1] = valorAInsertar;
				count++;
				return true;
			}
		}
		return false;
	}

	// Insertar 0, después de 1
	// [1, 2, 3, 4, 5, X, X, X]
	// [1, 0, 2, 3, 4, 5, X, X]

	int ObtenerElemento(const size_t indice) const
	{
		if (indice < capacity)
			return elements[indice];
		else
			cout << "ERROR, se intentó obtener un valor en una posición inválida de este array. Posición: "
			<< indice << endl;
		return -INFINITY;
	}

	//unsigned variable sin signo (no puede ser negativo jamás)
	// size_t es un unsigned long long, es decir, un número de 64 bits (enorme) que no puede ser negativo
	// si usamos size_t para índices de arrays, no nos tenemos que preocupar por que sean valores negativos.
	void AsignarElemento(const size_t indice, const int valor)
	{
		if (indice < capacity)
			elements[indice] = valor;
		else
			cout << "ERROR, se intentó escribir un valor en una posición inválida de este array. Posición: "
			<< indice << endl;
	}

	// te regresa el índice de la posición en el array donde hay un elemento con valor == value
	int BuscarElemento(const int valor) const
	{
		for (int i = 0; i < count; i++)
		{
			if (elements[i] == valor)
				return i;
		}
		// si sale del for es porque checamos todos los elementos y ninguno fue == valor.
		return -1;
	}

	int QuitarUltimoElemento()
	{
		// si sí hay al menos un elemento, entonces sí lo podemos sacar.
		if (count > 0)
		{
			count--; // nos basta hacer esto para que ese último elemento ya no se pueda acceder.
			return elements[count];
		}

		// no se necesita el else porque si entró al if de arriba entonces ya va a hacer return y no
		// llegaría a esta parte del código.
		cout << "ERROR el dynamic array estaba vacío pero se intentó sacar un elemento de él." << endl;
		return -INFINITY;
	}

	// Sirve para iterar sobre los elementos que tiene el array.
	int GetCount() const
	{
		return count;
	}

	void Print() const
	{
		cout << "imprimiendo Array: " << endl;  // aporta 1 línea ejecutada
		for (int i = 0; i < count; i++)			// aporta count líneas ejecutadas (porque i va desde 0 hasta count)
			cout << elements[i] << ", ";		// aporta count líneas ejecutadas porque está dentro del for que va de 0 hasta count
		cout << endl;							// aporta 1 línea ejecutada
		// 1 + count + count + 1 = 2 + count*2
		// count = 10 -> 2 + count*2 = 2 + (10)*2 == 22
		// count = 1000 -> 2 + count*2 = 2 + (1000)*2 == 2002
		// La complejidad en tiempo de esta función está dictada por la cantidad de elementos en count.
		// por cada elemento en count que haya, se ejecuta x-líneas más, donde x son la cantidad de líneas dentro del for.
	}

	// si yo tengo count = 10, se ejecutan en total 22 líneas de código en Print.
	// ¿si count fuera 1000, cuántas líneas se ejecutarían?

private:
	// IMPORTANTE: las propiedades de elements, count, y capacity son privadas FORZOSAMENTE, por seguridad.

	// ¿Dónde almacenamos esos N elementos? D: 
	// No lo podemos guardar en una variable de tipo primitivo, float, int, char, etc. ahí solo cabe un valor.
	// No lo podemos guardar en un array[10] porque esa cosa tiene únicamente y para siempre 10 elementos. Es un array de tamaño estático.
	// Usamos memoria dinámica para almacenar esos elementos. Porque es un array de tamaño dinámico.
	int* elements;

	// Count, es una propiedad que nos dice cuántos elementos hay dentro del array.
	int count;

	// Capacity, qué tamaño tiene realmente el array (tanto usado como vacío).
	int capacity;

	// Resize(X), es el que se encarga de cambiar el tamaño dinámicamente.
	// esto involucra el proceso de:
	// 1) Pedir memoria para el nuevo arreglo más grande.
	// 2) copiar los elementos del viejo arreglo al nuevo arreglo.
	// 3) borrar el viejo arreglo.

};

void DemostracionDynamicArray();
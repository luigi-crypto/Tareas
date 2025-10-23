#pragma once

#include <iostream>
#define COUNT_DYNAMIC_ARRAY_COPIES 1
using namespace std;

/// <summary>
/// Un array que incrementa su tama�o autom�ticamente cuando se intenta insertar un elemento en �l,
/// pero ya est� lleno.
/// </summary>
class DynamicArray
{
public:
	static const int maxCapacity = 1024;

	DynamicArray(int capacity = 0);

	~DynamicArray();

	//Append(x) a�adir el valor x en la posici�n �ltima que se ha ocupado del array.
	// si ya est� lleno el arreglo, manda a incrementar su tama�o autom�ticamente.
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
				cout << "ERROR: se excedi� el tama�o m�ximo del dynamic array" << endl;
				return;
			}
			// capacity = capacity == 0 ? 1 : capacity * 2; // este ser�a el if de una l�nea que equivale al if-else de arriba

			// entonces est� lleno y hay que pedir m�s memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
			int* arrayConMasMemoria = new int[capacity]; // trae el doble de memoria
			for (int i = 0; i < oldCapacity; i++)
			{
				arrayConMasMemoria[i] = elements[i];
				/*TAREA 3.1 AUMENTAR SU VALOR*/
#if COUNT_DYNAMIC_ARRAY_COPIES//aqui tambien
				copyCounter++;//aumentamos el contador
#endif
			}
			delete[] elements;

			// reasignamos nuestra variable interna de elements, a que apunte a la direcci�n del arreglo nuevo con m�s memoria.
			elements = arrayConMasMemoria;

			// En otras palabras, mandar a llamar la funci�n Resize()
		}
		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos m�s.
	}

	bool InsertarDespuesDeValor(int valorAEncontrar, int valorAInsertar)
	{
		// un for para buscar el �ndice del valor a encontrar
		for (int i = 0; i < count; i++)
		{
			if (valorAEncontrar == elements[i])
			{
				// adem�s, tenemos que checar si se necesita hacer el resize. 
				// si s� se necesita pues lo haces.
				if (count == capacity)
				{
					int oldCapacity = capacity;
					if (capacity == 0)
						capacity = 1;
					else if (capacity * 2 < maxCapacity)
						capacity *= 2;
					else
					{
						cout << "ERROR: se excedi� el tama�o m�ximo del dynamic array" << endl;
						return false;
					}
					// capacity = capacity == 0 ? 1 : capacity * 2; // este ser�a el if de una l�nea que equivale al if-else de arriba

					// entonces est� lleno y hay que pedir m�s memoria, copiar el arreglo actual al nuevo, y borrar el viejo.
					int* arrayConMasMemoria = new int[capacity]; // trae el doble de memoria
					for (int i = 0; i < oldCapacity; i++)
					{
						arrayConMasMemoria[i] = elements[i];
						/*TAREA 3.1 AUMENTAR SU VALOR*/
#if COUNT_DYNAMIC_ARRAY_COPIES//aqui tambien
						copyCounter++;//aumentamos el contador
#endif
					}
					delete[] elements;

					// reasignamos nuestra variable interna de elements, a que apunte a la direcci�n del arreglo nuevo con m�s memoria.
					elements = arrayConMasMemoria;

					// En otras palabras, mandar a llamar la funci�n Resize()
				}

				// entonces ya lo encontramos y hay que poner que i+1 es igual a valorAInsertar
				// pero para no perder los valores que ya estaban hay que recorrer todos los 
				// dem�s elementos una posici�n a la derecha, empezando desde el final
				for (int j = count; j > i; j--)
				{
					elements[j] = elements[j - 1];
				}
				// finalmente ponemos el valor a insertar en la posici�n i+1
				elements[i + 1] = valorAInsertar;
				count++;
				return true;
			}
		}
		return false;
	}

	// Insertar 0, despu�s de 1
	// [1, 2, 3, 4, 5, X, X, X]
	// [1, 0, 2, 3, 4, 5, X, X]

	int ObtenerElemento(const size_t indice) const
	{
		if (indice < capacity)
			return elements[indice];
		else
			cout << "ERROR, se intent� obtener un valor en una posici�n inv�lida de este array. Posici�n: "
			<< indice << endl;
		return -INFINITY;
	}

	//unsigned variable sin signo (no puede ser negativo jam�s)
	// size_t es un unsigned long long, es decir, un n�mero de 64 bits (enorme) que no puede ser negativo
	// si usamos size_t para �ndices de arrays, no nos tenemos que preocupar por que sean valores negativos.
	void AsignarElemento(const size_t indice, const int valor)
	{
		if (indice < capacity)
			elements[indice] = valor;
		else
			cout << "ERROR, se intent� escribir un valor en una posici�n inv�lida de este array. Posici�n: "
			<< indice << endl;
	}

	// te regresa el �ndice de la posici�n en el array donde hay un elemento con valor == value
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
		// si s� hay al menos un elemento, entonces s� lo podemos sacar.
		if (count > 0)
		{
			count--; // nos basta hacer esto para que ese �ltimo elemento ya no se pueda acceder.
			return elements[count];
		}

		// no se necesita el else porque si entr� al if de arriba entonces ya va a hacer return y no
		// llegar�a a esta parte del c�digo.
		cout << "ERROR el dynamic array estaba vac�o pero se intent� sacar un elemento de �l." << endl;
		return -INFINITY;
	}

	// Sirve para iterar sobre los elementos que tiene el array.
	int GetCount() const
	{
		return count;
	}

	void Print() const
	{
		cout << "imprimiendo Array: " << endl;  // aporta 1 l�nea ejecutada
		for (int i = 0; i < count; i++)			// aporta count l�neas ejecutadas (porque i va desde 0 hasta count)
			cout << elements[i] << ", ";		// aporta count l�neas ejecutadas porque est� dentro del for que va de 0 hasta count
		cout << endl;							// aporta 1 l�nea ejecutada
		// 1 + count + count + 1 = 2 + count*2
		// count = 10 -> 2 + count*2 = 2 + (10)*2 == 22
		// count = 1000 -> 2 + count*2 = 2 + (1000)*2 == 2002
		// La complejidad en tiempo de esta funci�n est� dictada por la cantidad de elementos en count.
		// por cada elemento en count que haya, se ejecuta x-l�neas m�s, donde x son la cantidad de l�neas dentro del for.
	}

	// si yo tengo count = 10, se ejecutan en total 22 l�neas de c�digo en Print.
	// �si count fuera 1000, cu�ntas l�neas se ejecutar�an?

private:
	// IMPORTANTE: las propiedades de elements, count, y capacity son privadas FORZOSAMENTE, por seguridad.

	// �D�nde almacenamos esos N elementos? D: 
	// No lo podemos guardar en una variable de tipo primitivo, float, int, char, etc. ah� solo cabe un valor.
	// No lo podemos guardar en un array[10] porque esa cosa tiene �nicamente y para siempre 10 elementos. Es un array de tama�o est�tico.
	// Usamos memoria din�mica para almacenar esos elementos. Porque es un array de tama�o din�mico.
	int* elements;

	// Count, es una propiedad que nos dice cu�ntos elementos hay dentro del array.
	int count;

	// Capacity, qu� tama�o tiene realmente el array (tanto usado como vac�o).
	int capacity;

	// Resize(X), es el que se encarga de cambiar el tama�o din�micamente.
	// esto involucra el proceso de:
	// 1) Pedir memoria para el nuevo arreglo m�s grande.
	// 2) copiar los elementos del viejo arreglo al nuevo arreglo.
	// 3) borrar el viejo arreglo.


	/*TAREA 3.1//////////////DECLARAR LA VARIABLE copyCounter//////////////////*/
#if COUNT_DYNAMIC_ARRAY_COPIES/*Segun yo esto es para que se pueda acceder por que es privada*/
	int copyCounter;//inicializamos la variable
#endif

};

template<typename Ti>
class MiDinamicArray
{
private:
	Ti* elementos;
	int capacidad;
	int count;
public:
	static const int maxCapacity = 1024;

	MiDinamicArray(int lol = 0)
		: elementos(nullptr), capacidad(lol), count(0)
	{
		if (capacidad > 0)
			elementos = new Ti[capacidad];
	}

	~MiDinamicArray()
	{
		delete[] elementos;
	}

	// devolver elemento por referencia para poder leer/escribir
	Ti& operator[](int i)
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
		if (capacidad > count)
		{
			int newCap = (count == 0) ? 0 : count;
			if (newCap == 0)
			{
				delete[] elementos;
				elementos = nullptr;
				capacidad = 0;
				return;
			}
			Ti* nuevo = new Ti[newCap];
			for (int i = 0; i < count; i++)
				nuevo[i] = elementos[i];
			delete[] elementos;
			elementos = nuevo;
			capacidad = newCap;
		}
	}

	int i() const { return count; }

	void DemostracionDynamicArray();
};
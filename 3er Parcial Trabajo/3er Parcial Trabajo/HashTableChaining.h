#pragma once

#include "LinkedList.h"


template <typename T>
class HashTableChaining
{
public:
	HashTableChaining(size_t _numeroDeListas)
	{
		numeroDeListas = _numeroDeListas;
		if (_numeroDeListas == 0)
		{
			arrayDeListasLigadas = nullptr;
			return;
		}

		arrayDeListasLigadas = new LinkedList<T>[numeroDeListas];
	}

	virtual ~HashTableChaining()//el destructyor lo hacemos virtual para la herencia
	{
		if (arrayDeListasLigadas != nullptr)
		{
			delete[] arrayDeListasLigadas;
		}
	}

	virtual void Add(T value)
	{
		// Inserta el elemento con valor 'value' en el índice que nos dice la función hash.
		size_t indice = FuncionHash(value);
		arrayDeListasLigadas[indice].PushBack(value);
	}

	bool BorrarValor(T value)
	{
		size_t indice = FuncionHash(value);
		return arrayDeListasLigadas[indice].BorrarNodoPorValor(value);
	}

	bool Encontrar(T value)
	{
		size_t indice = FuncionHash(value);
		return arrayDeListasLigadas[indice].Encontrar(value);
	}

	void Imprimir()
	{
		// Por cada cubeta
		for (int i = 0; i < numeroDeListas; i++)
		{
			if (arrayDeListasLigadas[i].GetCount() == 0)
			{
				cout << "vacia" << endl;
			}
			else
				arrayDeListasLigadas[i].Print();
		}
	}

private:

	// Recibe una llave (del tipo de dato 'T' que almacena esta tabla) y 
	// retorna un entero que es el índice de en qué espacio de arrayDeListasLigadas debe estar.
	size_t FuncionHash(T llave)
	{
		if constexpr (is_same_v<T, string>)
		{
			// entonces sí es una string.
			string llaveString = static_cast<string>(llave);
			return ((size_t)llaveString[0] - 65); // 65 es el código de la A mayúscula en ASCII
		}
		else
		{
			// NOTA: esto (en teoría) solo debería funcionar para valores numéricos, no para otros tipos de dato.
			return llave % numeroDeListas;
		}
	}

	// Dijimos que tiene N índices, y en cada uno de esos índices tiene un contenedor,
	// en este caso, una lista ligada (linkedList)
	LinkedList<T>* arrayDeListasLigadas;
	// Normalmente a esos N índices les llaman "buckets" o cubetas.

	// Variable que nos dice cuántos índices tiene esta hash table. Para saber hasta dónde se puede acceder 
	// con el puntero de arrayDeListasLigadas.
	size_t numeroDeListas;

};

void DemostracionHashTableChaining();
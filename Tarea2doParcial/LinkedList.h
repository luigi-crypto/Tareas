#pragma once
#include <iostream>
using namespace std;

// Las cosas templates S� pueden dejar la declaraci�n Y definici�n en el .h

//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* next;
//};
//
//template <typename T>
//class Node
//{
//	T data;
//	Node<T>* parent;
//	Node<T>* right;
//	Node<T>* left;
//};


template <typename T>
class LinkedList
{
public:
	LinkedList()
	{
		count = 0; // si inicia vac�a, su count ser�a 0.
		// y si va a empezar vac�a, no necesitamos pedir memoria para el primer elemento.
		first = nullptr; // como no se va a usar ahorita todav�a, lo ponemos como nullptr.
	}
	// nada m�s por el est�ndar de c�mo se llama la funci�n en las listas ligadas.
	void PushBack(const T value)
	{
		Append(value);
	}

	// A�ade un nodo con el valor "value" al final de la lista ligada.
	void Append(const T value)
	{
		// tenemos que checar el caso en el que first es nullptr. Es decir, cuando la lista est� vac�a.
		if (first == nullptr)
		{
			first = new Node(value);
			count++;
			return; // ya lo pusimos al frente y despu�s de �l es nullptr, entonces ya es el primero de la lista (y tambi�n el �ltimo)
		}

		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		// y avanzamos el "next" de los nodos, hasta el final de la lista (cuando el next del nodo actual sea nullptr)
		// nodoActual se va convirtiendo en SU next hasta que ya sea nullptr.
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// cuando se sale de este while, es que ya llegamos al final de la lista.
		// y entonces a�adimos un nuevo nodo con el valor value.
		Node* nuevoNodo = new Node(value);
		// El nodo que antes era el �ltimo, ahora es el pen�ltimo, 
		// y nuevoNodo es el �ltimo (porque su next es nullptr).
		nodoActual->next = nuevoNodo;
		count++;
	}

	// por ejemplo: insertar "Pepe" despu�s de "Juan"
	bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
	{
		// encontrar el nodo donde est� valorAEncontrar
		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		// y avanzamos el "next" de los nodos, checando si su valor es valorAEncontrar,
		// 
		// y si no lo encontramos, regresamos false porque nunca lo encontramos.		// 
		while (nodoActual != nullptr)
		{
			// checamos si este nodo tiene el valorAEncontrar
			if (nodoActual->data == valorAEncontrar)
			{
				// si s� lo es, pues insertamos el nuevo valor despu�s de este.
				// primero creamos un nuevo nodo que va a tener el valorAInsertar
				Node* newNode = new Node(valorAInsertar);
				// el nuevo->next ahora al que antes apuntaba nodoActual->next
				newNode->next = nodoActual->next;

				// el nodoActual->next ahora apunta al nuevo
				nodoActual->next = newNode;

				count++;

				// como ya lo insertamos, ya no hay nada que hacer y nos salimos.
				return true;
			}

			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// ya no hay m�s nodos que checar, no se encontr� entonces no insertamos nada y regresamos false.
		cout << "Advertencia, no existe el valor: " << valorAEncontrar << " en esta lista ligada" << endl;
		return false;
	}

	// Funci�n que nos quite el primer nodo que tenga el valor dado.
	bool BorrarNodoPorValor(const T valorDelNodoABorrar)
	{
		if (count == 0)
		{
			// no hay nada que borrar porque est� vac�a.
			cout << "Advertencia, tratando de borrar de una lista ligada vac�a en BorrarNodoPorValor()." << endl;
			return false;
		}
		// hay que encontrar el primer nodo que tenga data == valorDelNodoABorrar
		// encontrar el nodo donde est� valorAEncontrar
		// comenzamos al inicio de la lista (el nodo first)
		Node* nodoActual = first;
		if (nodoActual->data == valorDelNodoABorrar)
		{
			// es un caso especial porque hay que reasignar al first.

			first = nodoActual->next;
			delete nodoActual;
			if (count == 1)
				first = nullptr;
			count--;
			return true;
		}

		while (nodoActual->next != nullptr)
		{
			// checamos si EL NODO QUE SIGUE este nodo es a quien buscamos (el que tiene valorDelNodoABorrar)
			if (nodoActual->next->data == valorDelNodoABorrar)
			{
				// s� lo encontramos, entonces lo borramos.
				Node* nodoABorrar = nodoActual->next;
				// el nodo actual apunta al que sigue del que sigue

				nodoActual->next = nodoActual->next->next;

				// y ahora s� borramos a ese nodo auxiliar.
				delete nodoABorrar;

				count--;
				return true;
			}

			nodoActual = nodoActual->next; // el nodo actual se mueve al que le sigue en la lista.
		}

		// si se acaba el while, entonces no lo encontramos, 


		// entonces no borramos nada y regresamos false.
		cout << "Advertencia, no existe el valor: " << valorDelNodoABorrar << " en esta lista ligada" << endl;
		return false;
	}

	// regresa el valor almacenado en el nodo del inicio de la lista ligada
	T Front()
	{
		if (first != nullptr)
			return first->data;

		// si s� es nulo, entonces le imprimes un error al usuario: 
		cout << "Advertencia se pidi� el front de la lista ligada pero est� vac�a." << endl;
		return T{}; // regresamos el valor T por defecto, seg�n el tipo que sea T.
	}

	// regresa el valor almacenado en el nodo al final de la lista ligada
	T Back()
	{
		if (count == 0)
		{
			cout << "Advertencia se pidi� el Back de la lista ligada pero est� vac�a." << endl;
			return T{}; // regresamos el valor T por defecto, seg�n el tipo que sea T.
		}

		// ciclo para llegar hasta el �ltimo nodo de la lista.
		Node* nodoActual = first;
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next;
		}

		// ya llegamos al final, entonces regresamos la data de ese nodo.
		return nodoActual->data;
	}

	// funci�n que nos da el valor (los datos) del Nodo i-�simo de la lista.
	T GetByIndex(const size_t indice) const  // como es size_t no puede ser negativo.
	{
		if (indice >= count)
		{
			cout << "ERROR: intentando acceder a un nodo con un �ndice inv�lido." << endl;
			return T{}; // retornamos un valor por defecto.
		}

		// necesitamos acceder desde el first, 
		Node* nodoActual = first;

		// y desde �l avanzar n posiciones, hacer n movimientos hacia el next, con n = indice.
		for (int i = 0; i < indice; i++)
		{
			nodoActual = nodoActual->next;
		}
		// ya llegaste al i-�simo que te pidieron, y retornas su valor
		return nodoActual->data;
	}

	~LinkedList()
	{
		Node* current = first;
		Node* nextNode = nullptr;
		while (current != nullptr)
		{
			nextNode = current->next; // 1. Guardar el puntero al siguiente nodo.
			delete current;          // 2. Liberar la memoria del nodo actual.
			current = nextNode;      // 3. Mover al siguiente nodo.
		}
		first = nullptr;
		count = 0;
	}

	/* LAS DE TAREA */
	//  https://cplusplus.com/reference/.
	 void PushFront(const T& data)
	{
		 Node* nuevoNodo = new Node(data);
		 nuevoNodo->next = first;
		 first = nuevoNodo;
		 count++;
	}

	 void PopFront()
	{
		if (first == nullptr)
		{
			return;
		}

	Node* nodoeliminar = first;
	first = first->next;
	delete nodoeliminar;
	count--;
	}

	 void Print()
	{
		Node* nodoActual = first;
		while (nodoActual != nullptr)
		{
			cout << nodoActual->data << " ";
			nodoActual = nodoActual->next;
		}
		cout << endl;
	}

	// Encontrar d�nde nos falta liberar memoria en esta clase. Si s� hace falta implem�ntenlo, 
	// si no hace falta, expliquen por qu�.

private:
	// clase anidada.
	// Sirve para que este node en espec�fico solo exista dentro de las funciones de la clase LinkedList.
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cu�l nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el �ltimo de la lista.
	};

	Node* first; // el puntero al primer nodo de nuestra lista.
	int count; // cu�ntos elementos tiene dentro esta lista.

};

void DemostracionLinkedList();
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SentinelLinkedList
{
public:
	SentinelLinkedList()
	{
		// El nodo NIL tiene un data X por defecto (no importa)
		NIL = new Node(T{});
		// NIL se apunta a sí mismo tanto hacia adelante como hacia atrás.
		NIL->next = NIL;
		NIL->prev = NIL;
		count = 0;
	}

	~SentinelLinkedList()
	{
		// ¡OJO! El nodo centinela solamente se borra cuando se borra la lista.
		Node* nodoActual = NIL->next;
		while (nodoActual != NIL)
		{
			Node* nodoABorrar = nodoActual;
			nodoActual = nodoActual->next;
			delete nodoABorrar;
		}

		delete NIL;
		cout << "Sentinel linked list destruida con éxito" << endl;
	}

	// En esta versión no necesita ningún tipo de chequeo. Además es tiempo constante O(1)
	void Append(T value)
	{
		Node* newNode = new Node(value);

		// el que es el último nodo antes de insertar el nuevo ahora apunta al nuevo hacia adelante
		// OJO: el previo de NIL es el último nodo.
		NIL->prev->next = newNode;
		
		// el nuevo nodo apunta al anterior último hacia atrás
		newNode->prev = NIL->prev;

		// NIL ahora hacia atrás apunta al nuevo nodo.
		NIL->prev = newNode;

		// El nuevo nodo apunta a NIL hacia adelante
		newNode->next = NIL;
		count++;
	}

	// Función PopBack quita y borra el último elemento de la Lista y regresa su valor.
	T PopBack()
	{
		// tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de hacer PopBack de una lista vacía." << endl;
			return T{}; // regresamos un valor por defecto.
		}

		// El nodo final es el prev de NIL. 
		Node* nodoABorrar = NIL->prev;
		T valorDelNodoABorrar = nodoABorrar->data;

		// hace las reconexiones entre prev's y next's y reduce el count en 1.
		Delete(nodoABorrar);

		// Regresamos el valor que almacena dicho nodo.
		return valorDelNodoABorrar;
	}

	// Función Front devuelve el valor del primer elemento de la lista
	T Front()
	{
		// tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el front de una lista vacía." << endl;
			return T{}; // regresamos un valor por defecto.
		}
		// El nodo inicial es el next de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->next->data;
	}

	// Back devuelve el valor del último elemento de la lista.
	T Back()
	{
		// tenemos que checar que no esté vacía la lista.
		if (count == 0)
		{
			cout << "Error, trataron de sacar el Back de una lista vacía." << endl;
			return T{}; // regresamos un valor por defecto.
		}
		// El nodo final es el prev de NIL. Regresamos el valor que almacena dicho nodo.
		return NIL->prev->data;
	}

	// Regresa true si hay al menos un nodo con dicho value, y falso si no.
	bool Contains(T value)
	{
		Node* nodoEncontrado = Search(value);
		// si no encontramos el nodo, entonces regresamos false
		if (nodoEncontrado == nullptr)
			return false;
		// si sí lo encontramos, regresamos true.
		return true;

		// return nodoEncontrado != nullptr;
	}

	// Nos regresa los datos guardados el nodo en la i-ésima posición desde el inicio.
	T ObtenerValorPorIndice(size_t indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un índice inválido:" << indice << endl;
			return T{};
		}

		Node* nodoActual = NIL->next;
		for (int i = 0; i < indice; i++)
			nodoActual = nodoActual->next;

		return nodoActual->data;
	}
	
	// versión inventada que trata de llegar más rápido al índice dependiendo de si está en la mitad de atrás
	// o en la mitad de adelante.
	T ObtenerValorPorIndiceOptimizada(int indice)
	{
		if (indice >= count)
		{
			cout << "Error, trataron de acceder a un índice inválido:" << indice << endl;
			return T{};
		}

		// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] // 10 nodos
		// dame el 9no tú tienes que hace 9 iteraciones
		// pero si empezaras desde el final, solo tendrías que hacer una iteración
		// si ese índice es mayor que la mitad del count, entonces empieza desde el final.
		// y ahora tenemos que hacer count-índice iteraciones.
		Node* nodoActual = nullptr;
		if(indice < count/2)
		{
			nodoActual = NIL->next;
			for (int i = 0; i < indice; i++)
				nodoActual = nodoActual->next;
		}
		else
		{
			int iteraciones = count - indice;
			nodoActual = NIL->prev;
			for (int i = 0; i < iteraciones; i++)
				nodoActual = nodoActual->prev;
		}
		
		return nodoActual->data;
	}


	void DeleteByValue(T value)
	{
		Node* nodoABorrar = Search(value);
		// si es nullptr, no se encontró un nodo con ese value, entonces no hay nada que borrar.
		if (nodoABorrar == nullptr)
		{
			cout << "no se encontró el valor a borrar: " << value << " en esta lista con centinela." << endl;
			return;
		}

		Delete(nodoABorrar);
	}

	/* FUNCIONES PARA EL EXAMEN QUE SE ENTREGA A MÁS TARDAR EL JUEVES 6 DE NOVIEMBRE A LAS 11:59 PM*/
	void PushFront(T value)
	{
		//Crea el nuevo nodo
		Node* newNode = new Node(value);

		//Identifica al que era el primer nodo
		Node* oldFirst = NIL->next;

		//Conecta el nuevo nodo en su lugar
		newNode->next = oldFirst;  // El nuevo nodo apunta hacia adelante a oldFirst
		newNode->prev = NIL;       // El nuevo nodo apunta hacia atrás a NIL

		NIL->next = newNode;       // El Centinela ahora apunta hacia adelante a newNode (es el nuevo primero)
		oldFirst->prev = newNode;  // El que ERA primero ahora apunta hacia atrás a newNode

		//Actualiza el contador
		count++; 
	}

	T PopFront()
	{
		// Checar si esta vacia
		if (count == 0) // o if (NIL->next == NIL) en ambas funcionaria igual
		{
			cout << "Error, trataron de hacer PopFront de una lista vacia." << endl;
			return T{};
		}
		// Si no está vacia continua con la logica
		Node* nodoABorrar = NIL->next;
		T valor = nodoABorrar->data;

		Delete(nodoABorrar);//esta es su funcion que reconecta lod nodos
		delete nodoABorrar;//esta libera la memoria
		return valor;
	}
	/* FIN DE FUNCIONES PARA EL EXAMEN QUE SE ENTREGA A MÁS TARDAR EL JUEVES 6 DE NOVIEMBRE A LAS 11:59 PM*/


private:
	// clase anidada.
	// Sirve para que este node en específico solo exista dentro de las funciones de la clase LinkedList.
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
			prev = nullptr;
		}

		T data; // los datos que realmente se guardan en la lista
		Node* next; // cuál nodo sigue de este nodo, en la lista ligada.
		// si next == nullptr, entonces este nodo es el último de la lista.
		Node* prev; // cuál nodo va antes de este nodo en la lista ligada.
	};

	// función privada porque la clase Node es privada, entonces no se puede usar fuera de esta clase.
	// Función que busca el primer nodo con valor "value" y lo devuelve.
	Node* Search(T value)
	{
		// Empezamos desde el nodo inicial.
		// OJO: el nodo inicial es el next de NIL (NIL->next)
		Node* nodoActual = NIL->next;

		// hacemos un ciclo para iterar por toda la lista. 
		// Si el nodo actual llegó a NIL, quiere decir que ya llegaste al final de la lista.
		while (nodoActual != NIL)
		{
			// si este nodo tiene el valor value que buscamos, entonces ya lo encontramos y retornamos el nodo.
			if (nodoActual->data == value)
			{
				return nodoActual;
			}
			nodoActual = nodoActual->next;
		}

		// Si se salió del ciclo, quiere decir que llegaste al final de la lista.
		cout << "no se encontró el valor: " << value << " en esta lista con centinela." << endl;
		return nullptr;
	}

	// función privada porque la clase Node es privada, entonces no se puede usar fuera de esta clase.
	void Delete(Node* nodoABorrar)
	{
		// si sí se encontró, pues vamos a borrar ese nodo.
		// Del nodoABorrar su nodo previo ahora va a apuntar hacia adelante a quien nodoABorrar apunta hacia adelante
		nodoABorrar->prev->next = nodoABorrar->next;
		// Del nodoABorrar su siguiente ahora apunta hacia atrás al nodo que apunta actualmente hacia atrás el nodo a borrar.
		nodoABorrar->next->prev = nodoABorrar->prev;
		count--;
	}

	Node* NIL;
	int count;
};

void DemostracionSentinelLinkedList();
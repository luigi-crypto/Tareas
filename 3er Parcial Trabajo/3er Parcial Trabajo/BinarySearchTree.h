#pragma once
#include <iostream>
#include <stack>
using namespace std;
#include<vector> // Recuerden, "vector" es el nombre del DynamicArray en c++ STL.


template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	// Añade un elemento de tipo T al árbol.
	void Add(T value)
	{
		// Si no hay nodo raíz... 
		if (root == nullptr)
		{
			// entonces este valor se va a convertir en el nodo raíz.
			root = new Node(value);
			return; // y nos salimos porque ya lo insertamos.
		}

		// Se mueve por el árbol usando izquierda-derecha hasta encontrar un lugar en el árbol que esté vacío.
		// Necesitamos una variable que representa el nodo contra el cual se está comparando value en cada iteración
		Node* nodoActual = root;
		// while(true) es que se ejecute infinitamente,
		// entonces DEBE haber algo dentro del while que nos permita salir de él.
		while (true)
		{
			// Si me tengo que ir a la derecha Y el hijo derecho del NodoActual es nullptr...
			// si el valor de value es mayor que el del nodo actual...
			if (value > nodoActual->value)
			{
				// ... entonces me tengo que ir a la derecha, 
				// PERO primero checo si el nodo a la derecha del actual NO es nullptr
				if (nodoActual->rightChild != nullptr)
				{
					nodoActual = nodoActual->rightChild;
					continue; // continue te devuelve al inicio del while.
				}
				else // si no tiene hijo derecho...
				{
					// ... entonces value se convierte en el hijo derecho del nodo actual.
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->rightChild = nodoConNuevoValor;
					// El nuevo nodo ahora apunta al nodo actual como su padre
					nodoConNuevoValor->parent = nodoActual;
					// Ya que metimos el nuevo nodo, ya acabamos la función y nos salimos.
					return;
				}
			}
			// NOTA 2: Su compañero Juan Alexis se lleva 5 puntos extras en el parcial final por haber notado el problema con anticipación.
			// NOTA: PARA EL CASO DE LA CLASE, ESTE ÁRBOL VA A TRATAR A LOS VALORES IGUALES MANDÁNDOLOS A LA IZQUIERDA
			// VA A HABER OCASIONES EN LAS QUE LOS ÁRBOLES NO PERMITAN REPETIDOS.
			else if (value <= nodoActual->value) // si fuimos menores O IGUALES ... 
			{
				// ... entonces nos tenemos que ir a la izquierda
				// PERO primero checo si el nodo a la izquierda del actual NO es nullptr
				if (nodoActual->leftChild != nullptr)
				{
					// entonces SÍ tiene un hijo izquierdo
					nodoActual = nodoActual->leftChild;
					continue; // continue te devuelve al inicio del while.
				}
				else // si no tiene hijo izquierdo...
				{
					// ... entonces value se covierte en el hijo izquierdo del nodo actual.
					Node* nodoConNuevoValor = new Node(value);
					nodoActual->leftChild = nodoConNuevoValor;
					// El nuevo nodo ahora apunta al nodo actual como su padre
					nodoConNuevoValor->parent = nodoActual;
					// Ya que metimos el nuevo nodo, ya acabamos la función y nos salimos.
					return;
				}
			}
		}
	}


	T MaxValue()
	{
		// Es solamente irse por los hijos derechos hasta que ya no haya más.
		// Checar que la raíz sea válida
		if (root == nullptr)
		{
			cerr << "Error, se llamó la función MaxValue pero el árbol está vacío." << endl;
			return T{}; // regresamos un valor por defecto.
		}

		// puntero auxiliar hacia el nodo que actualmente estamos checando en el árbol.
		Node* nodoActual = root;
		// Mientras el hijo derecho de este nodo actual siga siendo un nodo válido...
		while (nodoActual->rightChild != nullptr)
		{
			nodoActual = nodoActual->rightChild;
		}
		// Retornamos el valor del nodo actual, ya que es el valor más alto.
		return nodoActual->value;
	}

	// Retorna el valor más bajo en el árbol.
	T MinValue()
	{
		// Es solamente irse por los hijos izquierdos hasta que ya no haya más.
		// Checar que la raíz sea válida
		if (root == nullptr)
		{
			cerr << "Error, se llamó la función MinValue pero el árbol está vacío." << endl;
			return T{}; // regresamos un valor por defecto.
		}

		// puntero auxiliar hacia el nodo que actualmente estamos checando en el árbol.
		Node* nodoActual = root;
		// Mientras el hijo izquierdo de este nodo actual siga siendo un nodo válido...
		while (nodoActual->leftChild != nullptr)
		{
			nodoActual = nodoActual->leftChild;
		}
		// Retornamos el valor del nodo actual, ya que es el valor más bajo.
		return nodoActual->value;
	}

	// Versión pública de búsqueda
	/********************************************************
	1) Implementar la función "Search" del Binary Search Tree de manera iterativa (10 puntos).*/
	bool Find(T value)
	{
		Node* resultado = FindNode(value);//nuestro puntero apunta a a resultado que es el valor q buscamos
		if (resultado == nullptr)//si nuestor resultado es nulo
			return false; // no se encontró.
		return true; // sí se encontró
	}

	T Siguiente(T value)
	{
		// Checamos que el valor value esté presente en el árbol y obtenemos dicho nodo
		Node* nodoConValue = FindNode(value);
		if (nodoConValue == nullptr)
		{
			// Imprimimos un error y regresamos un error por defecto.
			cerr << "ERROR, no existe un nodo con valor: " << value << " en este árbol, no hay sucesor para él" << endl;
			return T{};
		}

		// SI sí existe, mandamos a llamar la de sucesor
		// pero tenemos que checar que sí haya un sucesor
		Node* sucesor = Sucesor(nodoConValue);
		if (sucesor == nullptr)
		{
			cout << "No hay sucesor para el nodo con valor: " << value << " en este árbol" << endl;
			return T{};
		}
		return sucesor->value;
	}

	T Anterior(T value)
	{
		// Checamos que el valor value esté presente en el árbol y obtenemos dicho nodo
		Node* nodoConValue = FindNode(value);
		if (nodoConValue == nullptr)
		{
			// Imprimimos un error y regresamos un error por defecto.
			cerr << "ERROR, no existe un nodo con valor: " << value << " en este árbol, no hay predecesor para él" << endl;
			return T{};
		}

		// SI sí existe, mandamos a llamar la de predecesor
		// pero tenemos que checar que sí haya un predecesor
		Node* predecesor = Predecesor(nodoConValue);
		if (predecesor == nullptr)
		{
			cout << "No hay predecesor para el nodo con valor: " << value << " en este árbol" << endl;
			return T{};
		}
		return predecesor->value;
	}

	// Borra el primer nodo encontrado que tenga dicho valor
	bool BorrarPorValor(T valor)
	{
		// como siempre en árboles, empezamos desde la raíz.
		if (root == nullptr)
		{
			// sin el try-catch, porque esto es un error grave.
			throw invalid_argument("Este árbol está vacío");
			return false; // por si le quieren seguir depurando incluso tras este error.
		}
		// Primero que todo, hay que encontrar si está un nodo con dicho valor.
		Node* nodoABorrar = FindNode(valor);
		// Si el nodo A Borrar es nullptr, entonces no existe un nodo con dicho valor
		if (nodoABorrar == nullptr)
		{
			// sin el try-catch, porque esto es un error grave.
			throw invalid_argument("No hay nodo con dicho valor en este árbol");
			return false; // por si le quieren seguir depurando incluso tras este error.
		}

		// Si sí hay dicho nodo, checamos en cuál de los 3 casos de Borrado cae:
		/* 1) Si X no tiene hijos (si su left y su right son nullptr),
		haces que el puntero a hijo de su padre que apunta a este
		nodo sea null y luego borras este nodo. No requieres reconexiones. */
		if (nodoABorrar->leftChild == nullptr && nodoABorrar->rightChild == nullptr)
		{
			// Entonces estamos en el caso 1, que es el más fácil.
			DeleteCaso1(nodoABorrar);
			return true;;
		}
		// Aquí quiere decir que tiene al menos un hijo. 
		// Checamos si tiene solo 1 de los 2 hijos.
		if (nodoABorrar->leftChild == nullptr && !(nodoABorrar->rightChild == nullptr) ||
			!(nodoABorrar->leftChild == nullptr) && nodoABorrar->rightChild == nullptr)
		{
			// Entonces estamos en el caso #2:
			DeleteCaso2(nodoABorrar);
			return true;
		}

		// Si llegó hasta esta parte del código, entonces estamos en el Caso #3,
		// el nodo a borrar tiene sus dos hijos.
		// 1. Encontrar sucesor 'Y' del nodo a Borrar 'X'
		Node* nodoSucesor = Sucesor(nodoABorrar);
		Node* hijoDerechoDelSucesor = nodoSucesor->rightChild;
		Node* padreDelSucesor = nodoSucesor->parent;


		// El resto del subárbol derecho de X se vuelve el subárbol derecho de ‘Y’.
		// En pocas palabras: el sucesor ahora apunta hacia donde antes apuntaba el nodo a borrar
		nodoSucesor->leftChild = nodoABorrar->leftChild;
		// Necesitamos asegurarnos de que el sucesor NO es el mismo hijo derecho del nodo a borrar
		if (nodoSucesor != nodoABorrar->rightChild)
			nodoSucesor->rightChild = nodoABorrar->rightChild;

		nodoSucesor->leftChild->parent = nodoSucesor;

		if (nodoSucesor->rightChild != nullptr) // tenemos que asegurarnos de que no es nulo.
		{
			nodoSucesor->rightChild->parent = nodoSucesor;
		}

		// Ahora hacemos la conexión del sucesor con el padre del nodo que se va a borrar.
		nodoSucesor->parent = nodoABorrar->parent;
		// Primero checamos que el parent no sea nullptr (el caso donde se está borrando al nodo Raíz)
		if (nodoABorrar->parent != nullptr)
		{
			// Necesitamos saber si el nodo a borrar era hijo izquierdo o derecho de su padre
			if (nodoABorrar->parent->leftChild == nodoABorrar)
				nodoSucesor->parent->leftChild = nodoSucesor;
			else
				nodoSucesor->parent->rightChild = nodoSucesor;
		}
		else // si entra a este else, se está borrando al nodo raíz
		{
			// tenemos que actualizar el puntero a la raíz
			root = nodoSucesor;
		}

		// NOTA: Según yo, a fuerzas es el hijo izquierdo, porque sino no sería el sucesor.
		if (padreDelSucesor != nullptr)
			padreDelSucesor->leftChild = hijoDerechoDelSucesor;

		// SOLO SI EL SUCESOR TIENE HIJO DERECHO
		if (hijoDerechoDelSucesor != nullptr)
		{
			// El hijo derecho de ‘Y’ antes de moverlo se recorre a la posición donde estaba 'Y'
			// Reconectar al papá de Y con el hijo derecho de Y y viceversa
			hijoDerechoDelSucesor->parent = padreDelSucesor;
		}


		delete nodoABorrar;
		return true;
	}


	// Es la versión pública de la función, que un usuario puede utilizar.
	// La otra de InOrderRecursivo NO es pública porque los usuarios no deben manipular nodos del árbol 
	// directamente nunca.
	void InOrderRecursivo()
	{
		cout << "In order Recursivo: ";
		InOrderRecursivo(root);
		cout << endl;
	}

	void PreOrderRecursivo()
	{
		cout << "Pre order Recursivo: ";
		PreOrderRecursivo(root);
		cout << endl;
	}

	void PostOrderRecursivo()
	{
		cout << "Post order Recursivo: ";
		PostOrderRecursivo(root);
		cout << endl;
	}

	pair<T, T> ObtenerMinimoYMaximo()
	{
		T max = MaxValue();
		T min = MinValue();
		return pair<T, T>(min, max);
	}

	T* ObtenerRaizMinimoYMaximo()
	{
		T* resultado = new T[3];
		resultado[0] = root->value;
		resultado[1] = MinValue();
		resultado[2] = MaxValue();
		return resultado;
	}

	vector<T> ObtenerRaizMinimoYMaximoConVector()
	{
		vector<T> resultado;
		resultado.push_back(root->value);
		resultado.push_back(MinValue());
		resultado.push_back(MaxValue());
		return resultado;
	}

	void Clear() {
		ClearRecursivo(root);
		root = nullptr;
	}

private:

	// Cada nodo pesa 3 punteros (8 bytes por puntero en un sistema operativo de 64 bits)
	// más los bytes que pese T. Entonces los árboles gastan  mucha más memoria que los arrays.
	class Node
	{
	public:

		Node(T _value)
		{
			value = _value;
			parent = nullptr;
			rightChild = nullptr;
			leftChild = nullptr;
		}

		T value;
		// Puntero hacia el Nodo padre. 
		Node* parent;
		// Puntero hacia el hijo derecho
		Node* rightChild;
		// puntero hacia el hijo izquierdo
		Node* leftChild;
	};

	void ClearRecursivo(Node* nodo) {
		if (nodo == nullptr) return;
		ClearRecursivo(nodo->leftChild);
		ClearRecursivo(nodo->rightChild);
		delete nodo;
	}

	//1)TAREA
	Node* FindNode(T value)//nuestro puntero apunta a nuestra funcion FindNode()
	{
		// Checar que la raíz sea válida
		if (root == nullptr)
			return nullptr; //si la raíz es inválida, cualquier búsqueda dará falso.

		// puntero auxiliar hacia el nodo que actualmente estamos checando en el árbol.
		Node* nodoActual = root;
		// Mientras este nodo actual siga siendo un nodo válido
		while (nodoActual != nullptr)
		{
			// checamos si el nodo actual tiene el valor igual al que estamos buscando.
			if (nodoActual->value == value)
				return nodoActual; // si sí es igual, ya lo encontramos.

			// Si no tiene el valor buscado, tenemos que ver si ahora el actual va a ser su hijo derecho o izquierdo
			// Si value es mayor que el valor del nodo actual
			if (value > nodoActual->value)
			{
				// entonces el nodo actual ahora avanza a su hijo derecho
				nodoActual = nodoActual->rightChild;
			}
			else
			{
				// y si no, entonces el nodo actual ahora avanza a su hijo izquierdo 
				nodoActual = nodoActual->leftChild;
			}
		}
		// este while se rompe cuando se llega a la posición donde debería estar value, pero en su lugar hay nullptr.
		// entonces, en este punto ya no se encontró value, y regresamos false.
		return nullptr;
	}

	//2)TAREA
	void DeletePostOrder(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// 1. Viaja al sub-árbol izquierdo recursivamente.
			DeletePostOrder(nodoActual->leftChild);

			// 2. Viaja al sub-árbol derecho recursivamente.
			DeletePostOrder(nodoActual->rightChild);

			// 3. Borra el nodo actual.
			delete nodoActual;
		}
	}





	void DeleteCaso1(Node* nodoABorrar)
	{
		// primero tenemos que checar que este nodo SÍ tenga un padre,
		if (nodoABorrar->parent == nullptr)
		{
			// si no tiene padre, entonces este nodo a borrar es la raíz :D y simplemente se borra
			delete nodoABorrar;
			root = nullptr;
			return;
		}
		// nodoABorrar checa si es el hijo izquierdo O derecho de su padre 
		if (nodoABorrar->parent->leftChild == nodoABorrar) // checamos si nodo a borrar es hijo izquierdo
		{
			// entonces sí es el hijo izquierdo
			nodoABorrar->parent->leftChild = nullptr; // le dice a su papá que ya no tiene hijo izquierdo
		}
		else
		{
			// si no, nodo a borrar es el hijo derecho
			nodoABorrar->parent->rightChild = nullptr; // le dice a su papá que ya no tiene hijo derecho
		}

		// sin importar si es hijo derecho o izquierdo, pues se borra este nodo.
		delete nodoABorrar;
	}

	void DeleteCaso2(Node* nodoABorrar)
	{
		// Si X solo tiene un hijo, haces que dicho hijo tome el lugar de X en el árbol y
		// luego borramos X. Requiere 2 reconexiones (del padre de X al hijo de X y viceversa).
		// Que el parent del hijo de X ahora sea el parent de X
		Node* hijoDeNodoABorrar = nullptr;

		if (nodoABorrar->leftChild == nullptr) // si el izquierdo es nullptr, el derecho es el hijo válido
			hijoDeNodoABorrar = nodoABorrar->rightChild;
		else
			hijoDeNodoABorrar = nodoABorrar->leftChild; // y si no, entonces el izquierdo es el válido


		hijoDeNodoABorrar->parent = nodoABorrar->parent;

		// tenemos que checar que no sea la raíz:
		if (nodoABorrar == root)
		{
			root = hijoDeNodoABorrar;
		}
		// checamos si el nodo a borrar es el hijo izquierdo o derecho de su padre para conectar al 
		// abuelo con su nieto
		else if (nodoABorrar->parent->leftChild == nodoABorrar)
			nodoABorrar->parent->leftChild = hijoDeNodoABorrar;
		else
			nodoABorrar->parent->rightChild = hijoDeNodoABorrar;

		// y por último borramos al nodo a borrar
		delete nodoABorrar;
	}

	Node* Sucesor(Node* node)
	{
		// Caso 1: El nodo sí tiene un hijo derecho
		if (node->rightChild != nullptr)
		{
			// Paso 1: Dar un paso a la derecha
			Node* nodoActual = node->rightChild; // este nodo auxiliar es como el "nodoActual" que usamos en otras funciones.

			// Paso 2: irte lo más a la izquierda que se pueda desde ahí.
			while (nodoActual->leftChild != nullptr)
				nodoActual = nodoActual->leftChild;

			// El while se rompe cuando el nodo actual ya no tiene hijo izquierdo, y entonces ya encontramos al sucesor
			return nodoActual;
		}
		// Caso 2: El nodo NO tiene un hijo derecho.
		// Preguntar al parent del nodo actual si el nodo actual es su hijo izquierdo
		Node* nodoActual = node;
		Node* padreNodoActual = nodoActual->parent;
		// Si subiste hasta el padre de la raíz (el cual es nullptr) entonces no habrá un sucesor.
		while (nodoActual->parent != nullptr)
		{
			// Si el nodo actual es igual al hijo izquierdo de su padre
			if (nodoActual == padreNodoActual->leftChild)
			{
				// ... entonces el padre es el sucesor
				return padreNodoActual;
			}
			// Si no, el nodo actual ahora apunta al padre, y se repite el proceso.
			nodoActual = padreNodoActual;
			padreNodoActual = padreNodoActual->parent;
		}

		// si te sales de este while, entonces no hay sucesor
		return nullptr;
	}

	Node* Predecesor(Node* node)
	{
		// Caso 1: El nodo sí tiene un hijo izquierdo
		if (node->leftChild != nullptr)
		{
			// Paso 1: Dar un paso a la derecha
			Node* nodoActual = node->leftChild; // este nodo auxiliar es como el "nodoActual" que usamos en otras funciones.

			// Paso 2: irte lo más a la derecha que se pueda desde ahí.
			while (nodoActual->rightChild != nullptr)
				nodoActual = nodoActual->rightChild;

			// El while se rompe cuando el nodo actual ya no tiene hijo derecho, y entonces ya encontramos al predecesor
			return nodoActual;
		}
		// Caso 2: El nodo NO tiene un hijo izquierdo.
		// Preguntar al parent del nodo actual si el nodo actual es su hijo derecho
		Node* nodoActual = node;
		Node* padreNodoActual = nodoActual->parent;
		// Si subiste hasta el padre de la raíz (el cual es nullptr) entonces no habrá un predecesor.
		while (nodoActual->parent != nullptr)
		{
			// Si el nodo actual es igual al hijo izquierdo de su padre
			if (nodoActual == padreNodoActual->rightChild)
			{
				// ... entonces el padre es el predecesor
				return padreNodoActual;
			}
			// Si no, el nodo actual ahora apunta al padre, y se repite el proceso.
			nodoActual = padreNodoActual;
			padreNodoActual = padreNodoActual->parent;
		}

		// si te sales de este while, entonces no hay predecesor
		return nullptr;
	}

	void InOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces mandamos a llamar esta misma función pero con el hijo izquierdo del actual
			InOrderRecursivo(nodoActual->leftChild);
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";
			// mandamos a llamar esta misma función pero con el hijo derecho del actual
			InOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PreOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces 
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";

			//mandamos a llamar esta misma función pero con el hijo izquierdo del actual
			PreOrderRecursivo(nodoActual->leftChild);

			// mandamos a llamar esta misma función pero con el hijo derecho del actual
			PreOrderRecursivo(nodoActual->rightChild);
		}
	}

	void PostOrderRecursivo(Node* nodoActual)
	{
		// Si el nodo actual no es nullptr ...
		if (nodoActual != nullptr)
		{
			// ... entonces mandamos a llamar esta misma función pero con el hijo izquierdo del actual
			PostOrderRecursivo(nodoActual->leftChild);
			// mandamos a llamar esta misma función pero con el hijo derecho del actual
			PostOrderRecursivo(nodoActual->rightChild);
			// Visitamos al nodo actual (en este caso visitar significa imprimir su valor)
			cout << nodoActual->value << ", ";
		}
	}


	/*3) Implementación Post-order del Binary Search Tree de manera iterativa.
	*/


	void PostOrderIterativo()
	{
		cout << "Post order Iterativo: ";
		if (root == nullptr)//Vamos a comprobar que el abrol no esté vacío.
		{
			cout << endl;
			return;
		}

		// Se utiliza dos pilas la pila que es la primcipal pila1 para almacenar en orden 
		// y la  pila2 para almacenar Post-order.
		stack<Node*> pila1; // Pila temporal: Contiene los nodos a visitar.
		stack<Node*> pila2; // Pila final: Contiene los nodos en orden Post-order.

		pila1.push(root);//empuja el nodo raíz a la pila1

		//Llenar pila2 en el orden inverso
		while (!pila1.empty())//mientras la pila1 no este vacía se ejecuta el proceso
		{
			Node* nodoActual = pila1.top();//Nuestro puntero apnuta al nodo actual que sera el tope o el primero de la pila1
			pila1.pop();//y elimina el tope de la pila uno

			pila2.push(nodoActual); // Mueve el nodo a la pila final (Raíz)

			// Empuja primero al hijo izquierdo y luego al derecho.
			// Como es una pila LIFO el hijo derecho se procesará antes que el izquierdo en la siguiente iteración de pila1
			// Osea un recorrido inverso Raíz -> Derecha -> Izquierda.
			if (nodoActual->leftChild != nullptr)//Comprueba si el nodo tiene un hijo izquierdo
			{
				pila1.push(nodoActual->leftChild);//si si lo empuja a la pila1
			}
			if (nodoActual->rightChild != nullptr)//lo mism pero con el derecho
			{
				pila1.push(nodoActual->rightChild);//si si lo empuja a la pila1
			}
		}

		// Imprimir los nodos de pila2 que estan en Post-order
		while (!pila2.empty())
		{
			cout << pila2.top()->value << ", ";
			pila2.pop();
		}
		cout << endl;
		/********************************************************/



	}

	// Puntero al nodo raíz de este árbol
	Node* root;
	// int count;

};

void DemostracionBinarySearchTree();
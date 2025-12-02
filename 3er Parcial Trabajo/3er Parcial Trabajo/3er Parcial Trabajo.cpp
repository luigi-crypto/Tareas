#include "Hashtable_presentacion.h"
#include "BinarySearchTree.h"
#include "HashSet.h"
#include <iostream>

using namespace std;

// Asegúrate de declarar la función antes de usarla
void DemostracionBinarySearchTree();

int main_presentacion()
{
	Presentacion();
	return 0;
}

int main_demostracion_bst()
{
	DemostracionBinarySearchTree();
	return 0;
}

int HashSet()
{
	DemostracionHashSet();
	return 0;
}

int main()
{
	main_presentacion();
	DemostracionBinarySearchTree();
	DemostracionHashSet();
	return 0;
}
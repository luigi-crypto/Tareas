#include "DynamicArray.h"


DynamicArray::DynamicArray(int in_capacity)
{
	capacity = in_capacity;
	// Vamos a pedir N elementos en memoria, donde N = capacity,
	// y se los vamos a asignar a nuestro puntero elements.
	if (capacity > 0)
		elements = new int[capacity];
	else
		elements = nullptr; // si es 0, no pierdes tiempo pidiendo memoria dinámica que puede que no se use.

	count = 0; // le decimos que ahorita no tiene nada dentro, por lo tanto es 0.
}

DynamicArray::~DynamicArray()
{
	// si sí se pidió memoria dinámica, entonces sí necesitamos hacer este delete.
	if(capacity > 0)
		// IMPORTANTE usar los '[]' cuando se hace delete de un arreglo de memoria dinámica.
		delete [] elements;
}

// como estamos pidiendo memoria dinámica, hay que recordar liberar memoria dinámica cuando ya no 
// sea necesaria. (Cuando se le hace delete a este objeto, o cuando sale del scope (las {}) donde se declaró)




void DemostracionDynamicArray()
{
	DynamicArray myDArray = DynamicArray(5);

	for (int i = 0; i < 6; i++)
	{
		myDArray.Append(i);
	}
	myDArray.Append(7);
	myDArray.Append(8);
	myDArray.Append(9);
	// aquí ya se necesitaría otra vez el resize, porque se acaban los espacios disponibles,
	// y ahora tendríamos un array de 10*2 espacios, de los cuales tenemos ocupados 11.
	myDArray.Append(10);
	myDArray.Print();


	cout << "imprimiendo el array dinámico" << endl;
	for (int i = 0; i < myDArray.GetCount(); i++)
	{
		cout << myDArray.ObtenerElemento(i) << endl;
	}


	/* PRUEBAS DE LAS FUNCIONES QUE USTEDES HARÁN PARA LA TAREA */

}
#include "DynamicArray.h"


DynamicArray::DynamicArray(int in_capacity)
{
	capacity = in_capacity;
	// Vamos a pedir N elementos en memoria, donde N = capacity,
	// y se los vamos a asignar a nuestro puntero elements.
	if (capacity > 0)
		elements = new int[capacity];
	else
		elements = nullptr; // si es 0, no pierdes tiempo pidiendo memoria din�mica que puede que no se use.

	count = 0; // le decimos que ahorita no tiene nada dentro, por lo tanto es 0.
	//TAREA 3.1 RESET COPY COUNTER!!!!!!!!!!/
#if COUNT_DYNAMIC_ARRAY_COPIES//aqui reseteamos el contador
	copyCounter++;
#endif
}

DynamicArray::~DynamicArray()
{
	// si s� se pidi� memoria din�mica, entonces s� necesitamos hacer este delete.
	if (capacity > 0)
		// IMPORTANTE usar los '[]' cuando se hace delete de un arreglo de memoria din�mica.
		delete[] elements;
}

// como estamos pidiendo memoria din�mica, hay que recordar liberar memoria din�mica cuando ya no 
// sea necesaria. (Cuando se le hace delete a este objeto, o cuando sale del scope (las {}) donde se declar�)




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
	// aqu� ya se necesitar�a otra vez el resize, porque se acaban los espacios disponibles,
	// y ahora tendr�amos un array de 10*2 espacios, de los cuales tenemos ocupados 11.
	myDArray.Append(10);
	myDArray.Print();


	cout << "imprimiendo el array din�mico" << endl;
	for (int i = 0; i < myDArray.GetCount(); i++)
	{
		cout << myDArray.ObtenerElemento(i) << endl;
	}


	/* PRUEBAS DE LAS FUNCIONES QUE USTEDES HAR�N PARA LA TAREA */
	MiDinamicArray<int> arr(2);/*Aqui solo declaramos un arreglo de dos de capacidad*/
	arr.push_back(10);/*Aqui agregamos uno*/
	arr.push_back(20);/*Aquí el segundo*/
	arr.push_back(30);/*Aqui ya son 3 ya no cabe pero como hicimos todo lo que se vio en el .h se redimencionara para que quepan 3*/
	cout << arr[0];// imprime 10
	cout << endl;// salto de linea
	cout << arr[1];// imprime 20
	cout << endl;
	cout << arr[2];    // imprime 30
	cout << endl;
	arr.pop_back();// quita el último elemento (30)
	cout << "El tamaño de la array es de: " << arr.i(); // imprime 2
}
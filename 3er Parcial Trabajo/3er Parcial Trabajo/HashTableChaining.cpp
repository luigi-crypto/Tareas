#include "HashTableChaining.h"
#include <iostream>
using namespace std;

void DemostracionHashTableChaining()
{
	HashTableChaining<int> myHashTable = HashTableChaining<int>(4);

	// Insertamos valores sin colisión.
	myHashTable.Add(39); // lista 3
	myHashTable.Add(252); // lista 0

	// Insertamos valores con colisión.
	myHashTable.Add(40); // colisión con 252
	myHashTable.Add(252); // colisión con 252 otra vez, pero debe quedar después de 40.
	// EN SU TAREA, AL AÑADIR ESTE SEGUNDO 252, DEBERÍA MANDAR UN THROW DE UNA EXCEPCIÓN PORQUE NO PERMITE REPETIDOS.

	cout << "dewspués de añadir con colisión al 40 y 252" << endl;
	myHashTable.Imprimir();

	// Prueba de funciones de encontrar y borrar
	myHashTable.Encontrar(40);
	myHashTable.BorrarValor(252); // debe borrar el primer 252, no el segundo.
	cout << "después de borrar el primer 252" << endl;
	myHashTable.Imprimir();



	HashTableChaining<string> myHashTableString = HashTableChaining<string>(27);

	// Insertamos valores sin colisión.
	myHashTableString.Add("Hola"); // lista H
	myHashTableString.Add("Mundo"); // lista M

	// Insertamos valores con colisión.
	myHashTableString.Add("Hello"); // colisión con Hola
}

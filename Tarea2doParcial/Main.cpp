#include "Tarea0.h"/*Agregamos los .h correspondientes*/
#include "LinkedList.h"
#include "DynamicArray.h"
#include <iostream>
using namespace std;

void mainTarea0()
{
	int arr[] = { 1,2,3,4,5 };/*creamos un array de enteros**/
	Printarray<int>(arr, 5);/*Aqui decimos cual es nuestro arreglo y cual es su tamaño*/
	cout << endl;/*Un salto de linea para que no se junte esto con lo anterior*/
	string arr2[] = { "Hola", "Mundo", "!", "Como estas?" };/*Aqui hacemos lo mismo solo que con palabras strings*/
	Printarray<string>(arr2, 4);
};/**Es algo parecido a la sobrecarga bueno al menos eso me parece a mí por que con una solo puedes crear muchas casi iguales*/


void mainTarea1()
{
	void DemostracionDynamicArray();
};

 void mainTarea2()
 {
	 DemostracionLinkedList();
 }

int main()
{
	//TAREA 0 =====================/===================//
    mainTarea0();
	cout << endl;
	//TAREA 1 =====================/===================//
	mainTarea1();
	cout << endl;
	//Tarea 2========================/================//
	mainTarea2();
}




#include "Tarea0.h"/*Agregamos los .h correspondientes*/
#include "Tarea1.h"
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
	 MiDinamicArray<int> arr(2);/*Aqui solo declaramos un arreglo de dos de capacidad*/
	 arr.push_back(10);/*Aqui agregamos uno*/
	 arr.push_back(20);/*Aquí el segundo*/
	 arr.push_back(30);/*Aqui ya son 3 ya no cabe pero como hicimos todo lo que se vio en el .h se redimencionara para que quepan 3*/
	 cout << arr[0];// imprime 10
	 cout << endl;// salto de linea
	 cout << arr[1];// imprime 20
	 cout << endl;
	 cout<<arr[2];    // imprime 30
	 cout<<endl;
	 arr.pop_back();// quita el último elemento (30)
	 cout<<"El tamaño de la array es de: "<<arr.i(); // imprime 2
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




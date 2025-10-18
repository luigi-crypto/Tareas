#include "Tarea0.h"
#include "Tarea1.h"
#include <iostream>
using namespace std;

void mainTarea0()
{
	int arr[] = { 1,2,3,4,5 };
	Printarray<int>(arr, 5);
	cout << endl;
	string arr2[] = { "Hola", "Mundo", "!", "Como estas?" };
	Printarray<string>(arr2, 4);
};


 void mainTarea1()
 {
	 MiDinamicArray<int> arr(2);
	 arr.push_back(10);
	 arr.push_back(20);
	 arr.push_back(30);// se redimensiona
	 cout << arr[0];
	 cout << endl;
	 cout << arr[1];
	 cout << endl;
	 cout<<arr[2];    // imprime 30
	 cout<<endl;
	 arr.pop_back();
	 cout<<"El tamaño de la array es de: "<<arr.i(); // imprime 2
 };

int main()
{
	//TAREA 0 =====================/===================//
    mainTarea0();
	cout << endl;
	//TAREA 1 =====================/===================//
	mainTarea1();
}




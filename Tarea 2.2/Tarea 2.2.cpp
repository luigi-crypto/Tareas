//Ejercicio Estructuras : 35 puntos.
//1) Hacer una estructura(struct) llamada VectorDeValores.
//1.1) Internamente tiene dos variables, uno es un puntero a float, y la otra es un int para el tamaño del array.
//1.2) Hacer un constructor que reciba como parámetros un array de floats y un int del tamaño del array de floats y los asigne a las variables internas.
//1.3) Hacer un constructor por defecto, que ponga el tamaño del array en 2, y pida la memoria dinámica correspondiente, y después inicialice esos valores en 0.
//1.4) Hacer un destructor que libere la memoria dinámica solicitada, e imprima cuántos elementos liberó.
#include <iostream>
using namespace std;

struct VectoresDeValores
{
	float* ptr;
	int tamano;

	VectoresDeValores(float arr[], int tamano) {
		this->tamano = tamano;
		ptr = new float[tamano];
		for (int i = 0; i < tamano; i++)
		{
			ptr[i] = arr[i];
		}
	}

	VectoresDeValores() {
		tamano = 2;
		ptr = new float[tamano];
		for(int i=0; i < tamano; i++)
		{
			ptr[i] = 0;
		}
		
	}
	~VectoresDeValores() {
		delete[] ptr;
		cout << "Se liberaron " << tamano << " elementos." << endl;
	}
};

int main()
{
	VectoresDeValores vec1; //Constructor por defecto
	float arr[] = { 1.1, 2.2, 3.3, 4.4 };
	VectoresDeValores vec2(arr, 4); //Constructor con parámetros
	return 0;
}

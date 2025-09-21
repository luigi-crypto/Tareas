#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1) Hacemos un array de 5 booleanos
bool arrayBool[5];

// 1.1) Prototipo de función que recibe un array de booleanos y su tamaño
void ModificarArray(bool arr[], int tamanio);

// 1.4) Prototipo de la sobrecarga que recibe un array de enteros
void ModificarArray(int* arr, int tamanio);


int main()
{
    // 1) Creamos el array de booleanos
    bool arrayBool[5];

    // 1.2) Llamamos a la función que modifica el array de booleanos
    ModificarArray(arrayBool, 5);

    cout << "Array de booleanos (pares false, impares true):" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Indice " << i << " -> " << (arrayBool[i] ? "true" : "false") << endl;
    }

    cout << endl;

    // 1.3) Creamos un array de 10 enteros, inicializado del 0 al 9
    int arrayEnteros[10] = { 0,1,2,3,4,5,6,7,8,9 };

    // 1.5) Llamamos a la función sobrecargada para modificar el array de enteros con %2
    ModificarArray(arrayEnteros, 10);

    return 0;
}




// 1.2) Función que recibe un array de booleanos y lo modifica:
// en los índices pares -> false
// en los índices impares -> true
void ModificarArray(bool arr[], int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        if (i % 2 == 0) arr[i] = false;
        else arr[i] = true;
    }
}



// 1.4) Sobrecarga de la función pero ahora recibe enteros
// 1.6) Aquí NO se permite usar corchetes [], así que usamos aritmética de punteros
// 1.7) Para no modificar el puntero original, usamos una variable auxiliar que apunte al inicio del array
// 1.8) Imprimimos las direcciones de memoria y el valor modificado
void ModificarArray(int* arr, int tamanio)
{
    int* aux = arr; // puntero auxiliar que apunta al inicio del array

    for (int i = 0; i < tamanio; i++)
    {
        *aux = *aux % 2; // reemplazamos el valor actual por su residuo %2
        cout << "Direccion: " << aux << " -> Valor: " << *aux << endl;
        aux++; // avanzamos una posición en memoria
    }
}

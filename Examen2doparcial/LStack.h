#pragma once
#include <iostream>
#include <forward_list> // ¡La estructura de datos requerida!
#include <stdexcept>    // Para manejar errores (opcional pero recomendado)

// Usamos el 'using' del archivo de ejemplo
using namespace std;

template<typename T> // 1. Es una clase template
class LStack
{
public:
    LStack()
    {
        // Inicializamos nuestro contador
        count = 0;
    }

	// Destructor: No es necesario hacer nada por que se destrtuye sola
    ~LStack()
    {
    }

    void Push(T value)
    {
        // push_front agrega al inicio de la lista
        elements.push_front(value);
        count++;
    }

    // Saca y regresa el elemento del tope de la pila
    T Pop()
    {
        // Verificamos si hay elementos
        if (Vacio())
        {
            // La clase original regresaba -INFINITY.
            // Para un template no podemos regresar -INFINITY si T es un string.
            // Regresar el valor por defecto de T
            cout << "ERROR la pila estaba vacía pero se intentó sacar un elemento de ella." << endl;
            return T();
        }

        //Guardamos el valor del principio 
        T topValue = elements.front();

        //Quitamos el elemento del principio
        elements.pop_front();

        //decrementa nuestro contador 
        count--;

        //Regresamos el valor guardado
        return topValue;
    }

    // Regresa el elemento del tope de la pila PERO sin sacarlo
    T Peek()
    {
        if (Vacio())
        {
            cout << "ERROR la pila estaba vacía pero se intentó hacer Peek de ella." << endl;
            return T();
        }

        // front nos da el primer elemento sin quitarlo
        return elements.front();
    }

    // Regresa el número de elementos en la pila
    int Count()
    {
        // Simplemente regresamos nuestro contador 
        return count;
    }

	bool Vacio()//esta no estaba pero es util
    {
        return count == 0;
    }

    // Función de ayuda para imprimir
    void PrintStack()
    {
        cout << "Imprimiendo stack: " << endl;
        // Iteramos la lista (desde el frente hasta el final)
        for (const T& val : elements)
        {
            cout << val << " , ";
        }
        cout << "NULL" << endl;
    }

private:
    //Usamos std::forward_list para almacenar los elementos
    std::forward_list<T> elements;
    int count;
};

int PrubeaLStack();

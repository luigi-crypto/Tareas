#pragma once

#include "HashTableChaining.h"
#include <stdexcept>//Permite a tu programa acceder a clases de manejo de excepciones predefinidas, que se utilizan para informar y gestionar errores comunes de manera estructurada. de Florida State University
#include <iostream>

template <typename T>
// HashSet hereda publicamente de HashTableChaining
class HashSet : public HashTableChaining<T>
{
public:
    // El constructor llama al constructor de la clase base.
    //aquí solo pasamos el argumento al constructor del padre.
    HashSet(size_t numeroDeListas) : HashTableChaining<T>(numeroDeListas) {}

    // Sobreescribe el método Add para implementar la lógica sin repetidos.
     void Add(T value) override
    {
        //Verificar si el elemento ya existe usando la función Encontrar (heredada).
        if (this->Encontrar(value))
        {
            //Si ya existe, lanzamos una excepción y no hacemos nada más.
            std::cerr << "ALERTA ROJA:" << value << " ya existe no se volvera a añadir :)." << std::endl;
            // throw std::invalid_argument("Error: No se permiten elementos repetidos en HashSet."); esto segun chat
            return; // Salimos sin añadir
        }

        //Si no existe, llamamos al método Add de la clase base para que lo inserte.
        // Usamos el operador de ámbito para asegurar que llamamos a la función del padre.
        HashTableChaining<T>::Add(value);
    }

    // El resto de métodos (BorrarValor, Encontrar, Imprimir) se heredan directamente 
    // de HashTableChaining y funcionan sin cambios.
};

void DemostracionHashSet();
#pragma once
#include "SentinelLinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
class LQueue
{
private:
    SentinelLinkedList<T> data;

public:
    // Enqueue agrega al final es lo mismo que un append
    //Dequeue  saca del inicio  popfront elimina al primero lo mismo igual
    //Front  mira el primero sin sacarlo front ya lo teniamos
    LQueue() 
    {
    }  // la lista ya se inicializa vacía sola

    // Devuelve el número de elementos en la cola
    int GetCount() { return data.GetCount(); }

    void Enqueue(T value)
    {
        data.Append(value);  // Append de la lista
    }

    T Dequeue()
    {
        return data.PopFront();  // PopFront de la lista
    }

    T Front()
    {
        return data.Front();  // Front de la lista
    }
    
};
void DemostraciondeLQueue();



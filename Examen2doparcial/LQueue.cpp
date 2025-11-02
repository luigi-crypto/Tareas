#include "LQueue.h"




void DemostraciondeLQueue()
{
    LQueue<int> cola;

    cola.Enqueue(10);
    cola.Enqueue(20);
    cola.Enqueue(30);

    cout << "El primero es:" << cola.Front() << endl;
    //lo sacamos
    cola.Dequeue();
    cout << "El nuevo primero es:" << cola.Front() << endl;
    //lo volvemos a sacar
    cola.Dequeue();
    cout << "Por ultimo el primero en la cola es:" << cola.Front() << endl;
}

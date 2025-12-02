#include "HashSet.h"
#include <iostream>
using namespace std;
void DemostracionHashSet()
{

    // Creamos un HashSet de enteros 4
    HashSet<int> miConjunto(4);

    miConjunto.Add(39); // Indice 3
    miConjunto.Add(252); // Indice 0
    miConjunto.Add(40); // Indice 0 (Colisión con 252)

    miConjunto.Imprimir();

    // Esto llamará a la función Add de HashSet, que lo detectará y emitirá un aviso/error.
    miConjunto.Add(40);//REPETIDO

    miConjunto.Add(39);//repetido

    miConjunto.Imprimir(); // Debe ser idéntico al anterior.

    if (miConjunto.BorrarValor(40))
        cout << "Valor 40 borrado con exito." << endl;
    else
        cout << "El valor 40 no pudo ser borrado." << endl;

    miConjunto.Imprimir();

}
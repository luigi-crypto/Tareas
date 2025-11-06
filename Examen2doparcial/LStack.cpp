#include <iostream>
#include <string>
#include "LStack.h"

using namespace std;

int PrubeaLStack()
{
    LStack<int> pilaDeInts;
    pilaDeInts.Push(1242);
    pilaDeInts.Push(214);
    pilaDeInts.Push(32564);

    pilaDeInts.PrintStack();
    cout << "Peek: " << pilaDeInts.Peek() << endl;
    cout << "Elementos: " << pilaDeInts.Count() << endl; // Imprime 3

    cout << "Pop: " << pilaDeInts.Pop() << endl;
    cout << "Pop: " << pilaDeInts.Pop() << endl;

    pilaDeInts.PrintStack();
    cout << "Elementos: " << pilaDeInts.Count() << endl; // Imprime 1

    LStack<string> pilaDeStrings;
    pilaDeStrings.Push("Luis");
    pilaDeStrings.Push("Diego");
    pilaDeStrings.Push("Hola");

    pilaDeStrings.PrintStack();
    cout << "Peek: " << pilaDeStrings.Peek() << endl;
    cout << "Elementos: " << pilaDeStrings.Count() << endl; // Imprime 3

    cout << "Pop: " << pilaDeStrings.Pop() << endl;
    pilaDeStrings.PrintStack();
    return 0;
}

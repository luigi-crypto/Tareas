#pragma once

#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;

public:
    HashTable(int size) {
        this->size = size;
        table.assign(size, -1); // -1 representa casilla vacía
    }

    int hash(int key) {
        return key % size;
    }

    bool insert(int key) {
        int index = hash(key);
        int start = index;  // Para detectar loop completo

        // Caso: tabla llena (si no hay -1 en la tabla)
        bool full = true;
        for (int value : table) {
            if (value == -1) {
                full = false;
                break;
            }
        }
        if (full) {
            cout << "Error: La tabla esta llena. No se puede insertar " << key << endl;
            return false;
        }

        // Proceso de Linear Probing
        while (table[index] != -1) {
            index = (index + 1) % size;

            // Si regresamos al inicio → tabla llena
            if (index == start) {
                cout << "Error: No se pudo insertar " << key << " (tabla llena)." << endl;
                return false;
            }
        }

        // Insertar el elemento
        table[index] = key;
        return true;
    }

    void print() {
        cout << "Tabla Hash: ";
        for (int i = 0; i < size; i++) {
            if (table[i] == -1)
                cout << "[ ] ";
            else
                cout << "[" << table[i] << "] ";
        }
        cout << endl;
    }
};

int Presentacion() {
    HashTable ht(8);

    // Ejemplos: puedes cambiarlos según tu animación
    ht.insert(15);
    ht.insert(23);
    ht.insert(10);
    ht.insert(18);
    ht.print();

    return 0;
}
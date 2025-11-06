#include <iostream>
#include <cmath> // es útil para tan()
#include "Herencia.h"

using namespace std;

const float PI = 3.1416;

float Circulo::CalcularArea() {
    // radio es la variable privada de Circulo
    return PI * radio * radio;
}

float Circulo::CalcularPerimetro() {
    // radio es la variable privada de Circulo
    return 2 * PI * radio;
}


float Cuadrado::CalcularArea() {
    // lado es la variable protected de Cuadrado
    return lado * lado;
}

float Cuadrado::CalcularPerimetro() {
    // lado es la variable protected de Cuadrado
    return 4 * lado;
}


float FiguraNLados::CalcularArea() {
    // Área = (n * l^2) / (4 * tan(PI / n))
    float l_al_cuadrado = longitudLado * longitudLado;
    float angulo_radianes = PI / numLados;
    float tangente = tan(angulo_radianes);

    return (numLados * l_al_cuadrado) / (4 * tangente);
}

float FiguraNLados::CalcularPerimetro() {
    return numLados * longitudLado;
}


float Cubo::CalcularArea() {
    // Reinterpretamos como "Área de Superficie Total"
    // 'lado' es accesible porque es 'protected' en Cuadrado
    return 6 * lado * lado;
}

float Cubo::CalcularPerimetro() {
    // Reinterpretamos como "Suma de las 12 aristas"
    return 12 * lado;
}

float Cubo::CalcularVolumen() {
    // Función extra de Cubo
    return lado * lado * lado;
}


// Constructor
Linea::Linea(string name, float* arregloIn, int tamano)
    : Figura(name), numSegmentos(tamano) // Llama al constructor base e inicializa
{
    // PASO 1: Pedir memoria dinámica
    segmentos = new float[numSegmentos];

    // PASO 2: Copiar los datos del arreglo original
    for (int i = 0; i < numSegmentos; i++) {
        segmentos[i] = arregloIn[i];
    }
}

// Destructor
Linea::~Linea() {
    // PASO 3: Liberar la memoria dinámica
    // Se usa 'delete[]' porque se pidió con 'new[]'
    delete[] segmentos;
}

float Linea::CalcularArea() {
    // El área de una línea es 0
    return 0.0f;
}

float Linea::CalcularPerimetro() {
    // El "perímetro" es la suma de todos los segmentos
    float sumaTotal = 0.0f;
    for (int i = 0; i < numSegmentos; i++) {
        sumaTotal += segmentos[i];
    }
    return sumaTotal;
}
void ImprimirInfo(Figura* fig) {
    if (fig == nullptr) {
        cout << "Error: Figura nula." << endl;
        return;
    }

    cout << "------------------------------------" << endl;
    cout << "Figura: \t" << fig->ObtenerNombreDeFigura() << endl;
    cout << "  Area: \t" << fig->CalcularArea() << endl;
    cout << "  Perimetro: \t" << fig->CalcularPerimetro() << endl;

    Cubo* posibleCubo = dynamic_cast<Cubo*>(fig);
    if (posibleCubo != nullptr) {
        // ¡Sí era un Cubo! Ahora sí podemos llamar a CalcularVolumen()
        cout << "  Volumen: \t" << posibleCubo->CalcularVolumen() << endl;
    }
}


/**
 * Función principal de la práctica donde se crea y prueba todo.
 */
int PruebaHerencia() {
    cout << "--- Iniciando Prueba de Herencia ---" << endl << endl;

    // --- Usaremos un arreglo de apuntadores a Figura ---
    // Esta es la forma más elegante de manejar polimorfismo.

    const int numFiguras = 6;
    Figura* misFiguras[numFiguras]; // Un arreglo de 6 apuntadores

    // --- Creamos el arreglo para la Linea ---
    float segmentosDeLinea[] = { 10.5f, 5.2f, 8.3f }; // Suma = 24.0
    int numSegmentos = 3;

    // --- Llenamos el arreglo con objetos (creados en memoria dinámica) ---
    misFiguras[0] = new Circulo("Círculo Grande", 10.0f);   // r=10
    misFiguras[1] = new Cuadrado("Cuadrado Pequeño", 5.0f); // l=5
    misFiguras[2] = new FiguraNLados("Pentágono", 5, 6.0f); // n=5, l=6
    misFiguras[3] = new Cubo("Cubo de Hielo", 3.0f);       // l=3
    misFiguras[4] = new Linea("Línea Rota", segmentosDeLinea, numSegmentos);
    misFiguras[5] = new FiguraNLados("Hexágono", 6, 2.0f);  // n=6, l=2


    // --- Recorremos el arreglo e imprimimos la info ---
    // ¡Aquí brilla el Polimorfismo!
    // El mismo bucle llama a tu función 'ImprimirInfo',
    // y C++ sabe exactamente qué 'CalcularArea' debe usar.

    for (int i = 0; i < numFiguras; i++) {
        ImprimirInfo(misFiguras[i]);
    }

    cout << "------------------------------------" << endl;

    // --- ¡MUY IMPORTANTE: Liberar toda la memoria! ---
    // Por cada 'new' que hicimos, debemos hacer un 'delete'.

    cout << "\n--- Liberando Memoria ---" << endl;
    for (int i = 0; i < numFiguras; i++) {
        delete misFiguras[i]; // Llama al destructor virtual correcto
        misFiguras[i] = nullptr; // Buena práctica
    }

    cout << "--- Prueba Finalizada ---" << endl;
    return 0;
}

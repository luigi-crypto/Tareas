#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// Declaraciones de funciones
void darsemana(int dia);
void darhora();
void asignarhora();
string obtenerHorario(int h);
void mostrarDiaEspecial(int h);

int main()
{
    cout << "Hola primero demostrare como funciona el programa" << endl;
    darhora(); //en esta funcion que tiene un for recorre la array de dias para mostrar los dias de la semana
    //y ademas muestra la hora actual y en que momento del dia estamos
    cout << "Ahora mostrare todo el ciclo del dia para que vean como funciona el programa" << endl;
    asignarhora();
    cout << "Para el dia elegido va a ser el miercoles" << endl;

    // Obtenemos la hora actual del sistema
    time_t ahora = time(0);        // tiempo en segundos desde 1970
    tm* tiempoLocal = localtime(&ahora); // convierte a hora local
    int hora = tiempoLocal->tm_hour;   // hora (0–23)

    mostrarDiaEspecial(hora); //llamamos a la nueva funcion para ver todos los dias y el horario

    return 0;
}

// Definiciones de funciones (después del main)

void darsemana(int dia) {
    switch (dia) { //este switch le asigna a cada numero un dia de la semana
    case 0: cout << "Lunes" << endl; break;
    case 1: cout << "Martes" << endl; break;
    case 2: cout << "Miercoles" << endl; break;
    case 3: cout << "Jueves" << endl; break;
    case 4: cout << "Viernes" << endl; break;
    case 5: cout << "Sabado" << endl; break;
    case 6: cout << "Domingo" << endl; break;
    default: cout << "Dia invalido" << endl;
    }
} //esta funcion le asigna a cada numero un dia de la semana

void darhora()
{
    // Obtenemos la hora actual del sistema
    time_t ahora = time(0);        // tiempo en segundos desde 1970
    tm* tiempoLocal = localtime(&ahora); // convierte a hora local
    int hora = tiempoLocal->tm_hour;   // hora (0–23)
    int minuto = tiempoLocal->tm_min;  // minuto (0–59)
    int segundo = tiempoLocal->tm_sec; // segundo (0–59)

    //esto lo sacamos de chat gpt que es el como programar para que nos de la hora actual 
    //todo lo demas es mio

    int dias[7] = { 0, 1, 2, 3, 4, 5, 6 }; //esta array va a darle un numero a cada dia de la semana empezando por lunes y terminando por domingo

    cout << "Hora actual: " << hora << ":" << minuto << ":" << segundo << endl;
    for (int i = 0; i < 7; i++) //este for recorre la array de dias para mostrar los dias de la semana y aparte nos da el horario en el que estamos
    {
        darsemana(dias[i]);
        if (hora >= 12 && minuto >= 0 && segundo >= 0 && hora <= 12 && minuto <= 59 && segundo <= 59) //le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es mediodia" << endl;
        }
        else if (hora >= 13 && minuto >= 0 && segundo >= 0 && hora <= 19 && minuto <= 59 && segundo <= 59) //le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de tarde" << endl;
        }
        else if (hora >= 20 && minuto >= 0 && segundo >= 0 && hora <= 23 && minuto <= 59 && segundo <= 59) //le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de noche" << endl;
        }
        else if (hora >= 0 && minuto >= 0 && segundo >= 0 && hora <= 5 && minuto <= 59 && segundo <= 59) //le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de madrugada" << endl;
        }
        else if (hora >= 6 && minuto >= 0 && segundo >= 0 && hora <= 11 && minuto <= 59 && segundo <= 59) //le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de mañana" << endl;
        }
    }
}

void asignarhora()
{
    int a = 4;
    for (int i = 0; i < 5; i++)
    {
        // Variables locales para la demostración
        int hora_demo = a; //le asignamos la variable a para que indique 4 para poder ver todo el ciclo del programa
        int minuto_demo = 0; //asignamos todo a cero para poder mostrarles todo el funcionamiento del programa
        int segundo_demo = 0; //asignamos todo a cero para poder mostrarles todo el funcionamiento del programa

        int dias[7] = { 0, 1, 2, 3, 4, 5, 6 };

        cout << "Hora demostracion: " << hora_demo << ":" << minuto_demo << ":" << segundo_demo << endl;
        for (int j = 0; j < 7; j++)
        {
            darsemana(dias[j]);
            if (hora_demo >= 12 && hora_demo <= 12)
            {
                cout << "Es de mediodia" << endl;
            }
            else if (hora_demo >= 13 && hora_demo <= 19)
            {
                cout << "Es de tarde" << endl;
            }
            else if (hora_demo >= 20 && hora_demo <= 23)
            {
                cout << "Es de noche" << endl;
            }
            else if (hora_demo >= 0 && hora_demo <= 5)
            {
                cout << "Es de madrugada" << endl;
            }
            else if (hora_demo >= 6 && hora_demo <= 11)
            {
                cout << "Es de mañana" << endl;
            }
        }
        a = a + 4; //va sumando de 4 en 4 para ir mostrando todo el ciclo del dia
    }
}

//funcion que devuelve el horario como string según la hora
string obtenerHorario(int h) {
    //esto nos devuelve en que parte del dia estamos
    if (h >= 0 && h <= 5) return "madrugada";
    else if (h >= 6 && h <= 11) return "mañana";
    else if (h == 12) return "mediodia";
    else if (h >= 13 && h <= 19) return "tarde";
    else return "noche";
}

//funcion que recorre todos los dias y dice si es miercoles o no con el horario
void mostrarDiaEspecial(int h) {
    for (int i = 0; i < 7; i++) //recorre todos los dias de la semana
    {
        string horario = obtenerHorario(h); //obtenemos en que parte del dia estamos

        if (i == 2) { // 2 = miercoles
            cout << "Hoy SÍ es miercoles, es de " << horario << endl;
        }
        else {
            cout << "No es miercoles, es de " << horario << endl;
        }
    }
}
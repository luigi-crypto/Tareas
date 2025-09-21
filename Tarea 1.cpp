#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

// Obtenemos la hora actual del sistema
time_t ahora = time(0);        // tiempo en segundos desde 1970
tm* tiempoLocal = localtime(&ahora); // convierte a hora local

int hora = tiempoLocal->tm_hour;   // hora (0–23)
int minuto = tiempoLocal->tm_min;  // minuto (0–59)
int segundo = tiempoLocal->tm_sec; // segundo (0–59)

//esto lo sacamos de chat gpt que es el como programar para que nos de la hora actual 
//todo lo demas es mio

int dias[7] = { 0, 1, 2, 3, 4, 5, 6 };//esta array va a darle un numero a cada dia de la semana empezando por domingo y terminando por sabado  

void darsemana(int dia) {
    switch (dia) {//este switch le asigna a cada numero un dia de la semana
    case 0: cout << "Lunes" << endl; break;
    case 1: cout << "Martes" << endl; break;
    case 2: cout << "Miercoles" << endl; break;
    case 3: cout << "Jueves" << endl; break;
    case 4: cout << "Viernes" << endl; break;
    case 5: cout << "Sabado" << endl; break;
    case 6: cout << "Domingo" << endl; break;
    default: cout << "Dia invalido" << endl;
    }
}//esta array le asigna a cada numero un dia de la semana

void darhora()
{
    cout << "Hora actual: " << hora << ":" << minuto << ":" << segundo << endl;
    for (int i = 0; i < 7; i++)//este for recorre la array de dias para mostrar los dias de la semana y aparte nos da el horario en el que estamos
    {
        darsemana(dias[i]);
        if (hora >= 12 && minuto >= 0 && segundo >= 0 && hora <= 12 && minuto <= 59 && segundo <= 59)//le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es mediodia" << endl;
        }
        else if (hora >= 13 && minuto >= 0 && segundo >= 0 && hora <= 19 && minuto <= 59 && segundo <= 59)//le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de tarde" << endl;
        }
        else if (hora >= 20 && minuto >= 0 && segundo >= 0 && hora <= 23 && minuto <= 59 && segundo <= 59)//le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de noche" << endl;
        }
        else if (hora >= 0 && minuto >= 0 && segundo >= 0 && hora <= 5 && minuto <= 59 && segundo <= 59)//le ponemos un tope a la hora para que nos muestre bien todo el horario
        {
            cout << "Es de madrugada" << endl;
        }
        else if (hora >= 6 && minuto >= 0 && segundo >= 0 && hora <= 11 && minuto <= 59 && segundo <= 59)//le ponemos un tope a la hora para que nos muestre bien todo el horario
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
        hora = a;//le asignamos la variable a para que indique 4 para poder ver todo el ciclo del programa
        minuto = 0;//asignamos todo a cero para poder mostrarles todo el funcionamiento del programa
        segundo = 0;//asignamos todo a cero para poder mostrarles todo el funcionamiento del programa
        darhora();//mandamos llamar a la funcion darhora en el for para que cambie segun la hora
        a = a + 4;//va sumando de 4 en 4 para ir mostrando todo el ciclo del dia
    }

}




int main()
{
    cout << "Hola primero demostrare como funciona el programa" << endl;
    darhora();//en esta funcion que tiene un for recorre la array de dias para mostrar los dias de la semana
    //y ademas muestra la hora actual y en que momento del dia estamos
    cout << "Ahora mostrare todo el ciclo del dia para que vean como funciona el programa" << endl;
    asignarhora();
    cout << "Para el dia elegido va a ser el miercoles" << endl;
    //ahora para que el dia sea diferente y pueda decir "no es martes pero ya es medio dia o tarde haremos lo siguiente"
    //crearemos una nueva funcion parecida a la que ya tenemos solo que va a elegir un numero al azar y por ejemplo
    //es el 3 que es miercoles va a decir
    //hoy no es domingo pero es mediodia o tarde o noche o madrugada o manana
    //hoy no es lunes pero es mediodia o tarde o noche o madrugada o manana
    //blblalba
    //hoy es miercoles y es mediodia
    //y asi con todos los dias de la semana
    //entonces digamos que hoy es martes

}


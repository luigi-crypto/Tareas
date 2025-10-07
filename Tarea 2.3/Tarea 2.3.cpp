//Ejercicio de clases : 40 puntos.
//NOTA: para esta parte van a necesitar pensarle un poco más, por eso valor más.
//2) Hacer una clase(class) llamada Rect, la cual tiene dentro variables para almacenar una coordenada X, una coordenada Y, un alto y un ancho.Para que lo conceptualicen mejor, un Rect sería un rectángulo en un espacio 2D y X, Y nos define la posición dónde empieza y cuánto alto y ancho tiene a partir de esa posición.
//2.1) Hacer un constructor por defecto que ponga todos esos valores en 0.
//2.2) Hacer un constructor que reciba un parámetro para asignar a cada uno de esos valores.
//2.3) Hacer un constructor que reciba solo dos parámetros, uno para alto y otro para ancho y los asigne.Además, que a las coordenadas X y Y les ponga 0.
//2.4) Hacer una función(método) que reciba por referencia una variable de tipo Rect e imprima las coordenadas X y Y de dicha variable, así como las coordenadas X y Y donde terminaría ese Rect tomando en cuenta su Alto y Ancho.La función debe regresar false si al menos uno de los campos del Rect es menor que 0, y regresar true al final si todo sale bien.Además, saquen las coordenadas X y Y donde terminaría dicho Rect como dos parámetros por referencia.
//2.5) Hacer una función(método) llamada CheckOverlap que reciba dos Rect y regrese true si hay un traslape entre dichos Rect, es decir, si en al menos un punto ocupan el mismo espacio.De lo contrario, regresa false.Ejemplos: los rects{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 6, Y = 6, Alto = 5, Ancho = 5 } no se traslapan, mientras que{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 2, Y = 2, Alto = 2, Ancho = 2 } sí.También{ X = 0, Y = 0, Alto = 5, Ancho = 5 } y{ X = 1, Y = 1, Alto = 7.5, Ancho = 2 } se traslapan.Usen estos ejemplos en su código para demostrar que su función es correcta.
#include <iostream>
#include "Tarea 2.3.h"
using namespace std;

Rect::Rect() {
    x = 0;
    y = 0;
    alto = 0;
    ancho = 0;
}

Rect::Rect(double x, double y, double alto, double ancho) {
    this->x = x;
    this->y = y;
    this->alto = alto;
    this->ancho = ancho;
}

Rect::Rect(double alto, double ancho) {
    x = 0;
    y = 0;
    this->alto = alto;
    this->ancho = ancho;
}

bool imprimircoor(Rect& rect, double& X, double& Y)
{
    if (rect.x < 0 || rect.y < 0 || rect.alto < 0 || rect.ancho < 0) {
        cout << "Error al menos uno de los campos del Rect es menor que 0." << endl;
        return false;
    }
    else {
        X = rect.x + rect.ancho;
        Y = rect.y + rect.alto;
        cout << "Coordenadas iniciales: (" << rect.x << ", " << rect.y << ")" << endl;
        cout << "Coordenadas finales: (" << X << ", " << Y << ")" << endl;
        return true;
    }
}

bool CheckOverlap(const Rect& rect1, const Rect& rect2) {
    if (rect1.x < rect2.x + rect2.ancho && rect1.x + rect1.ancho > rect2.x && rect1.y < rect2.y + rect2.alto && rect1.y + rect1.alto > rect2.y)
    {
        return true;
    }
    return false;
}

int main()
{
    Rect rect1(0, 0, 5, 5);
    Rect rect2(6, 6, 5, 5);
    Rect rect3(2, 2, 2, 2);
    Rect rect4(1, 1, 7.5, 2);
    double X, Y;

    imprimircoor(rect1, X, Y);
    imprimircoor(rect2, X, Y);
    imprimircoor(rect3, X, Y);
    imprimircoor(rect4, X, Y);

    if (CheckOverlap(rect1, rect2)) {
        cout << "Rect1 y Rect2 se traslapan? Si" << endl;
    }
    else {
        cout << "Rect1 y Rect2 se traslapan? No" << endl;
    }

    if (CheckOverlap(rect1, rect3)) {
        cout << "Rect1 y Rect3 se traslapan? Si" << endl;
    }
    else {
        cout << "Rect1 y Rect3 se traslapan? No" << endl;
    }

    if (CheckOverlap(rect1, rect4)) {
        cout << "Rect1 y Rect4 se traslapan? Si" << endl;
    }
    else {
        cout << "Rect1 y Rect4 se traslapan? No" << endl;
    }

    return 0;
}
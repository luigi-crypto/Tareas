#pragma once
//en este archivo va la declaracion de la clase y las funciones
//aqui estan las de este archivo
class Rect {
	public:
	double x;
	double y;
	double alto;
	double ancho;
	Rect(); //constructor por defecto
	Rect(double x, double y, double alto, double ancho); //constructor con 4 parametros
	Rect(double alto, double ancho); //constructor con 2 parametros
};
bool imprimircoor(Rect& rect, double& X, double& Y);
bool CheckOverlap(const Rect& rect1, const Rect& rect2);

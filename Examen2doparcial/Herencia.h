#pragma once
#include <iostream>

using namespace std;


//clase padre
class Figura {
private:
    string nombre;

public:
    Figura(string name) : nombre(name) {}

    virtual ~Figura() {}

	//para que las hereden obligatoriamente las clases hijas
    virtual float CalcularArea() = 0;
    virtual float CalcularPerimetro() = 0;

    const string& ObtenerNombreDeFigura() {
        return nombre;
    }
};

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(string name, float r) : Figura(name), radio(r) 
    {
    }
    virtual ~Circulo() override 
    {
    }

    //override confirma que estamos sobrescribiendo
    virtual float CalcularArea() override;
    virtual float CalcularPerimetro() override;
};

class Cuadrado : public Figura {
protected:
    //protected para que Cubo pueda acceder a lado
    float lado;

public:
    Cuadrado(string name, float l) : Figura(name), lado(l)
    {
    }
    virtual ~Cuadrado() override 
    {
    }

    virtual float CalcularArea() override;
    virtual float CalcularPerimetro() override;
};

class FiguraNLados : public Figura {
private:
    int numLados;
    float longitudLado;

public:
    FiguraNLados(string name, int n, float l) : Figura(name), numLados(n), longitudLado(l)
    {
    }
    virtual ~FiguraNLados() override 
    {
    }

    virtual float CalcularArea() override;
    virtual float CalcularPerimetro() override;
};

class Cubo : public Cuadrado {
public:
    Cubo(string name, float l) : Cuadrado(name, l)
    {
    }

    virtual ~Cubo() override
    {
    }
    virtual float CalcularArea() override;
    virtual float CalcularPerimetro() override;
    virtual float CalcularVolumen();
};

class Linea : public Figura {
private:
    float* segmentos;
    int numSegmentos;

public:
    Linea(string name, float* arregloIn, int tamano);
    virtual ~Linea() override;

    virtual float CalcularArea() override;
    virtual float CalcularPerimetro() override;
};

int PruebaHerencia();

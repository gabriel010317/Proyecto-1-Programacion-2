#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Producto
{
protected:
	string nombre;
	float precio;
	int cantidad;
public:
	Producto();
	Producto(string,float,int);
	~Producto();

    string getNombre() const;
    void setNombre(string);

	virtual float getPrecio() = 0;
    void setPrecio(float);

    int getCantidad() const;
    void setCantidad(int);

	string toString();
};


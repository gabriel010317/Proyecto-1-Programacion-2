#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class producto
{
private:
	string nombre;
	float precio;
	int cantidad;
public:
	producto();
	producto(string,float,int);
	~producto();

    string getNombre() const;
    void setNombre(string);

	virtual float getPrecio() = 0;
    void setPrecio(float);

    int getCantidad() const;
    void setCantidad(int);

	string toString() {
		stringstream x;
		return x.str();
	}
};


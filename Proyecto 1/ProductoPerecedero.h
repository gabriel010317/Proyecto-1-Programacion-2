#pragma once
#include "Producto.h"
#include "Fecha.h"

class ProductoPerecedero:public Producto
{
	Fecha *fechaDeVencimiento;
	float precioFinal;
public:
	ProductoPerecedero(string, float, int, int, int, int);
	float getPrecio();
	void calcularPrecio(Fecha*);
	string toString();
};


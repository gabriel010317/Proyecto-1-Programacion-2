#pragma once
#include "Producto.h"
using namespace std;
class ProductoNoPerecedero : public Producto
{
private:
	float porcentajeDeDescuento;
public:
	ProductoNoPerecedero(string, float, int, float);
	float getPrecio();
	void setPorcentajeDeDescuento(float);
	string toString();
};


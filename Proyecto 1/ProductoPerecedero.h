#pragma once
#include "producto.h"
#include "Fecha.h"

class ProductoPerecedero:public producto
{
private:
	ProductoPerecedero(string, float, int, Fecha);
public:
	float getPrecio();
};


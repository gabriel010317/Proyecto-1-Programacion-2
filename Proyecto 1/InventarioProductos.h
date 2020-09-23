#pragma once
#include <iostream>
#include "Producto.h"
#include "Colecciones/IIterable.h"
#include "Colecciones/IList.h"

class InventarioProductos
{
private:
	IList* productos;
public:
	InventarioProductos(IList*);
	void agregarProducto(Producto*);
	void eliminarProducto(string);
	Producto* consultarProducto(string);
	string toString();
	~InventarioProductos();

};
#pragma once
#include "Producto.h";
class Nodo{
private:
	Producto * producto;
	Nodo * siguiente;
public:
	Nodo(Producto*, Nodo*);

	void setProducto(Producto*);
	Producto *getProducto();

	void setSiguiente(Nodo*);
	Nodo* getSiguiente();

	string toString();
	~Nodo();
};
#include "Nodo.h"

Nodo::Nodo(Producto* producto, Nodo* nodo) {
	this->producto = producto;
	this->siguiente = nodo;
}

void Nodo::setProducto(Producto* producto) {
	this->producto = producto;
}

Producto*  Nodo::getProducto() {
	return producto; 
}

void Nodo::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

Nodo* Nodo::getSiguiente() {
	return siguiente;
}

string Nodo::toString() {
	return  this->producto->toString();
}

Nodo:: ~Nodo() {
	delete producto;
}
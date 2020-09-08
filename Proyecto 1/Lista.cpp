#include "Lista.h"

Lista::Lista(){
	this->pInicio = NULL;
}

void Lista::insertar(Producto* producto){
	if (this->pInicio == NULL)
		this->pInicio = new Nodo(producto, NULL);
	else {
		Nodo* pActual = this->pInicio;
		while (pActual->getSiguiente() != NULL) {
			pActual = pActual->getSiguiente();
		}
		pActual->setSiguiente(new Nodo(producto, NULL));
	}
}

string Lista::toString(){
	stringstream s;
	Nodo* pActual = pInicio;
	while (pActual != NULL){
		s << pActual->toString();
		pActual = pActual->getSiguiente();
	}
	return s.str();
}

Iterador* Lista::obtenerIterador(){
	return new Iterador(pInicio);
}

Lista::~Lista() {
	while (this->pInicio != NULL) {
		Nodo* eliminado = this->pInicio;
		this->pInicio = this->pInicio->getSiguiente();
		delete eliminado;
	}
}
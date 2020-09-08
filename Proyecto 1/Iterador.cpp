#include "Iterador.h"

Iterador::Iterador(Nodo* nodo)
	:cursor(nodo) {
	pInicial = nodo;
}

bool Iterador::estaVacio() const{
	return cursor != NULL;
}

Producto* Iterador::elementoActual() const{
	return cursor->getProducto();
}

void Iterador::primero(){
	cursor = pInicial;
}

void Iterador::siguiente(){
	cursor = cursor->getSiguiente();
}

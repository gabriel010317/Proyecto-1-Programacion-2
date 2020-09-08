#pragma once
#include "Nodo.h"

class Iterador {
private:
	Nodo* cursor;
	Nodo* pInicial;
public:
	Iterador(Nodo*);
	bool estaVacio() const;
	Producto* elementoActual() const;
	void primero();
	void siguiente();
};
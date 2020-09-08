#pragma once
//#include "Nodo.h"
#include "Iterador.h"

class Lista{
private:
	Nodo *pInicio;
	//Nodo *pFinal;
public:
	Lista();
	void insertar(Producto*);
	string toString();
	Iterador* obtenerIterador();
	~Lista();
}; 

#include "IteradorArrayList.h"

IteradorArrayList::IteradorArrayList(ObjetoBase** arreglo, int cantidad)
{
	this->arreglo = arreglo;
	this->cantidad = cantidad;
	this->posicionActual = 0;
}

bool IteradorArrayList::haySiguiente()
{
	if (this->posicionActual >= this->cantidad)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ObjetoBase* IteradorArrayList::actual()
{
	if (this->haySiguiente()) {
		ObjetoBase* dato = this->arreglo[this->posicionActual];
		this->posicionActual++;
		return dato;
	}
	return nullptr;
}

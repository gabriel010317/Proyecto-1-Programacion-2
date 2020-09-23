#pragma once
#include "IMaquinaVendedora.h"
#include "producto.h"
#include "EntradaSalida.h"
#include "Fecha.h"
#include "InventarioProductos.h"

class MenuCobro
{

private:
	//monedero
	InventarioProductos* productos;
	Fecha* hoy;

public:
	MenuCobro(InventarioProductos *,Fecha*);
	MenuCobro();
	void invocarMenu();
	void imprimirProductos();

private:
	char mostrarOpciones();
	string logo();
	string miniLogo();
};

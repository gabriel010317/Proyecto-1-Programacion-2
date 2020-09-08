#pragma once
#include "IMaquinaVendedora.h"
#include "producto.h"
class MenuCobro
{

private:
	//monedero

public:
	MenuCobro();
	void invocarMenu();


private:
	char mostrarOpciones();
	string logo();
};

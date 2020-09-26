#pragma once
//#include "IMaquinaVendedora.h"
#include "Maquina.h"
#include "producto.h"
#include "EntradaSalida.h"
#include "Fecha.h"
#include "InventarioProductos.h"
#include "IMaquinaVendedora.h"

class MenuCobro
{
private:
	//monedero
	//IMaquinaVendedora* maquina;
	//Fecha* hoy; Para que ocupa la fecha??????
	/*
		No logre hacer la implementacion con IMaquinaVendedora, 
		la interfaz no tiene manera de imprimir productos, por lo 
		tanto, asocie el menu cobro directamente a Maquina (ver UML)

		Si se puede, implementarlo con la interfaz de la maquina 
		vendedora.

		Borre este comentario :D
	*/

	Maquina* maquina;
public:
	//MenuCobro(IMaquinaVendedora*,Fecha*); No se ocupa fecha ¿?
	MenuCobro(Maquina*);
	void invocarMenu();

private:
	void imprimirProductos();
	char mostrarOpciones();
	string logo();
	string miniLogo();
};

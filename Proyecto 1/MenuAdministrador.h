#pragma once
#include "IMaquinaAdministradora.h"
#include "InventarioProductos.h"
#include "EntradaSalida.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "Fecha.h"
class MenuAdministrador
{

private:
	InventarioProductos* productos;
	Fecha* hoy;
public:
	MenuAdministrador(InventarioProductos*, Fecha*);
	void invocarMenu();


private:
	char mostrarOpciones();
	string logo();
	string miniLogo();

	
	virtual int getIdentificador();
	void ingresarProducto();
	virtual string getNombre();
	virtual void setNombre();
	virtual string toString();
	virtual void imprimirProductos();
	virtual Producto* crearProducto();
	virtual void agregarProviciones();
	virtual void disminuirProviciones();
	virtual void borrar();
	virtual Producto* consulta(string id);
	virtual void ingresarDinero();
	virtual void retirarDinero(int cantidad);


};
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

	
	virtual int getIdentificador();
	void ingresarProducto();
	virtual string getNombre();
	virtual void setNombre();
	virtual string toString();
	virtual void imprimirProductos();
	virtual Producto* crearProducto();
	virtual void agregarProviciones(string idProducto);
	virtual void disminuirProviciones(string idProducto);
	virtual void borrar(string id);
	virtual Producto* consulta(string id);
	virtual void ingresarDinero();
	virtual void retirarDinero(int cantidad);


};
#pragma once
#include "IMaquinaAdministradora.h"
#include "producto.h"
class MenuAdministrador
{

private:
	//InventarioAlimentos* inventarioAlimentos;

public:
	MenuAdministrador();
	void invocarMenu();


private:
	char mostrarOpciones();
	string logo();


	virtual int getIdentificador();
	virtual string getNombre();
	virtual void setNombre();
	virtual string toString();
	virtual void insertar(Producto* p);
	virtual void agregarProviciones(string idProducto, int cantidad);
	virtual void disminuirProviciones(string idProducto, int cantidad);
	virtual void borrar(string id);
	virtual Producto* consulta(string id);
	virtual void ingresarDinero();
	virtual void retirarDinero(int cantidad);


};
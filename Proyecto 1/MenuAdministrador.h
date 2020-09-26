#pragma once
#include "IMaquinaAdministradora.h"
#include "InventarioProductos.h"
#include "EntradaSalida.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "IMaquinaAdministradora.h"
#include "Fecha.h"

class MenuAdministrador
{
private:
	IMaquinaAdministradora* Maquina;
	Fecha* hoy;
public:
	MenuAdministrador(IMaquinaAdministradora*, Fecha*);

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
	virtual void consultarProducto();
	virtual void disminuirProviciones();
	virtual void borrar();
	virtual Producto* consulta(string id);
	virtual void ingresarDinero();
	virtual void retirarDinero();


};
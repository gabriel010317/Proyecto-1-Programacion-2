#pragma once
#include "IMaquinaAdministradora.h"
#include "IMaquinaVendedora.h"
#include "InventarioProductos.h"
#include "MonederoElectronico.h"
#include "Producto.h"
#include "Colecciones/IList.h"
#include "Colecciones/IIterador.h"
#include "Colecciones/ArrayList.h"
#include "Colecciones/LinkedList.h"
#include <exception>

using namespace std;

class Maquina : public IMaquinaAdministradora, public IMaquinaVendedora{
private:
	int identificador;
	string nombre;
	InventarioProductos* productos;
	MonederoElectronico* monedero;
public:
	Maquina(int, string, MonederoElectronico*, InventarioProductos*);

	int getIdentificador();

	string getNombre();
	void setNombre(string);

	string toString();

	//Administran porductos
	void insertarProducto(Producto*);
	void agregarProvisiones(string, int);
	void disminuirProvisiones(string, int);
	void borrar(string);
	Producto* consultar(string);
	string mostrarProductos();
	string mostrarProductosPorPosicion();
	Producto* mostrarProductoPorPosicion(int);

	//Administran el monedero
	void ingresarDinero(int);
	void retirarDinero(int);

	//Realizar compra de productos
	string realizarCompra(string, int, int);

	~Maquina();
};


#include <iostream>
#include "Fecha.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
#include "IMaquinaAdministradora.h"
#include "Colecciones/ArrayList.h"
#include "Colecciones/LinkedList.h"
#include "EntradaSalida.h"

using namespace std;

int main() 
{ 

	Fecha* Hoy = new Fecha(1, 1, 2020);
	InventarioProductos* productos = new InventarioProductos(new ArrayList(10));
	MenuAdministrador* MA = new MenuAdministrador(productos, Hoy);
	MenuCobro* MC = new MenuCobro(productos,Hoy);
	MenuPrincipal* MP = new MenuPrincipal(MA, MC);

	MP->invocarMenu();
	
	
	ProductoPerecedero* Arroz = new ProductoPerecedero("Arroz", 1500, 1, 20, 1, 2020);
	Arroz->calcularPrecio(Hoy);
	cout << Arroz->toString() << endl;
	cin.get();
}

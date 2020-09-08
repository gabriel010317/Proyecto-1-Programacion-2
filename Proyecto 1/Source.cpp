#include <iostream>
#include "Fecha.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
#include "IMaquinaAdministradora.h"

using namespace std;

int main() 
{ 
	MenuAdministrador* MA = new MenuAdministrador();
	MenuCobro* MC = new MenuCobro();
	MenuPrincipal* MP = new MenuPrincipal(MA, MC);

	MP->invocarMenu();
	
	
	
	Fecha* Hoy = new Fecha(1, 1, 2020);
	ProductoPerecedero* Arroz = new ProductoPerecedero("Arroz", 1500, 1, 20, 1, 2020);
	Arroz->calcularPrecio(Hoy);
	cout << Arroz->toString() << endl;
	cin.get();
}

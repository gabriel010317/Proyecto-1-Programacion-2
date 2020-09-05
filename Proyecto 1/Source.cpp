#include <iostream>
#include "Fecha.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
using namespace std;

int main() { 
	Fecha* Hoy = new Fecha(1, 1, 2020);
	ProductoPerecedero* Arroz = new ProductoPerecedero("Arroz", 1500, 1, 20, 1, 2020);
	Arroz->calcularPrecio(Hoy);
	cout << Arroz->toString() << endl;
	cin.get();
}

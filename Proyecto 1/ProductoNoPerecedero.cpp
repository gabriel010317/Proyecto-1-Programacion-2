#include "ProductoNoPerecedero.h"
ProductoNoPerecedero::ProductoNoPerecedero(string nom, float pre, int can, float des)
	:Producto(nom, pre, can), porcentajeDeDescuento(des) 
{

}

float ProductoNoPerecedero::getPrecio() {
	return precio - (precio * porcentajeDeDescuento);
}

void ProductoNoPerecedero::setPorcentajeDeDescuento(float des)
{
	this->porcentajeDeDescuento = des;
}
string ProductoNoPerecedero::toString() {
	stringstream x;
	x << Producto::toString();
	x << "Precio unitario: " << this -> getPrecio();
	x << "\n----------------------------------------------\n\n";
	return x.str();
 }
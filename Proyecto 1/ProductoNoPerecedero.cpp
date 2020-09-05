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
	x << Producto::toString() << endl;
	x << "Precio: " << this -> getPrecio();
	return x.str();
 }
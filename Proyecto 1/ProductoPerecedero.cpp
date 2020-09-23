#include "ProductoPerecedero.h"
ProductoPerecedero::ProductoPerecedero(string nom, float pre, int can, int d, int m, int a)
	:Producto(nom, pre, can), precioFinal(0.0)
{
	fechaDeVencimiento = new Fecha(d, m, a);
}

float ProductoPerecedero::getPrecio()
{
	return precioFinal;
}
void ProductoPerecedero::calcularPrecio(Fecha* actual) {
	bool descuento = false;
	if ((actual->getMes() == fechaDeVencimiento->getMes()) && ((actual->getDia() + 7) >= fechaDeVencimiento->getDia()))
		descuento = true;
	else {
		if (actual->getMes() < fechaDeVencimiento->getMes()) {
			if ((fechaDeVencimiento->getDia() < 23) || (actual->getDia() > 7)) {
				descuento = true;
			}
			else {
				if ((30 - actual->getDia()) + fechaDeVencimiento->getDia() >= 7)
					descuento = true;
			}
		}
	}
	if (descuento) {
		precioFinal = precio / 2;
	}
	else {
		precioFinal = precio;
	}
}

string ProductoPerecedero::toString() {
	stringstream x;
	x << Producto::toString();
	x << "	Precio Unitario: " << precioFinal;
	x << "	Fecha de vencimiento: " << fechaDeVencimiento->toStringLineal() << endl;
	x << "\n----------------------------------------------\n";
	return x.str();
}

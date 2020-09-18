#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(){
	this->dinero = 0;
}

MonederoElectronico::MonederoElectronico(float montoInicial){
	this->dinero = (int)montoInicial;
}

string MonederoElectronico::desgloceVuelto(string& compra){
	stringstream r(compra);
	/*r << "Monto Total: " << totalCompra << endl;
	r << "Monto Pagado: " << montoPago << endl;
	r << "---------------Desgloce de Vuelto---------------" << endl;
	int vuelto = montoPago - totalCompra;
	int contador = 0;
	while (vuelto > 0) {
		if (vuelto % 2000) {
			for (int i = vuelto; i % 2000; i - 2000)
				contador += 1;
			r << contador << "Billete(s) de 2000." << endl;
		}
		if (vuelto % 1000) {
			for (int i = vuelto; i % 1000; i - 1000)
				contador += 1;
			r << contador << "Billete(s) de 1000." << endl;
		}
		if (vuelto % 500) {
			for (int i = vuelto; i % 500; i - 500)
				contador += 1;
			r << contador << "Moneda(s) de 500." << endl;
		}
		if (vuelto % 100) {
			for (int i = vuelto; i % 100; i - 100)
				contador += 1;
			r << contador << "Moneda(s) de 100." << endl;
		}
	}*/
	return r.str();
}

void MonederoElectronico::setDinero(int dinero){
	this->dinero = dinero;
	//this->dinero += dinero;
}

int MonederoElectronico::getDinero(){
	return this->dinero;
}

string MonederoElectronico::toString(){
	stringstream s;
	s << "Monto contenido en monedero electronico: ";
	s << this->dinero << endl;
	return s.str();
}

MonederoElectronico::~MonederoElectronico(){

}

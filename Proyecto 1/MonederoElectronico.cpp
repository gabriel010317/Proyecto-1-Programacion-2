#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(){
	this->dinero = 0;
}

MonederoElectronico::MonederoElectronico(float montoInicial){
	this->dinero = (int)montoInicial;
}

string MonederoElectronico::desgloceVuelto(string &compra){
	stringstream r;
	string auxiliar;
	int vuelto = 0;
	r << compra;
	r << "---------------Desgloce de Vuelto---------------" << endl;
	while (!r.eof()) {
		r >> auxiliar;
		if (stringstream(auxiliar) >> vuelto) {
			while (vuelto > 0) {
				int contador = 0;
				if (vuelto % 2000) {
					for (vuelto; vuelto % 2000; vuelto - 2000)
						contador += 1;
					r << contador << "Billete(s) de 2000." << endl;
				}
				if (vuelto % 1000) {
					for (vuelto; vuelto % 1000; vuelto - 1000)
						contador += 1;
					r << contador << "Billete(s) de 1000." << endl;
				}
				if (vuelto % 500) {
					for (vuelto; vuelto % 500; vuelto - 500)
						contador += 1;
					r << contador << "Moneda(s) de 500." << endl;
				}
				if (vuelto % 100) {
					for (vuelto; vuelto % 100; vuelto - 100)
						contador += 1;
					r << contador << "Moneda(s) de 100." << endl;
				}
			}
		}
		auxiliar.clear();
	}
	return r.str();
}

void MonederoElectronico::setDinero(int dinero){
	this->dinero = dinero;
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

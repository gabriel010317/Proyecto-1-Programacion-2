#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(){
	this->dinero = 0;
}

MonederoElectronico::MonederoElectronico(float montoInicial){
	this->dinero = (int)montoInicial;
}

string MonederoElectronico::desgloceVuelto(string &compra){
	stringstream r, s;
	string auxiliar;
	int vuelto = 0;
	int contador;
	s << "---------------Desgloce de Vuelto---------------" << endl;
	r << compra;
	while (!r.eof()) {
		r >> auxiliar;
		if (stringstream(auxiliar) >> vuelto) {
			while (vuelto > 0) {
				contador = 0;
				while (vuelto > 0 && vuelto >= 2000) {
					contador += 1;
					vuelto -= 2000;
					}
				s << contador << " Billete(s) de 2000." << endl;
				
				contador = 0;
				while (vuelto > 0 && vuelto >= 1000) {
					contador += 1;
					vuelto -= 1000;
				}
				s << contador << " Billete(s) de 1000." << endl;
				
				contador = 0;
				while (vuelto > 0 && vuelto >= 500) {
					contador += 1;
					vuelto -= 500;
				}
				s << contador << " Moneda(s) de 500." << endl;;

				contador = 0;
				while (vuelto > 0 && vuelto >= 100) {
					contador += 1;
					vuelto -= 100;
				}
				s << contador << " Monedas(s) de 100." << endl;
				s << "Valor de vuelto no retornable: " << vuelto << endl;
			}
		}
		auxiliar.clear();
	}
	return s.str();
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

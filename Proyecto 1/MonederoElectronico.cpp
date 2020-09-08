#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(){
	this->dinero = 0;
}

MonederoElectronico::MonederoElectronico(float montoInicial){
	this->dinero = (int)montoInicial;
}

string MonederoElectronico::desgloceVuelto(string& compra){
	return string();
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

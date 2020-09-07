#include "MonederoElectronico.h"

MonederoElectronico::MonederoElectronico(){
	this->dinero = 0;
}

MonederoElectronico::MonederoElectronico(float montoInicial){
	this->dinero = montoInicial;
}

string MonederoElectronico::desgloceVuelto(string& compra){
	return string();
}

void MonederoElectronico::setDinero(int dinero){
	this->dinero += dinero;
}

int MonederoElectronico::getDinero(){
	return dinero;
}

string MonederoElectronico::toString(){
	return string();
}

MonederoElectronico::~MonederoElectronico(){

}

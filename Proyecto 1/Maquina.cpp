#include "Maquina.h"

Maquina::Maquina(int identificador, string nombre, MonederoElectronico* monedero){
	this->identificador = identificador;
	this->nombre = nombre;
	this->monedero = monedero;
	//this->productos = NULL
}

int Maquina::getIdentificador(){
	return this->identificador;
}

string Maquina::getNombre(){
	return this->nombre;
}

void Maquina::setNombre(string nombre){
	this->nombre = nombre;
}

string Maquina::toString(){
	stringstream s;
	s << "Identificador de Maquina: ";
	s << this->identificador << endl;
	s << "Nombre de Maquina: ";
	s << this->nombre << endl;
	s << this->productos->toString();
	s << this->monedero->toString();
	return string();
}

void Maquina::insertarProducto(Producto* producto){
	if (producto != NULL)
		productos->insertar(producto);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad){
	
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad){

}

void Maquina::borrar(string algo){

}

Producto* Maquina::consultar(string nombre){
	Iterador* iterador = this->productos->obtenerIterador();
	iterador->primero();
	while (iterador->estaVacio()) {
		if (iterador->elementoActual()->getNombre() == nombre)
			return iterador->elementoActual();
		iterador->siguiente();
	}
	delete iterador;
}

void Maquina::ingresarDinero(int cantidad){
	this->monedero->setDinero(cantidad);
}

void Maquina::retirarDinero(int cantidad){
	this->monedero->setDinero(this->monedero->getDinero() - cantidad);
}

string Maquina::realizarCompra(string idProducto, int cantidad, int montoPago){
	return string();
}

Maquina::~Maquina(){
	delete productos;
	delete monedero;
}

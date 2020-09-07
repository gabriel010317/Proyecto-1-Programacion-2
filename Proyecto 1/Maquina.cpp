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
	return string();
}

void Maquina::insertarProducto(Producto* producto){
	//productos->agregar(producto);
}

void Maquina::agregarProvisiones(string idProductos, int cantidad){

}

void Maquina::disminuirProvisiones(string idProducto, int cantidad){

}

void Maquina::borrar(string algo){

}

Producto* Maquina::consultar(string algo){
	return nullptr;
}

void Maquina::ingresarDinero(int cantidad){

}

void Maquina::retirarDinero(int cantidad){
}

string Maquina::realizarCompra(string idProducto, int cantidad, int montoPago){
	return string();
}

Maquina::~Maquina(){
	//delete productos;
	delete monedero;
}

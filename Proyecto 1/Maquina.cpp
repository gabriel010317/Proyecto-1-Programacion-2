#include "Maquina.h"

Maquina::Maquina(int identificador, string nombre, MonederoElectronico* monedero, IList* productos){
	this->identificador = identificador;
	this->nombre = nombre;
	this->monedero = monedero;
	this->productos = productos;
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
		productos->insertarAlFinal(producto);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad){
	
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad){

}

void Maquina::borrar(string algo){

}

Producto* Maquina::consultar(string nombre){
	IIterador* iterador = this->productos->obtenerIterador();
	Producto* Resultado = nullptr;
	while (iterador->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iterador->actual());
		if (actual->getNombre() == nombre){
			Resultado = actual;
			break;
		}
	}
	delete iterador;
	return Resultado;
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

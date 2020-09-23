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
	IIterador* iterador = this->productos->obtenerIterador();
	while (iterador->haySiguiente()) {
		if (dynamic_cast<Producto*>(iterador->actual())->getNombre() == idProducto) {
			dynamic_cast<Producto*>(iterador->actual())->setCantidad(dynamic_cast<Producto*>(iterador->actual())->getCantidad() + cantidad);
			break;
		}
	}
	delete iterador;
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad){
	IIterador* iterador = this->productos->obtenerIterador();
	while (iterador->haySiguiente()) {
		if (dynamic_cast<Producto*>(iterador->actual())->getNombre() == idProducto) {
			dynamic_cast<Producto*>(iterador->actual())->setCantidad(dynamic_cast<Producto*>(iterador->actual())->getCantidad() - cantidad);
			break;
		}
	}
	delete iterador;
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
	stringstream s;
	int totalCompra = 0;
	string vuelto;
	Producto* productoCompra = NULL;

	s << "---------------Recibo de Compra---------------" << endl;
	s << std::to_string(cantidad);

	IIterador* iterador = this->productos->obtenerIterador();
	while (iterador->haySiguiente()) {
		if (dynamic_cast<Producto*>(iterador->actual())->getNombre() == idProducto) {

			/*dynamic_cast<IMaquinaAdministradora*>(this)->disminuirProvisiones(idProducto, cantidad);
			productoCompra = dynamic_cast<IMaquinaAdministradora*>(this)->consultar(idProducto);*/

			productoCompra = dynamic_cast<Producto*>(iterador->actual());

			break;
		}
	}
	delete iterador;

	totalCompra = (productoCompra->getPrecio() * cantidad);

	s << "\t" << productoCompra->getNombre() << "\t" << totalCompra << endl;

	vuelto = s.str();
	s << this->monedero->desgloceVuelto(vuelto);

	delete productoCompra;

	return s.str();
}

Maquina::~Maquina(){
	delete productos;
	delete monedero;
}

#include "Maquina.h"

Maquina::Maquina(int identificador, string nombre, MonederoElectronico* monedero, InventarioProductos* productos){
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
		productos->agregarProducto(producto);
}

void Maquina::agregarProvisiones(string idProducto, int cantidad){
	if (consultar(idProducto)) {
		Producto* temp = consultar(idProducto);
		temp->setCantidad(temp->getCantidad() + cantidad);
	}
	else {
		throw logic_error("No se encontro el producto");
	}
}

void Maquina::disminuirProvisiones(string idProducto, int cantidad){
	if (consultar(idProducto)) {
		Producto* temp = consultar(idProducto);
		if (temp->getCantidad() >= cantidad)
			temp->setCantidad(temp->getCantidad() - cantidad);
		else
			throw logic_error("No se puede disminuir el producto en tal cantidad");
	}
	else {
		throw logic_error("No se encontro el producto");
	}
}

void Maquina::borrar(string id){
	if (consultar(id))
		this->productos->eliminarProducto(id);
	else
		throw logic_error("No se encontro el producto");
}

Producto* Maquina::consultar(string nombre){
	return this->productos->consultarProducto(nombre);
}

string Maquina::mostrarProductos()
{
	return this->productos->toString();
}

string Maquina::mostrarProductosPorPosicion()
{
	return this->productos->toStringPosicion();
}

void Maquina::ingresarDinero(int cantidad){
	this->monedero->setDinero(this->monedero->getDinero() + cantidad);
}

void Maquina::retirarDinero(int cantidad){
	if (this->monedero->getDinero() >= cantidad)
		this->monedero->setDinero(this->monedero->getDinero() - cantidad);
	else
		throw out_of_range("No hay suficiente dinero para retirar");
}

string Maquina::realizarCompra(string idProducto, int cantidad, int montoPago){
	Producto* productoCompra = dynamic_cast<IMaquinaAdministradora*>(this)->consultar(idProducto);
	int totalCompra = productoCompra->getPrecio() * cantidad;

	if (montoPago < totalCompra) {
		delete productoCompra;
		throw out_of_range("Monto de pago insuficiente.");
	}

	dynamic_cast<IMaquinaAdministradora*>(this)->disminuirProvisiones(idProducto, cantidad);
	dynamic_cast<IMaquinaAdministradora*>(this)->ingresarDinero(montoPago);


	stringstream s;
	s << "---------------Recibo de Compra---------------" << "\n";
	s << std::to_string(cantidad) << "\t";
	s << productoCompra->getNombre() << "\t";
	s << totalCompra << "\n";
	string voucher = s.str();

	delete productoCompra;

	stringstream r;
	r << this->monedero->desgloceVuelto(voucher);

	return r.str();
}

Maquina::~Maquina(){
	delete productos;
	delete monedero;
}

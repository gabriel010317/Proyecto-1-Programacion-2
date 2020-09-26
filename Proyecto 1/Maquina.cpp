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
	
	/*
	IIterador* iterador = this->productos->obtenerIterador();
	while (iterador->haySiguiente()) {
		if (dynamic_cast<Producto*>(iterador->actual())->getNombre() == idProducto) {
			dynamic_cast<Producto*>(iterador->actual())->setCantidad(dynamic_cast<Producto*>(iterador->actual())->getCantidad() + cantidad);
			break;
		}
	}
	delete iterador;*/
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
	
	
	/*
	IIterador* iterador = this->productos->obtenerIterador();
	while (iterador->haySiguiente()) {
		if (dynamic_cast<Producto*>(iterador->actual())->getNombre() == idProducto) {
			dynamic_cast<Producto*>(iterador->actual())->setCantidad(dynamic_cast<Producto*>(iterador->actual())->getCantidad() - cantidad);
			break;
		}
	}
	delete iterador;*/
}

void Maquina::borrar(string id){
	if (consultar(id))
		this->productos->eliminarProducto(id);
	else
		throw logic_error("No se encontro el producto");
}

Producto* Maquina::consultar(string nombre){
	return this->productos->consultarProducto(nombre);
	/*Producto* Resultado = nullptr;
	while (iterador->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(iterador->actual());
		if (actual->getNombre() == nombre){
			Resultado = actual;
			break;
		}
	}
	delete iterador;
	return Resultado;*/
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
	//this->monedero->setDinero(cantidad);
	this->monedero->setDinero(this->monedero->getDinero() + cantidad);
}

void Maquina::retirarDinero(int cantidad){
	//tenga cuidado con las implementaciones de este tipo
	//que pasa si va a retirar mas dinero del que tiene?

	if (this->monedero->getDinero() >= cantidad)
		this->monedero->setDinero(this->monedero->getDinero() - cantidad);
	else
		throw out_of_range("No hay suficiente dinero para retirar");
}

string Maquina::realizarCompra(string idProducto, int cantidad, int montoPago){
	/*stringstream s;
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
/*
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
	
	return s.str();*/
	return "por implementar";
}

Maquina::~Maquina(){
	delete productos;
	delete monedero;
}

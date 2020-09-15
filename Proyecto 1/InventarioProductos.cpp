#include "InventarioProductos.h"

InventarioProductos::InventarioProductos(IList* lista) : productos(lista){

}
void InventarioProductos::agregarProducto(Producto* prod) {
	this->productos->insertarAlFinal(prod);
}

void InventarioProductos::eliminarProducto(string id) {
	int contador = 0;
	IIterador* ite = this->productos->obtenerIterador();
	while (ite->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(ite->actual());
		if (actual->getNombre() == id) {
			this->productos->borrarEnPosicion(contador);
			break;
		}
		contador++;
	}
}
Producto* InventarioProductos::consultarProducto(string busqueda){
	IIterador* ite = this->productos->obtenerIterador();
	Producto* resultado = nullptr;
	while (ite->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(ite->actual());
		if (actual->getNombre() == busqueda) {
			resultado = actual;
			break;
		}
	}
	delete ite;
	return resultado;
}

string InventarioProductos::toString() {
	return this->productos->toString();
}

InventarioProductos::~InventarioProductos() {
	this->productos->liberarDatosInternos();
	delete this->productos;
}
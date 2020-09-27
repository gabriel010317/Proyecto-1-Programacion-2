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

string InventarioProductos::toStringPosicion()
{
	stringstream x;
	int contador = 0;
	IIterador* ite = this->productos->obtenerIterador();
	while (ite->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(ite->actual());
		x << "[ " << ++contador << " ]\t" << actual->getNombre() << endl;
	}
	return x.str();
}

string InventarioProductos::toString() {
	return this->productos->toString();
}

Producto* InventarioProductos::consultarPorPos(int p)
{
	stringstream x;
	int contador = 0;
	IIterador* ite = this->productos->obtenerIterador();
	while (ite->haySiguiente()) {
		Producto* actual = dynamic_cast<Producto*>(ite->actual());
		if (contador == p)
		{
			if (actual != NULL)
				return actual;
		}
			
		else
			contador++;
		
	}
	return nullptr;
	
}

InventarioProductos::~InventarioProductos() {
	this->productos->liberarDatosInternos();
	delete this->productos;
}
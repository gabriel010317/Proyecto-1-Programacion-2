#include "Producto.h"

Producto::Producto() : nombre(""), precio(0.0), cantidad (0){
   
}
Producto::Producto(string nom, float pre, int can):nombre(nom), precio(pre), cantidad(can) {

}
Producto::~Producto() {

}
string Producto::getNombre() const
{
    return nombre;
}

void Producto::setNombre(string nom)
{
    this->nombre = nom;
}

void Producto::setPrecio(float pre)
{
    this->precio = pre;
}

int Producto::getCantidad() const
{
    return cantidad;
}

void Producto::setCantidad(int can)
{
    this->cantidad = can;
}

string Producto::toString() {
    stringstream s;
    s << "  Producto: " << nombre << endl;
    s << "  Cantidad: " << cantidad << endl;
    return s.str();
}

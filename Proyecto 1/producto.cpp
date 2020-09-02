#include "producto.h"

producto::producto() : nombre(""), precio(0.0), cantidad (0){
   
}
producto::producto(string nom, float pre, int can):nombre(nom), precio(pre), cantidad(can) {

}
producto::~producto() {

}
string producto::getNombre() const
{
    return nombre;
}

void producto::setNombre(string nom)
{
    this->nombre = nom;
}

void producto::setPrecio(float pre)
{
    this->precio = pre;
}

int producto::getCantidad() const
{
    return cantidad;
}

void producto::setCantidad(int can)
{
    this->cantidad = can;
}


#pragma once
#include <string>

class Producto;

class IMaquinaAdministradora{
public:
	virtual int getIdentificador() = 0;
	virtual std::string getNombre() = 0;
	virtual void setNombre(std::string) = 0;
	virtual std::string toString() = 0;
	virtual void insertarProducto(Producto*) = 0;
	virtual void agregarProvisiones(std::string, int) = 0;
	virtual void disminuirProvisiones(std::string, int) = 0;
	virtual void borrar(std::string) = 0;
	virtual Producto* consultar(std::string) = 0;
	virtual std::string mostrarProductos() = 0;
	virtual void ingresarDinero(int) = 0;
	virtual void retirarDinero(int) = 0;
};


#pragma once
#include <string>

class IMaquinaVendedora{
	virtual std::string getNombre() = 0;
	virtual std::string realizarCompra(std::string, int, int) = 0;
	virtual std::string toString() = 0;
	
};


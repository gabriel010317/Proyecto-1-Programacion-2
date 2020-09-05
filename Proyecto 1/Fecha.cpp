#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes (m), anio(a) {

}
int Fecha::getDia() const
{
    return dia;
}

void Fecha::setDia(int d)
{
    this->dia = d;
}

int Fecha::getMes() const
{
    return mes;
}

void Fecha::setMes(int m)
{
    this->mes = m;
}

int Fecha::getAnio() const
{
    return anio;
}

void Fecha::setAnio(int a)
{
    this->anio = a;
}

std::string Fecha::toString() const {
    std::stringstream x;
    x << "dia:  " << dia << endl;
    x << "mes:  " << mes << endl;
    x << "anio: " << anio << endl;
    return x.str();    
}
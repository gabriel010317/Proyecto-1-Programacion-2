#pragma once
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
public:
    Fecha(int,int,int);

public:
    int getDia() const;
    void setDia(int dia);

    int getMes() const;
    void setMes(int mes);

    int getAnio() const;
    void setAnio(int anio);
};


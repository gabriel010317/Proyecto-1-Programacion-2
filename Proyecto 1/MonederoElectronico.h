#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class MonederoElectronico{
private:
	int dinero;
public:
	MonederoElectronico();
	MonederoElectronico(float);
	string desgloceVuelto(string&);
	void setDinero(int);
	int getDinero();
	string toString();
	~MonederoElectronico();
};


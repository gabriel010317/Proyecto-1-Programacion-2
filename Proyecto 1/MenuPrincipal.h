#pragma once
#include "MenuAdministrador.h"
#include "MenuCobro.h"
#include <sstream>
#include <iostream>
using namespace std;

class MenuPrincipal
{
private:
	MenuAdministrador* menuAdmin;
	MenuCobro* menuCobro;
	char mostrarOpciones();
	string logo();

public:
	MenuPrincipal(MenuAdministrador* menuAdmin, MenuCobro* menuCobro);
	void invocarMenu();
	~MenuPrincipal();
};

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Fecha.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "MenuPrincipal.h"
#include "MenuAdministrador.h"
#include "MenuCobro.h"
#include "IMaquinaAdministradora.h"
#include "Colecciones/ArrayList.h"
#include "Colecciones/LinkedList.h"
#include "EntradaSalida.h"
#include "Maquina.h"
#include <iostream>
#include <stdio.h>      // puts, printf /
#include <ctime>       // time_t, struct tm, time, localtime 

class Bootstrapper
{
public:
	static void correrAplicacion()
	{

		//saca fecha del sistema
		time_t now;
		struct tm nowLocal;

		now = time(nullptr);

		nowLocal = *localtime(&now);

		int d = nowLocal.tm_mday;
		int m = nowLocal.tm_mon + 1;
		int y = nowLocal.tm_year + 1900;

	
		Fecha* Hoy = new Fecha(d, m, y);
		InventarioProductos* productos = new InventarioProductos(new ArrayList(16));
		MonederoElectronico* monedero = new MonederoElectronico();
		Maquina* m1 = new Maquina(1, "Maquina 1", monedero, productos);
		MenuAdministrador* MA = new MenuAdministrador(m1, Hoy);
		MenuCobro* MC = new MenuCobro(m1);
		MenuPrincipal* MP = new MenuPrincipal(MA, MC);


		MP->invocarMenu();


	}
};


#pragma once
#include <iostream>
#include <string>
using namespace std;
class EntradaSalida {
public:
	static string recibeString();
	static int recibeInt();
	static bool recibeBool();
	static float recibeFloat();
	static void imprimir(string);
};
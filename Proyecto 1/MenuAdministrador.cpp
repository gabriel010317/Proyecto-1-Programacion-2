#include "MenuAdministrador.h"
MenuAdministrador::MenuAdministrador()
{
}

void MenuAdministrador::invocarMenu()
{
	const char opcionSalida = '8';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			//this->ingresarAlimento();
			break;
		case '2':
			//this->imprimirAlimentos();
			break;
		case '3':
			//this->imprimirAlimentos();
			break;
		case '4':
			//this->imprimirAlimentos();
			break;
		case '5':
			//this->imprimirAlimentos();
			break;
		case '6':
			//this->imprimirAlimentos();
			break;
		case '7':
			//this->imprimirAlimentos();
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

char MenuAdministrador::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "					 Menu Administrativo " << endl << "					Seleccione una opcion:" << endl;
	cout << "*******************************************************************************************\n";
	cout << "	1.	Insertar Producto" << endl;
	cout << "	2.	Agregar Proviciones" << endl;
	cout << "	3.	Disminuir Proviciones" << endl;
	cout << "	4.	Borrar Producto" << endl;
	cout << "	5.	Consultar Producto" << endl;
	cout << "	6.	Ingresar Dinero" << endl;
	cout << "	7.	Retirar Dinero" << endl;
	cout << "	8.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string MenuAdministrador::logo()
{
	stringstream s;
	s << "*******************************************************************************************" << endl << endl;
	s << "	%       % % %    %     %   % % %   % % %     %   %   % % %   %    %   % % %" << endl;
	s << "	%       %   %    % % % %   %   %   %   %     %   %     %     % %  %   %   %" << endl;
	s << "	%       % % %    %  %  %   % % %   %   %     %   %     %     %  % %   % % %" << endl;
	s << "	%       %   %    %     %   %   %   %   %     %   %     %     %    %   %   %" << endl;
	s << "	% % %   %   %    %     %   %   %   % % % %   % % %   % % %   %    %   %   %" << endl;
	s << "	---------------------------------------------------------------> DEL TIEMPO" << endl << endl;
	s << "*******************************************************************************************" << endl;
	return s.str();
}

int MenuAdministrador::getIdentificador()
{
	return 0;
}

string MenuAdministrador::getNombre()
{
	return string();
}

void MenuAdministrador::setNombre()
{
}

string MenuAdministrador::toString()
{
	return string();
}

void MenuAdministrador::insertar(Producto* p)
{
}

void MenuAdministrador::agregarProviciones(string idProducto, int cantidad)
{
}

void MenuAdministrador::disminuirProviciones(string idProducto, int cantidad)
{
}

void MenuAdministrador::borrar(string id)
{
}

Producto* MenuAdministrador::consulta(string id)
{
	return nullptr;
}

void MenuAdministrador::ingresarDinero()
{
}

void MenuAdministrador::retirarDinero(int cantidad)
{
}

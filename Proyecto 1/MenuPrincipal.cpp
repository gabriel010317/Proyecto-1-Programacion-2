#include "MenuPrincipal.h"
using namespace std;

char MenuPrincipal::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "					Menu Principal " << endl << "				    Seleccione una opcion:" << endl;
	cout << "*******************************************************************************************\n";
	cout << "	1.	Menu Administrador" << endl;
	cout << "	2.	Menu Cobro" << endl;
	cout << "	3.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string MenuPrincipal::logo()
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

MenuPrincipal::MenuPrincipal(MenuAdministrador* menuAdmin, MenuCobro* menuCobro)
{
	this->menuAdmin = menuAdmin;
	this->menuCobro = menuCobro;
}

void MenuPrincipal::invocarMenu()
{
	const char opcionSalida = '3';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->menuAdmin->invocarMenu();
			break;
		case '2':
			this->menuCobro->invocarMenu();
			break;
		case opcionSalida:
			break;
		default:
			cout << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

MenuPrincipal::~MenuPrincipal()
{
	delete menuAdmin;
	delete menuCobro;
}

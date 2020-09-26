#include "MenuCobro.h"
#include "EntradaSalida.h"
#include "producto.h"
#include "InventarioProductos.h"
#include "ProductoPerecedero.h"
#include "ProductoNoPerecedero.h"
#include "Fecha.h"

MenuCobro::MenuCobro(Maquina* p):maquina(p)
{
	
	
}

void MenuCobro::invocarMenu()
{
	const char opcionSalida = '3';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->imprimirProductos();
			break;
		case '2':
			//this->imprimirAlimentos();
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

void MenuCobro::imprimirProductos()
{
	EntradaSalida::imprimir(maquina->mostrarProductosPorPosicion());
	system("pause");
}

char MenuCobro::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "					 Menu de Cobro " << endl << "					Seleccione una opcion:" << endl;
	cout << "*******************************************************************************************\n";
	cout << "	1.	Mostrar Productos" << endl;
	cout << "	2.	Seleccionar Producto" << endl;
	cout << "	3.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string MenuCobro::logo()
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

string MenuCobro::miniLogo()
{
	stringstream s;
	s << "	*******************************" << endl;
	s << "		%       %     %" << endl;
	s << "		%       % % % %" << endl;
	s << "		%       %  %  %" << endl;
	s << "		%       %     %" << endl;
	s << "		% % %   %     %" << endl;
	s << "		----->DEL TIEMPO" << endl << endl;
	s << "	*******************************" << endl;

	return s.str();
}

void MenuCobro::comprar()
{
	int pos;
	EntradaSalida::imprimir("	Ingrese La poscicion del producto: ");
	pos=EntradaSalida::recibeInt(); //cin>>pos;
	maquina->mostrarProductosPorPosicion(pos);
}

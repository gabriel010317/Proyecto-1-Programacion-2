#include "MenuAdministrador.h"
//----------------------------------------- FUNCIONES BASICAS -------------------------------------------------
MenuAdministrador::MenuAdministrador(InventarioProductos* inv, Fecha* actual) : productos(inv), hoy(actual)
{

}
void MenuAdministrador::setNombre()
{
}
string MenuAdministrador::getNombre()
{
	return string();
}

string MenuAdministrador::toString()
{
	return string();
}

//----------------------------------------- FUNCIONES DE MENU -------------------------------------------------
char MenuAdministrador::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "					 Menu Administrativo " << endl << "					Seleccione una opcion:" << endl;
	cout << "*******************************************************************************************\n";
	cout << "	1.	Insertar Producto" << endl;
	cout << "	2.	Imprimir Productos" << endl;
	cout << "	3.	Agregar Proviciones" << endl;
	cout << "	4.	Disminuir Proviciones" << endl;
	cout << "	5.	Borrar Producto" << endl;
	cout << "	6.	Consultar Producto" << endl;
	cout << "	7.	Ingresar Dinero" << endl;
	cout << "	8.	Retirar Dinero" << endl;
	cout << "	9.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}
void MenuAdministrador::invocarMenu()
{
	const char opcionSalida = '9';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			this->ingresarProducto();
			break;
		case '2': {
			this->imprimirProductos();
			
			break;
		}
		case '3': {
			
			this->agregarProviciones();
			break;
		}
		case '4': {
			
			this->disminuirProviciones();
			break;
		}
		case '5':{
			
			this->borrar();
			break;
		}
		case '6':
			//this->imprimirAlimentos();
			break;
		case '7':
			//this->imprimirAlimentos();
			break;
		case '8':
			break;
		case opcionSalida:
			break;
		default:
			cerr << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
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
string MenuAdministrador::miniLogo()
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

int MenuAdministrador::getIdentificador()
{
	return 0;
}

//----------------------------------------- FUNCIONES DE PRODUCTO ---------------------------------------------
void MenuAdministrador::ingresarProducto() {
	EntradaSalida::imprimir(miniLogo());
	Producto* prod = crearProducto();
	this->productos->agregarProducto(prod);
}
Producto* MenuAdministrador::crearProducto()
{
	string nombre;
	float precio;
	int cantidad;
	bool esPerecedero = false;
	
	EntradaSalida::imprimir("	  Menu para Ingresar Productos");
	EntradaSalida::imprimir("	*******************************\n");

	EntradaSalida::imprimir("	El producto es perecedero?");
	esPerecedero = EntradaSalida::recibeBool();
	EntradaSalida::imprimir("	Ingrese el nombre del producto");
	nombre = EntradaSalida::recibeString();
	EntradaSalida::imprimir("	Ingrese el precio del producto");
	precio = EntradaSalida::recibeFloat();
	EntradaSalida::imprimir("	Ingrese la cantidad de unidades");
	cantidad = EntradaSalida::recibeInt();
	if (esPerecedero) {
		int dv, mv, av;
		EntradaSalida::imprimir("	Ingrese el dia de vencimiento");
		dv = EntradaSalida::recibeInt();
		EntradaSalida::imprimir("	Ingrese el mes de vencimiento");
		mv = EntradaSalida::recibeInt();
		EntradaSalida::imprimir("	Ingrese el anio de vencimiento");
		av = EntradaSalida::recibeInt();
		ProductoPerecedero* a = new ProductoPerecedero(nombre, precio, cantidad, dv, mv, av);
		a->calcularPrecio(hoy);
		EntradaSalida::imprimir("	Producto ingresado correctamente");
		system("pause");
		return a;

	}
	else {
		float desc;
		EntradaSalida::imprimir("	Ingrese el porcentaje de descuento (0-1)");
		desc = EntradaSalida::recibeFloat();
		EntradaSalida::imprimir("	Producto ingresado correctamente");
		system("pause");
		return new ProductoNoPerecedero(nombre, precio, cantidad, desc);
	}
}

void MenuAdministrador::agregarProviciones(){
	
	EntradaSalida::imprimir(miniLogo());
	EntradaSalida::imprimir("	  Menu para Agregar Proviciones");
	EntradaSalida::imprimir("	*******************************\n");
	Producto* temp = nullptr;
	EntradaSalida::imprimir("	Ingrese el nombre del producto a aumentar");
	string nombre = EntradaSalida::recibeString();
	if (productos->consultarProducto(nombre)) {
		temp = productos->consultarProducto(nombre);
		EntradaSalida::imprimir("	Ingrese la cantidad de unidades que desea aumentar");
		int cant = EntradaSalida::recibeInt();
		temp->setCantidad(temp->getCantidad() + cant);
		EntradaSalida::imprimir("	Unidades agregadas exitosamente");
		system("pause");
	}
	else {
		EntradaSalida::imprimir("	No se ha encontrado el producto");
		EntradaSalida::imprimir("	No se pudo agregar unidades");
		system("pause");
	}
}
void MenuAdministrador::disminuirProviciones()
{
	EntradaSalida::imprimir(miniLogo());
	EntradaSalida::imprimir("	Menu para Disminuir Proviciones");
	EntradaSalida::imprimir("	*******************************\n");

	EntradaSalida::imprimir("	Ingrese el nombre del producto a disminuir");
	string nombre = EntradaSalida::recibeString();
	
	Producto* temp = nullptr;
	if (productos->consultarProducto(nombre)) {
		temp = productos->consultarProducto(nombre);
		EntradaSalida::imprimir("	Ingrese la cantidad de unidades que desea disminuir");
		int cant = EntradaSalida::recibeInt();
		if (cant < temp->getCantidad()) {
			temp->setCantidad(temp->getCantidad() - cant);
			EntradaSalida::imprimir("	Unidades disminuidas exitosamente");
			system("pause");
		}
		else {
			EntradaSalida::imprimir("	No hay suficientes unidades para disminuir en " + cant);
			EntradaSalida::imprimir("	No se pudo disminuir unidades");
			system("pause");
		}
	}
	else {
		EntradaSalida::imprimir("	No se ha encontrado el producto");
		EntradaSalida::imprimir("	No se pudo disminuir unidades");
		system("pause");
	}
}
void MenuAdministrador::imprimirProductos() {
	EntradaSalida::imprimir(miniLogo());
	EntradaSalida::imprimir("	  Menu para Ingresar Productos");
	EntradaSalida::imprimir("	*******************************\n");
	EntradaSalida::imprimir( "----------------------------------------------\n");
	EntradaSalida::imprimir(this->productos->toString());
	system("pause");
}
Producto* MenuAdministrador::consulta(string id)
{
	return productos->consultarProducto(id);
}
void MenuAdministrador::borrar()
{
	EntradaSalida::imprimir(miniLogo());
	EntradaSalida::imprimir("	  Menu para Borrar Productos");
	EntradaSalida::imprimir("	*******************************\n");
	EntradaSalida::imprimir("	Ingrese el nombre del producto a eliminar");
	string id = EntradaSalida::recibeString();



	Producto* temp = nullptr;
	if (consulta(id)) {
		temp = consulta(id);
		productos->eliminarProducto(id);
		EntradaSalida::imprimir("	Borrado con exito");
		system("pause");
	}
	else {
		EntradaSalida::imprimir("	No se encontro el producto");
		system("pause");
	}
}




//----------------------------------------- FUNCIONES DE MONEDERO ---------------------------------------------
void MenuAdministrador::ingresarDinero()
{
}
void MenuAdministrador::retirarDinero(int cantidad)
{
}











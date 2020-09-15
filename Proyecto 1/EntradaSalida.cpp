#include "EntradaSalida.h"

string EntradaSalida::recibeString()
{
    string res;
    do {
        if (cin >> res)
            break;
        cerr << "Cadena de caracteres incorrecta, intentelo de nuevo" << endl;
    } while (cin.fail());
    return res;
}

int EntradaSalida::recibeInt() {
    int res;
    cin >> res;
    while (cin.fail()) {
        cerr << "numero entero incorrecto, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> res;
    }
    return res;
}

bool EntradaSalida::recibeBool() {
    int res;
    cout << "[1] SI\t[0] NO" << endl;
    cin >> res;
    while (cin.fail() || (res != 1 && res != 0)) {
        cout << "Valor invalido, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> res;
    }
    if (res == 1) {
        return true;
    }
    if (res == 0) {
        return false;
    }
}

float EntradaSalida::recibeFloat() {
    float res;
    cin >> res;
    while (cin.fail()) {
        cerr << "numero incorrecto, intentelo de nuevo" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> res;
    }
    return res;
}

void EntradaSalida::imprimir(string a) {
    cout << a << endl;
}
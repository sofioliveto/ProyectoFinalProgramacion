//
// Created by sofis on 5/21/2023.
//
#include <iostream>
#include "Cliente.h"

using namespace std;


void Cliente::setnumcliente(int _numcliente) {
    numcliente = _numcliente;
}

int Cliente::getnumcliente() {
    return numcliente;
}

void Cliente::setnombre(std::string _nombre) {
    nombre = _nombre;
}

string Cliente::getnombre() {
    return nombre;
}

void Cliente::setapellido(string _apellido) {
    apellido = _apellido;
}

string Cliente::getapellido() {
    return apellido;
}

void Cliente::setestado(int _estado) {
    estado = _estado;
}

int Cliente::getestado() {
    return estado;
}

void Cliente::setantiguedad(int _antiguedad) {
    antiguedad = _antiguedad;
}

int Cliente::getantiguedad() {
    return antiguedad;
}


void Cliente::setsaldo(long double _saldo) {
    saldo = _saldo;
}

long double Cliente::getsaldo() {
    return saldo;
}

void Cliente::setmembresia(int _membresia) {
    membresia = _membresia;
}

int Cliente::getmembresia() {
    return membresia;
}

Cliente::Cliente() {
    numcliente = -1;
    nombre = "";
    apellido = "";
    estado = 0;
    antiguedad = -1;
    saldo = 0;
    Transaccion();
}

Cliente::Cliente(int _numcliente, string _nombre, string _apellido, int _estado, int _antiguedad, long double _saldo,
                 int _membresia) {
    numcliente = _numcliente;
    nombre = _nombre;
    apellido = _apellido;
    estado = _estado;
    antiguedad = _antiguedad;
    saldo = _saldo;
    membresia = _membresia;
}

void Cliente::extraccion(long double _monto, int _dia, int _mes, int _anio) {
    int i, numero;
    for (i = 0; i < 100; i++) {
        if (transacciones[i].getanio() == -1) {
            numero= transacciones[i-1].getnumtransaccion()+1;
            transacciones[i] = Transaccion(numero, _monto, _dia, _mes, _anio);
            transacciones[i].setcategoria("E");
            while (transacciones[i].getmonto() > saldo) {
                cout << "No cuenta con ese monto de dinero en su cuenta" << endl;
                cout << "Su saldo actual es: " << saldo << endl;
                break;
            }
            if (transacciones[i].getmonto() <= saldo) {
                saldo = saldo - transacciones[i].getmonto();
                cout << "Su saldo actual es: " << saldo << endl;
                break;
            }
        }
    }
}

void Cliente::deposito(long double _monto, int _dia, int _mes, int _anio) {
    int i, numero;
    for (i = 0; i < 100; i++) {
        if (transacciones[i].getanio() == -1) {
            numero= transacciones[i-1].getnumtransaccion()+1;
            transacciones[i] = Transaccion(numero, _monto, _dia, _mes, _anio);
            transacciones[i].setcategoria("D");
            while (transacciones[i].getmonto() <= 0) {
                cout << "Ingrese un monto valido para depositar" << endl;
                cout << "Su saldo actual es: " << saldo << endl;
                break;
            }
            saldo = saldo + transacciones[i].getmonto();
            cout << "Su saldo actual es: " << saldo << endl;
            break;
        }
    }
}

void Cliente::imprimircliente() {
    cout << "Numero de cliente:" << numcliente << endl;
    cout << "NOMBRE:" << nombre << endl;
    cout << "APELLIDO:" << apellido << endl;
    if (estado == 1) {
        cout << "ESTADO: Activo" << endl;
        cout << "MEMBRESIA: " << membresia << endl;
        if (membresia == 1) {
            cout << "el cliente tiene una tarjeta BLACK" << endl
                 << "el limite mensual de su tarjeta es de: $250.000"
                 << endl;
        } else if (membresia == 2) {
            cout << "el cliente tiene una tarjeta ORO" << endl << "el limite mensual de su tarjeta es de: $50.000"
                 << endl;
        } else if (membresia == 3) {
            cout << "el cliente tiene una tarjeta PLATA" << endl << "el limite mensual de su tarjeta es de: $25.000"
                 << endl;
        }
    } else if (estado == 0) {
        cout << "ESTADO: Inactivo" << endl;
        cout << "MEMBRESIA: " << membresia << endl;
    }
    cout << "ANTIGUEDAD:" << antiguedad << endl;
    cout << "SALDO:" << saldo << endl;
}
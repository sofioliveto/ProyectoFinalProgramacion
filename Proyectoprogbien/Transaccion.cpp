//
// Created by sofis on 5/21/2023.
//
#include <iostream>
#include "Transaccion.h"
using namespace std;

void Transaccion::setnumtransaccion(int _numtransaccion) {
    numtransaccion = _numtransaccion;
}

int Transaccion::getnumtransaccion() {
    return numtransaccion;
}

void Transaccion::setmonto(long double _monto) {
    monto = _monto;
}

long double Transaccion::getmonto() {
    return monto;
}

void Transaccion::setdia(int _dia) {
    dia = _dia;
}

int Transaccion::getdia() {
    return dia;
}

void Transaccion::setmes(int _mes) {
    mes = _mes;
}

int Transaccion::getmes() {
    return mes;
}

void Transaccion::setanio(int _anio) {
    anio = _anio;
}

int Transaccion::getanio() {
    return anio;
}

void Transaccion::setcategoria(string _categoria) {
    categoria = _categoria;
}

string Transaccion::getcategoria() {
    return categoria;
}

Transaccion::Transaccion() {
    numtransaccion = 0;
    monto = 0;
    dia = 0;
    mes = 0;
    anio = -1;
    categoria = 'C';
}

Transaccion::Transaccion(int _numtransaccion, long double _monto, int _dia, int _mes, int _anio) {
    numtransaccion = _numtransaccion;
    monto = _monto;
    dia = _dia;
    mes = _mes;
    anio = _anio;
}

void Transaccion::imprimirtransacciones() {
    cout << "Numero de Transaccion: " << numtransaccion << endl;
    cout << "Monto: " << monto << endl;
    cout << "Tipo: " << categoria << endl;
    cout << "Dia: " << dia << endl;
    cout << "Mes: " << mes << endl;
    cout << "Anio: " << anio << endl;
}
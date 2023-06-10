//
// Created by sofis on 5/21/2023.
//
#include <iostream>
using namespace std;


class Transaccion {
protected:
    //Atributos
    int numtransaccion;
    long double monto;
    int dia;
    int mes;
    int anio;
    string categoria;
public:
    void setnumtransaccion(int _numtransaccion);
    int getnumtransaccion();
    void setmonto(long double _monto);
    long double getmonto();
    void setdia(int _dia);
    int getdia();
    void setmes(int _mes);
    int getmes();
    void setanio(int _anio);
    int getanio();
    void setcategoria(string _categoria);
    string getcategoria();

    //Metodos
    void imprimirtransacciones();

    //Constructores
    Transaccion();
    Transaccion(int _numtransaccion, long double _monto, int _dia, int _mes, int _anio);
};
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Cliente.h"

using namespace std;

int *pdia;
int *pmes;
int *panio;

void validarFechas() {
    int banddia = 0, bandmes = 0, bandanio = 0, dia, mes, anio;
    while (banddia == 0) {
        cout << "Dia: ";
        cin >> dia;
        while (dia > 31 || dia < 1) {
            cout << "El dia ingresado no es valido. Ingrese nuevamente: ";
            cin >> dia;
        }
        banddia = 1;
    }
    while (bandmes == 0) {
        cout << "Mes: ";
        cin >> mes;
        while (mes < 1 || mes > 12) {
            cout << "El mes ingresado no es valido. Ingrese nuevamente: ";
            cin >> mes;
        }
        bandmes = 1;
    }
    while (bandanio == 0) {
        cout << "Anio: ";
        cin >> anio;
        while (anio < 1950 || anio > 2023) {
            cout << "El anio ingresado no es valido. Ingrese nuevamente: ";
            cin >> anio;
        }
        bandanio = 1;
    }
    pdia = &dia;
    pmes = &mes;
    panio = &anio;
}

void cargarcliente(Cliente *clientes) {
    string cnombre, capellido;
    int cnumcliente, cestado, cantiguedad, cmembresia;
    float csaldo;
    for (int i = 0; i < 100; i++) {
        if (clientes[i].getantiguedad() == -1) {
            cnumcliente = i;
            cout << "NOMBRE: ";
            cin >> cnombre;
            cout << "APELLIDO: ";
            cin >> capellido;
            cout << "ESTADO (1 para activo, 0 para inactivo): ";
            cin >> cestado;
            while (cestado != 0 && cestado != 1) {
                cout << "Ingrese un estado valido!! 1 para activo, 0 para inactivo" << endl << "ESTADO: ";
                cin >> cestado;
            }
            cout << "ANTIGUEDAD (ingrese el anio en el que creo la cuenta): ";
            cin >> cantiguedad;
            while (cantiguedad <= 1900 || cantiguedad > 2023) {
                cout << "Ingrese un anio valido!!" << endl << "ANTIGUEDAD: ";
                cin >> cantiguedad;
            }
            cout << "MEMBRESIA(ingrese 1 para BLACK, 2 para ORO y 3 para PLATA): ";
            cin >> cmembresia;
            while (cmembresia != 1 && cmembresia != 2 && cmembresia != 3) {
                cout << "Ingrese una numero de membresia valido" << endl << "MEMBRESIA: ";
                cin >> cmembresia;
            }
            while (cmembresia == 1 && cantiguedad > 2019) {
                cout << "el cliente debe tener una antiguedad mayor a tres anios para ser BLACK" << endl
                     << "Ingrese una numero de membresia valido: ";
                cin >> cmembresia;
            }
            cout << "SALDO: ";
            cin >> csaldo;
            while (csaldo < 0) {
                cout << "Ingrese un saldo positivo!!" << endl << "SALDO: ";
                cin >> csaldo;
            }
            clientes[i] = Cliente(cnumcliente, cnombre, capellido, cestado, cantiguedad, csaldo, cmembresia);
            break;
        }
    }
}

void cambiarestado(Cliente *clientes) {
    string opc;
    int i;
    cout << "Ingrese el numero del cliente al que le quiere cambiar su estado: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "el cliente ingresado no existe" << endl << "ingrese el numero de cliente correctamente: ";
        cin >> i;
    }
    cout << "Se le cambiara el estado actual ";
    if (clientes[i].getestado() == 1) {
        cout << "(Activo)";
        clientes[i].setestado(0);
    } else if (clientes[i].getestado() == 0) {
        cout << "(Inactivo)";
        clientes[i].setestado(1);
    }
    cout << " al cliente " << clientes[i].getapellido() << ", " << clientes[i].getnombre() << endl;
    if (clientes[i].getestado() == 1) {
        cout << "NUEVO ESTADO: Activo" << endl;
    } else if (clientes[i].getestado() == 0) {
        cout << "NUEVO ESTADO: Inactivo" << endl;
    }
}

void cambiarmembresia(Cliente *clientes) {
    int i, opc;
    cout << "Ingrese el numero del cliente al que le quiere cambiar su membresia: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "el cliente ingresado no existe" << endl << "ingrese el numero de cliente correctamente: ";
        cin >> i;
    }
    cout << "Membresia actual de " << clientes[i].getapellido() << ", " << clientes[i].getnombre() << ": ";
    if (clientes[i].getmembresia() == 1) {
        cout << "BLACK" << endl;
    } else if (clientes[i].getmembresia() == 2) {
        cout << "ORO" << endl;
    } else if (clientes[i].getmembresia() == 3) {
        cout << "PLATA" << endl;
    }
    cout << "Ingrese 1 para cambiarlo a BLACK, 2 para ORO y 3 para PLATA: ";
    cin >> opc;
    while (opc != 1 && opc != 2 && opc != 3) {
        cout << "Ingrese una numero de membresia valido" << endl << "MEMBRESIA: ";
        cin >> opc;
    }
    while (opc == 1 && clientes[i].getantiguedad() > 2019) {
        cout << "el cliente debe tener una antiguedad mayor a tres anios para ser BLACK" << endl
             << "Ingrese una numero de membresia valido: ";
        cin >> opc;
    }
    clientes[i].setmembresia(opc);
    if (clientes[i].getmembresia() == 1) {
        cout << "el cliente se cambio a la membresia BLACK exitosamente" << endl
             << "el limite mensual de su tarjeta es de: $250.000" << endl;
    } else if (clientes[i].getmembresia() == 2) {
        cout << "el cliente se cambio a la membresia ORO exitosamente" << endl
             << "el limite mensual de su tarjeta es de: $50.000" << endl;
    } else if (clientes[i].getmembresia() == 3) {
        cout << "el cliente se cambio a la membresia PLATA exitosamente" << endl
             << "el limite mensual de su tarjeta es de: $25.000" << endl;
    }
}

void mostrarclientes(Cliente *clientes) {
    int i;
    ofstream archivo;
    archivo.open("Clientes.txt");
    //encabezados
    archivo << "numcliente" << ", " << "nombre" << ", " << "apellido" << ", "
            << "saldo" << ", " << "membresia" << ", " << "antiguedad"
            << ", " << "estado" << endl;
    for (i = 0; i < 100; i++) {
        if (clientes[i].getantiguedad() != -1) {
            //datos
            archivo << clientes[i].getnumcliente() << ", " << clientes[i].getnombre() << ", "
                    << clientes[i].getapellido() << ", " << clientes[i].getsaldo() << ", "
                    << clientes[i].getmembresia() << ", " << clientes[i].getantiguedad()
                    << ", " << clientes[i].getestado() << endl;
        }
    }
    archivo.close();
    ifstream fileloaded;

    for (i=0;i<100;i++){
        if (clientes[i].getantiguedad() != -1) {
            clientes[i].imprimircliente();
            cout<<"-----------------"<<endl;
        }
    }
    cout << "Se genero y guardo el archivo Clientes.txt" << endl;
}

void mostrarUNcliente(Cliente *clientes) {
    int i;
    cout << "Ingrese el numero del cliente que quiere consultar: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "el cliente ingresado no existe" << endl << "ingrese el numero de cliente que quiere ver: ";
        cin >> i;
    }
    cout << "--------------" << endl;
    clientes[i].imprimircliente();
    cout << "--------------" << endl;
}

void extraccion(Cliente *clientes) {
    float cinmonto;
    int i, j;
    cout << "Ingrese el numero de cliente al cual desea realizar la extraccion de dinero: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "El cliente ingresado no existe" << endl << "ingrese el numero de cliente correctamente: ";
        cin >> i;
    }
    if (clientes[i].getestado() == 1) {
        cout << "Monto a extraer: ";
        cin >> cinmonto;
        validarFechas();
        clientes[i].extraccion(cinmonto, *pdia, *pmes, *panio);
    } else {
        cout << "El cliente seleccionado es inactivo y no puede realizar transacciones de ningun tipo" << endl;
    }
}

void depositar(Cliente *clientes) {
    float cinmonto;
    int i, j;
    cout << "Ingrese el numero de cliente al cual desea realizar el deposito de dinero: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "El cliente ingresado no existe" << endl << "ingrese nuevamente el numero de cliente: ";
        cin >> i;
    }
    if (clientes[i].getestado() == 1) {
        cout << "Monto a depositar: ";
        cin >> cinmonto;
        validarFechas();
        clientes[i].deposito(cinmonto, *pdia, *pmes, *panio);
    } else {
        cout << "El cliente seleccionado es inactivo y no puede realizar transacciones de ningun tipo" << endl;
    }
}

void mostrartransacciones(Cliente *clientes) {
    int i, j;
    ofstream archivo;
    archivo.open("Transacciones.txt");
    //encabezados
    archivo << "numcliente" << ", "<< "numtransaccion" << ", " << "cantidad"
            << ", " << "tipo" << ", " << "dia" << ", " << "mes" << ", " << "anio" <<endl;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            //datos
            if (clientes[i].transacciones[j].getanio() != -1) {
                archivo << clientes[i].getnumcliente() << ", "
                        << clientes[i].transacciones[j].getnumtransaccion() << ", "
                        << clientes[i].transacciones[j].getmonto() << ", "
                        << clientes[i].transacciones[j].getcategoria() << ", "
                        << clientes[i].transacciones[j].getdia() << ", "
                        << clientes[i].transacciones[j].getmes() << ", "
                        << clientes[i].transacciones[j].getanio() << endl;
            }
        }
    }
    archivo.close();
    ifstream fileloaded;
    for(i=0;i<100;i++){
        if (clientes[i].getnumcliente()!=-1){
            cout<< "NUMERO DE CLIENTE: "<<clientes[i].getnumcliente()<<endl;
            for(j=0;j<100;j++){
                if (clientes[i].transacciones[j].getanio()!=-1) {
                    clientes[i].transacciones[j].imprimirtransacciones();
                    cout << "-----" << endl;
                }
            }
            cout<<"---------------------------"<<endl;
        }
    }
    cout << "Se genero y guardo el archivo Transacciones.txt" << endl;
}

void transaccionesmeses(Cliente *clientes) {
    int band = 0;
    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (clientes[j].transacciones[k].getmes() >= 1 && clientes[j].transacciones[k].getanio() == 2023 &&
                clientes[j].transacciones[k].getmes() <= 6) {
                cout << "--------------" << endl;
                cout << "Cliente numero " << clientes[j].getnumcliente() << endl;
                clientes[j].transacciones[k].imprimirtransacciones();
                cout << "--------------" << endl;
                band = 1;
            }
        }
    }
    if (band == 0) {
        cout << "No se registran transacciones en el periodo de los ultimos 6 meses" << endl;
    }
}

void transaccionesanio(Cliente *clientes) {
    int cinanio, band = 0;
    cout << "Anio: ";
    cin >> cinanio;
    while (cinanio < 1950 || cinanio > 2023) {
        cout << "El anio ingresado no es valido" << endl;
        cout << "Anio: ";
        cin >> cinanio;
    }
    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (clientes[j].transacciones[k].getanio() == cinanio) {
                cout << "--------------" << endl;
                cout << "Cliente numero " << clientes[j].getnumcliente() << endl;
                clientes[j].transacciones[k].imprimirtransacciones();
                cout << "--------------" << endl;
                band = 1;
            }
        }
    }
    if (band == 0) {
        cout << "No se registran transacciones en el anio ingresado" << endl;
    }
}

void transaccioncliente(Cliente *clientes) {
    int i, j, band=0;
    cout << "Ingrese el numero de cliente que desea ver la transaccion: ";
    cin >> i;
    while (clientes[i].getantiguedad() == -1 || i >= 100 || i < 0) {
        cout << "El cliente ingresado no existe" << endl << "ingrese nuevamente el numero de cliente: ";
        cin >> i;
    }
    for (j = 0; j < 100; j++) {
        if (clientes[i].transacciones[j].getanio() != -1) {
            cout<< "-----------"<<endl;
            clientes[i].transacciones[j].imprimirtransacciones();
            cout<< "-----------"<<endl;
            band=1;
        }
    }
    if (band==0){
        cout << "El cliente no realizo ninguna transaccion" << endl;
    }
}

void leerarchivo (Cliente *clientes) {
    ifstream archivo ("Clientes.txt");
    string linea, dato;
    int numero;
    float numerofloat;
    stringstream s;
    int index = -1, index_dato = 0, i=0;
    while (getline(archivo, linea, '\n')){
        s.str(linea);
        if (index==-1){
            index++;
            s.clear();
            continue;
        }
        index_dato=0;
        while (getline(s,dato, ',')) {
            // INGRESAR A ARREGLO ETC
            switch (index_dato) {
                case 0:
                    numero= stoi(dato);
                    clientes[i].setnumcliente(numero);
                    break;
                case 1:
                    clientes[i].setnombre(dato);
                    break;
                case 2:
                    clientes[i].setapellido(dato);
                    break;
                case 3:
                    numerofloat= stoi(dato);
                    clientes[i].setsaldo(numerofloat);
                    break;
                case 4:
                    numero= stoi(dato);
                    clientes[i].setmembresia(numero);
                    break;
                case 5:
                    numero= stoi(dato);
                    clientes[i].setantiguedad(numero);
                    break;
                case 6:
                    numero= stoi(dato);
                    clientes[i].setestado(numero);
                    break;
            }
            index_dato++;

        }
        s.clear();
        i++;
    }
}


void leerarchivoT(Cliente *clientes) {
    ifstream archivo ("Transacciones.txt");
    string linea, dato;
    int numero;
    float numerofloat;
    stringstream s;
    int index = -1, index_dato = 0, i=0, j=0;
    while (getline(archivo, linea, '\n')){
        s.str(linea);
        if (index==-1){
            index++;
            s.clear();
            continue;
        }
        index_dato=0;
        while (getline(s,dato, ',')) {
            // INGRESAR A ARREGLO ETC
            switch (index_dato) {
                case 0:
                    numero= stoi(dato);
                    i=numero;
                    break;
                case 1:
                    numero= stoi(dato);
                    clientes[i].transacciones[j].setnumtransaccion(numero);
                    break;
                case 2:
                    numerofloat= stoi(dato);
                    clientes[i].transacciones[j].setmonto(numerofloat);
                    break;
                case 3:
                    clientes[i].transacciones[j].setcategoria(dato);
                    break;
                case 4:
                    numero= stoi(dato);
                    clientes[i].transacciones[j].setdia(numero);
                    break;
                case 5:
                    numero= stoi(dato);
                    clientes[i].transacciones[j].setmes(numero);
                    break;
                case 6:
                    numero= stoi(dato);
                    clientes[i].transacciones[j].setanio(numero);
                    break;
            }
            index_dato++;

        }
        s.clear();
        j++;
    }
}

int main() {
    string cincategoria;
    string cinnombre, cinapellido;
    int opc, opc2;

    Cliente clientes[100];
    leerarchivo(clientes);
    leerarchivoT(clientes);
    //clientes[0] = Cliente(0, "juan", "perez", 1, 1980, 4000, 1);
    //clientes[1] = Cliente(1, "sofi", "cpp", 1, 1980, 2000, 1);

    while (1) {
        cout << "BIENVENIDO AL BANCO UCC \n";
        cout << "---------MENU---------" << endl;
        cout << "1) Cargar cliente" << endl;
        cout << "2) Cambiar estado de cliente" << endl;
        cout << "3) Cambiar membresia de cliente" << endl;
        cout << "4) Extraer dinero" << endl;
        cout << "5) Depositar dinero" << endl;
        cout << "6) Consultar cliente" << endl;
        cout << "7) Consultar todos los clientes" << endl;
        cout << "8) Informe de extracciones y depositos" << endl;
        cout << "9) Ver transacciones por cliente" << endl;
        cout << "10) Salir del Programa" << endl;
        cout << "Ingrese Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "CARGAR CLIENTE " << endl;
                cargarcliente(clientes);
                break;
            case 2:
                cout << "CAMBIAR ESTADO DE CLIENTE" << endl;
                cambiarestado(clientes);
                break;
            case 3:
                cout << "CAMBIAR MEMBRESIA DE CLIENTE" << endl;
                cambiarmembresia(clientes);
                break;
            case 4:
                cout << "EXTRACCION DE DINERO" << endl;
                extraccion(clientes);
                break;
            case 5:
                cout << "DEPOSITAR DINERO " << endl;
                depositar(clientes);
                break;
            case 6:
                cout << "CONSULTAR CLIENTE" << endl;
                mostrarUNcliente(clientes);
                break;
            case 7:
                cout << "CONSULTAR TODOS LOS CLIENTES " << endl;
                mostrarclientes(clientes);
                break;
            case 8:
                cout << "MENU" << endl;
                cout << "1) Ver todas las transacciones" << endl;
                cout << "2) Ver transacciones por anio" << endl;
                cout << "3) Ver transacciones por periodo de seis meses" << endl;
                cout << "Ingrese Opcion: ";
                cin >> opc2;
                switch (opc2) {
                    case 1:
                        mostrartransacciones(clientes);
                        break;
                    case 2:
                        transaccionesanio(clientes);
                        break;
                    case 3:
                        transaccionesmeses(clientes);
                        break;
                }
                break;
            case 9:
                transaccioncliente(clientes);
                break;
            case 10:
                cout << "El programa se cerrara" << endl;
                return 0;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    }
}

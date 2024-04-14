#include "controlador.h"
#include "modelo.h"


void Cliente::leerDatosCliente(const string &nombreArchivo, Cliente listaClientes[], int &tamanoLista)
{
    ifstream archivoClientes(nombreArchivo);
    string linea;
    tamanoLista = 0;

    getline(archivoClientes, linea);

    while (getline(archivoClientes, linea))
    {
        stringstream ss(linea);

        ss >> listaClientes[tamanoLista].id;
        ss.ignore();
        getline(ss, listaClientes[tamanoLista].nombre, ';');
        getline(ss, listaClientes[tamanoLista].apellido, ';');
        getline(ss, listaClientes[tamanoLista].correo, ';');
        ss >> listaClientes[tamanoLista].edad;
        ss.ignore();

        tamanoLista++;
    }
}

void Auto::leerDatosAuto(const string &nombreArchivo, Auto listaAutos[], int &tamanoLista)
{
    ifstream archivoAutos(nombreArchivo);
    string linea;
    tamanoLista = 0;

    getline(archivoAutos, linea);

    while (getline(archivoAutos, linea))
    {
        stringstream ss(linea);

        ss >> listaAutos[tamanoLista].id;
        ss.ignore();
        getline(ss, listaAutos[tamanoLista].fabricante, ';');
        getline(ss, listaAutos[tamanoLista].modelo, ';');
        ss >> listaAutos[tamanoLista].anio;
        ss.ignore();
        ss >> listaAutos[tamanoLista].vendidoA;
        ss.ignore();
        ss >> listaAutos[tamanoLista].compradoA;
        ss.ignore();
        ss >> listaAutos[tamanoLista].vendidoPor;
        ss.ignore();
        ss >> listaAutos[tamanoLista].compradoPor;
        ss.ignore();

        tamanoLista++;
    }
}


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

struct Cliente
{
    int id;
    string nombre;
    string apellido;
    string correo;
    int edad;
};

struct Auto
{
    int id;
    string fabricante;
    string modelo;
    int anio;
    int vendidoA;
    int compradoA;
    int vendidoPor;
    int compradoPor;
};

extern Auto listaAutos[2000];
extern Cliente listaClientes[2000];

void leerDatosCliente(const string &nombreArchivo, Cliente listaClientes[], int &tamanoLista);
void leerDatosAuto(const string &nombreArchivo, Auto listaAutos[], int &tamanoLista);
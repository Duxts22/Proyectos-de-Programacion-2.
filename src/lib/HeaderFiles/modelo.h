#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

class Cliente
{
public:
    int id;
    string nombre;
    string apellido;
    string correo;
    int edad;

    void leerDatosCliente(const string &nombreArchivo, Cliente *listaClientes, int &tamanoLista);
};

class Auto
{
public:
    int id;
    string fabricante;
    string modelo;
    int anio;
    int vendidoA;
    int compradoA;
    int vendidoPor;
    int compradoPor;

    void leerDatosAuto(const string &nombreArchivo, Auto *listaAutos, int &tamanoLista);
};

extern Cliente cliente;
extern Auto autos;

extern Auto *listaAutos;
extern Cliente *listaClientes;
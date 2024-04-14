#pragma once

#include "modelo.h"
#include "vista.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>

using namespace std;

class Controlador
{
public:
    void caso1(int idCliente, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos);
    void caso2(int idCliente, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos);
    void caso3(int idAuto, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos);
    void caso4(Auto &autoComprado, Cliente &cliente, const string &nombreArchivoAutos, const string &nombreArchivoClientes);
    void caso5(int opcion, int id, const string &nombreArchivoClientes, const string &nombreArchivoAutos);
    void caso6(int idAuto, Auto listaAutos[], int tamanoListaAutos);

    void ejecutarOpcion(int &opcionPrincipal, int &idCliente, Cliente listaClientes[], Auto listaAutos[], int &tamanoListaClientes, int &tamanoListaAutos, Auto &autoComprado, Cliente &cliente, bool &estaCorriendo);
};
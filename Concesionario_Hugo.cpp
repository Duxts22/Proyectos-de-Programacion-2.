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

void mostrarMenu(int &opcionUsuario);

void leerDatosCliente(const string &nombreArchivo, Cliente listaClientes[], int &tamanoLista);
void leerDatosAuto(const string &nombreArchivo, Auto listaAutos[], int &tamanoLista);

void caso1(int idCliente, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos);

int main()
{
    Auto listaAutos[2000];
    Cliente listaClientes[2000];

    bool estaCorriendo = true;

    int autosComprados = 0;
    int autosVendidos = 0;
    int idCliente;
    int opcionPrincipal;
    int tamanoListaAutos;
    int tamanoListaClientes;

    string nombreCliente;

    cout << "Bienvenido a la Consecionaria" << endl;
    while (estaCorriendo)
    {
        mostrarMenu(opcionPrincipal);

        switch (opcionPrincipal)
        {
        case 1:
            caso1(idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            cout << "Gracias por preferirnos" << endl;
            estaCorriendo = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    }
    return 0;
}

void mostrarMenu(int &opcionUsuario)
{
    cout << "Que desea realizar" << endl
         << "1. Ver cantidad de autos comprados y vendidos por clientes." << endl
         << "2. Ver la lista de autos comprados y vendidos por clientes." << endl
         << "3. Ver datos de clientes." << endl
         << "4. Modificar datos." << endl
         << "5. Eliminar datos" << endl
         << "6. Mostrar ganancia o perdida de un auto." << endl
         << "7. Salir." << endl;
    cin >> opcionUsuario;
}

void leerDatosCliente(const string &nombreArchivo, Cliente listaClientes[], int &tamanoLista)
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

void leerDatosAuto(const string &nombreArchivo, Auto listaAutos[], int &tamanoLista)
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

void caso1(int idCliente, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos)
{
    int autosComprados = 0;
    int autosVendidos = 0;
    string nombreCliente;

    cout << "\nIngrese el ID del cliente: ";
    cin >> idCliente;

    leerDatosCliente("clients.csv", listaClientes, tamanoListaClientes);

    leerDatosAuto("cars_data.csv", listaAutos, tamanoListaAutos);

    for (int i = 0; i < tamanoListaClientes; i++)
    {
        if (listaClientes[i].id == idCliente)
        {
            nombreCliente = listaClientes[i].nombre;
            break;
        }
    }

    if (nombreCliente.empty())
    {
        cout << "No se encontró ningún cliente con el ID " << idCliente << ".\n";
        return;
    }

    for (int i = 0; i < tamanoListaAutos; i++)
    {
        if (listaAutos[i].compradoA == idCliente)
        {
            autosComprados++;
        }
        if (listaAutos[i].vendidoA == idCliente)
        {
            autosVendidos++;
        }
    }

    cout << "El cliente " << nombreCliente << " ha comprado " << autosComprados << " autos y ha vendido " << autosVendidos << " autos.\n";
    autosComprados = 0;
    autosVendidos = 0;
    cout << "Presione una tecla para continuar" << endl;
    getch();
}
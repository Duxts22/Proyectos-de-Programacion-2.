#include "lib/HeaderFiles/controlador.h"
#include "lib/HeaderFiles/modelo.h"
#include "lib/HeaderFiles/vista.h"

Auto *listaAutos = new Auto[2000];
Cliente *listaClientes = new Cliente[2000];

Cliente cliente;
Auto autos;
Controlador controlador;
Vista vista;

int main()
{
    bool estaCorriendo = true;
    int opcionPrincipal;
    int autosComprados = 0;
    int autosVendidos = 0;
    int idCliente, idAuto;
    int tamanoListaAutos = 2000;
    int tamanoListaClientes = 2000;

    Auto autoComprado;

    string nombreCliente;

    cout << "\nBienvenido a la Consecionaria" << endl;
    while (estaCorriendo)
    {
        vista.mostrarMenu(opcionPrincipal);
        controlador.ejecutarOpcion(opcionPrincipal, idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos, autoComprado, cliente, estaCorriendo);
    }

    delete[] listaAutos;
    delete[] listaClientes;

    return 0;
}

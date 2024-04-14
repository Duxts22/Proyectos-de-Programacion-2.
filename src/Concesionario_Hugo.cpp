#include "lib/HeaderFiles/clases.h"
#include "lib/HeaderFiles/switch.h"

Auto listaAutos[2000];
Cliente listaClientes[2000];

int main()
{
    bool estaCorriendo = true;

    int autosComprados = 0;
    int autosVendidos = 0;
    int idCliente, idAuto;
    int opcionPrincipal;
    int tamanoListaAutos;
    int tamanoListaClientes;

    Auto autoComprado;
    Cliente cliente;

    string nombreCliente;

    cout << "\nBienvenido a la Consecionaria" << endl;
    while (estaCorriendo)
    {
        mostrarMenu(opcionPrincipal);
        ejecutarOpcion(opcionPrincipal, idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos, autoComprado, cliente, estaCorriendo);
    }
    return 0;
}
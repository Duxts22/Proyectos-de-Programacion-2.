#include "vista.h"
#include <iostream>

using namespace std;

void Vista::mostrarMenu(int &opcionUsuario)
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
#include "clases.h"
#include "switch.h"

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
        cout << "No se encontro ningun cliente con el ID " << idCliente << ".\n";
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

void caso2(int idCliente, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos)
{
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
        cout << "No se encontro ningun cliente con el ID " << idCliente << ".\n";
        getch();
        return;
    }

    cout << "Autos comprados por " << nombreCliente << ":\n";
    for (int i = 0; i < tamanoListaAutos; i++)
    {
        if (listaAutos[i].compradoA == idCliente)
        {
            cout << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " " << listaAutos[i].anio << "\n";
        }
    }

    cout << "\nAutos vendidos por " << nombreCliente << ":\n";
    for (int i = 0; i < tamanoListaAutos; i++)
    {
        if (listaAutos[i].vendidoA == idCliente)
        {
            cout << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " " << listaAutos[i].anio << "\n";
        }
    }
    cout << "Presione una tecla para continuar\n"
         << endl;
    getch();
}

void caso3(int idAuto, Cliente listaClientes[], Auto listaAutos[], int tamanoListaClientes, int tamanoListaAutos)
{
    int opcion;
    int idCliente;
    string nombreCliente;

    cout << "\nIngrese el ID del auto: ";
    cin >> idAuto;

    leerDatosAuto("cars_data.csv", listaAutos, tamanoListaAutos);

    for (int i = 0; i < tamanoListaAutos; i++)
    {
        if (listaAutos[i].id == idAuto)
        {
            cout << "1. Ver datos del vendedor\n";
            cout << "2. Ver datos del comprador\n";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                idCliente = listaAutos[i].compradoA;
                break;
            case 2:
                idCliente = listaAutos[i].vendidoA;
                break;
            default:
                cout << "Opcion invalida\n";
                return;
            }
            break;
        }
    }

    leerDatosCliente("clients.csv", listaClientes, tamanoListaClientes);

    bool clienteEncontrado = false;

    for (int i = 0; i < tamanoListaClientes; i++)
    {
        if (listaClientes[i].id == idCliente)
        {
            cout << "==============================================\n";
            cout << "Nombre: " << listaClientes[i].nombre << "\n";
            cout << "Apellido: " << listaClientes[i].apellido << "\n";
            cout << "Correo: " << listaClientes[i].correo << "\n";
            cout << "Edad: " << listaClientes[i].edad << "\n";
            cout << "==============================================\n";

            clienteEncontrado = true;
            break;
        }
    }

    if (!clienteEncontrado)
    {
        cout << "No se encontro ningun cliente con el ID " << idCliente << ".\n";
    }
}

void caso4(Auto &autoComprado, Cliente &cliente, const string &nombreArchivoAutos, const string &nombreArchivoClientes)
{
    int tamanoListaClientes = 2000;
    int tamanoListaAutos = 2000;

    int opcion;
    do
    {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Agregar auto\n";
        cout << "3. Modificar auto\n";
        cout << "4. Salir\n";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            ifstream archivoCliente(nombreArchivoClientes);
            string linea;
            int ultimoIdCliente = 0;
            while (getline(archivoCliente, linea))
            {
                stringstream ss(linea);
                ss >> ultimoIdCliente;
            }
            archivoCliente.close();

            cliente.id = ultimoIdCliente + 1;

            cout << "\nIngrese la informacion del nuevo cliente:\n";
            cout << "ID: " << cliente.id << "\n";
            cout << "Nombre: ";
            cin >> cliente.nombre;
            cout << "Apellido: ";
            cin >> cliente.apellido;
            cout << "Correo: ";
            cin >> cliente.correo;
            cout << "Edad: ";
            cin >> cliente.edad;

            ofstream archivoClientesOut(nombreArchivoClientes, ios::app);
            archivoClientesOut << cliente.id << ";" << cliente.nombre << ";" << cliente.apellido << ";" << cliente.correo << ";" << cliente.edad << "\n";
            archivoClientesOut.close();

            break;
        }
        case 2:
        {
            ifstream archivoAutos(nombreArchivoAutos);
            string linea;
            int ultimoIdAuto = 0;
            while (getline(archivoAutos, linea))
            {
                stringstream ss(linea);
                ss >> ultimoIdAuto;
            }
            archivoAutos.close();

            autoComprado.id = ultimoIdAuto + 1;

            leerDatosCliente("clients.csv", listaClientes, tamanoListaClientes);

            cout << "\nIngrese la informacion del auto comprado:\n";
            cout << "ID: " << autoComprado.id << "\n";
            cout << "Fabricante: ";
            cin >> autoComprado.fabricante;
            cout << "Modelo: ";
            cin >> autoComprado.modelo;
            cout << "Año: ";
            cin >> autoComprado.anio;
            cout << "Precio compra: ";
            cin >> autoComprado.compradoPor;
            cout << "ID del cliente que lo compro: ";
            cin >> autoComprado.vendidoA;

            bool CompradorExiste = false;
            for (int i = 0; i < tamanoListaClientes; i++)
            {
                if (listaClientes[i].id == autoComprado.vendidoA)
                {
                    CompradorExiste = true;
                    break;
                }
            }

            if (!CompradorExiste)
            {
                cout << "El cliente no existe. Por favor, agregue un nuevo cliente.\n";
                return;
            }

            cout << "Precio venta: ";
            cin >> autoComprado.vendidoPor;

            cout << "ID del cliente que lo vendio: ";
            cin >> autoComprado.compradoA;

            bool VendedorExiste = false;
            for (int i = 0; i < tamanoListaClientes; i++)
            {
                if (listaClientes[i].id == autoComprado.compradoA)
                {
                    VendedorExiste = true;
                    break;
                }
            }

            if (!VendedorExiste)
            {
                cout << "El cliente no existe. Por favor, agregue un nuevo cliente.\n";
                return;
            }

            ofstream archivoAutosOut(nombreArchivoAutos, ios::app);
            archivoAutosOut << autoComprado.id << ";" << autoComprado.fabricante << ";" << autoComprado.modelo << ";" << autoComprado.anio << ";" << autoComprado.vendidoA << ";" << autoComprado.compradoA << ";" << autoComprado.vendidoPor << ";" << autoComprado.compradoPor << "\n";
            archivoAutosOut.close();

            break;
        }
        case 3:
        {
            int idAuto;
            cout << "\nIngrese el ID del auto a modificar: ";
            cin >> idAuto;

            leerDatosAuto("cars_data.csv", listaAutos, tamanoListaAutos);

            bool autoEncontrado = false;
            for (int i = 0; i < tamanoListaAutos; i++)
            {
                if (listaAutos[i].id == idAuto)
                {
                    autoEncontrado = true;
                    cout << "Ingrese el nuevo ID del cliente que lo compro: ";
                    cin >> listaAutos[i].compradoA;
                    cout << "Ingrese el nuevo ID del cliente que lo vendio: ";
                    cin >> listaAutos[i].vendidoA;

                    ofstream archivoAutosOut(nombreArchivoAutos);
                    for (int j = 0; j < tamanoListaAutos; j++)
                    {
                        archivoAutosOut << listaAutos[j].id << ";" << listaAutos[j].fabricante << ";" << listaAutos[j].modelo << ";" << listaAutos[j].anio << ";" << listaAutos[j].vendidoA << ";" << listaAutos[j].compradoA << ";" << listaAutos[j].vendidoPor << ";" << listaAutos[j].compradoPor << "\n";
                    }
                    archivoAutosOut.close();
                    break;
                }
            }

            cout << "Auto modificado con exito.\n";

            if (!autoEncontrado)
            {
                cout << "No se encontro ningun auto con el ID " << idAuto << ".\n";
            }
            break;
        }

        case 4:
        {
            cout << "Saliendo...\n";
            break;
        }

        default:
        {
            cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
        }
    } while (opcion != 3);
}
void caso5(int opcion, int id, const string &nombreArchivoClientes, const string &nombreArchivoAutos)
{
    string linea;
    int idActual;
    bool encontrado = false;

    cout << "\n1. Eliminar cliente\n";
    cout << "2. Eliminar auto\n";
    cin >> opcion;

    cout << "\nIngrese el ID del cliente o auto a eliminar: ";
    cin >> id;

    switch (opcion)
    {
    case 1:
    {
        ifstream archivoClientes(nombreArchivoClientes);
        ofstream archivoTemporal("temp.csv");

        while (getline(archivoClientes, linea))
        {
            stringstream ss(linea);
            ss >> idActual;

            if (idActual != id)
            {
                archivoTemporal << linea << "\n";
            }
            else
            {
                encontrado = true;
            }
        }

        archivoClientes.close();
        archivoTemporal.close();

        remove(nombreArchivoClientes.c_str());
        rename("temp.csv", nombreArchivoClientes.c_str());

        if (encontrado)
        {
            cout << "Cliente eliminado con éxito.\n";
        }
        else
        {
            cout << "No se encontró ningún cliente con el ID " << id << ".\n";
        }
    }
    break;
    case 2:
    {
        ifstream archivoAutos(nombreArchivoAutos);
        ofstream archivoTemporal("temp.csv");

        while (getline(archivoAutos, linea))
        {
            stringstream ss(linea);
            ss >> idActual;

            if (idActual != id)
            {
                archivoTemporal << linea << "\n";
            }
            else
            {
                encontrado = true;
            }
        }

        archivoAutos.close();
        archivoTemporal.close();

        remove(nombreArchivoAutos.c_str());
        rename("temp.csv", nombreArchivoAutos.c_str());

        if (encontrado)
        {
            cout << "Auto eliminado con éxito.\n";
        }
        else
        {
            cout << "No se encontró ningún auto con el ID " << id << ".\n";
        }
    }
    break;
    default:
        cout << "Opción inválida\n";
    }
}

void caso6(int idAuto, Auto listaAutos[], int tamanoListaAutos)
{
    int precioCompra, precioVenta, gananciaPerdida;

    cout << "\nIngrese el ID del auto: ";
    cin >> idAuto;

    leerDatosAuto("cars_data.csv", listaAutos, tamanoListaAutos);

    for (int i = 0; i < tamanoListaAutos; i++)
    {
        if (listaAutos[i].id == idAuto)
        {
            precioCompra = listaAutos[i].compradoPor;
            precioVenta = listaAutos[i].vendidoPor;

            if (precioVenta > 0)
            {
                gananciaPerdida = precioVenta - precioCompra;

                if (gananciaPerdida > 0)
                {
                    cout << "===============================================================\n";
                    cout << "El auto " << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " genero una ganancia de " << gananciaPerdida << "\n";
                    cout << "===============================================================\n";
                }
                else if (gananciaPerdida < 0)
                {
                    cout << "===============================================================\n";
                    cout << "El auto " << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " genero una perdida de " << -gananciaPerdida << "\n";
                    cout << "===============================================================\n";
                }
                else
                {
                    cout << "El auto " << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " no genero ni ganancias ni perdidas.\n";
                }
            }
            else
            {
                cout << "El auto " << listaAutos[i].fabricante << " " << listaAutos[i].modelo << " no se ha vendido aun, por lo que se considera una perdida de " << precioCompra << ".\n";
            }
            break;
        }
    }
}

void ejecutarOpcion(int &opcionPrincipal, int &idCliente, Cliente listaClientes[], Auto listaAutos[], int &tamanoListaClientes, int &tamanoListaAutos, Auto &autoComprado, Cliente &cliente, bool &estaCorriendo)
{
    switch (opcionPrincipal)
    {
    case 1:
        caso1(idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos);
        break;

    case 2:
        caso2(idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos);
        break;

    case 3:
        caso3(idCliente, listaClientes, listaAutos, tamanoListaClientes, tamanoListaAutos);
        break;

    case 4:
        caso4(autoComprado, cliente, "cars_data.csv", "clients.csv");
        break;

    case 5:
        caso5(opcionPrincipal, idCliente, "clients.csv", "cars_data.csv");
        break;

    case 6:
        caso6(idCliente, listaAutos, tamanoListaAutos);
        break;

    case 7:
        cout << "Gracias por preferirnos" << endl;
        estaCorriendo = false;
        break;

    default:
        cout << "Opcion invalida" << endl;
    }
}
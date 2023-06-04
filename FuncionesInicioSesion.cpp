#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios/funcionesUsuarios.cpp"
#include "funcionesFacturas.cpp"

using namespace std;

void menuInicial();
void menuAdmin();
void menuEmpleado();
void menuClientes();

//Cliente
int menuForCliente();
void menuCompleteForTheClient();

// menuInicial
void menuInicial()
{
    int opcion;
    string adminUsername = "Admin";
    string adminPass = "SOMOS.UCA";
    string temp1;
    string temp2;
    do
    {
        cout << "-----------------Bienvenido al menu de MCSerigraph--------------" << endl;
        cout << "Elegir el tipo de cuenta" << endl;
        cout << "1. Soy Administrador" << endl;
        cout << "2. Soy Empleado" << endl;
        cout << "3. Soy Cliente" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingresa el usuario: " << endl;
            cin >> temp1;

            cout << "Ingresa password: " << endl;
            cin >> temp2;

            if (temp1 == adminUsername && temp2 == adminPass)
            {
                menuAdmin();
                system("pause");
            }
            else
            {
                cout << "Credenciales invalidas." << endl;
            }
            system("pause");
            break;
        case 2:
            system("cls");
            menuEmpleado();
            system("pause");
            break;
        case 3:
            system("cls");
            menuCompleteForTheClient();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Saliendo....... " << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida, selecciona una opcion del menu...";
            system("pause");
            break;
        }
    } while (opcion != 4);
}

/// menuAdmin
void menuAdmin()
{
    int optionA;
    do
    {
        system("cls||clear");

        cout << "-----------------Bienvenido al menu de Administrador de MCSerigraph--------------" << endl;
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Seccion de clientes" << endl;
        cout << "2. Seccion de productos" << endl;
        cout << "3. Seccion de usuarios" << endl;
        cout << "4. Seccion de facturas" << endl;
        cout << "5. Salir" << endl;
        cin >> optionA;

        switch (optionA)
        {
        case 1:
            system("cls");
            cout << "Entrando a la seccion de clientes...";
            MenuCompleteClient();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Entrando a la seccion de productos...";
            MenuCompleteProduct();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Entrando a la seccion de usuarios...";
            MenuCompleteUsuario();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Entrando a la seccion de facturas...";
            MenuCompleteFactura();
            system("pause");
            break;
        case 5:
            cout << "Saliendo....... " << endl;
            break;
        default:
            cout << "Opcion invalida, selecciona una opcion del menu...";
            system("pause");
            break;
        }
    } while (optionA != 5);
}

// menuEmpleado
void menuEmpleado()
{
    int optionC;
    do
    {
        system("cls");
        cout << "-----------------Bienvenido al menu de empleados de MCSerigraph--------------" << endl;
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Ingresar a clientes " << endl;
        cout << "2. Ingresar a productos " << endl;
        cout << "3. Ingresar a facturas " << endl;
        cout << "4. Salir" << endl;
        cin >> optionC;

        switch (optionC)
        {
        case 1:
            system("cls");
            cout << "Entrando a la seccion de clientes...";
            MenuCompleteClient();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Entrando a la seccion de productos...";
            MenuCompleteProduct();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Entrando a la seccion de facturas...";
            MenuCompleteFactura();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Saliendo.................... " << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida " << endl;
            system("pause");
            break;
        }
    } while (optionC != 4);
}

//Facturas cliente

int menuFacturasCliente()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "1. Agregar datos a la factura" << endl;
    cout << "2. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteFacturaCliente()
{
    int op, pos, cantidad, posProd;
    //char IDF[14];
    char NProduct[10];
    factura facturas;
    producto prod;
    // leerFactura();

    do
    {
        system("cls");

        op = menuFacturasCliente();
        switch (op)
        {
        case 1:
            system("cls");
            facturas.numFactura = lastFactura + 1;
            cout << "Ingresa la fecha:";
            scanf(" %[^\n]", facturas.fecha);
            cout << "Ingresa el cliente:";
            scanf(" %[^\n]", facturas.nombreCliente);
            cout << "Ingresa una observacion:";
            scanf(" %[^\n]", facturas.observacion);
            agregarFactura(facturas);
            cout << "¿Cuantos productos va a facturar?: ";
            cin >> cantidad;
            for (int i = 0; i < cantidad; i++)
            {
                // llenar detalles
                detalles[lastDetFac].idDetalle = lastDetFac + 1;
                detalles[lastDetFac].numFac = facturas.numFactura;
                cout << "Ingrese el codigo del producto: ";
                scanf(" %[^\n]", NProduct);
                posProd = BuscarProducto(NProduct);
                if (posProd == -1)
                {
                    cout << "Producto no existe...\n";
                    break;
                }
                else
                {
                    prod = getProducto(posProd);
                    printf("producto: %s\n precio: %.2f\n", prod.nombreP, prod.precio);
                    strcpy(detalles[lastDetFac].nomProducto, prod.nombreP);
                    detalles[lastDetFac].precioP = prod.precio;
                    cout << "Ingrese la cantidad de productos: ";
                    cin >> detalles[lastFactura].cantidad;
                    lastDetFac++;
                }
            }
            encabezadoFactura(facturas.numFactura-1);
            // agregarDatosParaFactura();
            // agregarFactura(facturas);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Saliendo....... " << endl;
            system("pause");
            break;
        default:
            system("cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 2);
    guardarFactura();
}

//Cliente

int menuForCliente()
{
    int op;

    cout << "-----------------Bienvenido al menu de clientes de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "1. Agregar cliente " << endl;
    cout << "2. Mostrar productos " << endl;
    cout << "3. Seccion de facturas " << endl;
    cout << "4. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void menuCompleteForTheClient()
{
    int op, pos, resp;
    char ID[14];
    cliente Clientes;
    leerCliente();

    do
    {
        system("cls");

        op = menuForCliente();
        switch (op)
        {
        case 1:
            system("cls");
            cout << " ID: " << endl;
            cout << " Nombre: " << endl;
            cout << " Apellido: " << endl;
            scanf(" %[^\n]", Clientes.ID);
            scanf(" %[^\n]", Clientes.nombre);
            scanf(" %[^\n]", Clientes.apellido);
            agregarCliente(Clientes);
            guardarClientes();
            system("pause");
            break;
        case 2:
            system("cls");
            MostrarProductos();
            system("pause");
            break;
        case 3:
            system("cls");
            MenuCompleteFacturaCliente();
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Saliendo....... " << endl;
            system("pause");
            break;
        default:
            system("cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 4);
}
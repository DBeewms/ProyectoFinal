#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios/funcionesUsuarios.cpp"
#include "clientes/funcionesClientes.cpp"
#include "productos/funcionesProductos.cpp"
#include "funcionesFacturas.cpp"

using namespace std;

void menuInicial();
void menuAdmin();
void menuEmpleados();
/////////////////////////////////////////////////////////////////////////////////
void menuInicial()
{
    int opcion;
    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Elegir el tipo de cuenta" << endl;
    cout << "1. Administrador " << endl;
    cout << "2. Empleados " << endl;
    cout << "3. Clientes " << endl;

    do
    {
        system("cls");
        switch (opcion)
        {
        case 1:
            system("cls");
            menuAdmin();
            system("pause");
            break;
        case 2:
            /* code */
            break;
        default:
            break;
        }
    } while (opcion != 2);
}
/////////////////////////////////////////////////////////////////////////////
void menuAdmin()
{
    int optionA;
    do
    {
        system("cls||clear");

        cout << "-----------------Bienvenido al menu de MCSerigraph--------------" << endl;
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Seccion de clientes" << endl;
        cout << "2. Seccion de productos" << endl;
        cout << "3. Seccion de usuarios" << endl;
        cout << "4. Seccion de facturas" << endl;
        cout << "7. Salir" << endl;
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
/////////////////////////////////////////////////////////////////////
void menuEmpleado()
{
    int optionC, respuesta;
    do
    {
        system("cls||clear");
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Ingresar a productos " << endl;
        cout << "2. Ingresar a facturas " << endl;
        cout << "3. Salir" << endl;
        cin >> optionC;

        switch (optionC)
        {
        case 1:
            cout << "Ha entrado a Productos " << endl;
            cout << "¿Que le gustaria hacer? " << endl;
            menuP();
            system("pause");
            break;
        case 2:
            cout << "Ha entrado a Facturas " << endl;
            break;
            system("pause");

        case 3:
            cout << "Saliendo.................... " << endl;
        default:
            cout << "Opcion invalida " << endl;
            break;
        }
    } while (optionC != 3);
}

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
void menuClientes();

bool credencialesAdmin();

//menuInicial
void menuInicial()
{
    int opcion;
    cout << "-----------------Bienvenido al menu de MCSerigraph--------------" << endl;
    cout << "Elegir el tipo de cuenta" << endl;
    cout << "1. Soy Administrador" << endl;
    cout << "2. Soy Empleado" << endl;
    cout << "3. Soy Cliente" << endl;
    cout << "4. Salir" << endl;

    do
    {
        system("cls");
        switch (opcion)
        {
        case 1:
            system("cls");
            bool adminAdmin;
            adminAdmin = credencialesAdmin();
            if(adminAdmin == true){
                menuAdmin();
            }
            system("pause");
            break;
        case 2:
            system("cls");
            //Desarrollar menu empleados
            system("pause");
            break;
        case 3:
            system("cls");
            menuClientes();
            system("pause");
            break;
        case 4:
            cout << "Saliendo....... " << endl;
            break;
        default:
            break;
        }
    } while (opcion != 4);
}

///menuAdmin
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

//menuEmpleado
void menuEmpleado()
{
    int optionC, respuesta;
    do
    {
        system("cls");
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Ingresar a clientes " << endl;
        cout << "2. Ingresar a productos " << endl;
        cout << "3. Ingresar a facturas " << endl;
        cout << "4. Salir" << endl;
        cin >> optionC;

        switch (optionC)
        {
        case 1:
            cout << "Ha entrado a Clientes " << endl;
            cout << "¿Que le gustaria hacer? " << endl;
            MenuCompleteClient();
            system("pause");
        case 2:
            cout << "Ha entrado a Productos " << endl;
            cout << "¿Que le gustaria hacer? " << endl;
            MenuCompleteProduct();
            system("pause");
            break;
        case 3:
            cout << "Ha entrado a Facturas " << endl;
            break;
            system("pause");
        case 4:
            cout << "Saliendo.................... " << endl;
        default:
            cout << "Opcion invalida " << endl;
            break;
        }
    } while (optionC != 4);
}

//menuClientes
//editar menuclientes solo agregar/editar, no mostrar

void menuClientes()
{
    int optionA;
    do
    {
        system("cls||clear");

        cout << "-----------------Bienvenido al menu de MCSerigraph--------------" << endl;
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Seccion de clientes" << endl;
        cout << "2. Seccion de facturas" << endl;
        cout << "3. Salir" << endl;
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
            cout << "Entrando a la seccion de facturas...";
            system("pause");
            break;
        case 3:
            cout << "Saliendo....... " << endl;
            break;
        default:
            cout << "Opcion invalida, selecciona una opcion del menu...";
            system("pause");
            break;
        }
    } while (optionA != 5);
}

bool credencialesAdmin(){
    string adminUsername = "Admin";
    string adminPass = "SOMOS.UCA";
    bool marcador;

    string temp1;
    string temp2;

    cout << "Ingresa el usuario: " << endl;
    cin >> temp1;
    
    cout << "Ingresa password: " << endl;
    cin >> temp2;

    if(temp1 == adminUsername && temp2 == adminPass){
        marcador = true;
        return marcador;
    } else cout << "Datos invalidos, intente de nuevo." << endl;

}
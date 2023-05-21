#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes/funcionesClientes.cpp"
#include "productos/funcionesProductos.cpp"
#include "facturas.h"

using namespace std;

int lastFactura = 0;

void encabezadoFactura();
void pieDeFactura();

void agregarFactura(factura facturas);

factura getFacturas(int pos);

int buscandoCliente(int position11);
int buscandoProducto(int position22);

void MostrarFactura();
void MostrarFacturas();
void editarFactura();
void ExisteFactura();
void EliminarFacturas();

void menuPrincipal();

//agregar datos
//hacer que # de factura funcione
void encabezadoFactura(){
    cout << "===================MCSerigraph===================" << endl;
    cout << "Direccion:" << endl;
    cout << "Telefono:" << endl;
    cout << "Factura #" << endl;
    cout << "=================================================" << endl;
}

void pieDeFactura(){
    cout << "=================================================" << endl;
    cout << "Gracias por su compra";
    cout << "=================================================" << endl;
}

void agregarFactura(factura facturas){
    recibo[lastFactura] = facturas;
    lastFactura++;
}

factura getFacturas(int pos){
    return recibo[pos];
}

int buscandoCliente(int position11){
    leerCliente();

    char IDpos1[14];
    cliente Clientes;

    cout << " Escribe el ID del cliente para agregar: " << endl;
    scanf(" %[^\n]", Clientes.ID);
    position11 = BuscarCliente(IDpos1);
    cout << endl;
    return position11;
}

int buscandoProducto(int position22){
    leerProducto();

    char IDpos2[14];
    producto productos;


    cout << " Escribe el ID producto para agregar: " << endl;
    scanf(" %[^\n]", productos.IDP);
    position22 = BuscarProducto(IDpos2);
    return position22;
}

void MostrarFactura(){
    int position11; 
    int position22;

    buscandoCliente(position11);
    buscandoProducto(position22);

    position11 = buscandoCliente(position11);
    position22 = buscandoProducto(position22);

    MostrarCliente(position11);
    MostrarProducto(position22);
}





void menuPrincipal(){
    int option;
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
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls||clear");
            cout << "Entrando a la seccion de clientes...";
            MenuCompleteClient();
            system("pause");
            break;
        case 2:
            system("cls||clear");
            cout << "Entrando a la seccion de productos...";
            MenuCompleteProduct();
            system("pause");
            break;
        case 3:
            system("cls||clear");
            cout << "Entrando a la seccion de usuarios...";
            system("pause");
            break;    
        case 4:
            system("cls||clear");
            cout << "Entrando a la seccion de facturas...";
            system("pause");
            break;    
        default:
            cout << "Opcion invalida, selecciona una opcion del menu...";
            system("pause");
            break;
        }
    } while (option != 7);
    
    
}
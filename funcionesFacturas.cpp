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
int BuscarFactura(char idF[]);

int buscandoCliente(int position11);
int buscandoProducto();
int calcularCantidadProducto(int cantidad);

void agregarDatosParaFactura();

void MostrarFactura();
void MostrarFacturas();
void editarFactura();
void ExisteFactura();
void EliminarFacturas();

FILE *baseDatosFactura;
void guardarFactura();
void leerFactura();
int CalcularRegFactura(FILE *regFactura);

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

int calcularCantidadProducto(int cantidad){
    
    cout << "¿Cuanta cantidad de este producto quieres agregar?" << endl;
    cin >> cantidad;
    return cantidad;
}

int buscandoProducto(){
    int pos, cantidad;
    char ID[14];
    producto productos;

    leerProducto();
    
    
    cout << " Escribe el ID del producto a agregar: " << endl;
    scanf(" %[^\n]", productos.IDP);
    pos = BuscarProducto(ID);

    calcularCantidadProducto(cantidad);

    return pos;
}

int BuscarFactura(char idF[])
{
    int posicion = 0;
    for (int i = 0; i < lastFactura; i++)
    {
        if (strcmp(idF, recibo[i].numFactura) == 0)
        {
            posicion = i;
        }
    }
    return posicion;
}

void agregarDatosParaFactura(){
    int position11; 
    int position22;
    int cantidadProductos;

    buscandoCliente(position11);
    position11 = buscandoCliente(position11);

    for (int i = 0; i < cantidadProductos; i++)
    {
        buscandoProducto();
        position22 = buscandoProducto();

        calcularCantidadProducto(cantidadProductos);
        cantidadProductos =  calcularCantidadProducto(cantidadProductos);
    }
    
    

    //mostrar
    MostrarCliente(position11);
    MostrarProducto(position22);

}

int menuF()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "Ver la cantidad de facturas hasta el  momento " << lastFactura << endl;
    cout << "1. Agregar datos a la factura" << endl;
    cout << "2. Buscar factura " << endl;
    cout << "3. Mostrar todas las facturas " << endl;
    cout << "3. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteClient()
{
    int op, pos, resp;
    char IDF[14];
    factura facturas;
    leerCliente();

    do
    {
        system("cls");

        op = menuC();
        switch (op)
        {
        case 1:
            system("cls");
            agregarDatosParaFactura();
            agregarFactura(facturas);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << " Escribe el numero de factura a buscar: " << endl;
            scanf(" %[^\n]", facturas.numFactura);
            pos = BuscarFactura(IDF);
            MostrarFactura(pos);
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarFacturas();
            system("pause");
            break;
        case 4:
            cout << "Saliendo....... " << endl;
            break;
        default:
            system("cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 6);
    guardarFactura();
}

void guardarFactura(){
    baseDatosFactura = fopen("datosfactura.bin", "wb");
    fwrite(recibo, sizeof(factura), lastFactura, baseDatosFactura);
    fclose(baseDatosFactura);
}

void leerFactura(){
    baseDatosFactura = fopen("datosfactura.bin", "rb");
    if (baseDatosFactura == NULL)
    {
        return;
    }
    lastFactura = CalcularRegFactura(baseDatosFactura);
    fread(recibo, sizeof(factura), 500, baseDatosFactura);

    fclose(baseDatosFactura);
}

int CalcularRegFactura(FILE *regFactura){
    int tam_archivo, num_facturas;

    fseek(regFactura, 0, SEEK_END);
    tam_archivo = ftell(regFactura);
    rewind(regFactura);

    num_facturas = tam_archivo / sizeof(factura);
    
    return num_facturas;
}
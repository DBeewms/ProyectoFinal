#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes/funcionesClientes.cpp"
#include "productos/funcionesProductos.cpp"
#include "usuarios/funcionesUsuarios.cpp"
#include "facturas.h"
#include "Auxiliar.h"

using namespace std;

int lastFactura = 0;
int lastDetFac = 0;

void encabezadoFactura(int i);
void pieDeFactura();

void agregarFactura(factura facturas);
void imprimirDetalle(int numFact);

factura getFacturas(int pos);
int BuscarFactura(char idF[]);

int buscandoCliente(int position11);
int buscandoProducto();
int calcularCantidadProducto(int cantidad);

void agregarDatosParaFactura();
/*
void MostrarFactura(int pos);
void MostrarFacturas();
void editarFactura();
void ExisteFactura();
void EliminarFacturas();
*/
FILE *baseDatosFactura;
void guardarFactura();
void leerFactura();
int CalcularRegFactura(FILE *regFactura);

int menuF();
void MenuCompleteFactura();

// agregar datos
// hacer que # de factura funcione
void encabezadoFactura(int i)
{
    cout << "===================MCSerigraph===================" << endl;
    cout << "Direccion: Masaya" << endl;
    cout << "Telefono: 25613023" << endl;
    cout << "Factura #: " << recibo[i].numFactura << endl;
    cout << "Fecha: " << recibo[i].fecha << endl;
    cout << "=================================================" << endl;
    cout << "Cliente: " << recibo[i].nombreCliente << endl;
    imprimirDetalle(recibo[i].numFactura);
}

// NO aplicar IVA
void imprimirDetalle(int numFact)
{
    float total = 0, monto = 0;
    printf("PRODUCTO \t | CANTIDAD \t | PRECIO \t | TOTAL\n");

    for (int i = 0; i < lastDetFac; i++)
    {
        //printf("%d=%d\n", numFact, detalles[i].numFac);
        if (numFact == detalles[i].numFac)
        {

            total = detalles[i].cantidad * detalles[i].precioP;
            monto += total;
            printf("%s \t %3d \t %.2f \t %.2f\n", detalles[i].nomProducto, detalles[i].cantidad, detalles[i].precioP, total);
        }
    }
    printf("Monto a pagar: %.2f\n", monto);
    pieDeFactura();
}

void pieDeFactura()
{
    cout << "=================================================" << endl;
    cout << "Gracias por su compra" << endl;
    cout << "=================================================" << endl;
}

void agregarFactura(factura facturas)
{
    recibo[lastFactura] = facturas;
    lastFactura++;
}

void agregarDetFac(detFac detFactura)
{
    detalles[lastDetFac] = detFactura;
    lastDetFac++;
}

factura getFacturas(int pos)
{
    return recibo[pos];
}

int buscandoCliente(int position11)
{
    leerCliente();

    char IDpos1[14];
    cliente Clientes;

    cout << " Escribe el ID del cliente para agregar: " << endl;
    scanf(" %[^\n]", Clientes.ID);
    position11 = BuscarCliente(IDpos1);
    cout << endl;
    return position11;
}


int BuscarFactura(int idF)
{
    int posicion = 0;
    for (int i = 0; i < lastFactura; i++)
    {
        if (idF == recibo[i].numFactura)
        {
            posicion = i;
        }
    }
    return posicion;
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
    cout << "4. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteFactura()
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

        op = menuF();
        switch (op)
        {
        case 1:
            system("cls");
            facturas.numFactura = lastFactura + 1;
            gotoxy4(10,5);
            cout << "Ingresa la fecha:";
            gotoxy4(28,5);
            scanf(" %[^\n]", facturas.fecha);
            gotoxy4(10,6);
            cout << "Ingresa el cliente:";
            gotoxy4(30,6);
            scanf(" %[^\n]", facturas.nombreCliente);
            gotoxy4(10,7);
            cout << "Ingresa una observacion:";
            gotoxy4(35,7);
            scanf(" %[^\n]", facturas.observacion);
            agregarFactura(facturas);
            cout << "Cuantos productos va a facturar?: ";
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
                    printf("Producto: %s - Precio: %.2f\n", prod.nombreP, prod.precio);
                    strcpy(detalles[lastDetFac].nomProducto, prod.nombreP);
                    detalles[lastDetFac].precioP = prod.precio;
                    cout << "Ingrese la cantidad de productos: ";
                    cin >> detalles[lastDetFac].cantidad;
                    lastDetFac++;
                }
            }
            encabezadoFactura(facturas.numFactura - 1);
            // agregarDatosParaFactura();
            // agregarFactura(facturas);

            system("pause");
            break;
            /*
        case 2:
            system("cls");
            cout << " Escribe el numero de factura a buscar: " << endl;
            scanf(" %d", &facturas.numFactura);
            pos = BuscarFactura(IDF);
            MostrarFactura(pos);
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarFacturas();
            system("pause");
            break;
        */
        case 4:
            cout << "Saliendo....... " << endl;
            break;
        default:
            system("cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 4);
    guardarFactura();
}


void guardarFactura()
{
    baseDatosFactura = fopen("datosfactura.bin", "wb");
    fwrite(recibo, sizeof(factura), lastFactura, baseDatosFactura);
    fclose(baseDatosFactura);
}

void leerFactura()
{
    baseDatosFactura = fopen("datosfactura.bin", "rb");
    if (baseDatosFactura == NULL)
    {
        return;
    }
    lastFactura = CalcularRegFactura(baseDatosFactura);
    fread(recibo, sizeof(factura), 500, baseDatosFactura);

    fclose(baseDatosFactura);
}

int CalcularRegFactura(FILE *regFactura)
{
    int tam_archivo, num_facturas;

    fseek(regFactura, 0, SEEK_END);
    tam_archivo = ftell(regFactura);
    rewind(regFactura);

    num_facturas = tam_archivo / sizeof(factura);

    return num_facturas;
}
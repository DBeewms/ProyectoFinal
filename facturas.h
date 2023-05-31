#include <iostream>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int numFactura;
    char fecha[10];
    char nombreCliente[60];
    char observacion[100];
} factura;

typedef struct
{
    int idDetalle;
    int numFac;
    char nomProducto[30];
    float precioP;
    int cantidad; 
} detFac; //detalles factura

factura recibo[1000];

detFac detalles[10000];


#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 200



typedef struct
{
    char ID[14];
    char nombre[30];
    char apellido[30];
    char direccion[100];
}cliente;

cliente Clien[MAX];
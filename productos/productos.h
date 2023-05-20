#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 200


typedef struct
{
    char IDP[10];
    char nombreP[30];
    char descripcion[100];
    char precio[]; //se cambio de float a char
}producto;

producto productos[MAX];
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 200

typedef struct
{
    char IDU[14];
    char nombreU[30]; 
    char email[100];
    char password[20];
} usuario;

usuario usuarios[MAX];
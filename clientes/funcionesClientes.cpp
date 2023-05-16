#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

using namespace std;
// Se pone la posicion de donde se iniciara

int lastReg = 0;

// se agregan fuciones

// Create
void agregarCliente(cliente Cliente);
// Read
void MostrarCliente(int pos);
void MostrarCliente();
int BuscarCliente(char id[]);
void ClienteInicial(int pos);
cliente getClientes(int pos);
// update
void editarCliente(cliente Clientes, int pos);
// delete
void borrarCliente(int pos);
// Menu
int menuC();
void MenuComplete();
// Archivos
FILE *registroCliente;
void guardarCliente();
void leerCliente();
void CalcularReg(FILE *archivo);

// Se definen las funciones

void agregar(cliente Cliente)
{
    Clien[lastReg] = Cliente;
    lastReg++;
}

void MostrarCliente(int pos)
{
    cout << "ID: " << Clien[pos].ID << endl;
    cout << "NOMBRE: " << Clien[pos].nombre << endl;
    cout << "APELLIDO: " << Clien[pos].apellido << endl;
    cout << "DIRECCION: " << Clien[pos].direccion << endl;
}

cliente getClientes(int pos)
{
    return Clien[pos];
}

int BuscarCliente(char id[])
{
    int posicion = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(id, Clien[i].ID) == 0)
        {
            posicion = i;
        }
    }
    return posicion;
}

void MostrarCliente(){
    system("cls||clear");
    if(lastReg==0){
        cout << "No hay clientes registrados " << endl;
        return;
    }
    for(int i = 0; i < lastReg; i++)
    {
        cout << "======================\n";
        MostrarCliente(i);
    }
    cout << "Ultimo cliente..... " <<endl;
}
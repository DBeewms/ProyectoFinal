#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AuxiliarC.h"
#include "clientes.h"

using namespace std;
// Se pone la posicion de donde se iniciara

int lastReg = 0;

// Create
void agregarCliente(cliente Cliente);
// Read
void MostrarCliente(int pos);
void MostrarClientes();
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
void guardarClientes();
void leerCliente();
int CalcularReg(FILE *archivo);

// Se definen las funciones

void agregarCliente(cliente Cliente)
{
    Clien[lastReg] = Cliente;
    lastReg++;
}

void MostrarCliente(int pos)
{
    
    cout << "ID: " << Clien[pos].ID << endl;
    cout << "NOMBRE: " << Clien[pos].nombre << endl;
    cout << "APELLIDO: " << Clien[pos].apellido << endl;
}

cliente getClientes(int pos)
{
    return Clien[pos];
}

int BuscarCliente(char id[])
{
    int posicion = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(id, Clien[i].ID) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void MostrarClientes()
{
    system("cls");
    if (lastReg == 0)
    {
        cout << "No hay clientes registrados " << endl;
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout << "======================\n";
        MostrarCliente(i);
    }
    cout << "Ultimo cliente..... " << endl;
}

void borrarCliente(int pos)
{
    if (pos == lastReg)
    {
        cout << "No hay registro " << endl;
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        Clien[i] = Clien[i + 1];
    }
    lastReg--;
    ClienteInicial(lastReg);
}

void ClienteInicial(int pos)
{
    strcpy(Clien[pos].ID, "");
    strcpy(Clien[pos].nombre, "");
    strcpy(Clien[pos].apellido, "");
}

int menuC()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "Ver la cantidad de clientes registrados " << lastReg << endl;
    cout << "1. Agregar cliente " << endl;
    cout << "2. Editar cliente " << endl;
    cout << "3. Eliminar cliente " << endl;
    cout << "4. Buscar cliente " << endl;
    cout << "5. Mostrar todos los clientes " << endl;
    cout << "6. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteClient()
{
    int op, pos, resp;
    char ID[14];
    cliente Clientes;
    leerCliente();

    do
    {
        system("cls");

        op = menuC();
        switch (op)
        {
        case 1:
            system("cls");
            gotoxy1(10,5);
            cout << " ID: " << endl;
            gotoxy1(10,6);
            cout << " Nombre: " << endl;
            gotoxy1(10,7);
            cout << " Apellido: " << endl;
            gotoxy1(15,5);
            scanf(" %[^\n]", Clientes.ID);
            gotoxy1(19,6);
            scanf(" %[^\n]", Clientes.nombre);
            gotoxy1(21,7);
            scanf(" %[^\n]", Clientes.apellido);
            agregarCliente(Clientes);
            system("pause");

            break;
        case 2:
            system("cls");
            gotoxy1(10,5);
            cout << "Escribe el ID a buscar: " << endl;
            gotoxy1(34,5);
            scanf(" %[^\n]", Clientes.ID);
            pos = BuscarCliente(ID);
            MostrarCliente(pos);
            gotoxy1(10,6);
            cout << " Datos a editar " << endl;
            gotoxy1(10,7);
            cout << " ID: " << endl;
            gotoxy1(15,7);
            scanf(" %[^\n]", Clientes.ID);
            gotoxy1(10,8);
            cout << " Nombre: " << endl;
            gotoxy1(18,8);
            scanf(" %[^\n]", Clientes.nombre);
            gotoxy1(10,9);
            cout << " Apellido: " << endl;
            gotoxy1(21,9);
            scanf(" %[^\n]", Clientes.apellido);
            //editarCliente(Clientes, pos);
            cout << " Actualizando registro.......... " << endl;
            system("pause");
            break;
        case 3:
            if (lastReg == 0)
            {
                cout << " No hay nada que eliminar " << endl;
                break;
            }
            cout << "Escribe el ID del cliente: " << endl;
            cin >> ID;
            pos = BuscarCliente(ID);
            Clientes = getClientes(pos);
            cout << "Realmente quiere solicitar elimimar a este cliente: " << Clientes.nombre << " " << Clientes.apellido << " ? " << endl;
            cout << "Escribe 1 para acceder y 2 para negar: " << endl;
            cin >> resp;
            if (resp == 1)
            {
                borrarCliente(pos);
                cout << " Registro Eliminado " << endl;
            }
            else
            {
                cout << " Operacion cancelada " << endl;
            }
            system("pause");
            break;
        case 4:
            system("cls");
            gotoxy1(10,5);
            cout << " Escribe el ID a buscar: " << endl;
            gotoxy1(35,5);
            scanf(" %[^\n]", ID);
            pos = BuscarCliente(ID);
            if(pos == -1) cout << "Registro no existe\n";
            else MostrarCliente(pos);
            system("pause");
            break;
        case 5:
            system("cls");
            MostrarClientes();
            system("pause");
            break;
        case 6:
            cout << "Saliendo....... " << endl;
            break;

        default:
            system("cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 6);
    guardarClientes();
}

void guardarClientes()
{
    registroCliente = fopen("datosCliente.bin", "wb");
    fwrite(Clien, sizeof(cliente), lastReg, registroCliente);
    fclose(registroCliente);
}

void leerCliente()
{
    registroCliente = fopen("datosCliente.bin", "rb");
    if (registroCliente == NULL)
    {
        return;
    }
    lastReg = CalcularReg(registroCliente);
    fread(Clien, sizeof(cliente), MAX, registroCliente);

    fclose(registroCliente);
}

int CalcularReg(FILE *archivo)
{
    int tam_archivo, num_clientes;
    // se obtiene el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    // Se calcula el numero de clientes
    num_clientes = tam_archivo / sizeof(cliente);

    return num_clientes;
}

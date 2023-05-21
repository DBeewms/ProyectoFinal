#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

using namespace std;

int lastReg = 0;

void agregarProducto(producto productos);

void MostrarProducto(int pos);
void MostrarProductos();
int BuscarProducto(char id[]);
void ProductoInicial(int pos);
producto getProducto(int pos);

void editarProducto(producto productos, int pos);

void borrarProducto(int pos);

int menuP();
void MenuComplete();

FILE *registroProducto;
void guardarProducto();
void leerProducto();
int CalcularReg(FILE *archivo);


void agregarProducto(producto product)
{
    productos[lastReg] = product;
    lastReg++;
}

void MostrarProducto(int pos)
{
    cout << "ID: " << productos[pos].IDP << endl;
    cout << "NOMBRE DEL PRODUCTO: " << productos[pos].nombreP << endl;
    cout << "DESCRIPCION: " << productos[pos].descripcion << endl;
    cout << "PRECIO: " << productos[pos].precio << endl;
}

producto getProducto(int pos)
{
    return productos[pos];
}

int BuscarProducto(char id[])
{
    int posicion = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(id, productos[i].IDP) == 0)
        {
            posicion = i;
        }
    }
    return posicion;
}

void MostrarProductos()
{
    system("cls||clear");
    if (lastReg == 0)
    {
        cout << "No hay clientes registrados " << endl;
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout << "======================\n";
        MostrarProducto(i);
    }
    cout << "Ultimo producto..... " << endl;
}

void editarProducto(producto product, int pos)
{
    productos[pos];
}

void borrarProducto(int pos)
{
    if (pos == lastReg)
    {
        cout << "No hay registro " << endl;
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        productos[i] = productos[i + 1];
    }
    lastReg--;
    ProductoInicial(lastReg);
}

void ProductoInicial(int pos)
{
    strcpy(productos[pos].IDP, "");
    strcpy(productos[pos].nombreP, "");
    strcpy(productos[pos].descripcion, "");
    strcpy(productos[pos].precio, "");
}

int menuP()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "Ver la cantidad de clientes registrados " << lastReg << endl;
    cout << "1. Agregar cliente " << endl;
    cout << "2. Editar cliete " << endl;
    cout << "3. Eliminar cliente " << endl;
    cout << "4. Buscar cliente " << endl;
    cout << "5. Mostrar todos los clientes " << endl;
    cout << "6. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteProduct()
{
    int op, pos, resp;
    char ID[14];
    producto productos;
    leerProducto();

    do
    {
        system("cls||clear");

        op = menuP();
        switch (op)
        {
        case 1:
            system("cls||clear");
            cout << " ID: " << endl;
            cout << " Nombre: " << endl;
            cout << " DESCRIPCION: " << endl;
            cout << " PRECIO:" <<endl;
            scanf(" %[^\n]", productos.IDP);
            scanf(" %[^\n]", productos.nombreP);
            scanf(" %[^\n]", productos.descripcion);
            scanf(" %[^\n]", productos.precio);
            agregarProducto(productos);
            system("pause");

            break;
        case 2:
            system("cls||clear");
            cout << "Escribe el ID a buscar: " << endl;
            scanf(" %[^\n]", productos.IDP);
            pos = BuscarProducto(ID);
            MostrarProducto(pos);
            cout << " Datos a editar " << endl;
            cout << " ID: " << endl;
            scanf(" %[^\n]", productos.IDP);
            cout << " Nombre: " << endl;
            scanf(" %[^\n]", productos.nombreP);
            cout << " Descripcion: " << endl;
            scanf(" %[^\n]", productos.descripcion);
            cout << " Precio" << endl;
            scanf(" %[^\n]", productos.precio);
            editarProducto(productos, pos);
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
            pos = BuscarProducto(ID);
            productos = getProducto(pos);
            cout << "¿Realmente quiere solicitar elimimar a este producto: " << productos.nombreP << "" << productos.IDP << " ? " << endl;
            cout << "Escribe 1 para acceder y 2 para negar: " << endl;
            cin >> resp;
            if (resp == 1)
            {
                borrarProducto(pos);
                cout << " Registro Eliminado " << endl;
            }
            else
            {
                cout << " Operacion cancelada " << endl;
            }
            system("pause");
            break;
        case 4:
            system("cls||clear");
            cout << " Escribe el ID del producto a buscar: " << endl;
            scanf(" %[^\n]", productos.IDP);
            pos = BuscarProducto(ID);
            MostrarProducto(pos);
            system("pause");
            break;
        case 5:
            system("cls||clear");
            MostrarProductos();
            system("pause");
        case 6:
            cout << "Saliendo....... " << endl;
            break;

        default:
            system("clear||cls");
            cout << " Opcion no valida " << endl;
            system("pause");
            break;
        }
    } while (op != 6);
    guardarProducto();
}

void guardarProducto()
{
    registroProducto = fopen("datos.bin", "wb");
    fwrite(productos, sizeof(producto), lastReg, registroProducto);
    fclose(registroProducto);
}

void leerCliente()
{
    registroProducto = fopen("datos.bin", "rb");
    if (registroProducto == NULL)
    {
        return;
    }
    lastReg = CalcularReg(registroProducto);
    fread(productos, sizeof(producto), MAX, registroProducto);

    fclose(registroProducto);
}

int CalcularReg(FILE *archivo)
{
    int tam_archivo, num_productos;
    // se obtiene el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    // Se calcula el numero de clientes
    num_productos = tam_archivo / sizeof(producto);
    
    return num_productos;
}
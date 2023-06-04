#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

using namespace std;

int lastRegP = 0;

void agregarProducto(producto productos);

void MostrarProducto(int pos);
void MostrarProductos();
int BuscarProducto(char id[]);
void ProductoInicial(int pos);
producto getProducto(int pos);

void editarProducto(producto productos, int pos);

void borrarProducto(int pos);

int menuP();
void MenuCompleteProduct();

FILE *registroProducto;
void guardarProducto();
void leerProducto();
int CalcularRegP(FILE *archivo);


void agregarProducto(producto product)
{
    productos[lastRegP] = product;
    lastRegP++;
}

void MostrarProducto(int pos)
{
    cout << "ID: " << productos[pos].IDP << endl;
    cout << "NOMBRE DEL PRODUCTO: " << productos[pos].nombreP << endl;
    cout << "DESCRIPCION: " << productos[pos].descripcion << endl;
    printf("PRECIO: %.2f\n", productos[pos].precio);
    //cout << "PRECIO: " << productos[pos].precio << endl;
}

producto getProducto(int pos)
{
    return productos[pos];
}

int BuscarProducto(char id[])
{
    int posicion = -1;
    for (int i = 0; i < lastRegP; i++)
    {
        //printf("%s es igual %s\n", id, productos[i].IDP);
        if (strcmp(id, productos[i].IDP) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void MostrarProductos()
{
    system("cls");
    if (lastRegP == 0)
    {
        cout << "No hay registro " << endl;
        return;
    }
    for (int i = 0; i < lastRegP; i++)
    {
        cout << "======================\n";
        MostrarProducto(i);
    }
    cout << "Ultimo producto..... " << endl;
}

void borrarProducto(int pos)
{
    if (pos == lastRegP)
    {
        cout << "No hay registro " << endl;
        return;
    }
    for (int i = pos; i < lastRegP - 1; i++)
    {
        productos[i] = productos[i + 1];
    }
    lastRegP--;
    ProductoInicial(lastRegP);
}

void ProductoInicial(int pos)
{
    strcpy(productos[pos].IDP, "");
    strcpy(productos[pos].nombreP, "");
    strcpy(productos[pos].descripcion, "");
    productos[pos].precio=0;
    //strcpy(productos[pos].precio, "");
}

int menuP()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "Cantidad de productos almacenados " << lastRegP << endl;
    cout << "1. Agregar producto " << endl;
    cout << "2. Editar producto " << endl;
    cout << "3. Eliminar producto " << endl;
    cout << "4. Buscar producto " << endl;
    cout << "5. Mostrar todos los productos " << endl;
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
        system("cls");

        op = menuP();
        switch (op)
        {
        case 1:
            system("cls");
            cout << " ID: " << endl;
            cout << " Nombre: " << endl;
            cout << " DESCRIPCION: " << endl;
            cout << " PRECIO:" <<endl;
            scanf(" %[^\n]", productos.IDP);
            scanf(" %[^\n]", productos.nombreP);
            scanf(" %[^\n]", productos.descripcion);
            scanf("%f", &productos.precio);
            agregarProducto(productos);
            system("pause");

            break;
        case 2:
            system("cls");
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
            scanf("%f", &productos.precio);
            //editarProducto(productos, pos);
            cout << " Actualizando registro.......... " << endl;
            system("pause");
            break;
        case 3:
            if (lastRegP == 0)
            {
                cout << " No hay nada que eliminar " << endl;
                break;
            }
            cout << "Escribe el ID del producto: " << endl;
            cin >> ID;
            pos = BuscarProducto(ID);
            productos = getProducto(pos);
            cout << "Realmente quiere solicitar elimimar a este producto: " << productos.nombreP << " " << productos.IDP << " ? " << endl;
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
            //copiar estrucutura en demas funciones, clientes y usuarios
            system("cls");
            cout << " Escribe el ID del producto a buscar: " << endl;
            scanf(" %[^\n]", ID);
            pos = BuscarProducto(ID);
            if(pos == -1) cout << "Registro no existe\n";
            else MostrarProducto(pos);
            system("pause");
            break;
        case 5:
            system("cls");
            MostrarProductos();
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
    guardarProducto();
}

void guardarProducto()
{
    registroProducto = fopen("datosProducto.bin", "wb");
    fwrite(productos, sizeof(producto), lastRegP, registroProducto);
    fclose(registroProducto);
}

void leerProducto()
{
    registroProducto = fopen("datosProducto.bin", "rb");
    if (registroProducto == NULL)
    {
        return;
    }
    lastRegP = CalcularRegP(registroProducto);
    fread(productos, sizeof(producto), MAX, registroProducto);

    fclose(registroProducto);
}

int CalcularRegP(FILE *archivo)
{
    int tam_archivo, num_productos;
    // se obtiene el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    num_productos = tam_archivo / sizeof(producto);
    
    return num_productos;
}
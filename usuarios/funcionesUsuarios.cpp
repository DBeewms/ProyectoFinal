#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "AuxiliarU.h"
#include "usuarios.h"

using namespace std;
int lastRegU = 0;

// create
void agregarUsuario(usuario Usuario);
/*Read*/
void mostrarUsuario(int pos);
void mostrarUsuarios();
int buscarUsuario(char IDU[]);
void inicialUsuario(int pos);
usuario getUsuarios(int pos);
/*Update*/
void editarUsuario(usuario User2, int pos);
/*Delete*/
void borrarUsuario(int pos);
/*Menu*/
int menuU();
void MenuCompleteUsuario();
/*Archivos*/
FILE *registroUsuario;
void guardarUsuario();
void leerUsuario();
int CalcularRegU(FILE *archivo);

/*Se definen las funciones*/

void agregarUsuario(usuario users)
{
    usuarios[lastRegU] = users;
    lastRegU++;
}

void mostrarUsuario(int pos)
{
    cout << "ID:" << usuarios[pos].IDU << endl;
    cout << "NOMBRE DEL USUARIO:" << usuarios[pos].nombreU << endl;
    cout << "EMAIL:" << usuarios[pos].email << endl;
    cout << "PASSWORD:" << usuarios[pos].password << endl;
}

usuario getUsuarios(int pos)
{
    return usuarios[pos];
}

int buscarUsuario(char id[])
{
    int posicion = -1;
    for (int i = 0; i < lastRegU; i++)
    {
        if (strcmp(id, usuarios[i].IDU) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void mostrarUsuarios()
{
    system("cls");
    if (lastRegU == 0)
    {
        cout << "No hay usuarios registrados" << endl;
        return;
    }

    for (int i = 0; i < lastRegU; i++)
    {
        cout << "=========================\n";
        mostrarUsuario(i);
    }
    cout << "Ultimo usuario...." << endl;
}

void editarUsuario(usuario User2, int pos){
    usuarios[pos]=User2;
}

void borrarUsuario(int pos)
{
    if (pos == lastRegU)
    {
        cout << "No hay registro " << endl;
        return;
    }
    for (int i = pos; i < lastRegU - 1; i++)
    {
        usuarios[i] = usuarios[i + 1];
    }
    lastRegU--;
    inicialUsuario(lastRegU);
}

void inicialUsuario(int pos)
{
    strcpy(usuarios[pos].IDU, "");
    strcpy(usuarios[pos].nombreU, "");
    strcpy(usuarios[pos].email, "");
    strcpy(usuarios[pos].password, "");
}

int menuU()
{
    int op;

    cout << "-----------------Bienvenido al menu de MCSerigraph-------------- " << endl;
    cout << "Seleccione una de las opciones " << endl;
    cout << "Ver la cantidad de clientes registrados " << lastRegU << endl;
    cout << "1. Agregar usuario " << endl;
    cout << "2. Editar usuario " << endl;
    cout << "3. Eliminar usuario " << endl;
    cout << "4. Buscar usuario" << endl;
    cout << "5. Mostrar todos los usuario " << endl;
    cout << "6. Salir " << endl;
    cout << " Digite la opcion " << endl;
    cin >> op;
    return op;
}

void MenuCompleteUsuario()
{
    int op, pos, resp;
    char ID[14];
    usuario User2;
    leerUsuario();

    do
    {
        system("cls");

        op = menuU();
        switch (op)
        {
        case 1:
            system("cls");
            gotoxy3(10,5);
            cout << " ID: " << endl;
            gotoxy3(10,6);
            cout << " Nombre: " << endl;
            gotoxy3(10,7);
            cout << " Email: " << endl;
            gotoxy3(10,8);
            cout << " Password:" << endl;
            gotoxy3(15,5);
            scanf(" %[^\n]", User2.IDU);
            gotoxy3(19,6);
            scanf(" %[^\n]", User2.nombreU);
            gotoxy3(18,7);
            scanf(" %[^\n]", User2.email);
            gotoxy3(21,8);
            scanf(" %[^\n]", User2.password);

            agregarUsuario(User2);
            system("pause");

            break;
        case 2:
            system("cls");
            cout << "Escribe el ID a buscar: " << endl;
            scanf(" %[^\n]", User2.IDU);
            pos = buscarUsuario(ID);
            mostrarUsuario(pos);
            cout << " Datos a editar " << endl;
            cout << " ID: " << endl;
            scanf(" %[^\n]", User2.IDU);
            cout << " Nombre: " << endl;
            scanf(" %[^\n]", User2.nombreU);
            cout << " email" << endl;
            scanf(" %[^\n]", User2.email);
            cout << " Password " << endl;
            scanf(" %[^\n]", User2.password);
            editarUsuario(User2, pos);
            cout << " Actualizando registro.......... " << endl;
            system("pause");
            break;
        case 3:
            if (lastRegU == 0)
            {
                cout << " No hay nada que eliminar " << endl;
                break;
            }
            cout << "Escribe el ID del Usuario: " << endl;
            cin >> ID;
            pos = buscarUsuario(ID);
            User2 = getUsuarios(pos);
            cout << "Realmente quiere solicitar elimimar a este usuarios " << User2.nombreU << " " << User2.IDU << " ? " << endl;
            cout << "Escribe 1 para acceder y 2 para negar: " << endl;
            cin >> resp;
            if (resp == 1)
            {
                borrarUsuario(pos);
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
            gotoxy3(10,5);
            cout << " Escribe el ID del usuario a buscar: " << endl;
            gotoxy3(53,5);
            scanf(" %[^\n]", ID);
            pos = buscarUsuario(ID);
            if (pos == -1)
                cout << "Registro no existe\n";
            else
                mostrarUsuario(pos);
            system("pause");
            break;
        case 5:
            system("cls");
            mostrarUsuarios();
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
    guardarUsuario();
}

void guardarUsuario()
{
    registroUsuario = fopen("datosUsuario.bin", "wb");
    fwrite(usuarios, sizeof(usuario), lastRegU, registroUsuario);
    fclose(registroUsuario);
}

void leerUsuario()
{
    registroUsuario = fopen("datosUsuario.bin", "rb");
    if (registroUsuario == NULL)
    {
        return;
    }
    lastRegU = CalcularRegU(registroUsuario);
    fread(usuarios, sizeof(usuario), MAX, registroUsuario);

    fclose(registroUsuario);
}

int CalcularRegU(FILE *archivo)
{
    int tam_archivo, num_usuarios;
    // se obtiene el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    num_usuarios = tam_archivo / sizeof(usuarios);

    return num_usuarios;
}
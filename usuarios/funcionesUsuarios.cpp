#include <stdio.h>
#include <stdlib.h>
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
void editarUsuario();
/*Delete*/
void eliminarUsuario(int pos);
/*Menu*/
void menuUsuarios();
void menuCompleto();
/*Archivos*/
FILE *resgistroUsuario;
void guardarUsuario();
void leerUsuario();
void calcularReg(FILE *archivo);


/*Se definen las funciones*/

void agregarUsuario(usuario Usuario)
{
    usuarios[lastRegU] = Usuario;
    lastRegU++;
}   


void mostrarUsuario(int pos)
{
    cout << "ID:" << usuarios[pos].IDU << endl;
    cout << "NOMBRE DE USUARIO:" << usuarios[pos].nombreU << endl;
    cout << "EMAIL:" << usuarios[pos].email << endl;
    cout << "CONTRASEÑA:" <<usuarios[pos].password << endl;

}

usuario getUsuarios(int pos)
{
    return usuarios[pos];
}

int buscarUsuario(char IDU[])
{
    int posicion = 0;
    for(int i = 0; i < lastRegU; i++)
    {
        if (strcmp(IDU, usuarios[i].IDU) == 0)
        {
            posicion = i;
        }
    }
    return posicion;
}

void mostrarUsuarios()
{
    system("cls||clear");
    if (lastRegU == 0)
    {
        cout << "No hay usuarios registrados" << endl;
        return;
    }

    for(int i = 0; i < lastRegU; i++)
    {
       cout<< "=========================\n";
       mostrarUsuario(i); 
    }
    cout << "Ultimo usuario...." << endl;
}
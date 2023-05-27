#include <iostream>
#include "clientes/funcionesClientes.cpp"
#include "productos/funcionesProductos.cpp"
#include "usuarios/funcionesUsuarios.cpp" 


using namespace std;


int main()
{
    int option;
    do
    {
        system("cls||clear");

        cout << "-----------------Bienvenido al menu de MCSerigraph--------------" << endl;
        cout << "Seleccione una de las opciones: " << endl;
        cout << "1. Seccion de clientes" << endl;
        cout << "2. Seccion de productos" << endl;
        cout << "3. Seccion de usuarios" << endl;
        cout << "4. Seccion de facturas" << endl;
        cout << "7. Salir" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            system("cls||clear");
            cout << "Entrando a la seccion de clientes...";
            MenuCompleteClient();
            system("pause");
            break;
        case 2:
            system("cls||clear");
            cout << "Entrando a la seccion de productos...";
            MenuCompleteProduct();
            system("pause");
            break;
        case 3:
            system("cls||clear");
            cout << "Entrando a la seccion de usuarios...";
            MenuCompleteUsuario();
            system("pause");
            break;    
        case 4:
            system("cls||clear");
            cout << "Entrando a la seccion de facturas...";
            system("pause");
            break;    
        default:
            cout << "Opcion invalida, selecciona una opcion del menu...";
            system("pause");
            break;
        }
    } while (option != 7);

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int arreglo[20];

    arreglo[5] = 89;

    int CIcliente, pos;
    bool flag = false;

    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> CIcliente;

    for (int i = 0; i < 20; i++) {
        if (CIcliente == arreglo[i]) {
            flag = true;
            pos = i;
        }
    }

    if (flag) {
        cout << "Se ha encontrado este cliente: \n";
        cout << "CI: " << CIcliente << endl;
        cout << "Posición: " << pos<< endl;
        system("pause");
    } else {
        cout << "El cliente no esta registrado" << endl;
        system("pause");
    }

    system("cls");
    return 0;
}

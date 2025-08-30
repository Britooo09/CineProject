#include <iostream>
using namespace std;

int main() {
    string nombres[50], aux1;
    int cedulas[50], busqueda, aux2;
    bool existe = false;

    for (int i = 0; i < 50; i++) {
        cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
        cin >> nombres[i];

        do {
            existe = false;
            cout << "Ingrese el numero de cedula de " << nombres[i] << ": ";
            cin >> busqueda;

            for (int j = 0; j < 50; j++) {
                if (busqueda == cedulas[j]) {
                    existe = true;
                }
            }

            if (existe) {
                cout << "Ese numero de cedula ya esta registrado\n";
            }
        } while (existe);
        cedulas[i] = busqueda;
    }

    cout << "\nSe ha llegado al maximo de registros posible\n";
    system("pause");
    system("cls");

    for (int i = 0; i < 50; i++) {
        for (int j = i + 1; j < 50; j++) {
            if (nombres[i] > nombres[j]) {
                aux1 = nombres[j];
                nombres[j] = nombres[i];
                nombres[i] = aux1;

                aux2 = cedulas[j];
                cedulas[j]=cedulas[i];
                cedulas[i]=aux2;
            }
        }
    }

    cout<<"Lista de registros, ordenada alfabeticamente:\n\n";
    cout<<"Cedula\tNombre\n";
    for (int i = 0; i < 50; i++)
    {
        cout<<cedulas[i]<<"    "<<nombres[i]<<"\n";
    }

    system("pause");
    return 0;
}
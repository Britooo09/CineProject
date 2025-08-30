#include <iostream>
using namespace std;

class Pelicula {
    string nombre;
    int sala;

public:
    Pelicula(string a, int b): nombre(a), sala(b) {}

    string GetNombre() {
        return nombre;
    }
    int GetSala() {
        return sala;
    }
};

int main() {
    Pelicula* peli[2];

    string nombrePeli;
    int salaPeli;

    for (int i = 0; i < 2; i++) {

        cout << "Nombre\n";
        cin >> nombrePeli;

        cout << "Sala\n";
        cin >> salaPeli;

        peli[i] = new Pelicula(nombrePeli, salaPeli);
    }

    for (int j = 0; j < 2; j++) {
        cout << "Película " << j + 1 << ":\n";
        cout << j + 1 << ". " << peli[j]->GetNombre() << " (Sala " << peli[j]->GetSala() << ")\n";
    }
}
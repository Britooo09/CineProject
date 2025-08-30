#include <iostream>
using namespace std;

string userlist[] = { "pepito", "juanito", "jaimito" };
string passlist[] = { "password", "tpoo", "12345" };
string asientos[6][7][10];

float gen = 50.0, lun = 25.0, mpt = 40.0, am = 25.0, nuevoprecio = 0;

class Pelicula {
    string nombre, clas;
    int sala, hora;
public:
    Pelicula(string _nombre, int _sala, int _hora, string _clas): nombre(_nombre), sala(_sala), hora(_hora), clas(_clas) {}

    string GetNombre() {
        return nombre;
    }
    string GetClas() {
        return clas;
    }
    int GetSala() {
        return sala;
    }
    int GetHora() {
        return hora;
    }
};

Pelicula* peli[6];

void crearAsientos(int a);
void mostrarAsientos(int a);
void crearPeliculas();
void mostrarPeliculas();

int main() {
    crearPeliculas();
    mostrarPeliculas();
    cout<<"\n\n";

    asientos[0][2][2] = "X ";
    asientos[0][2][3] = "X ";

    mostrarAsientos(0);

    system("pause");
    return 0;
}

void crearAsientos(int a) {         // LISTO
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i > 1 && i < 7) && (j == 4 || j == 5)) {
                asientos[a][i][j] = "  ";
            } else {
                asientos[a][i][j] = "O ";
            }
        }
    }

    asientos[a][0][0] = "1 ";
    asientos[a][0][1] = "2 ";
    asientos[a][0][2] = "3 ";
    asientos[a][0][3] = "4 ";
    asientos[a][0][4] = "5 ";
    asientos[a][0][5] = "6 ";
    asientos[a][0][6] = "7 ";
    asientos[a][0][7] = "8 ";
    asientos[a][0][8] = "9 ";
    asientos[a][0][9] = "10 ";
}

void mostrarAsientos(int a) {       // LISTO
    for (int i = 0; i < 7; i++) {
        cout << "  ";
        switch (i) {
        case 0:
            cout << "    ";
            break;
        case 1:
            cout << "F   ";
            break;
        case 2:
            cout << "E   ";
            break;
        case 3:
            cout << "D   ";
            break;
        case 4:
            cout << "C   ";
            break;
        case 5:
            cout << "B   ";
            break;
        case 6:
            cout << "A   ";
            break;
        }
        for (int j = 0; j < 10; j++) {
            cout << asientos[a][i][j];
        }
        cout << "\n";
    }
    cout << "    ========================\n";
    cout << "            Pantalla\n\n";
    cout << "  O = Disponible; X = Ocupado\n\n";
}

void crearPeliculas() {             // LISTO
    for (int i = 0; i < 6; i++) {
        crearAsientos(i);
    }

    peli[0] = new Pelicula("Película A", 1, 14, "G");
    peli[1] = new Pelicula("Película B", 2, 16, "PG");
    peli[2] = new Pelicula("Película C", 3, 17, "PG");
    peli[3] = new Pelicula("Película D", 4, 18, "PG");
    peli[4] = new Pelicula("Película E", 5, 18, "PG13");
    peli[5] = new Pelicula("Película F", 6, 20, "M18");
}

void mostrarPeliculas() {           // LISTO
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << peli[i]->GetNombre() << " (Sala " << peli[i]->GetSala() << ") | " << peli[i]->GetHora() << ":00 | " << peli[i]->GetClas() << "\n";
    }
}
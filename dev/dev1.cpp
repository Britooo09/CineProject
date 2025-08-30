#include <iostream>
#include <string>
using namespace std;

string userlist[] = { "pepito", "juanito", "jaimito" };
string passlist[] = { "password", "tpoo", "12345" };
string asientos[6][7][10];

int numCliente = 0;

float gen = 50.0, lun = 25.0, mpt = 40.0, am = 25.0, nuevoprecio = 0;

class Cliente {
    int cedula;
    string nombre;
    int descuento, pelicula, boleto;
public:
    Cliente(int _cedula, string _nombre, int _descuento, int _pelicula, int _boleto): cedula(_cedula), nombre(_nombre), descuento(_descuento), pelicula(_pelicula), boleto(_boleto) {
        switch (descuento) {
        case 1:
            descuento = lun;
            break;
        case 2:
            descuento = mpt;
            break;
        case 3:
            descuento = am;
            break;
        case 4:
            descuento = gen;
            break;
        }
    }

    int Getcedula() {
        return cedula;
    }
    string Getnombre() {
        return nombre;
    }
    int Getdescuento() {
        return descuento;
    }
    int Getpelicula() {
        return pelicula;
    }
    int Getboleto() {
        return boleto;
    }

    void Deletecedula() {
        cedula = '\0';
    }
    void Deletenombre() {
        nombre = '\0';
    }
    void Deletedescuento() {
        descuento = '\0';
    }
    void Deletepelicula() {
        pelicula = '\0';
    }
    void Deleteboleto() {
        boleto = '\0';
    }
};

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
Cliente* cliente[20];
int cedulas[20];

void encabezado();                  // LISTO
void login();                       // LISTO
void menu();                        // LISTO
void crearPeliculas();              // LISTO
void unaPelicula(int a);            // LISTO
void mostrarPeliculas();            // LISTO
void listaPeliculas();              // LISTO
void registro();                    // LISTO
void buscar();                      // LISTO
void eliminar();                    // 
void unCliente(int a);              // LISTO
void clientes();                    // LISTO
void crearAsientos(int a);          // LISTO
void mostrarAsientos(int a);        // LISTO
void precios();                     // LISTO

int main() {
    crearPeliculas();
    login();
    system("pause");
    return 0;
}

void encabezado() {                 // LISTO
    system("cls");
    cout << "\t\t* SISTEMA DE GESTION PRINCIPAL DEL CINE *\n\n";
}

void login() {                      // LISTO
    encabezado();

    string user, pass;
    cout << "Por favor, compruebe su identidad entrando con sus credenciales.\n";
    cout << "\nUsuario: ";
    cin >> user;
    cout << "\nContrasena: ";
    cin >> pass;

    bool correcto = false;
    for (int i = 0; i < 3; i++) {
        if ((user == userlist[i]) && (pass == passlist[i])) {
            correcto = true;
        }
    }

    if (correcto) {
        encabezado();
        cout << "Usted ha ingresado correctamente. Entrando al sistema...\n\n";
        system("pause");
        menu();
    } else {
        encabezado();
        cout << "Usuario y/o contrasena incorrectos. Por favor, intente de nuevo\n\n";
        system("pause");
        login();
    }
}

void menu() {                       // LISTO
    encabezado();

    int opc;
    cout << "Bienvenido al programa de gestion de boletos. Por favor, seleccione una opcion:\n";
    cout << "  1. Registrar nuevo cliente\n  2. Buscar cliente\n  3. Eliminar Cliente\n  4. Ver lista de clientes\n  5. Ver lista de peliculas\n  6. Precio de boletos\n  0. Salir del programa" << endl;
    cin >> opc;
    switch (opc) {
    case 1: {
        registro();
        break;
    }
    case 2: {
        buscar();
        break;
    }
    case 3: {
        eliminar();
        break;
    }
    case 4: {
        clientes();
        break;
    }
    case 5: {
        listaPeliculas();
        break;
    }
    case 6: {
        precios();
        break;
    }
    case 0: {
        break;
    }
    default: {
        cout << "La opcion que selecciono no es valida. Por favor, intente de nuevo";
        system("pause");
        menu();
        break;
    }
    }
}

void registro() {                   // LISTO
    encabezado();

    int CI, Dto, B, opc, filas, colum;
    string N;
    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> CI;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin >> ws, N);
    cout << "\nDesea aplicar un descuento?" << endl;
    cout << "  1. Lunes popular (Bs. " << lun << ")" << endl;
    cout << "  2. Miercoles para ti (Bs. " << mpt << ")" << endl;
    cout << "  3. Adulto mayor (Bs. " << am << ")" << endl;
    cout << "  4. No (Bs. " << gen << ")" << endl;
    cin >> Dto;
    encabezado();
    cout << "Indique la pelicula deseada segun la lista: " << endl;
    mostrarPeliculas();
    cin >> opc;
    cout << "\nIndique cuantos boletos desea comprar: ";
    cin >> B;
    encabezado();

    for (int i = 0; i < B; i++) {
        do {
            cout << "Seleccione el asiento " << i + 1 << " (ingrese primero las filas y luego las columnas): \n\n";
            mostrarAsientos(opc - 1);
            cin >> filas;
            cin >> colum;
            encabezado();
            if (asientos[opc - 1][filas][colum - 1] == "X ") {
                cout << "Ese asiento ya esta ocupado. Por favor, seleccione otro.\n";
            }

        } while (asientos[opc - 1][filas][colum - 1] == "X ");

        asientos[opc - 1][filas][colum - 1] = "X ";
    }

    cliente[numCliente] = new Cliente(CI, N, Dto, opc, B);
    cedulas[numCliente] = cliente[numCliente]->Getcedula();

    cout << "Registro de nuevo cliente exitoso\n";
    unCliente(numCliente);
    system("pause");
    numCliente++;
    menu();
}

void buscar() {                     // LISTO
    encabezado();

    int busqueda, pos;
    bool flag = false;
    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> busqueda;

    for (int i = 0; i < 20; i++) {
        if (busqueda == cedulas[i]) {
            flag = true;
            pos = i;
        }
    }

    if (flag) {
        encabezado();
        cout << "Se ha encontrado este cliente:\n";
        unCliente(pos);
    } else {
        cout << "El cliente no esta registrado\n\n";
    }
    system("pause");
    menu();
}

void eliminar() {                   // 
    encabezado();

    int busqueda, pos, opc;
    bool flag = false;
    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> busqueda;

    for (int i = 0; i < 20; i++) {
        if (busqueda == cedulas[i]) {
            flag = true;
            pos = i;
        }
    }

    if (flag) {
        encabezado();
        cout << "Esta seguro de que desea eliminar este cliente?\n";
        unCliente(pos);
        cout << "1. Si\n2. No\n\n";
        cin >> opc;

        if (opc == 1) {
            encabezado();
            cedulas[pos] = '\0';
            cliente[pos]->Deleteboleto();
            cliente[pos]->Deletecedula();
            cliente[pos]->Deletedescuento();
            cliente[pos]->Deletenombre();
            cliente[pos]->Deletepelicula();
            cout << "Se ha eliminado el cliente con exito\n\n";
        }
    } else {
        cout << "El cliente no esta registrado\n\n";
    }
    system("pause");
    menu();
}

void unCliente(int a) {             // LISTO
    cout << "  Cliente nro. " << a + 1 << endl;
    cout << "  CI: " << cliente[a]->Getcedula() << endl;
    cout << "  Nombre: " << cliente[a]->Getnombre() << endl;
    cout << "  Pelicula: ";
    unaPelicula(cliente[a]->Getpelicula());
    cout << "  Asiento(s): " << endl;
    cout << "  Total a pagar: Bs. " << cliente[a]->Getdescuento() * cliente[a]->Getboleto() << "\n\n";
}

void clientes() {                   // LISTO
    encabezado();

    for (int i = 0; i < 20; i++) {
        if (i) {
            cout << cliente[i]->Getcedula() << " | " << cliente[i]->Getnombre() << " | " << peli[cliente[i]->Getpelicula() - 1]->GetNombre() << "\n";
        }
    }
    system("pause");
    menu();
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

    peli[0] = new Pelicula("Pelicula A", 1, 14, "G");
    peli[1] = new Pelicula("Pelicula B", 2, 16, "PG");
    peli[2] = new Pelicula("Pelicula C", 3, 17, "PG");
    peli[3] = new Pelicula("Pelicula D", 4, 18, "PG");
    peli[4] = new Pelicula("Pelicula E", 5, 18, "PG13");
    peli[5] = new Pelicula("Pelicula F", 6, 20, "M18");
}

void unaPelicula(int a) {           // LISTO
    cout << a << ". " << peli[a - 1]->GetNombre() << " (Sala " << peli[a - 1]->GetSala() << ") | " << peli[a - 1]->GetHora() << ":00 | " << peli[a - 1]->GetClas() << "\n";
}

void mostrarPeliculas() {           // LISTO
    for (int i = 1; i < 7; i++) {
        cout << "  ";
        unaPelicula(i);
    }
}

void listaPeliculas() {             // LISTO
    encabezado();
    int opc;
    cout << "Indique una pelicula para ver los asientos disponibles: \n";
    mostrarPeliculas();
    cout << "  0. Volver al menu anterior\n";
    cin >> opc;
    if (opc) {
        encabezado();
        mostrarAsientos(opc - 1);
        system("pause");
    }
    menu();
}

void precios() {                    // LISTO
    encabezado();

    int opc, boleto;
    cout << "Precio de los boletos: \n";

    cout << "  1-General: " << gen;
    cout << "\n  2-Lunes Popular: " << lun;
    cout << "\n  3-Miercoles para ti: " << mpt;
    cout << "\n  4-Adultos Mayor: " << am << "\n\n";

    cout << "1. Modificar precio de los boletos\n";
    cout << "2. Volver al menu anterior\n\n";

    do {
        cout << "Digite la opcion: ";
        cin >> opc;
        if (opc == 1) {
            do {
                cout << "Digite el boleto a modificar: ";
                cin >> boleto;
                switch (boleto) {
                case 1: {
                    cout << "Digite el nuevo precio: ";
                    cin >> nuevoprecio;
                    gen = nuevoprecio;
                    cout << "  1-General: " << gen << endl;
                    cout << "  2-Lunes Popular: " << lun << endl;
                    cout << "  3-Miercoles para ti: " << mpt << endl;
                    cout << "  4-Adultos Mayor: " << am << endl;
                    break;
                }
                case 2: {
                    cout << "Digite el nuevo precio: ";
                    cin >> nuevoprecio;
                    lun = nuevoprecio;
                    cout << "  1-General: " << gen << endl;
                    cout << "  2-Lunes Popular: " << lun << endl;
                    cout << "  3-Miercoles para ti: " << mpt << endl;
                    cout << "  4-Adultos Mayor: " << am << endl;
                    break;
                }
                case 3: {
                    cout << "Digite el nuevo precio: ";
                    cin >> nuevoprecio;
                    mpt = nuevoprecio;
                    cout << "  1-General: " << gen << endl;
                    cout << "  2-Lunes Popular: " << lun << endl;
                    cout << "  3-Miercoles para ti: " << mpt << endl;
                    cout << "  4-Adultos Mayor: " << am << endl;
                    break;
                }
                case 4: {
                    cout << "Digite el nuevo precio: ";
                    cin >> nuevoprecio;
                    am = nuevoprecio;
                    cout << "  1-General: " << gen << endl;
                    cout << "  2-Lunes Popular: " << lun << endl;
                    cout << "  3-Miercoles para ti: " << mpt << endl;
                    cout << "  4-Adultos Mayor: " << am << endl;
                    break;
                }
                }
                if ((boleto < 1) || (boleto > 4)) {
                    cout << "Por favor, ingrese una opcion valida\n";
                }
            } while ((boleto < 1) || (boleto > 4));
        }
        if ((opc != 1) && (opc != 2)) {
            cout << "Por favor, ingrese una opcion valida\n";
        }
    } while ((opc != 1) && (opc != 2));
    menu();
}
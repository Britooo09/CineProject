/*PROGRAMA DE REGISTRO DE DATOS EN UN CINE
Proyecto de software. Taller de POO, sección 02
Realizado por:
Nelyany Bermúdez, CI: 30224010
Bismark Barrios, CI: 31087158
José Brito, CI: 30515175
Geomar Cedeño, CI: 30834323*/

#include <iostream>
#include <string>
using namespace std;

// Declaración de variables y arreglos globales
string userlist[] = { "pepito", "juanito", "jaimito" };
string passlist[] = { "password", "tpoo", "12345" };
string asientos[6][7][10];
string sesion = "0";
int numCliente = 0, numAsiento = 0;
int cedulas[20];
float gen = 50.0, lun = 25.0, mpt = 40.0, am = 25.0, nuevoprecio = 0;

// Todos los datos de cada cliente registrado
class Cliente {
    int cedula;
    string nombre;
    int descuento, pelicula, boleto;
    float precio, total;
public:
    Cliente(int _cedula, string _nombre, int _descuento, int _pelicula, int _boleto): cedula(_cedula), nombre(_nombre), descuento(_descuento), pelicula(_pelicula - 1), boleto(_boleto) {
        switch (descuento) {
        case 1:
            precio = lun;
            break;
        case 2:
            precio = mpt;
            break;
        case 3:
            precio = am;
            break;
        case 4:
            precio = gen;
            break;
        }
        total = precio * boleto;
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
    float Gettotal() {
        return total;
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
    void Deletetotal() {
        total = '\0';
    }
};

// Todos los datos de cada una de las películas disponibles
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

// Control de los asientos ocupados
struct Asientos {
    int cliente, fila, columna;
};

// Declaración de arreglos de las clases y estructuras creadas
Pelicula* peli[6];
Cliente* cliente[20];
Asientos ocupados[6][50];

// Declaración de todas las funciones
void encabezado();
void login();
void menu();
void crearAsientos(int a);
void crearPeliculas();
void mostrarAsientos(int a);
void unaPelicula(int a);
void mostrarPeliculas();
void unCliente(int a);
void registro();
void buscar();
void eliminar();
void clientes();
void listaPeliculas();
void precios();

int main() {
    crearPeliculas();
    login();
    system("pause");
    return 0;
}

// Inicio de la definición de funciones
void encabezado() {                     // Estructura que siempre debe aparecer en pantalla
    system("cls");
    cout << "\t\t* SISTEMA DE GESTION PRINCIPAL DEL CINE *\n";
    if (sesion != "0") {
        cout << "\t\t\t  Bienvenido, " << sesion << "\n\n";
    } else cout << "\n";
}

void login() {                          // Función de inicio de sesión en el programa
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
            sesion = userlist[i];
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

void menu() {                           // Menú principal
    encabezado();

    int opc;
    cout << "Bienvenido al programa de gestion de boletos. Por favor, seleccione una opcion:\n";
    cout << "  1. Registrar nuevo cliente\n  2. Buscar cliente\n  3. Eliminar Cliente\n  4. Ver lista de clientes\n  5. Ver lista de peliculas\n  6. Precio de boletos\n  0. Salir del programa" <<  "\n";
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
        encabezado();
        cout << "La opcion que selecciono no es valida. Por favor, intente de nuevo\n\n";
        system("pause");
        menu();
        break;
    }
    }
}

void crearAsientos(int a) {             // Función que se ejecuta al inicio para establecer los asientos disponibles una película
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

void crearPeliculas() {                 // Función que se ejecuta al inicio para definir todas las películas disponibles
    for (int i = 0; i < 6; i++) {
        crearAsientos(i);
    }

    peli[0] = new Pelicula("El Gato con Botas", 1, 14, "A");
    peli[1] = new Pelicula("Las Momias", 2, 15, "A");
    peli[2] = new Pelicula("Scream 6", 3, 15, "B");
    peli[3] = new Pelicula("Creed III", 4, 17, "B");
    peli[4] = new Pelicula("La Ballena", 5, 19, "B");
    peli[5] = new Pelicula("El Aro", 6, 20, "B");
}

void mostrarAsientos(int a) {           // Muestra los asientos disponibles para una película en específico
    for (int i = 0; i < 7; i++) {
        cout << "  ";
        switch (i) {
        case 0:
            cout << "    ";
            break;
        case 1:
            cout << "1   ";
            break;
        case 2:
            cout << "2   ";
            break;
        case 3:
            cout << "3   ";
            break;
        case 4:
            cout << "4   ";
            break;
        case 5:
            cout << "5   ";
            break;
        case 6:
            cout << "6   ";
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

void unaPelicula(int a) {               // Muestra todos los datos de una película
    a--;
    cout << a + 1 << ". " << peli[a]->GetNombre() << " (Sala " << peli[a]->GetSala() << ") | " << peli[a]->GetHora() << ":00 | " << peli[a]->GetClas() << "\n";
}

void mostrarPeliculas() {               // Muestra todas las películas disponibles
    for (int i = 1; i < 7; i++) {
        cout << "  ";
        unaPelicula(i);
    }
}

void unCliente(int a) {                 // Muestra todos los datos de un cliente
    cout << "  Cliente nro. " << a + 1 << "\n";
    cout << "  CI: " << cliente[a]->Getcedula() << "\n";
    cout << "  Nombre: " << cliente[a]->Getnombre() <<  "\n";

    cout << "  Pelicula: ";
    unaPelicula(cliente[a]->Getpelicula() + 1);

    cout << "  Asiento(s): ";
    for (int j = 0; j < 50; j++) {
        if ((ocupados[cliente[a]->Getpelicula()][j].cliente == a) && ocupados[cliente[a]->Getpelicula()][j].fila != 0) {
            cout << ocupados[cliente[a]->Getpelicula()][j].fila << "-" << ocupados[cliente[a]->Getpelicula()][j].columna + 1 << " ";
        }
    }

    cout << "\n  Total a pagar: Bs. " << cliente[a]->Gettotal() << "\n\n";
}

void registro() {                       // Ejecuta la opción 1 del menú principal. Permite registrar un nuevo cliente
    encabezado();

    int CI, Dto, B, opc, filas, colum;
    string N;
    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> CI;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin >> ws, N);

    // Se comprueba que la opción ingresada por el usuario es válida. Este método se utilizará en diversas ocasiones
    do {
        cout << "\nDesea aplicar un descuento?\n";
        cout << "  1. Lunes popular (Bs. " << lun << ")\n";
        cout << "  2. Miercoles para ti (Bs. " << mpt << ")\n";
        cout << "  3. Adulto mayor (Bs. " << am << ")\n";
        cout << "  4. No (Bs. " << gen << ")\n";
        cin >> Dto;
        if (Dto < 1 || Dto > 4) {
            encabezado();
            cout << "Por favor, ingrese una opcion valida";
        }
    } while (Dto < 1 || Dto > 4);

    encabezado();
    do {
        cout << "Indique la pelicula deseada segun la lista: \n";
        mostrarPeliculas();
        cin >> opc;
        if (opc < 1 || opc > 6) {
            encabezado();
            cout << "Por favor, ingrese una opcion valida\n";
        }
    } while (opc < 1 || opc > 6);

    do {
        cout << "\nIndique cuantos boletos desea comprar: ";
        cin >> B;
        if (B < 1 || B > 50) {
            cout << "\nPor favor, indique un numero valido";
        }
    } while (B < 1 || B > 50);
    encabezado();

    for (int i = 0; i < B; i++) {
        do {
            cout << "Seleccione el asiento " << i + 1 << " (ingrese primero las filas y luego las columnas): \n\n";
            mostrarAsientos(opc - 1);
            cin >> filas;
            cin >> colum;
            encabezado();
            if (asientos[opc - 1][filas][colum - 1] == "X ") {
                cout << "Ese asiento ya esta ocupado. Por favor, seleccione otro\n";
            }
            if (filas < 1 || filas > 6 || colum < 1 || colum > 10 || (filas != 1 && colum == 5) || (filas != 1 && colum == 6)) {
                cout << "Ese asiento no es valido. Por favor, vuelva a intentarlo\n";
            }

        } while (asientos[opc - 1][filas][colum - 1] == "X " || filas < 1 || filas > 6 || colum < 1 || colum > 10 || (filas != 1 && colum == 5) || (filas != 1 && colum == 6));

        // Es llevado el control de los asientos ocupados
        asientos[opc - 1][filas][colum - 1] = "X ";
        ocupados[opc - 1][numAsiento].cliente = numCliente;
        ocupados[opc - 1][numAsiento].fila = filas;
        ocupados[opc - 1][numAsiento].columna = colum - 1;
        numAsiento++;
    }

    cliente[numCliente] = new Cliente(CI, N, Dto, opc, B);
    cedulas[numCliente] = cliente[numCliente]->Getcedula();

    cout << "Registro de nuevo cliente exitoso\n";
    unCliente(numCliente);
    system("pause");
    numCliente++;
    menu();
}

void buscar() {                         // Ejecuta la opción 2 del menú principal. Busca (por cédula) entre los clientes registrados
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

void eliminar() {                       // Ejecuta la opción 3 del menú principal. Busca y elimina alguno de los clientes registrados
    encabezado();

    int busqueda, pos, opc;
    bool flag = false;
    cout << "Ingrese la cedula de identidad del cliente: ";
    cin >> busqueda;

    // Algoritmo de búsqueda
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

            //Verifica cuáles asientos fueron registrados por el cliente a eliminar y los restablece
            for (int i = 0; i < 50; i++) {
                if ((ocupados[cliente[pos]->Getpelicula()][i].cliente == pos) && (asientos[cliente[pos]->Getpelicula()][ocupados[cliente[pos]->Getpelicula()][i].fila][ocupados[cliente[pos]->Getpelicula()][i].columna] == "X ")) {
                    asientos[cliente[pos]->Getpelicula()][ocupados[cliente[pos]->Getpelicula()][i].fila][ocupados[cliente[pos]->Getpelicula()][i].columna] = "O ";
                }
            }

            ocupados[cliente[pos]->Getpelicula()];
            cedulas[pos] = '\0';
            cliente[pos]->Deleteboleto();
            cliente[pos]->Deletecedula();
            cliente[pos]->Deletedescuento();
            cliente[pos]->Deletenombre();
            cliente[pos]->Deletepelicula();

            encabezado();
            cout << "Se ha eliminado el cliente con exito\n\n";
            system("pause");
        } else if (opc == 2) {} else {
            encabezado();
            cout << "La opcion que selecciono no es valida. Regresando al menu principal\n";
            system("pause");
        }

    } else {
        cout << "El cliente no esta registrado\n\n";
        system("pause");
    }
    menu();
}

void clientes() {                       // Ejecuta la opción 4 del menú principal. Despliega la lista de clientes registrados
    encabezado();

    for (int i = 0; i < numCliente; i++) {
        if (cliente[i]->Getcedula()) {
            cout << cliente[i]->Getcedula() << " | " << cliente[i]->Getnombre() << " | " << peli[cliente[i]->Getpelicula()]->GetNombre() << "\n\n";
        }
    }
    system("pause");
    menu();
}

void listaPeliculas() {                 // Ejecuta la opción 5 del menú principal. Despliega la lista de películas y permite ver los asientos disponibles para cada una de ellas
    encabezado();
    int opc;
    cout << "Indique una pelicula para ver los asientos disponibles: \n";
    mostrarPeliculas();
    cout << "  0. Volver al menu anterior\n";

    do {
        cin >> opc;
        if (opc < 1 || opc > 6) {
            cout << "\nPor favor, ingrese una opcion valida\n";
        }
    } while (opc < 0 || opc > 6);

    if (opc) {
        encabezado();
        cout << "Asientos disponibles para " << peli[opc - 1]->GetNombre() << ":\n\n";
        mostrarAsientos(opc - 1);
        system("pause");
    }
    menu();
}

void precios() {                        // Ejecuta la opción 6 del menú principal. Permite ver y cambiar el precio de los boletos
    encabezado();

    int opc, boleto;
    cout << "Precio de los boletos: \n";

    cout << "  1-General: Bs. " << gen;
    cout << "\n  2-Lunes Popular: Bs. " << lun;
    cout << "\n  3-Miercoles para ti: Bs. " << mpt;
    cout << "\n  4-Adulto Mayor: Bs. " << am << "\n\n";

    cout << "1. Modificar precio de los boletos\n";
    cout << "2. Volver al menu anterior\n\n";

    do {
        cout << "Seleccione una opcion: ";
        cin >> opc;
        if (opc == 1) {
            do {
                cout << "Indique el boleto a modificar: ";
                cin >> boleto;
                switch (boleto) {
                case 1: {
                    cout << "Indique el nuevo precio: ";
                    cin >> nuevoprecio;
                    gen = nuevoprecio;
                    encabezado();
                    cout << "Precio actualizado\n\n";
                    system("pause");
                    break;
                }
                case 2: {
                    cout << "Indique el nuevo precio: ";
                    cin >> nuevoprecio;
                    lun = nuevoprecio;
                    encabezado();
                    cout << "Precio actualizado\n\n";
                    system("pause");
                    break;
                }
                case 3: {
                    cout << "Indique el nuevo precio: ";
                    cin >> nuevoprecio;
                    mpt = nuevoprecio;
                    encabezado();
                    cout << "Precio actualizado\n\n";
                    system("pause");
                    break;
                }
                case 4: {
                    cout << "Indique el nuevo precio: ";
                    cin >> nuevoprecio;
                    am = nuevoprecio;
                    encabezado();
                    cout << "Precio actualizado\n\n";
                    system("pause");
                    break;
                }
                }
                if ((boleto < 1) || (boleto > 4)) {
                    cout << "\nPor favor, ingrese una opcion valida\n";
                }
            } while ((boleto < 1) || (boleto > 4));
        }
        if ((opc != 1) && (opc != 2)) {
            cout << "\nLa opcion que selecciono no es valida. Por favor, intente de nuevo\n";
        }
    } while ((opc != 1) && (opc != 2));
    menu();
}
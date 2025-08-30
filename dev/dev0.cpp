#include <iostream>
#include<string>
using namespace std;

string userlist[] = { "pepito", "juanito", "jaimito" };
string passlist[] = { "password", "tpoo", "12345" };

float gen = 50.0, lun = 25.0, mpt = 40.0, am = 25.5, nuevoprecio = 0;
class cliente{
	int cedula;
	string nombre;
	int descuento,pelicula,boleto;
	public:
		cliente(int _cedula,string _nombre,int _descuento,int _pelicula,int _boleto):cedula(_cedula),nombre(_nombre),descuento(_descuento),pelicula(_pelicula),boleto(_boleto) {}
		int Getcedula(){
			return cedula;
		}
		string Getnombre(){
			return nombre;
		}
		int Getdescuento(){
			return descuento;
		}
		int Getpelicula(){
			return pelicula;
		}
		int Getboleto(){
			return boleto;
		}
};


void encabezado();
void login();
void menu();
void registro();
void buscar();
void eliminar();
void clientes();
void peliculas();
void precios();

int main() {
    login();
    system("pause");
    return 0;
}

void encabezado() {     // LISTO
    cout << "\t\t* GESTIÓN DE BOLETOS DEL CINE *\n\n";
}

void login() {          // LISTO
    encabezado();

    string user, pass;
    cout << "Por favor, compruebe su identidad entrando con sus credenciales.\n";
    cout << "\nUsuario: ";
    cin >> user;
    cout << "\nContraseña: ";
    cin >> pass;

    bool correcto = false;
    for (int i = 0; i < 3; i++) {
        if ((user == userlist[i]) && (pass == passlist[i])) {
            correcto = true;
        }
    }

    if (correcto) {
        system("cls");
        encabezado();
        cout << "Usted ha ingresado correctamente. Entrando al sistema...\n\n";
        system("pause");
        system("cls");
        menu();
    } else {
        system("cls");
        encabezado();
        cout << "Usuario y/o contraseña incorrectos. Por favor, intente de nuevo\n\n";
        system("pause");
        system("cls");
        login();
    }
}

void menu() {           // LISTO
    encabezado();

    int opc;
    cout << "Bienvenido al programa de gestion de boletos. Por favor, seleccione una opcion:\n";
    cout << "  1.Registrar nuevo cliente\n  2.Buscar nuevo cliente\n  3.Eliminar Cliente\n  4.Ver lista de clientes\n  5.Ver lista de peliculas\n  6.Precio de boletos\n  0.Salir del programa" << endl;
    cin >> opc;
    switch (opc) {
    case 1: {
        system("cls");
        registro();
        break;
    }
    case 2: {
        system("cls");
        buscar();
        break;
    }
    case 3: {
        system("cls");
        eliminar();
        break;
    }
    case 4: {
        system("cls");
        clientes();
        break;
    }
    case 5: {
        system("cls");
        peliculas();
        break;
    }
    case 6: {
        system("cls");
        precios();
        break;
    }
    case 0: {
        system("cls");
        break;
    }
    default: {
        cout << "la opción que selecciono no esta en el menú principal, ingrese de nuevo una opción";
        system("cls");
        menu();
        break;
    }
    }
}

void registro() {
	int CI,Dto,peli,B,opc;
	string N;
	cout<<"ingrese la cedula de identidad del cliente: "<<endl;
	cin>>CI;
	cout<<"ingrese el nombre del cliente: "<<endl;
	cin>>N;
	cout<<"�desea aplicar un descuento? "<<endl;
	cout<<"1.Lunes popular (Bs."<<lun<<")"<<endl;
	cout<<"2.Miercoles para ti (Bs"<<mpt<<")"<<endl;
	cout<<"3.Adulto mayor (Bs"<<am<<")"<<endl;
	cout<<"4. Ninguno (Bs"<<gen<<")"<<endl;
	cin>>Dto;
	system("cls");
	cout<<"Indique la pelicula deseada segun la lista: "<<endl;
	cout<<"1. "<<endl;
	cout<<"2. "<<endl;
	cout<<"3. "<<endl;
	cout<<"4. "<<endl;
	cout<<"5. "<<endl;
	cout<<"6. "<<endl;
	cin>>opc;
	cout<<"indique cuantos boletos desea comprar: "<<endl;
	cin>>B;
}

void buscar() {
    cout << "Fino señores\n";
}

void eliminar() {
    cout << "Fino señores\n";
}

void clientes() {
    cout << "Fino señores\n";
}

void peliculas() {
    cout << "Fino señores\n";
}

void precios() {        // LISTO
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
            } while ((boleto < 1) || (boleto > 4));
        }
    } while ((opc != 1) && (opc != 2));
    system("cls");
    menu();
}

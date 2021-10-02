#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
	int id, telefono;
	string nombre, codigoArea;
	Nodo *siguiente;
};

class listaSimple
{
private:
	Nodo *pInicio;

public:
	listaSimple();
	void agregarRegistro(void);
	void mostrarRegistro();
	void mostrarRegistro(Nodo *p);
};

void menu(void)
{

    cout<<"\t.:MENU:.\n";
    cout<<"1. Llenar registro"<<endl;
    cout<<"2. Mostrar registro"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"opcion : ";
}

listaSimple::listaSimple(void)
{
	pInicio = NULL;
}

void listaSimple::agregarRegistro(void)
{
	Nodo *dato;
	dato = new Nodo;

	cout<<"\t.:Registro de personas:.\n";
    cout<<"Ingrese el id: "; cin>>dato->id;
    cin.ignore();
    cout<<"Ingrese el nombre: "; getline(cin, dato->nombre);
    cout<<"Ingrese el codigo de area del pais: "; getline(cin, dato->codigoArea);
    cout<<"Ingrese el telefono: "; cin>>dato->telefono;

	dato->siguiente = NULL;

	if (!pInicio)
	{
		pInicio = dato;
	}
	else
	{
		Nodo *aux = pInicio;
		while (aux->siguiente != NULL)
		aux = aux->siguiente;
		aux->siguiente = dato;
	}
    cout<<"\t!Registro agregado correctamente!\n";
}

void listaSimple::mostrarRegistro()
{
	Nodo *dato = pInicio;
	if (!dato)
    {   
        cout<<"\t\n*No hay registro que mostrar*\n";
        return;
    }
	else
	{
        cout<<"id: "<<dato->id<<endl;
        cout<<"Nombre: "<<dato->nombre<<endl;
        cout<<"Codigo de area del pais: "<<dato->codigoArea<<endl;
        cout<<"Telefono: "<<dato->telefono<<endl;
		cout<<"\n";
		mostrarRegistro(dato->siguiente); 
	}
}

void listaSimple::mostrarRegistro(Nodo *dato)
{
	if (!dato)
		return;
	else
	{
        cout<<"id: "<<dato->id<<endl;
        cout<<"Nombre: "<<dato->nombre<<endl;
        cout<<"Codigo de area del pais: "<<dato->codigoArea<<endl;
        cout<<"Telefono: "<<dato->telefono<<endl;
		cout<<"\n";
		mostrarRegistro(dato->siguiente);
	}
}

int main(void)
{
	listaSimple registro;
	int opcion;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: registro.agregarRegistro();
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: 
					cout<<"\t.:Lista de registros:.\n";
                    registro.mostrarRegistro();
                    cout<<"\n";
                    system("pause");
                    break;
			case 3: 
					cout<<"Saliendo del programa...."<<endl;
					cout<<"\n";
                    system("pause");
					return 0;
                    default: 
					cout<<"!!Ingrese un numero valido!!"<<endl;
					cout<<"\n";
                    system("pause");
                    break;
        }
        system("cls");
    }while(opcion != 3);

	return 0;
}
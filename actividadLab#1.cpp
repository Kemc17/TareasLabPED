#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
	int carnet, edad, telefono;
	string nombre, apellido, email;
	Nodo *siguiente;
};

class listaSimple
{
private:
	Nodo *pInicio;

public:
	listaSimple();
	void agregarPersonas(void);
	void eliminarPersona(void);
	void mostrarLista();
	void mostrarLista(Nodo *p);
};

void menu(void)
{

    cout<<"\t.:MENU:.\n";
    cout<<"1. Llenar lista"<<endl;
    cout<<"2. Eliminar persona"<<endl;
    cout<<"3. Mostrar lista"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"opcion : ";
}

listaSimple::listaSimple(void)
{
	pInicio = NULL;
}

void listaSimple::agregarPersonas(void)
{
	Nodo *dato;
	dato = new Nodo;

	cout<<"\t.:Registro de personas:.\n";
    cout<<"Ingrese el carnet: "; cin>>dato->carnet;
    cin.ignore();
    cout<<"Ingrese el nombre: "; getline(cin, dato->nombre);
    cout<<"Ingrese el apellido: "; getline(cin, dato->apellido);
    cout<<"Ingrese la edad: "; cin>>dato->edad;
    cin.ignore();
    cout<<"Ingrese el telefono: "; cin>>dato->telefono;
    cin.ignore();
    cout<<"Ingrese el correo: "; getline(cin, dato->email);

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
    cout<<"\t!Persona agregada correctamente!\n";
}

void listaSimple::eliminarPersona(void)
{
	int carnet = 0;
	Nodo *p = pInicio;
	Nodo *q = NULL;

    cout<<"\t.:Eliminar personas:.\n";
	cout<<"\nIngrese el carnet: "; cin>>carnet;

    while ((p != NULL) && (p->carnet != carnet))
	{
		q = p;
		p = p->siguiente;
	}
	if (p == NULL)
	{
		cout << "*No existe la persona ingresada*" << endl;
		return;
	}

	if (pInicio->carnet == carnet)
	{
		pInicio = pInicio->siguiente;

		delete (p);
		cout<<"\t--Persona eliminada--\n";
		return;
	}

	if (q == NULL)
		p = p->siguiente;
	else
		q->siguiente = p->siguiente;
	delete (p);
	cout<<"\t--Persona eliminada--\n";
}

void listaSimple::mostrarLista()
{
	Nodo *dato = pInicio;
	if (!dato)
    {   
        cout<<"\t\n*No hay lista que mostrar*\n";
        return;
    }
	else
	{
        cout<<"Carnet: "<<dato->carnet<<endl;
        cout<<"Nombre: "<<dato->nombre<<endl;
        cout<<"Apellido: "<<dato->apellido<<endl;
        cout<<"Edad: "<<dato->edad<<endl;
        cout<<"Correo: "<<dato->email<<endl;
        cout<<"Telefono : "<<dato->telefono<<endl<<endl;
		mostrarLista(dato->siguiente);
	}
    
}
void listaSimple::mostrarLista(Nodo *dato)
{
	if (!dato)
		return;
	else
	{
        cout<<"Carnet: "<<dato->carnet<<endl;
        cout<<"Nombre: "<<dato->nombre<<endl;
        cout<<"Apellido: "<<dato->apellido<<endl;
        cout<<"Edad: "<<dato->edad<<endl;
        cout<<"Correo: "<<dato->email<<endl;
        cout<<"Telefono : "<<dato->telefono<<endl;
		mostrarLista(dato->siguiente);
	}
}

int main(void)
{
	listaSimple persona;
	int opcion;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: persona.agregarPersonas();
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: 
                    persona.eliminarPersona();
                    cout<<"\n";
                    system("pause");
                    break;
            case 3: 
					cout<<"\t.:Lista de personas:.\n";
                    persona.mostrarLista();
                    cout<<"\n";
                    system("pause");
                    break;
			case 4: 
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
    }while(opcion != 4);


	return 0;
}
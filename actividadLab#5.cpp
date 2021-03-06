#include <iostream>
#include <string>

using namespace std;

struct nodo
{
    int id, edad;
    string nombreDueno, nombreMascota, raza;
    float peso;
    nodo *sig;
};

class CircSimple
{
private:
    nodo *pInicio;

public:
    CircSimple();
    void insertarDatos(void);
    void imprimirDatos();
    void eliminarPersona(void);
};

CircSimple::CircSimple()
{
    pInicio = NULL;
}

void menu(void)
{

    cout<<"\t.:MENU:.\n";
    cout<<"1. Ingresar datos del cliente"<<endl;
    cout<<"2. Eliminar cliente"<<endl;
    cout<<"3. Mostrar clientes"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"opcion : ";
}

void CircSimple::insertarDatos(void)
{
    nodo *dato;
	dato = new nodo;

	cout<<"\t.:Registro de clientes:.\n";
    cout<<"Ingrese el id: "; cin>>dato->id;
    cin.ignore();
    cout<<"Ingrese el nombre del dueno: "; getline(cin, dato->nombreDueno);
    cout<<"Ingrese el nombre de la mascota: "; getline(cin, dato->nombreMascota);
    cout<<"Ingrese la raza de la mascota: "; getline(cin, dato->raza);
    cout<<"Ingrese el peso de la mascota: "<<"lb "; cin>>dato->peso;
    cin.ignore();
    cout<<"Ingrese la edad de la mascota: "<<"anos "; cin>>dato->edad;

	dato->sig = NULL;

	if (!pInicio)
	{
		pInicio = dato;
	}
	else
	{
		nodo *aux = pInicio;
		while (aux->sig != NULL)
		aux = aux->sig;
		aux->sig = dato;
	}
    cout<<"\t!Persona agregada correctamente!\n";
}


void CircSimple::imprimirDatos()
{	

	nodo *saltarin= new nodo();

    saltarin = pInicio;
    bool encontrado = false;
    int nodobuscado = 0;

    cout <<"Ingrese el ID del usuario a mostrar: ";
    cin >>  nodobuscado; cout << endl;
    cin.ignore();

    if (pInicio != NULL)
	{
		do
        {  
			if (saltarin->id == nodobuscado){
            cout <<"ID ["<<saltarin->id<<"]"<<endl;
            cout <<"Nombre del duenio: "<<saltarin->nombreDueno<<endl;
			cout <<"Nombre de la mascota: "<<saltarin->nombreMascota<<endl;
            cout <<"Raza de la mascota: "<<saltarin->raza<<endl;
            cout <<"Peso: "<<saltarin->peso<<" lb" <<endl;
            cout <<"Edad: " <<saltarin->edad <<" anos"<<endl;

            encontrado = true;
            }

            saltarin = saltarin->sig;

        } while (saltarin != pInicio && encontrado!= true);

        if(!encontrado)
		{
            cout <<"ID no encontrado."<<endl;
        }

        }else
		{
            cout <<"La lista esta vacia."<<endl;
        }
}

void CircSimple::eliminarPersona(void)
{
	int id = 0;
	nodo *p = pInicio;
	nodo *q = NULL;

    cout<<"\t.:Eliminar personas:.\n";
	cout<<"\nIngrese el ID: "; cin>>id;

    while ((p != NULL) && (p->id != id))
	{
		q = p;
		p = p->sig;
	}
	if (p == NULL)
	{
		cout << "*No existe la persona ingresada*" << endl;
		return;
	}

	if (pInicio->id == id)
	{
		pInicio = pInicio->sig;

		delete (p);
		cout<<"\t--Persona eliminada--\n";
		return;
	}

	if (q == NULL)
		p = p->sig;
	else
		q->sig = p->sig;
	delete (p);
	cout<<"\t--Persona eliminada--\n";
}

int main(void)
{
	CircSimple persona;
	int opcion;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: persona.insertarDatos();
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
                    persona.imprimirDatos();
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

#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
	int pupusas;
	string tipoPupusas, soda, ingredientes;
	Nodo *siguiente;
};

class listaSimple
{
private:
	Nodo *pInicio;

public:
	listaSimple();
	void agregarOrden(void);
	void mostrarOrden();
	void mostrarOrden(Nodo *p);
};

void menu(void)
{

    cout<<"\t.:MENU:.\n";
    cout<<"1. Agregar orden de pupusas"<<endl;
    cout<<"2. Mostrar orden de pupusas"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"opcion : ";
}

listaSimple::listaSimple(void)
{
	pInicio = NULL;
}

void listaSimple::agregarOrden(void)
{
	Nodo *dato;
	dato = new Nodo;

	cout<<"\t.:Orden de pupusas:.\n";
    cout<<"Ingrese la cantidad de pupusas totales: "; cin>>dato->pupusas;
    cin.ignore();
    cout<<"Tipo de pupusas (Arroz o maiz): "; getline(cin, dato->tipoPupusas);
    cout<<"Con Coca-Cola (Si o No): "; getline(cin, dato->soda);
    cout<<"Ingredientes de las pupusas: "; cin>>dato->ingredientes;

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
    cout<<"\t!Orden agregada correctamente!\n";
}

void listaSimple::mostrarOrden()
{
	Nodo *dato = pInicio;
	if (!dato)
    {   
        cout<<"\t\n*No hay orden que mostrar*\n";
        return;
    }
	else
	{
        cout<<"Pupusas: "<<dato->pupusas<<endl;
        cout<<"Tipo de pupusas: "<<dato->tipoPupusas<<endl;
        cout<<"Con Coca-Cola: "<<dato->soda<<endl;
        cout<<"Ingredientes: "<<dato->ingredientes<<endl;
		mostrarOrden(dato->siguiente);
    }
}
void listaSimple::mostrarOrden(Nodo *dato)
{
	if (!dato)
		return;
	else
	{
        cout<<"Pupusas: "<<dato->pupusas<<endl;
        cout<<"Tipo de pupusas: "<<dato->tipoPupusas<<endl;
        cout<<"Con Coca-Cola: "<<dato->soda<<endl;
        cout<<"Ingredientes: "<<dato->ingredientes<<endl;
		mostrarOrden(dato->siguiente);
	}
}

int main(void)
{
	listaSimple orden;
	int opcion;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: orden.agregarOrden();
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: 
					cout<<"\t.:Orden de pupusas:.\n";
                    orden.mostrarOrden();
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
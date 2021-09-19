#include <iostream>

using namespace std;

void menu();
void pedirDatos();
int metodoEuclicides(int, int);
void muestraConteo(int);

int mayor = 0, menor = 0, n1 = 0;

void menu(void)
{
    cout<<"\t.:MENU:.\n";
    cout<<"1. Ejercicio#1"<<endl;
    cout<<"2. Ejercicio#2"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion: ";
}

void pedirDatos()
{   
    cout<<"\n";
    cout<<"Ingrese un dato entero: "; cin>>mayor;
    cout<<"Ingrese un segundo dato entero: "; cin>>menor;
}

int metodoEuclicides(int n1, int n2)
{
    if (n1 == 0)
    {
        return n2;
    }
    return metodoEuclicides(n2 % n1, n1);
}

void muestraConteo(int n1)
{   
    cout<<"\n";
    cout<<"Ingrese el numero de dato a ver: "; cin>>n1;
    

    for (int i = 1; i < n1+1; i++)
    {   
        cout<<i<<" "<<endl;
    }

    for (int i = n1-1; i >= 1; i--)
    {
        cout<<i<<" "<<endl;
    }
    
}

int main()
{   
    int opcion = 0;

    do{
        menu();
        cin>>opcion;
        cin.ignore();
        
        switch(opcion){

            case 1: pedirDatos();
                    cout<<"\nEl resultado del MCD es: "<<metodoEuclicides(mayor, menor)<<endl<<endl;
                    cout<<"\n";
                    system("pause");
                    break;
            case 2: 
                    muestraConteo(n1);
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


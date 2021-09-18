#include <iostream>

using namespace std;

void pedirDatos();
int metodoEuclicides(int, int);

int mayor = 0, menor = 0;

int main()
{   
    cout<<endl;
    pedirDatos();
    cout<<"\nEl resultado del MCD es: "<<metodoEuclicides(mayor, menor)<<endl<<endl;
}

void pedirDatos()
{
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
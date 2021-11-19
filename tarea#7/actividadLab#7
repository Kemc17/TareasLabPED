#include <iostream>

using namespace std;

struct nodo
{
    int numero;
    nodo *hijoIzq; 
    nodo *hijoDer; 
};

class ABB
{

private:
    nodo *pAbb;

public:
    ABB();
    void insertar(void);
    void insNodoAbb(nodo **, int);

    void mostrarEnPeorden(void);
    void mostrarPre(nodo *);

    void mostrarEnInOrden(void);
    void mostrarIn(nodo *);

    void mostrarEnPosOrden(void);
    void mostrarPos(nodo *);
};

ABB::ABB(void)
{
    pAbb = NULL;
}

void ABB::insertar(void)
{

    int numero;

    cout << "Arbol binario\n";
    cout << "Ingrese el numero: ";
    cin >> numero;
    cin.ignore();

    insNodoAbb(&pAbb, numero);
}

void ABB::insNodoAbb(nodo **p, int numero)
{
    if (!(*p))
    {
        *p = new nodo;
        (*p)->numero = numero;
        (*p)->hijoIzq = NULL;
        (*p)->hijoDer = NULL;
    }
    else if (numero < (*p)->numero)
        insNodoAbb(&((*p)->hijoIzq), numero);
    else if (numero > (*p)->numero)
        insNodoAbb(&((*p)->hijoDer), numero);
    else
        cout << "Atencion: La llave ya esta en el arbol ";
}

void ABB::mostrarEnInOrden(void)
{
    mostrarIn(pAbb);
}

void ABB::mostrarIn(nodo *p)
{
    if (p)
    {
        mostrarIn(p->hijoIzq);
        cout << "Numero: " << p->numero <<  "  " <<  endl;
        mostrarIn(p->hijoDer);
    }
}

void ABB::mostrarEnPeorden(void)
{
    mostrarPre(pAbb);
}

void ABB::mostrarPre(nodo *p)
{
    if (p)
    {
         cout << "Numero: " << p->numero << "  " <<  endl;
        mostrarPre(p->hijoIzq);
        mostrarPre(p->hijoDer);
    }
}

void ABB::mostrarEnPosOrden(void)
{
    mostrarPos(pAbb);
}

void ABB::mostrarPos(nodo *p)
{
    if (p)
    {
        mostrarIn(p->hijoIzq);
        mostrarIn(p->hijoDer);
        cout << "Numero: " << p->numero << "  " <<  endl;
    }
}

int main(void)
{
    bool execute = true;
    int opc = 0;

    ABB objABB;

    cout << endl;

    do
    {
        cout << "\n\t.:Menu:." << endl;
        cout << "1) Agregar numero" <<  endl;
        cout << "2) Imprimir preOrder" <<  endl;
        cout << "3) Imprimir inOrder" <<  endl;
        cout << "4) Imprimir postOrder" <<  endl;
        cout << "5) Salir" <<  endl;
        cout << "Opcion: ";
        cin  >> opc;
            
        switch (opc)
        {
        case 1:
            cout << "----------------------" << endl;
            objABB.insertar();
            break;

        case 2:
            cout << "----------------------" << endl;
            objABB.mostrarEnPeorden();
            break;

        case 3:
            cout << "----------------------" << endl;
            objABB.mostrarEnInOrden();
            break;

        case 4:
            cout << "----------------------" << endl;
            objABB.mostrarEnPosOrden();
            break;

        case 5:
            cout << "----------------------" << endl;
            cout << "Saliendo del programa..."  << endl;
            execute = false;
            break;

        default:
            break;
        }
    } while (execute);

    cout << endl;
    return 0;
}

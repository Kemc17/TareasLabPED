#include <iostream>
#include <string>

using namespace std;

struct Usuario
{
    string nombre, perfil;
    int id;
};

Usuario solicitarUsuario(void)
{
    Usuario p;
    cout<<"Ingrese el id: ";
    cin>>p.id; cin.ignore();
    cout<<"Ingrese el nombre: ";
    getline(cin, p.nombre);
    cout<<"Ingrese el perfil del usuario (Administrador, Cliente o Trabajador): ";
    getline(cin, p.perfil);

    return p;
}

void mostrarUsuario(Usuario p)
{
    cout<<"id: "<<p.id<<"."<<endl;
    cout<<"Nombre: "<<p.nombre<<endl;
    cout<<"Perfil: "<<p.perfil<<endl;
    cout<<"\n";
}

typedef Usuario U;

struct nodo
{
    U dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble
{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble(void);
        void insertFront(U);
        void insertBack(U);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
};

int menu(){
    int opcion = 0;
    cout<<endl<<endl;
    cout<<"Bienvenidos!!!\n"<<endl;
    cout<<"\t.:MENU:.\n"<<endl;
    cout<<"1) ingresar un usuario de primero."<<endl;
    cout<<"2) ingresar un usuario despues."<<endl;
    cout<<"3) Mostrar usuarios de inicio a fin."<<endl;
    cout<<"4) Mostrar usuarios de fin a inicio."<<endl;
    cout<<"5) Salir."<<endl;
    cout<<"Opcion: ";
    cin>>opcion; cin.ignore();
    return opcion;
}

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(U dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insertBack(U dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else
    {
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void)
{
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarUsuario(saltarin->dato);
        saltarin = saltarin->sig;
    }
}
void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarUsuario(q->dato);
        q = q->ant;
    }
}


int main(void)
{
    ListaDoble user;
    
    bool continuar = true;
    Usuario p;
    Usuario pref;
    do{
        switch(menu())
        {   
            case 1: //Agregar una precuela
                p = solicitarUsuario();
                user.insertFront(p);
                cout << "Usuario de primero almacenado exitosamente!" << endl;
                break;
            case 2:
                p = solicitarUsuario();
                user.insertBack(p);
                cout<<"Usuario despues almacenado exitosamente!"<<endl;
                break;
            case 3:
                cout<<endl<<".:Usuarios:."<<endl;
                user.traversalForwardDirection();
                break;
            case 4:
                user.traversalReverseDirection();
                break;
            case 5: 
                continuar = false;
                break;
            default: 
                cout<<"Opcion escogida no valida, favor intentar de nuevo."<<endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
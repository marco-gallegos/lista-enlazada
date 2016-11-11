#ifndef LISTA
#define LISTA
#include<iostream>

using namespace std;

template <class DATO> class Lista;

template<class DATO> class Nodo
{
public:
    //constructor sobrecargado no permite construir sin pasarle dat
    Nodo(DATO dat,Nodo<DATO> * ant=NULL, Nodo<DATO> * sig = NULL):valor(dat),anterior(ant),
        siguiente(sig) { }

    DATO valor;
    Nodo<DATO> *anterior,*siguiente;

    friend class Lista<DATO>;


};

template<class DATO> ostream &operator <<(ostream &out,const Nodo<DATO> &a_mostrar)
{
    out<<a_mostrar.valor;
    return out;
}



template<class DATO> class Lista
{
public:
    Nodo<DATO> *head;
    //
    Nodo<DATO> *it;

    Lista():head(NULL),it(NULL){}

    void insertar(DATO a_insertar);
    bool eliminar(DATO a_borrar);
    bool eliminar(int pos);
    //regresara el dato que busca
    DATO buscar(DATO &a_buscar);
    void ultimo();
    void mostrar();

    void iterar();

};

template<class DATO> void Lista<DATO>::insertar(DATO a_insertar)
{
    if(this->head == NULL)
    {
        head = new Nodo<DATO>(a_insertar);
        return;
    }

    Nodo<DATO> *iterador= this->head;

    while(iterador->siguiente != NULL)
    {
        iterador = iterador->siguiente;
    }
    iterador->siguiente = new Nodo<DATO>(a_insertar,iterador);
    return;

}

template<class DATO> bool Lista<DATO>::eliminar(DATO a_borrar)
{
    Nodo<DATO> *iterador= this->head;
    Nodo<DATO> *anterior = NULL;
    if(a_borrar == this->head->valor)
    {
        this->head=this->head->siguiente;
        this->head->anterior = NULL;
        delete iterador;

        return true;
    }
    while(iterador->valor != a_borrar)
    {
        anterior = iterador;
        iterador= iterador->siguiente;
    }
    if(iterador->valor != a_borrar)
    {
        return false;
    }
    if(iterador->siguiente == NULL)
    {
        anterior->siguiente = NULL;
        delete iterador;
        return true;
    }

    iterador->siguiente->anterior = anterior;
    anterior->siguiente = iterador->siguiente;
    delete iterador;
    return true;
}

template<class DATO> void Lista<DATO>::iterar()
{
    if(this->it == NULL)
    {
        this->it = this->head;
    }
    int opc = 0;
    while(opc != 6)
    {
        cout<<"1 izquieda  2 derecha 6 salir"<<endl;
        cout<<this->it->valor<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            if(it->anterior == NULL)
            {
                cout<<"no hay"<<endl;
            }
            else
            {
                it=it->anterior;
            }
            break;
        case 2:
            if(it->siguiente == NULL)
            {
                cout<<"no hay"<<endl;
            }
            else
            {
                it=it->siguiente;
            }
            break;
        default:

            break;
        }
    }
}

#endif // LISTA


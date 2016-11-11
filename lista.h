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

    Lista():head(NULL){}

    void insertar(DATO a_insertar);
    void eliminar(DATO a_borrar);
    //regresara el dato que busca
    DATO buscar(DATO &a_buscar);
    void ultimo();
    void mostrar();
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

#endif // LISTA


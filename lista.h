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

template<class DATO> class Lista
{
public:
    Nodo<DATO> *head;

    Lista():head(NULL){}

    void insertar(DATO a_insertar);
    void eliminar(DATO a_borrar);
    //regresara el dato que busca
    DATO buscar(dato &a_buscar);
    void ultimo();
    void mostrar();

#endif // LISTA


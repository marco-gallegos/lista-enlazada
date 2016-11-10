#ifndef LISTA
#define LISTA
#include<iostream>

using namespace std;

template <class DATO> class Lista;

template<class DATO> class Nodo
{
public:
    Nodo(DATO dat,Nodo<DATO> * ant=NULL, Nodo<DATO> * sig = NULL):valor(dat),anterior(ant),
        siguiente(sig)
    {    }

    DATO valor;
    Nodo<DATO> *anterior,*siguiente;

    friend class Lista<DATO>;

};

#endif // LISTA


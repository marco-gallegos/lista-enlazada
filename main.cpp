#include <QCoreApplication>
#include "lista.h"

int main()
{
    //QCoreApplication a(argc, argv);
    Lista<string> mi_lista;
    mi_lista.insertar("hola");
    mi_lista.insertar("hola2");
    mi_lista.insertar("hola3");
    mi_lista.iterar();
    //return a.exec();
}


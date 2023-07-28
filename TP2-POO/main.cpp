#include <QCoreApplication>
#include <tablero.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int filas,columnas;

    cout<<"Filas: "; cin>>filas;
    cout<<"Columnas: "; cin>>columnas;

    Tablero* t = new Tablero(filas,columnas);

    t->mostrarTablero();


    return a.exec();
}

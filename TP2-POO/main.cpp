#include <QCoreApplication>
#include <tablero.h>
#include <juego.h>
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

    Juego* j = new Juego();

    j->iniciarPartida(t);

    t->mostrarTablero();

    char dir;
    cout<<"Direccion (w,a,s,d):"; cin>>dir;


    while(dir!='X')
    {
       j->crearRuta(t,dir);
       t->mostrarTablero();
       cout<<"Direccion (w,a,s,d):"; cin>>dir;
    }


    return a.exec();
}
